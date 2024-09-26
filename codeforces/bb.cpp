#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin>>s;
    string ans;
    for(int  i=0;i<s.size();i++)
    {   if(s[i]!='.'){
        ans.push_back(s[i]);
    }
    }
    cout<<ans<<endl;
    
return 0;    
}
