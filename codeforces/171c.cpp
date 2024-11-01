#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int total =(n * (n + 1)) / 2;
        vector<int> dp1;
        vector<int> dp2;

        int i = 0;
        while (i < n - 1) {
            if (s[i] == '0')
             {
                dp1.push_back(i);
            } 
            else 
            {
                dp2.push_back(i);
            }
            i++;
        }

        int p = dp1.size() - 1;
        int q = dp2.size() - 1;

        i = n - 1;
        reverse(dp2.begin(), dp2.end());

        while (i >= 0) {
            while (p >= 0 && dp1[p] >= i) 
            {
                --p;
            }
            while (q >= 0 && dp2[q] >= i)
             {
                --q;
            }

            if (s[i] == '1')
             {    if (q >= 0) 
                {
                    total=total-i-1;
                    q--;
                }
                else if (p >= 0)
                 {
                    total=total-i-1;
                    p--;
                }
                
            }
            i--;
        }

        cout << total << endl;
    }

    return 0;
}
