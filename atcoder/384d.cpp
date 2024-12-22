#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;






int main() {
   unsigned long long n, s;
    cin >> n >> s;

    vector<unsigned long long> dp(n);
    unsigned long long total_sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> dp[i];
        total_sum += dp[i];
    }

    s = s % total_sum;
     if(s==0)
     {
        cout<<"Yes"<<endl;
        return 0;
     }
    set<unsigned long long> prefixSums;
    long long prefixSum = 0;

    prefixSums.insert(prefixSum);

    for (int i = 0; i < n; i++) {
        prefixSum += dp[i];
        prefixSums.insert(prefixSum);
        if (prefixSums.find(s) != prefixSums.end()) {
            cout << "Yes\n";
            return 0;
        }
    }

    unsigned long long suffixSum = 0;
    for (int i = n - 1; i >= 0; i--) {
        suffixSum += dp[i];
        if (prefixSums.find(s - suffixSum) != prefixSums.end()) {
            cout << "Yes\n";
            return 0;
        }
    }
     unsigned long long window_sum = 0;
    int left = 0;

    for (int right = 0; right < n; right++) {
        // Add the current element to the window sum
        window_sum += dp[right];

        // Shrink the window if the sum exceeds the target s
        while (window_sum > s && left <= right) {
            window_sum -= dp[left];
            left++;
        }

        // Check if the current window sum equals s
        if (window_sum == s) {
            cout << "Yes\n";
            return 0;
        }
    }


    cout << "No\n";
    return 0;    
}
