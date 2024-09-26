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
      
    ll l;
    ll r;
    cin>>l;
    cin>>r;
    if(l%2==0)
    {
        ++l;
    }
    
        int x=l;
        int count=0;
        while(x<r-1)
        {
            x+=4;
            ++count;
        }
        cout<<count<<endl;
    
    
    



    }
    


     return 0;    
}
