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
      
    ll n;
    cin>>n;
    ll b;
    cin>>b;
    ll x=n*1+b*2;
    if(b%2==1 && n==0)
    {
        cout<<"NO"<<endl;
    }
    else if(n+b==1)
    {
        cout<<"NO"<<endl;
    }
    else if(x%2==0)
    {
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    



    }
    


     return 0;    
}
