#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //write your code here
    int t;
    cin>>t;
    while(t--)
    {
ll n;
ll m;
ll k;
cin>>n>>m>>k;
vector<ll>p;
p.push_back(n);
p.push_back(m);
p.push_back(k);
sort(p.begin(),p.end());
ll ans=0;
for(int i=0;i<=5;i++)
{
    for(int j=0;j<=5-i;j++)
    {
        for(int k=0;k<=(5-(i+j));k++)
        {
            ans=max(ans,(p[0]+i)*(p[1]+j)*(p[2]+k));
        }
    }
}
cout<<ans<<endl;
    }
    


     return 0;    
}
