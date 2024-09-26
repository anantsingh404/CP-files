#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //write your code here
    ll a,b;
    cin>>a>>b;
    int count=0;
    if(a==b)
    {
        cout<<1<<endl;
    }
    else{
        long long z=a;
        a=min(a,b);
        b=max(b,z);
        if(abs(b-a)%2==0 && abs(b-a)>=2)
        {
            cout<<3<<endl;
        }
        else{
            cout<<2<<endl;
        }

    }



     return 0;    
}
