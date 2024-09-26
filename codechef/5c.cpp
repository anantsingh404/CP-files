#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //write your code here
    ll t;
    cin>>t;
    while(t--)
    {
      int n,s,m;
      cin>>n>>s>>m;
      vector<pair<int,int>>vp;
      for(int i=0;i<n;i++)
      {
        int x;
        int y;
        cin>>x;
        cin>>y;
        vp.push_back({x,y});
      }
      sort(vp.begin(),vp.end());
      if(vp[0].first>=s)
      {
        cout<<"YES"<<endl;
        continue;
      }
      else if(m-vp[n-1].second>=s)
      {
        cout<<"YES"<<endl;
        continue;
      }
      else{
        bool ans=false;
        for(int i=1;i<n;i++)
        {
            if(vp[i].first-vp[i-1].second>=s)
            {
                ans=true;
            }
        }
        if(ans)
        {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
      }
    


    }
    


     return 0;    
}
