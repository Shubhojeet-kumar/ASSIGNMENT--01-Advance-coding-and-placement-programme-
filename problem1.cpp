#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();
    string t = s + s;

    vector<int> freq(26, 0);

    int left = 0, sum = 0, maxSum = 0;

    for (int right = 0; right < 2 * n; right++) {
        int idx = t[right] - 'a';
        int val = idx + 1;

        freq[idx]++;
        sum += val;

        while (freq[idx] > 1) {
            int lidx = t[left] - 'a';
            freq[lidx]--;
            sum -= (lidx + 1);
            left++;
        }

        while (right - left + 1 > n) {
            int lidx = t[left] - 'a';
            freq[lidx]--;
            sum -= (lidx + 1);
            left++;
        }

        maxSum = max(maxSum, sum);
    }

    cout << maxSum << endl;
}
