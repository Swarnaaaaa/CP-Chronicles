//Submission link:https://codeforces.com/contest/1225/submission/355550216
#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n, k;
    cin >> n >> k;
 
    vector<int> numbers(n);
    for(int i = 0; i < n; i++) cin >> numbers[i];
 
    const int MAX_VAL = 100000;
    vector<int> smallestPrime(MAX_VAL + 1);
    for(int i = 1; i <= MAX_VAL; i++) smallestPrime[i] = i;
 
    for(int i = 2; i * i <= MAX_VAL; i++){
        if(smallestPrime[i] == i){
            for(int j = i * i; j <= MAX_VAL; j += i){
                if(smallestPrime[j] == j)
                    smallestPrime[j] = i;
            }
        }
    }
 
    map<vector<pair<int,int>>, long long> frequency;
    long long answer = 0;
 
    for(int value : numbers){
        map<int,int> factorCount;
 
        while(value > 1){
            int primeFactor = smallestPrime[value];
            int exponent = 0;
            while(value % primeFactor == 0){
                value /= primeFactor;
                exponent++;
            }
            factorCount[primeFactor] += exponent;
        }
 
        vector<pair<int,int>> signature, complement;
        for(auto &entry : factorCount){
            int prime = entry.first;
            int remainder = entry.second % k;
 
            if(remainder != 0){
                signature.push_back({prime, remainder});
                complement.push_back({prime, (k - remainder) % k});
            }
        }
 
        sort(signature.begin(), signature.end());
        sort(complement.begin(), complement.end());
 
        answer += frequency[complement];
        frequency[signature]++;
    }
 
    cout << answer << "\n";
    return 0;
}

//Break each number into prime factors
//Keep only the remainder of powers modulo k
//Store this “pattern” 
//Look for another number whose pattern completes it to a multiple of k
//n → number of elements  k → power we care about
//smallestPrime[x] gives the smallest prime divisor of x. 
//frequency keeps count of how many times a signature has appeared
//answer stores final count of valid pairs