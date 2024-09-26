#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //write your code here
   
    ll n;
    cin>>n;
    vector<int>dp(n);
    priority_queue<int>pq;
    for(int i=0;i<n;i++)
    {
        cin>>dp[i];
        pq.push(dp[i]);
    }
    int count=0;
    while(pq.size()>1)
    {
        int x=pq.top();
        pq.pop();
        int y=pq.top();
        pq.pop();
        ++count;
        if(x-1>0)
        {
            pq.push(x-1);
        }
        if(y-1>0)
        {
         pq.push(y-1);
        }

    }
    cout<<count<<endl;




    
    


     return 0;    
}
