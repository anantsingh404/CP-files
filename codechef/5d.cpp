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
      string p;
      cin>>s;
      cin>>p;
      int j=0;
      int i=0;
      bool ans=false;
      while(i<s.size())
      {
        
        if(s[i]==p[j])
        {   
            j++;
        }
        if(s[i]=='?')
        {
            s[i]=p[j];
            j++;
        }
        if(j>=p.size())
        {
            ans=true;
            break;
        }
        i++;
      }
      while(i<s.size())
      {
        if(s[i]=='?'){
        s[i]='a';
      }
        i++;
      }
      if(ans)
      {
        cout<<"YES"<<endl;
        cout<<s<<endl;
      }
      else{
        cout<<"NO"<<endl;
      }


    }
    


     return 0;    
}
