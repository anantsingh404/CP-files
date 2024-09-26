#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;
const int N = 2e5 + 5;

int n, q, val[N], prv[N][16], nxt[N][16];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
         cin >> n >> q;
	auto get_idx = [](char c) {
		if (c == 'B') return 0;
		if (c == 'G') return 1;
		if (c == 'R') return 2;
		return 3;
	};
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		val[i] = (1 << get_idx(s[0])) | (1 << get_idx(s[1]));
	}
	for (int i = 0; i < 16; i++) prv[0][i] = nxt[n + 1][i] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 16; j++) prv[i][j] = prv[i - 1][j];
		prv[i][val[i]] = i;
	}
	for (int i = n; i >= 1; i--) {
		for (int j = 0; j < 16; j++) nxt[i][j] = nxt[i + 1][j];
		nxt[i][val[i]] = i;
	}
	while (q--) {
		int x, y; cin >> x >> y;
		if (x > y) swap(x, y);
		if (x == y) {
			cout << "0\n";
			continue;
		}
		if (val[x] & val[y]) {
			cout << y - x << '\n';
		} else {
			int res = mod;
			for (int i = 0; i < 4; i++) if (val[x] >> i & 1) {
				for (int j = 0; j < 4; j++) if (val[y] >> j & 1) {
					int mask = (1 << i) | (1 << j);
					if (prv[x][mask]) res = min(res, abs(x - prv[x][mask]) + abs(y - prv[x][mask]));
					if (nxt[x][mask]) res = min(res, abs(nxt[x][mask] - x) + abs(nxt[x][mask] - y));
				}
			}
			if (res == mod) res = -1;
			cout << res << '\n';
		}
	}
    }
    return 0;
}

