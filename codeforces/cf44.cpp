#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //write your code here
    int t;
    cin >> t;
    while (t--) {
    int n;
    cin >> n;
   
    vector<int> dp(n);
    for (int i = 0; i < n; ++i) {
        cin >> dp[i];
    
    }
    string s;
     cin >> s;
    for(int i=0;i<n;i++)
    {
        --dp[i];
    }
    vector<int>temp(n, 0);
     vector<int> vis(n, 0);
    
    
    int i=0;
    while(i<n){
        if (vis[i]==0) 
        {
            vector<int> dp1;
            int bc = 0;
            int x = i;
            
            while (vis[x]==0) 
            {
                vis[x] = 1;
                dp1.push_back(x);
                 x = dp[x];
            
            
            
            if (s[x] == '0')
                 {
                    bc++;
                }
               
            }
            
            for (int l=0;l<dp1.size();l++) 
            {
                temp[dp1[l]] = bc;
            }
        }
        i++;
    }

    for(int i=0;i<n;i++)
{
        cout<<temp[i]<< " ";
    }
    cout<<endl;
    }
    
    return 0;
}