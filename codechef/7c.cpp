#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;
bool matchesTemplate(const vector<int>& a, const string& s) {
    if (a.size() != s.size()) return false;

    unordered_map<int, char> numToChar;
    unordered_map<char, int> charToNum;

    for (size_t i = 0; i < a.size(); ++i) {
        int num = a[i];
        char ch = s[i];

        if (numToChar.find(num) == numToChar.end()) {
            numToChar[num] = ch;
        } else if (numToChar[num] != ch) {
            return false;
        }

        if (charToNum.find(ch) == charToNum.end()) {
            charToNum[ch] = num;
        } else if (charToNum[ch] != num) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& ai : a) cin >> ai;

        int m;
        cin >> m;
        vector<string> strings(m);
        for (string& s : strings) cin >> s;

        for (const string& s : strings) {
            if (matchesTemplate(a, s)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}