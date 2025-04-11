#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'
bool check(int mid,vector<int>&arr,int k)
{
    int count=0;  
    unordered_map<int,int>mp;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]<mid)
        {
            mp[arr[i]]++;
        }
        if(mp.size()==mid)
        {
            mp.clear();
            ++count;
            
        }
    }
    
    return count>=k;
    
}

int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int mini=1;
        int maxi=2e5+1;
        int ans=0;
        while(mini<=maxi)
        {
            int mid=(maxi+mini)/2;
            if(check(mid,arr,k))
            {
                ans=mid;
                mini=mid+1;
            }
            else{
                maxi=mid-1;
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}