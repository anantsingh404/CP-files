#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
const int mod=1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //write your code here
    ll t;
    cin>>t;
    while(t--)
    {
    int p;
    cin >> p;

    int q = 0;
    vector<ll> r;
    vector<ll> s;

    
    for (int i = 0; i < 62; i++) {
        if (p & (1LL << i)) {
            q++;
            r.push_back((1LL << i));
        }
    }

    q++;
    s.push_back(p);

    
    for (auto t : r) {
        if (p - t > 0) {
            s.push_back(p - t);
        }
    }

    reverse(s.begin(), s.end());

    
    cout << s.size() << endl;
    for (auto u : s) {
        cout << u << " ";
    }
    cout << endl;
}

 

return 0;
}
