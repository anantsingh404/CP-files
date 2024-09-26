#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool canFormGoodArray(ll length, ll l, ll r) {
    ll sum_diffs = (length - 1) * (length - 2) / 2;
    ll max_value = l + sum_diffs;
    return max_value <= r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t;
    cin >> t;
    while (t--) {
        ll l, r;
        cin >> l >> r;
        
        ll low = 1, high = r - l + 1;
        ll best = 1;
        
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            
            if (canFormGoodArray(mid, l, r)) {
                best = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if(l<r-1)
        {
            --best;
        }
        cout << best << endl;
    }

    return 0;
}
