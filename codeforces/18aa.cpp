#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin>>t;
    while(t--)
    {
       
    int n,k;
    cin>>n>>k;
    
    if(n<=k)
    {   long long sum=1ll*(n)*(n+1)/2;
        if(sum%2==0)
        {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    
    else{
        long long sum=(1ll*(n)*(n+1))/2-(1ll*(n-k)*(n-k+1))/2;
        if(sum%2)
        {
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }

    }


    
    
    
   }
return 0;    
}
