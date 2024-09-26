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
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        vector<vector<int>> round_results = 
        {
            {x1, x2, y1, y2},
            {x1, y2, y1, x2},
            {y1, x2, x1, y2},
            {y1, y2, x1, x2}
        };
        


        int sw = 0;

        
        
        for (const auto& result : round_results) {
            int sc = 0;
            int sl = 0;
            
            if (result[0] > result[1]) 
            {
                sc += 1;
            } 
            else if (result[0] < result[1]) {
                sl += 1;
            }
            
            if (result[2] > result[3])
            {
                sc += 1;
            } 
            else if (result[2] < result[3]) {
                sl += 1;
            }
            
            if (sc > sl) {
                sw += 1;
            }
        }
        cout << sw << endl;
    }

    return 0;
}
