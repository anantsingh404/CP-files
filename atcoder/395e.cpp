#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop (int i=0;i<n;i++)
const int mod=1e9+7;
const ll INF = LLONG_MAX;





//trie template
class trienode {
public:
    trienode* child[26];
    bool isleaf;

    trienode() {
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
        isleaf = false;
    }
};

class Trie {
public:
    trienode* root;

    Trie() {
        root = new trienode();
    }

    void insert(string word) {
        trienode* node = root;
        int n=word.size();
        for (int i = 0; i < n; i++) {
            int index = word[i] - 'a';
            if (node->child[index] == NULL) {
                node->child[index] = new trienode();
            }
            node = node->child[index];
        }
        node->isleaf = true;
    }

    bool search(string word) {
        trienode* node = root;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (node->child[index] == NULL) return false;
            node = node->child[index];
        }
        return node->isleaf;
    }

    bool startsWith(string word) {
        trienode* node = root;
        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if (node->child[index] == NULL) return false;
            node = node->child[index];
        }
        return true;
    }

    
};


//Disjoint set template

class dsu {
private:
    vector<int> parent;
    vector<int> rank;

public:
    dsu(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]); 
        }
        return parent[u];
    }

    void join(int u, int v) {
        int x = find(u);
        int y = find(v);

        if (x != y) {
            if (rank[x] > rank[y]) {
                parent[y] = x;
            } else if (rank[x] < rank[y]) {
                parent[x] = y;
            } else {
                parent[y] = x;
                rank[x]++;
            }
        }
    }

    bool connected(int u, int v) {
        return find(u) == find(v);
    }
};


//longest prefix suffix template

vector<int> computeLPS(string word) {
    int n = word.length();
    vector<int> lps(n, 0); 
    int len = 0; 
    int i = 1;

    while (i < n) {
        if (word[i] == word[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1]; 
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}



//segment tree template


class SegmentTree {
private:
    vector<int> tree; // Segment tree
    vector<int> data; // Original data
    int n;           // Size of the data

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = data[start]; 
        } else {
            int mid = (start + end) / 2;
            build(2 * node + 1, start, mid);      
            build(2 * node + 2, mid + 1, end);   
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2]; 
        }
    }

    void update(int node, int start, int end, int idx, int value) {
        if (start == end) {
            data[idx] = value; // Update the original data
            tree[node] = value; // Update the tree
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                update(2 * node + 1, start, mid, idx, value); // Left child
            } else {
                update(2 * node + 2, mid + 1, end, idx, value); // Right child
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2]; // Update internal node
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0; // Out of range
        if (l <= start && end <= r) return tree[node]; // Node is completely within range
        int mid = (start + end) / 2;
        int left_sum = query(2 * node + 1, start, mid, l, r); // Left child
        int right_sum = query(2 * node + 2, mid + 1, end, l, r); // Right child
        return left_sum + right_sum; // Combine results
    }

public:
    SegmentTree(vector<int>& input) {
        data = input;
        n = input.size();
        tree.resize(4 * n); // Size of segment tree
        build(0, 0, n - 1);  // Build the segment tree
    }

    void update(int idx, int value) {
        update(0, 0, n - 1, idx, value);
    }

    int query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};

int main() {
    int N, M;
    ll X;
    cin >> N >> M >> X;

    vector<vector<int>> g1(N + 1);
    vector<vector<int>> g2(N + 1);

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        g1[a].push_back(b);
        g2[b].push_back(a);
    }

    vector<vector<ll>> d(N + 1, vector<ll>(2, INF));
    d[1][0] = 0;

    priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<>> pq;
    pq.push({0, {1, 0}});

    while (!pq.empty()) {
        auto [c, s] = pq.top();
        auto [v, o] = s;
        pq.pop();

        if (v == N) {
            cout << c << '\n';
            return 0;
        }

        if (c > d[v][o]) continue;

        const auto& g = (o == 0) ? g1 : g2;
        for (int u : g[v]) {
            ll nc = c + 1;
            if (nc < d[u][o]) {
                d[u][o] = nc;
                pq.push({nc, {u, o}});
            }
        }

        ll fc = c + X;
        int no = 1 - o;
        if (fc < d[v][no]) {
            d[v][no] = fc;
            pq.push({fc, {v, no}});
        }
    }

    cout << -1 << '\n';
    return 0;
}
