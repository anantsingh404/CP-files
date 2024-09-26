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
       //write your code here
       ll x;
       ll y;
       cin>>x>>y;
       ll k;
       cin>>k;
       ll j=1;
       ll sumx=0;
       ll sumy=0;
       ll temp=k;
       while(k>1)
       {
        cout<<j<<" "<<j<<endl;
        k--;
        sumx+=j;
        sumy+=j;
        j++;
       }
       ll a=x*temp-sumx;
       ll b=y*temp-sumy;
       cout<<a<<" "<<b<<endl;



    


    }
    


     return 0;    
}
