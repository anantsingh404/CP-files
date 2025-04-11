#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pqmin priority_queue<int,vector<int>,greater<int>>
#define pqmax priority_queue<int>
const int mod=1e9+7;




/*

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

// Floyd-Warshall Algorithm (All-Pairs Shortest Path)
    void floydWarshall(vector<vector<int>> &graph) {
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


 // Find Shortest Path using Bellman-Ford (handles negative weights)
    bool bellmanFord(int src, vector<vector<pair<int, int>>> &edges) {
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



//segment st template


class Segmentst {
private:
    vector<int> st; // Segment st
    vector<int> data; // Original data
    int n;           // Size of the data

    void build(int node, int start, int end) {
        if (start == end) {
            st[node] = data[start]; 
        } else {
            int mid = (start + end) / 2;
            build(2 * node + 1, start, mid);      
            build(2 * node + 2, mid + 1, end);   
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
    Segmentst(vector<int>& input) {
        data = input;
        n = input.size();
        st.resize(4 * n); // Size of segment st
        build(0, 0, n - 1);  // Build the segment st
    }

    void update(int idx, int value) {
        update(0, 0, n - 1, idx, value);
    }

    int query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};

*/

#include <bits/stdc++.h>
using namespace std;

// Precompute the lexicographically smallest cyclic rotation of B
vector<int> getSmallestRotation(const vector<int>& B) {
    int M = B.size();
    string s;
    for (int x : B) s += to_string(x) + ","; // Convert B to a string for comparison

    // Find the smallest rotation using Booth's algorithm
    string t = s + s;
    int n = t.size();
    vector<int> f(n, -1);
    int k = 0;
    for (int j = 1; j < n; j++) {
        int i = f[j - k - 1];
        while (i != -1 && t[j] != t[k + i + 1]) {
            if (t[j] < t[k + i + 1]) k = j - i - 1;
            i = f[i];
        }
        if (t[j] != t[k + i + 1]) {
            if (t[j] < t[k]) k = j;
            f[j - k] = -1;
        } else {
            f[j - k] = i + 1;
        }
    }

    // Extract the smallest rotation
    vector<int> smallestRotation(B.begin() + k, B.end());
    smallestRotation.insert(smallestRotation.end(), B.begin(), B.begin() + k);
    return smallestRotation;
}

// Segment Tree with Lazy Propagation
struct SegmentTree {
    int n;
    vector<int> tree, lazy;

    SegmentTree(int size) {
        n = size;
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, -1);
    }

    void pushDown(int node, int left, int right) {
        if (lazy[node] != -1) {
            tree[node] = lazy[node];
            if (left != right) {
                lazy[2 * node + 1] = lazy[node];
                lazy[2 * node + 2] = lazy[node];
            }
            lazy[node] = -1;
        }
    }

    void updateRange(int node, int left, int right, int l, int r, int val) {
        pushDown(node, left, right);
        if (left > r || right < l) return;
        if (left >= l && right <= r) {
            lazy[node] = val;
            pushDown(node, left, right);
            return;
        }
        int mid = (left + right) / 2;
        updateRange(2 * node + 1, left, mid, l, r, val);
        updateRange(2 * node + 2, mid + 1, right, l, r, val);
        tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
    }

    int query(int node, int left, int right, int l, int r) {
        pushDown(node, left, right);
        if (left > r || right < l) return INT_MAX;
        if (left >= l && right <= r) return tree[node];
        int mid = (left + right) / 2;
        return min(query(2 * node + 1, left, mid, l, r),
                   query(2 * node + 2, mid + 1, right, l, r));
    }
};

// Main function to solve the problem
vector<int> solve(int N, int M, vector<int>& A, vector<int>& B) {
    // Step 1: Find the lexicographically smallest rotation of B
    vector<int> bestB = getSmallestRotation(B);

    // Step 2: Initialize the segment tree
    SegmentTree st(N);
    for (int i = 0; i < N; i++) st.updateRange(0, 0, N - 1, i, i, A[i]);

    // Step 3: Iterate through all possible subarrays of length M
    for (int i = 0; i <= N - M; i++) {
        // Check if the current subarray can be replaced with bestB
        bool canReplace = true;
        for (int j = 0; j < M; j++) {
            if (st.query(0, 0, N - 1, i + j, i + j) < bestB[j]) {
                canReplace = false;
                break;
            }
        }

        // If replacement is beneficial, update the segment tree
        if (canReplace) {
            for (int j = 0; j < M; j++) {
                st.updateRange(0, 0, N - 1, i + j, i + j, bestB[j]);
            }
        }
    }

    // Step 4: Extract the final array from the segment tree
    vector<int> result(N);
    for (int i = 0; i < N; i++) {
        result[i] = st.query(0, 0, N - 1, i, i);
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A(N), B(M);
        for (int i = 0; i < N; i++) cin >> A[i];
        for (int i = 0; i < M; i++) cin >> B[i];

        vector<int> result = solve(N, M, A, B);
        for (int x : result) cout << x << " ";
        cout << endl;
    }
    return 0;
}