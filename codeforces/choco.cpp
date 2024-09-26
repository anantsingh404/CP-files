#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //write your code here
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>dp(n);
        for(int i=0;i<n;i++)
        {
            cin>>dp[i];
        }
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[dp[i]]++;
        }
        vector<pair<int,int>>flag;
        
        for(auto itr:mp)
        {
            flag.push_back({itr.first,itr.second});
           

        }
        sort(flag.begin(),flag.end());
        int i=0;
        int j=1;
        int count=0;
        int sum=0;
        int m=flag.size();
        while(i<m)
        {
            while(j<m && flag[j].second-i>j-i)
            {
                j++;
            }
            if(j<m)
            {   sum+=flag[j].second;
                flag[j].second=0;
            }
            if(sum &&flag[i].second)
            {   sum+=flag[i].second-1;
                 -sum;
                ++count;
            }
            i++;
        }
        cout<<count<<endl;
    }

return 0;    
}
