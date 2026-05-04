#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long k;
    cin >> k;

    int rem = a[0] % k;
    for (int i = 1; i < n; i++) {
        if (a[i] % k != rem) {
            cout << -1 << endl;
            return 0;
        }
    }

    sort(a.begin(), a.end());

    long long median = a[n / 2];

    long long ops = 0;
    for (int i = 0; i < n; i++) {
        ops += abs(a[i] - median) / k;
    }

    cout << ops << endl;
}