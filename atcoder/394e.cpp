#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop (int i=0;i<n;i++)
const int mod=1e9+7;
const int INF = INT_MAX;
const int ALPHABET_SIZE = 26;




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
    int N;
    cin >> N;
    vector<vector<char>> adjj(N, vector<char>(N));
    
    // Read the adjacency matrix
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> adjj[i][j];
        }
    }
    
    // Precompute incoming and outgoing edges for each vertex and letter
    vector<vector<vector<int>>> in_edges(N, vector<vector<int>>(ALPHABET_SIZE));
    vector<vector<vector<int>>> out_edges(N, vector<vector<int>>(ALPHABET_SIZE));
    
    for (int u = 0; u < N; ++u) {
        for (int v = 0; v < N; ++v) {
            if (adjj[u][v] != '-') {
                char c = adjj[u][v];
                out_edges[u][c - 'a'].push_back(v); // Outgoing edge from u with label c
                in_edges[v][c - 'a'].push_back(u);  // Incoming edge to v with label c
            }
        }
    }
    
    // Result matrix
    vector<vector<int>> result(N, vector<int>(N, INF));
    
    // BFS queue: {u, v, distance}
    deque<tuple<int, int, int>> q;
    
    // Initialize BFS with base cases
    for (int u = 0; u < N; ++u) {
        result[u][u] = 0; // Empty path is a palindrome
        q.push_back({u, u, 0});
        
        for (int v = 0; v < N; ++v) {
            if (adjj[u][v] != '-') {
                if (result[u][v] > 1) {
                    result[u][v] = 1; // One-letter palindrome
                    q.push_back({u, v, 1});
                }
            }
        }
    }
    
    // BFS to find shortest palindromic paths
    while (!q.empty()) {
        auto [u, v, dist] = q.front();
        q.pop_front();
        
        // Explore all possible transitions
        for (int c = 0; c < ALPHABET_SIZE; ++c) {
            for (int u_prev : in_edges[u][c]) {
                for (int v_next : out_edges[v][c]) {
                    if (result[u_prev][v_next] > dist + 2) {
                        result[u_prev][v_next] = dist + 2; // Extend the path by 2 edges
                        q.push_back({u_prev, v_next, dist + 2});
                    }
                }
            }
        }
    }
    
    // Output the result
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (result[i][j] == INF) {
                cout << -1 << " ";
            } else {
                cout << result[i][j] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}