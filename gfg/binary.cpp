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
        string s;
        int a,b;
        cin>>s;
        cin>>a>>b;
        int sum=0;
        int oc=0;
        int zc=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!='0' && s[i]!='1')
            {
                sum=1;
            }
            if(s[i]=='1')
            {
                oc=1;
            }
            else{
                zc=1;
            }
        }
        if(sum==0)
        {
            if(a>b && oc && zc)
            {
                cout<<b<<endl;
            }
            else if(a>b && oc && zc)
            {
                cout<<a<<endl;
            }
            else{
                cout<<0<<endl;
            }
            continue;
        
        }
        cout<<0<<endl;

    }


     return 0;    
}
