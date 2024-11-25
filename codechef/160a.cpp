#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll MOD = 998244353;

int main() {
  int T;
    cin >> T;
    
    while (T--) {
        int n;
        string s;
        string flag;
        string temp1;
        string temp2;
        cin >> n ;
        cin>>s;
        flag=s;
        reverse(flag.begin(),flag.end());

        if (s == flag)
         {
            cout << 0 << endl;
            continue;
        }
        if (n == 2) 
        {
            cout << -1 << endl;
            continue;
        }

        s = s.substr(0, n - 1);
        flag= flag.substr(0,n- 1);
         temp1 = s;
        temp2=flag;
        reverse(temp1.begin(), temp1.end());
        reverse(temp2.begin(), temp2.end());
        if (n % 2==0 && temp1==s && temp2==flag) 
        {
            cout << -1 << endl;
                continue;
            
        }

        cout << 1 << endl;
    }

    return 0;
}
