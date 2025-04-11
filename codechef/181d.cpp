#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pqmin priority_queue<int,vector<int>,greater<int>>
#define  ull  unsigned long long
#define pqmax priority_queue<int>
const int mod=1e9+7;
const int N = 2e5 + 5;
vector<int> a[N];
int b[N], c, d[N], e;

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
int f(int g, int h)
 {
    d[g]=1;
    int i=0;
    while(i<a[g].size()) 
    {
        int j=a[g][i];
        if (j!=h)
        {
             d[g]=d[g]+f(j,g);
        }
        i++;
    }
    return d[g];
}

int k(int g, int h) 
{
    vector<int>l;
    int i=0;
    while (i<a[g].size())
    {
        int j=a[g][i];
        if (j!=h) 
        {
            int m=k(j,g);
            if(m)
            {
                 l.push_back(m);
            }
        }
        i++;
    }
    i=0;
    int ss=l.size();
    while(i+1<ss) 
    {
        b[l[i]]=e+1;
        b[l[i+1]]=e+1;
        e=e+1;
        i=i+2;
    }
    if(ss%2==1)
    {
        b[g]=e+1;
        b[l.back()]=e+1;
        e=e+1;
        return 0;
    }
    return g;
}

int main(){
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        
        for (int i=1;i<=n;i++)
        {
            a[i].clear();
        } 
        for (int i=2;i<=n;i++)
        {   
            int x;
            cin>>x;
            a[i].push_back(x);
            a[x].push_back(i);
        }
        if (n%2==1)
        {
            cout<<-1<<endl;
            continue;
        }
        f(1, 0);
        bool temp=1;
        for (int i=2;i<=n;i++) 
        {
            if (d[i]%2==0)
            {
                 temp=0;
                 break;
            }
        }
        if(temp==0)
        {
            cout<<-1<<endl;
            continue;
        }
        e=0;
        k(1,0);
        for (int i=1;i<=n;i++)
        {
            cout<<b[i]<<' ';
        } 
        cout<<endl;
    }
    return 0;
}
