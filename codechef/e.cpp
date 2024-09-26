#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int a, b;
        int d = 0;
        cin >> a >> b;
        int c = log2(a) / log2(3);
        c+=1;
        d += (2 * c);
        while (b > a) {
            int e = log2(b) / log2(3);
            int f = pow(3, e);
            int g =    b - max(f, a + 1);
            d += ((e + 1) * (g + 1));
            b = f - 1;
        }

        cout << d << endl;
    }
    return 0;
}
