//Submission link:https://codeforces.com/contest/1560/submission/355549761
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;

        long long diff = llabs(a - b);
        if (diff == 0) {
            cout << -1 << '\n';
            continue;
        }

        long long N = 2 * diff;
        if (a > N || b > N || c > N) {
            cout << -1 << '\n';
            continue;
        }

        long long half = N / 2;
        long long d = (c + half <= N) ? c + half : c - half;

        cout << d << '\n';
    }
    return 0;
}
//In a circle, opposite people are exactly N/2 apart
//If a == b:A person cannot look at themselves
//If any person number is greater than total people, such a circle cannot exist.
//If c + half is inside the circle → go forward

//Otherwise → wrap around backward. So d is the person opposite to c.
//Time: O(1)   Space: O(1)