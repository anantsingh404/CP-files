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
     string s;
     cin>>s;
     int n=s.size();
     if(n==1)
     {
        for(char i='a';i<'z';i++)
        {
            if(i!=s[0])
            {
                s.push_back(i);
                break;
            }
        }
        cout<<s<<endl;
     }
     else{
        string x;
        x.push_back(s[0]);
         for(char i='a';i<'z';i++)
        {
            if(i!=s[0] && i!=s[i])
            {
                x.push_back(i);
                break;
            }
        }
        x+=s.substr(1,n-1);
        cout<<x<<endl;

     }



    
    
    
   }
return 0;    
}
