#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--) {
        ll n, q;
        cin >> n >> q;
        string a, b;
        cin >> a >> b;

        vector<vector<int>> mp1(n, vector<int>(26, 0));
        vector<vector<int>> mp2(n, vector<int>(26, 0));

        // Initialize the frequency tables
        for (int i = 0; i < n; i++) {
            mp1[i][a[i] - 'a']++;
            mp2[i][b[i] - 'a']++;

            if (i > 0) {
                for (int j = 0; j < 26; j++) {
                    mp1[i][j] += mp1[i - 1][j];
                    mp2[i][j] += mp2[i - 1][j];
                }
            }
        }

        vector<int> results;
        for (int i = 0; i < q; i++) {
            int x, y;
            cin >> x >> y;
            x--; y--; 

            int sum = 0;

            for (int j = 0; j < 26; j++) {
                int p = mp1[y][j] - (x > 0 ? mp1[x - 1][j] : 0);
                int q = mp2[y][j] - (x > 0 ? mp2[x - 1][j] : 0);
                sum += min(p, q);
            }

            results.push_back(y - x + 1 - sum);
        }

        for (int result : results) {
            cout << result << endl;
        }
    }

    return 0;
}
