#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n,0);
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<pair<int,int>>vp;
    int i=0;
    while(i<n)
    {    
    int j=i;
    int count=0;
    while(j<n && a[j]==a[i])
    {   
         j++;
        ++count;
    }
    vp.push_back({a[i],count});
    i=j;
    }


    unordered_map<int,int>mp;
    i=0;
    int sum=0;
    int j=0;
    
    int m=vp.size();
    while(i<m)
    {  
      if(vp[i].second<2)
      {
      sum=0;
      mp.clear();

      i++;
      j=i;
      continue;
      }
       if(mp.find(vp[i].first)==mp.end())
       {
          if(vp[i].second==2)
          {
            sum+=vp[i].second;
            mp[vp[i].first]++;
            ans=max(ans,sum);
            i++;
            continue;
          }
          else if(vp[i].second>2)
          {
            sum+=2;
            mp[vp[i].first]++;
            ans=max(ans,sum);
            sum=2;
            mp.clear();
            mp[vp[i].first]++;
            j=i;
            ++i;
            continue;

          }
         
       }
       else
       {

       while(j<i && mp.find(vp[i].first)!=mp.end())
       {
        sum-=2;
       
            mp.erase(vp[j].first);
        
        ++j;

        }
         if(vp[i].second>2)
       {
        sum+=2;
        mp.clear();
        mp[vp[i].first]++;
        ans=max(ans,sum);
        j=i;
        sum=2;
        ++i;
        continue;


       }
       else if(vp[i].second==2)
       {
        sum+=2;
        mp[vp[i].first]++;
        ans=max(ans,sum);
        i++;

       }
      
       
      
       
    }
    
    }
    cout<<ans<<endl;
    return 0;
}