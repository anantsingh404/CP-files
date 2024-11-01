#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl (int i=0;i<n;i++)
const int mod=1e9+7;






int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //Trie trie;
    //dsu dset(n);
    //vector<int> ldps = comdputeLdpS(string);
    //SegmentTree segTree(array);
   
     ll t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int>vis(n,0);
        vector<int>dp(n);
        for (int i = 0; i < n; i++) {
            cin>>dp[i];
        }
        int total = 0;
          for (int i = 0; i < n; i++) {
            if (vis[i]==0)
             {
                int cl = 0;
                int j = i;
                
                while (vis[j]==0)
                 {
                    vis[j] = 1;
                    j = dp[j]-1; 
                    cl++;
                }
                if (cl>=3) 
                {
                    int s =(cl-1)/2;
                    total += s;
                }
            }
        }
        
        cout << total << endl;
    }
return 0;
}
