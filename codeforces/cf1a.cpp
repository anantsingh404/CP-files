#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct cmp {
    bool operator()(const pair<int, char>& a, const pair<int, char>& b) const {
        if (a.first == b.first) {
            return a.second > b.second; // prioritize lexicographically smaller character
        }
        return a.first < b.first; // for max-heap based on the frequency
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        string str;
        cin >> str;

        unordered_map<char, int> mp;
        for (char c : str) {
            mp[c]++;
        }

        // Priority queue with custom comparator for max-heap based on frequency
        priority_queue<pair<int, char>, vector<pair<int, char>>, cmp> pq;
        for (const auto& itr : mp) {
            pq.push({itr.second, itr.first});
        }

        string ans;
        while (pq.size() > 1) {
            pair<int, char> p1 = pq.top();
            pq.pop();
            pair<int, char> p2 = pq.top();
            pq.pop();

            ans.push_back(p1.second);
            ans.push_back(p2.second);

            if (p1.first - 1 > 0) {
                pq.push({p1.first - 1, p1.second});
            }
            if (p2.first - 1 > 0) {
                pq.push({p2.first - 1, p2.second});
            }
        }

        if (!pq.empty()) {
            int x = pq.top().first;
            char last_char = pq.top().second;
            while (x--) {
                ans.push_back(last_char);
            }
        }

        cout << ans << endl;
    }

    return 0;
}
