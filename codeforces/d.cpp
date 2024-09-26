#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t;
    cin >> t;
    
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        
        vector<char> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        bool success = true;
        int position = 0;
        int j = 0;
        
        while (position < n + 1) {
            if (j == n) {
                position = n + 1;
                break;
            }
            
            if (a[j] == 'C') {
                success = false;
                break;
            }
            
            if (a[j] == 'L') {
                if (j + 1 < n && a[j + 1] == 'L') {
                    position = j + 1;
                } else {
                    position = j + 2;
                }
                j = position - 1;
            } else if (a[j] == 'W') {
                int swim_distance = 0;
                while (j < n && a[j] == 'W') {
                    swim_distance++;
                    j++;
                    if (swim_distance > k) {
                        success = false;
                        break;
                    }
                }
                position = j;
            }
        }
        
        if (success && position >= n + 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
