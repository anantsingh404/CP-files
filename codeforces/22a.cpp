#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;
int maxXor(int lo,int hi,int k)
{
    int ans=0;
    for(int i=lo;i<hi;i++)
    {
        for(int j=(i+1);j<=hi;j++)
        {
            int x=i^j;
            if(x<=k)
            {
                ans=max(ans,x);
            }
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin>>t;
    while(t--)
    {
       
    int l,h,k;
    cin>>l>>h>>k;
    cout<<maxXor(l,h,k);


    
    
    
   }
return 0;    
}
