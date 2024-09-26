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
        string a;
        cin>>a;
        ll co=0;
        ll cz=0;
        stack<char>st;
        int i=0;

        while(i<n)
        {   
            if(st.empty())
        {
            st.push(a[i]);

        }
        else if(st.top()=='0' && a[i]=='0')
        {
            i++;
continue;
        }
        else{
            st.push(a[i]);
        }
        i++;
        }
        string temp;
        while(!st.empty())
        {
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++)
        {
            if(temp[i]=='1')
            {
                ++co;
            }
            else{
                ++cz;
            }
        }
        if(co>cz)
        {
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    


     return 0;    
}
