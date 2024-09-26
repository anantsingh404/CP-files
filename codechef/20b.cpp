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
     if(n%2==1)
     {
        int i=n;
        while(i>=1)
        {
            cout<<i<<" ";
            i-=2;
        }
        int j=2;
        while(j<=n)
        {
           cout<<j<<" ";
           j+=2;
        }
        cout<<endl;
     }
     else{
        cout<<-1<<endl;
     }
    }
    return 0;    
}
