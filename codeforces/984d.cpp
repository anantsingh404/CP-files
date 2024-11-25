// Function to compute XOR from 1 to n
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;


int compute_xor(int n) {
    if (n < 0) return 0;
    int rem = n % 4;
    if (rem == 0) return n;
    if (rem == 1) return 1;
    if (rem == 2) return n + 1;
    if (rem == 3) return 0;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int l, r, i, k;
        cin >> l >> r >> i >> k;
        int m = 1LL << i;
        // Handle m=0 case if i=0, but since m=1<<0 always
        // Find t_start and t_end
        int t_start, t_end;
        if (l > k) {
            // Ceiling division: (-l + k - m -1) / m
            t_start = (-l + k + m - 1) / m;
        } else {
            t_start = 0;
        }
        if (r >= k) {
            t_end = (r - k) / m;
        } else {
            t_end = -1;
        }

        int XOR_k = 0;
        if (t_start <= t_end) {
            int c = t_end - t_start + 1;
            // Compute XOR from t_start to t_end
            int XOR_t_start = compute_xor(t_end);
            int XOR_t_start_minus_1 = compute_xor(t_start - 1);
            int xor_t = XOR_t_start ^ XOR_t_start_minus_1;
            xor_t = xor_t << i;
            // If count is odd, XOR with k
            if (c % 2 == 1) {
                XOR_k = xor_t ^ k;
            } else {
                XOR_k = xor_t;
            }
        }

        // Compute XOR_total from l to r
        int xor_r = compute_xor(r);
        int xor_l_minus_1 = compute_xor(l - 1);
        int XOR_total = xor_r ^ xor_l_minus_1;
        int XOR_non_k = XOR_total ^ XOR_k;
        cout << XOR_non_k << "\n";
    }
}
