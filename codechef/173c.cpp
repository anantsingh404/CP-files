#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> pwr;
const int mod=1e9+7;
const int parent = 9973;
#define pqmin priority_queue<int,vector<int>,greater<int>>
#define pqmax priority_queue<int>







/*

//trie template
class trienode {
public:
    trienode* child[26];
    bool isleaf;

    trienode() {
        for (int i = 0; i < 26; i++) {
            child[i] = NUtt;
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
            if (node->child[index] == NUtt) {
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
            if (node->child[index] == NUtt) return false;
            node = node->child[index];
        }
        return node->isleaf;
    }

    bool startsWith(string word) {
        trienode* node = root;
        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if (node->child[index] == NUtt) return false;
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


// Depth First Search (DFS)
    void DFS(int start, vector<bool> &visited) {
        visited[start] = true;
        cout << start << " ";

        for (int i : adjList[start]) {
            if (!visited[i]) {
                DFS(i, visited);
            }
        }
    }


 void dijkstra(int start, vector<vector<pair<int, int>>> &adj) {
        vector<int> dist(V, INT_MAX); // Distance vector
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto &[v, weight] : adj[u]) {
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        // Print shortest distances
        cout << "Vertex\tDistance from Source\n";
        for (int i = 0; i < V; i++) {
            cout << i << "\t\t" << dist[i] << "\n";
        }
    }

// Floyd-Warshatt Algorithm (Att-Pairs Shortest Path)
    void floydWarshatt(vector<vector<int>> &graph) {
        vector<vector<int>> dist = graph;

        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        // Print the shortest distances between every pair of vertices
        cout << "Shortest distances between every pair of vertices:\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][j] == INT_MAX)
                    cout << "INF ";
                else
                    cout << dist[i][j] << " ";
            }
            cout << "\n";
        }
    }




    // Topological Sort (using DFS)
    void topologicalSortUtil(int v, vector<bool> &visited, stack<int> &Stack) {
        visited[v] = true;

        for (int i : adjList[v])
            if (!visited[i])
                topologicalSortUtil(i, visited, Stack);

        Stack.push(v);
    }

    void topologicalSort() {
        stack<int> Stack;
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++)
            if (!visited[i])
                topologicalSortUtil(i, visited, Stack);

        // Print contents of stack
        while (!Stack.empty()) {
            cout << Stack.top() << " ";
            Stack.pop();
        }
        cout << endl;
    }


 // Find Shortest Path using Bettman-Ford (handles negative weights)
    bool bettmanFord(int src, vector<vector<pair<int, int>>> &edges) {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        for (int i = 0; i < V - 1; i++) {
            for (int u = 0; u < V; u++) {
                for (auto &[v, weight] : edges[u]) {
                    if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                        dist[v] = dist[u] + weight;
                }
            }
        }

        // Check for negative weight cycles
        for (int u = 0; u < V; u++) {
            for (auto &[v, weight] : edges[u]) {
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    cout << "Graph contains a negative weight cycle\n";
                    return false;
                }
            }
        }

        // Print the distances
        cout << "Vertex\tDistance from Source\n";
        for (int i = 0; i < V; i++) {
            cout << i << "\t\t" << dist[i] << "\n";
        }
        return true;
    }

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



//stment st template


class stmentst {
private:
    vector<int> st; // stment st
    vector<int> data; // Original data
    int n;           // Size of the data

    void bd(int node, int start, int end) {
        if (start == end) {
            st[node] = data[start]; 
        } else {
            int mid = (start + end) / 2;
            bd(2 * node + 1, start, mid);      
            bd(2 * node + 2, mid + 1, end);   
            st[node] = st[2 * node + 1] + st[2 * node + 2]; 
        }
    }

    void update(int node, int start, int end, int idx, int value) {
        if (start == end) {
            data[idx] = value; // Update the original data
            st[node] = value; // Update the st
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                update(2 * node + 1, start, mid, idx, value); // Left child
            } else {
                update(2 * node + 2, mid + 1, end, idx, value); // Right child
            }
            st[node] = st[2 * node + 1] + st[2 * node + 2]; // Update internal node
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0; // Out of range
        if (l <= start && end <= r) return st[node]; // Node is completely within range
        int mid = (start + end) / 2;
        int left_sum = query(2 * node + 1, start, mid, l, r); // Left child
        int right_sum = query(2 * node + 2, mid + 1, end, l, r); // Right child
        return left_sum + right_sum; // Combine results
    }

public:
    stmentst(vector<int>& input) {
        data = input;
        n = input.size();
        st.resize(4 * n); // Size of stment st
        bd(0, 0, n - 1);  // bd the stment st
    }

    void update(int idx, int value) {
        update(0, 0, n - 1, idx, value);
    }

    int query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};

*/
int a;
int b;
vector<int> f;
vector<int> use;
vector<int> useD;
vector<ll> prbt;
void prwr(int lim) {
    pwr.resize(lim + 1);
    pwr[0] = 1;
    int i = 1;
    while (i <= lim) 
    {
        pwr[i] = (pwr[i - 1] * parent) % mod;
        i++;
    }
}

struct st {
    int l, r;
    ll h;
    bool lazy;
    int off;
};

vector<st> tree;


ll sbm(ll a, ll b) {
    ll res = a - b;
    res = (res % mod + mod) % mod;
    return res;
}

ll gb(int off, int len) {
    return sbm(prbt[off + len], (prbt[off] * pwr[len]) % mod);
}

void bd(int i, int l, int r) {
    tree[i] = {l, r, f[l] % mod, false, 0};
    if (l == r) {
        return;
    }
    int m = (l + r) / 2;
    bd(i * 2, l, m);
    bd(i * 2 + 1, m + 1, r);
    int len = tree[i * 2 + 1].r - tree[i * 2 + 1].l + 1;
    tree[i].h = (tree[i * 2].h * pwr[len] + tree[i * 2 + 1].h) % mod;
}

void push(int i) {
    if (!tree[i].lazy) {
        return;
    }
    int l = tree[i].l, r = tree[i].r;
    if (l != r) {
        int m = (l + r) / 2, len = m - l + 1;
        tree[i * 2] = {l, m, gb(tree[i].off, len), true, tree[i].off};
        tree[i * 2 + 1] = {m + 1, r, gb(tree[i].off + len, r - m), true, tree[i].off + len};
    }
    tree[i].lazy = false;
}

void upd(int i, int ql, int qr, int off) {
    int l = tree[i].l, r = tree[i].r;
    if (ql <= l && r <= qr) {
        tree[i].h = gb(off + (l - ql), r - l + 1);
        tree[i].lazy = true;
        tree[i].off = off + (l - ql);
        return;
    }
    push(i);
    int m = (l + r) / 2;
    if (qr > m) {
        upd(i * 2 + 1, ql, qr, off);
    }
    if (ql <= m) {
        upd(i * 2, ql, qr, off);
    }
    int len = tree[i * 2 + 1].r - tree[i * 2 + 1].l + 1;
    tree[i].h = (tree[i * 2].h * pwr[len] + tree[i * 2 + 1].h) % mod;
}

ll qry(int i, int ql, int qr) {
    int l = tree[i].l, r = tree[i].r;
    if (ql <= l && r <= qr) {
        return tree[i].h;
    }
    push(i);
    int m = (l + r) / 2;
    if (ql > m) {
        return qry(i * 2 + 1, ql, qr);
    }
    if (qr <= m) {
        return qry(i * 2, ql, qr);
    }
    return (qry(i * 2, ql, m) * pwr[qr - m] + qry(i * 2 + 1, m + 1, qr)) % mod;
}

int getVal(int i, int pos) {
    int l = tree[i].l, r = tree[i].r;
    if (l == r) {
        if (tree[i].lazy) {
            return useD[tree[i].off];
        }
        return tree[i].h;
    }
    push(i);
    if (pos <= (l + r) / 2) {
        return getVal(i * 2, pos);
    }
    return getVal(i * 2 + 1, pos);
}

vector<int> rbt(vector<int>& b) {
    int n = b.size();
    vector<int> s(2 * n), res(n);
    for (int i = 0; i < n; i++) {
        s[i] = b[i];
    }
    for (int i = n; i < 2 * n; i++) {
        s[i] = b[i % n];
    }
    int useIdx = 0, i = 1;
    while (i < n) {
        int j = 0;
        while (j < n && s[useIdx + j] == s[i + j]) {
            j++;
        }
        if (j == n) {
            break;
        }
        if (s[useIdx + j] > s[i + j]) {
            useIdx = max(i, useIdx + j + 1);
            i = useIdx + 1;
        } else {
            i += j + 1;
        }
    }
    i = 0;
    while (i < n) {
        res[i] = b[(useIdx + i) % n];
        i++;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    prwr(500005);
    while (t--) {
        cin >> a >> b;
        f.resize(a);
        for (int i = 0; i < a; i++) 
        {
            cin >> f[i];
        }
        vector<int> bArr(b);
        for (int i = 0; i < b; i++) 
        {
            cin >> bArr[i];
        }
        use = rbt(bArr);
        useD.assign(2 * b, 0);
        for (int i = 0; i < 2 * b; i++)
         {
            useD[i] = use[i % b];
        }
        prbt.assign(2 * b + 1, 0);
        for (int i = 0; i < 2 * b; i++) {
            prbt[i + 1] = (prbt[i] * parent + useD[i]) % mod;
        }
        tree.assign(4 * a, st());
        bd(1, 0, a - 1);
        for (int i = 0; i <= a - b; i++) 
        {
            if (qry(1, i, i + b - 1) != gb(0, b)) 
            {
                int lo = 0, hi = b;
                while (lo < hi)
                 {
                    int m = (lo + hi + 1) / 2;
                    if (qry(1, i, i + m - 1) == gb(0, m)) 
                    {
                        lo = m;
                    } else 
                    {
                        hi = m - 1;
                    }
                }
                if (lo < b && getVal(1, i + lo) > use[lo])
                 {
                    upd(1, i, i + b - 1, 0);
                }
            }
        }
        for (int i = 0; i < a; i++) {
          cout << getVal(1, i);
          if(i+1==a)
            {
            cout<<endl;
            }
            else
            {
            cout<<" ";
            }
        }
    }
    return 0;
}

