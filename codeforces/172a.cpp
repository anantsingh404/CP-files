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
    //vector<int> lps = computeLPS(string);
    //SegmentTree segTree(array);
   
     ll t;
    cin >> t;
    while (t--) {
        
    int n;
    cin>>n;
    int k;
    cin>>k;
    string s;
    cin>>s;
    int ans=-1;
    int sum1=0;
    int sum0=0;
    int c1=0;
    int c0=0;
    int i=n-1;
    vector<int>dp;
    while(i>=0)
    {
        dp.push_back(sum1);
    if(s[i]=='0')
    {   
      sum1-=1;
    }
    else{
    sum1+=1;
    }

i--;
  

}
sort(dp.begin(),dp.end());
reverse(dp.begin(),dp.end());
int j=2;
while(j<=n)
{   
    if(j-2<n)
    {
       sum0+=dp[j-2];
    }
    if(sum0>=k)
    {
        ans=j;
        break;
    }
    j++;
}
cout<<ans<<endl;
    }
return 0;
}
