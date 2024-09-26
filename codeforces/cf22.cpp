#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;

bool solve(int m,string &s,int n)
{    int i=0;
while(i<n)
    {
        int x = i / m;
        int y = i % m;
        
        if (x == 0 || x == m-1){
            if (s[i] != '1') {
                return false;
            }
        } 
        else if( y == 0 || y == m-1){
             if (s[i] != '1') {
                return false;
            }
        }
            else {
            if (s[i] != '0') {
                return false;
            }
        }
        i++;
    }
    return true;

}
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
    string s;
    cin>>s;
    bool ans=false;
    int x=sqrt(n);
    if(x*x!=n)
    {
        cout<<"NO"<<endl;
        continue;
    }
    ans|=solve(x,s,n);
        
    if(ans)
    {
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    



    }
    


     return 0;    
}
