#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;

void solve(vector<int>&b,vector<int>&l,int n){
      vector<pair<int,int>>ans;
     
      for(int i=0;i<n;i++)
      {
        ans.push_back({max(b[i],l[i]),min(b[i],l[i])});

      }
      int count=1;
      sort(ans.begin(),ans.end());
      for(int i=n-2;i>=0;i--)
      {
        if(ans[i].first<=ans[i+1].first && ans[i].second<=ans[i+1].second &&(ans[i].first==ans[i+1].second ||ans[i].second==ans[i+1].first|| ans[i].first==ans[i+1].first||ans[i].second==ans[i+1].second))
        {
            continue;
        }
        else{
            ++count;
        }
      }
      cout<<count;


   
}
int main()
{int n;
cin>>n;
    vector<int>l(n,0);
    vector<int>b(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    
    solve(l,b,n);
}
