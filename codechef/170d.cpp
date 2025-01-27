#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pqmin priority_queue<int,vector<int>,greater<int>>
#define pqmax priority_queue<int>
const int mod=1e9+7;
typedef pair<int, int> pii;




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

*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

// Check if a cell is valid for traversal
bool isValid(int x, int y, int n, int m, vector<vector<char>> &grid, vector<vector<int>> &visited, vector<vector<int>> &pathGrid, int time) {
    if (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == '.') {
        // Check time constraint except for start (0,0) and end (n-1,m-1)
        if (visited[x][y] == -1) return true;
        if ((x == 0 && y == 0) || (x == n - 1 && y == m - 1)) return true;
        if (visited[x][y] != time) return true;
    }
    return false;
}

// BFS to find shortest path and mark times
void markShortestPath(vector<vector<char>> &grid, vector<vector<int>> &visited) {
    int n = grid.size(), m = grid[0].size();
    queue<pair<pii, int>> q;
    q.push({{0, 0}, 0});
    visited[0][0] = 0;

    while (!q.empty()) {
        auto [pos, time] = q.front();
        q.pop();
        int x = pos.first, y = pos.second;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == '.' && visited[nx][ny] == -1) {
                visited[nx][ny] = time + 1;
                q.push({{nx, ny}, time + 1});
            }
        }
    }
}

// BFS to check if path is possible with new constraints
int secondTraversal(vector<vector<char>> &grid, vector<vector<int>> &visited) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> newVisited(n, vector<int>(m, -1));
    queue<pair<pii, int>> q;
    q.push({{0, 0}, 0});
    newVisited[0][0] = 0;

    while (!q.empty()) {
        auto [pos, time] = q.front();
        q.pop();
        int x = pos.first, y = pos.second;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (isValid(nx, ny, n, m, grid, newVisited, visited, time + 1)) {
                // Add 3 if revisiting due to time constraints
                int nextTime = (visited[nx][ny] == time + 1) ? time + 3 : time + 1;
                newVisited[nx][ny] = nextTime;
                q.push({{nx, ny}, nextTime});
            }
        }
    }

    return newVisited[n - 1][m - 1]; // If reachable, return time; otherwise, -1
}

int main() {
    ll t;
    cin>>t;
    while(t--){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> visited(n, vector<int>(m, -1));
    markShortestPath(grid, visited);

    int result = secondTraversal(grid, visited);

    cout << result << endl;
    }
    return 0;
}
