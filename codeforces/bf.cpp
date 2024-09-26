/******************************************************************************
 
Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.
 
*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //write your code her
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        int k;
    
        cin>>n;
        cin>>k;
        vector<int>dp(n);
        for(int i=0;i<n;i++)
        {
            cin>>dp[i];
        }
        sort(dp.begin(),dp.end());
        
        unordered_map<int,vector<int>>mp;
      
        for(int i=0;i<n;i++)
        {
            mp[dp[i]%k].push_back(dp[i]/k);
            
        //    dp1.push_back({dp[i]%k,dp[i]/k});
          //  dp[i]=dp[i]/k;
        }
      bool flag=true;
      int count=0;
      for(auto itr:mp)
      {
        if(itr.second.size()%2)
        {
            ++count;
        }
      }
      if(n%2==0)
      {
        if(count>0)
        {
            flag=false;
        }
      }
      if(n%2)
      {
        if(count>1)
        {
            flag=false;
        }
      }
      if(!flag)
      {
        cout<<-1<<endl;
    
      }
      else{
      int sum=0;
      for(auto itr:mp)
      {
          vector<int>vp(itr.second.begin(),itr.second.end());
        if(vp.size()%2==0)
        {
           sort(vp.begin(),vp.end());
           for(int i=0;i<vp.size()-1;i+=2)
           {
            sum+=abs(vp[i]-vp[i+1]);
           }
        }
        else{
            if(vp.size()>1){
            sort(vp.begin(),vp.end());
            int leftsum=0;
            for(int i=0;i<vp.size()-2;i+=2)
            {
                leftsum+=abs(vp[i]-vp[i+1]);
            }
            int rsum=0;
            for(int i=vp.size()-1;i>1;i-=2)
            {
                rsum+=abs(vp[i]-vp[i-1]);
            }
          sum+=min(leftsum,rsum);
        }
        }
      }

     cout<<sum<<endl;
      }
        
    }
return 0;    
}