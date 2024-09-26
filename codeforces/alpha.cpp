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
        int n;
        int m;
        int k;
        cin>>n>>m>>k;
        string a;
        cin>>a;
        unordered_map<pair<int,int>,int>left;
        unordered_map<int,int>right;
        vector<int>count(26,0);
        vector<int>count1(26,0);

        for(int i=0;i<n;i++)
        {
           count[a[i]-'a']++;
           for(int j=0;j<k;j++)
           {
            left[{a[i]-'a',j}]=max(left[{a[i]-'a',j}],count[j]);
           }
        }
         for(int i=0;i<n;i++)
        {
           count[a[i]-'a']++;
           for(int j=0;j<k;j++)
           {
            left[{a[i]-'a',j}]=max(left[{a[i]-'a',j}],count[j]);
           }
        }

        
    }

    


     return 0;    
}
