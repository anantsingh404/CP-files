#include <bits/stdc++.h>
using namespace std;

// Enable C++17 features
#if __cpp_init_captures
#define INIT_CAPTURES_SUPPORTED true
#else
#define INIT_CAPTURES_SUPPORTED false
#endif
bool check(int x)
{  
    if(x==2 || x==3)
    {
        return true;
    }
    if(x<=1 || x%2==0  || x%3==0)
    {
        return false;
    }
    for(int i=5;i*i<=x;i+=6)
    {
        if(x%i==0 || x%(i+2)==0)
        {
            return false;
        }
    }
    return true;
}
void solve() {
   int n,k;
   cin>>n>>k;
   if(n>1 && k>1)
   {
       cout<<"NO"<<endl;
   }
   else if(k==1)
   {
    if(check(n))
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
   }
   else if(n==1)
   {
    string s=string(k,'1');
    int x=stoi(s);
    if (check(x)) {
        cout <<"YES"<<endl;
    } 
    else {
        cout<<"NO"<<endl;
    }
}
   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

