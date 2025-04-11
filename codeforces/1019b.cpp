#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define endl '\n'

void solve() {
    
    string s;
    cin>>s;
    int n=s.size();
    int count=0;
    int temp=1;
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]!='0' && temp)
        {
            count+=(n-1)-i;
            temp=0;
        }
        else if(temp==0 && s[i]!='0')
        {
            ++count;
        }
    }
    cout<<count<<endl;
}

int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}