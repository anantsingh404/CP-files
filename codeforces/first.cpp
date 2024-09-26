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
    while(t--){
     int a, b;
    cin >> a >> b;
        
    vector<int>dp;
    dp.push_back(a);
        
    int count = 0;
    while(dp.size() < a)
    {
        int d = dp.back();
        dp.erase(dp.begin() + dp.size() - 1);
        for(int i = 0; i < min(b - 1, d - 1); i++)
        {
            dp.push_back(1);
        }
        dp.push_back(d - b + 1);
        count++;
    }
        
    cout << count << endl;
    }


     return 0;    
}
