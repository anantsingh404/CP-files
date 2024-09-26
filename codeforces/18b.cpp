#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //write your code here
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string a;
        string b;
        cin>>a;
        cin>>b;
        
        bool ans=true;
        for(int i=0;i<n;i++)
        {
           if(a[i]=='0' && b[i]=='1')
           {
            ans=false;
            break;
            
           }
           else if(a[i]=='0' && b[i]=='0')
           {
            continue;
           }
           else{
            break;
           }


        }
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
