#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pqmin priority_queue<ll,vector<ll>,greater<ll>>
#define pqmax priority_queue<ll>
const ll mod=1e9+7;




/*

//trie template
class trienode {
public:
    trienode* child[26];
    bool isleaf;

    trienode() {
        for (ll i = 0; i < 26; i++) {
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
        ll n=word.size();
        for (ll i = 0; i < n; i++) {
            ll index = word[i] - 'a';
            if (node->child[index] == NULL) {
                node->child[index] = new trienode();
            }
            node = node->child[index];
        }
        node->isleaf = true;
    }

    bool search(string word) {
        trienode* node = root;
        for (ll i = 0; i < word.size(); i++) {
            ll index = word[i] - 'a';
            if (node->child[index] == NULL) return false;
            node = node->child[index];
        }
        return node->isleaf;
    }

    bool startsWith(string word) {
        trienode* node = root;
        for (ll i = 0; i < word.length(); i++) {
            ll index = word[i] - 'a';
            if (node->child[index] == NULL) return false;
            node = node->child[index];
        }
        return true;
    }




    
};


//Disjoll set template

class dsu {
private:
    vector<ll> parent;
    vector<ll> rank;

public:
    dsu(ll n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (ll i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    ll find(ll u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]); 
        }
        return parent[u];
    }

    void join(ll u, ll v) {
        ll x = find(u);
        ll y = find(v);

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

    bool connected(ll u, ll v) {
        return find(u) == find(v);
    }
};


// Depth First Search (DFS)
    void DFS(ll start, vector<bool> &visited) {
        visited[start] = true;
        cout << start << " ";

        for (ll i : adjList[start]) {
            if (!visited[i]) {
                DFS(i, visited);
            }
        }
    }


 void dijkstra(ll start, vector<vector<pair<ll, ll>>> &adj) {
        vector<ll> dist(V, ll_MAX); // Distance vector
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            ll u = pq.top().second;
            pq.pop();

            for (auto &[v, weight] : adj[u]) {
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        // Prll shortest distances
        cout << "Vertex\tDistance from Source\n";
        for (ll i = 0; i < V; i++) {
            cout << i << "\t\t" << dist[i] << "\n";
        }
    }

// Floyd-Warshall Algorithm (All-Pairs Shortest Path)
    void floydWarshall(vector<vector<ll>> &graph) {
        vector<vector<ll>> dist = graph;

        for (ll k = 0; k < V; k++) {
            for (ll i = 0; i < V; i++) {
                for (ll j = 0; j < V; j++) {
                    if (dist[i][k] != ll_MAX && dist[k][j] != ll_MAX)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        // Prll the shortest distances between every pair of vertices
        cout << "Shortest distances between every pair of vertices:\n";
        for (ll i = 0; i < V; i++) {
            for (ll j = 0; j < V; j++) {
                if (dist[i][j] == ll_MAX)
                    cout << "INF ";
                else
                    cout << dist[i][j] << " ";
            }
            cout << "\n";
        }
    }




    // Topological Sort (using DFS)
    void topologicalSortUtil(ll v, vector<bool> &visited, stack<ll> &Stack) {
        visited[v] = true;

        for (ll i : adjList[v])
            if (!visited[i])
                topologicalSortUtil(i, visited, Stack);

        Stack.push(v);
    }

    void topologicalSort() {
        stack<ll> Stack;
        vector<bool> visited(V, false);

        for (ll i = 0; i < V; i++)
            if (!visited[i])
                topologicalSortUtil(i, visited, Stack);

        // Prll contents of stack
        while (!Stack.empty()) {
            cout << Stack.top() << " ";
            Stack.pop();
        }
        cout << endl;
    }


 // Find Shortest Path using Bellman-Ford (handles negative weights)
    bool bellmanFord(ll src, vector<vector<pair<ll, ll>>> &edges) {
        vector<ll> dist(V, ll_MAX);
        dist[src] = 0;

        for (ll i = 0; i < V - 1; i++) {
            for (ll u = 0; u < V; u++) {
                for (auto &[v, weight] : edges[u]) {
                    if (dist[u] != ll_MAX && dist[u] + weight < dist[v])
                        dist[v] = dist[u] + weight;
                }
            }
        }

        // Check for negative weight cycles
        for (ll u = 0; u < V; u++) {
            for (auto &[v, weight] : edges[u]) {
                if (dist[u] != ll_MAX && dist[u] + weight < dist[v]) {
                    cout << "Graph contains a negative weight cycle\n";
                    return false;
                }
            }
        }

        // Prll the distances
        cout << "Vertex\tDistance from Source\n";
        for (ll i = 0; i < V; i++) {
            cout << i << "\t\t" << dist[i] << "\n";
        }
        return true;
    }

//longest prefix suffix template

vector<ll> computeLPS(string word) {
    ll n = word.length();
    vector<ll> lps(n, 0); 
    ll len = 0; 
    ll i = 1;

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
    vector<ll> tree; // Segment tree
    vector<ll> data; // Original data
    ll n;           // Size of the data

    void build(ll node, ll start, ll end) {
        if (start == end) {
            tree[node] = data[start]; 
        } else {
            ll mid = (start + end) / 2;
            build(2 * node + 1, start, mid);      
            build(2 * node + 2, mid + 1, end);   
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2]; 
        }
    }

    void update(ll node, ll start, ll end, ll idx, ll value) {
        if (start == end) {
            data[idx] = value; // Update the original data
            tree[node] = value; // Update the tree
        } else {
            ll mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                update(2 * node + 1, start, mid, idx, value); // Left child
            } else {
                update(2 * node + 2, mid + 1, end, idx, value); // Right child
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2]; // Update llernal node
        }
    }

    ll query(ll node, ll start, ll end, ll l, ll r) {
        if (r < start || end < l) return 0; // Out of range
        if (l <= start && end <= r) return tree[node]; // Node is completely within range
        ll mid = (start + end) / 2;
        ll left_sum = query(2 * node + 1, start, mid, l, r); // Left child
        ll right_sum = query(2 * node + 2, mid + 1, end, l, r); // Right child
        return left_sum + right_sum; // Combine results
    }

public:
    SegmentTree(vector<ll>& input) {
        data = input;
        n = input.size();
        tree.resize(4 * n); // Size of segment tree
        build(0, 0, n - 1);  // Build the segment tree
    }

    void update(ll idx, ll value) {
        update(0, 0, n - 1, idx, value);
    }

    ll query(ll l, ll r) {
        return query(0, 0, n - 1, l, r);
    }
};

*/



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //Trie trie;
    //dsu dset(n);
    //vector<ll> lps = computeLPS(string);
    //SegmentTree segTree(array);
   
     ll t;
    cin >> t;
    while (t--)
    {
      string s,t;
      cin>>s>>t;
      ll n=s.size();
      reverse(t.begin(),t.end());
      vector<ll>dp(n,0);
      ll m=t.size();
      if(m>n)
      {
        cout<<-1<<endl;
        continue;
      }
      ll i=n-1;
      ll j=0;
      while(i>=0)
      {
        if(s[i]==t[j])
        {
            j++;
            dp[i]=1;
        }
        i--;
      }
      if(j<m)
      {
        cout<<-1<<endl;
        continue;
      }
      ll sum=0;
      ll ans=0;
      for(ll i=0;i<n;i++)
      {
        if(dp[i]==0)
        {
            ans+=(i+1-sum);
            ++sum;
        }
      }
      cout<<ans<<endl;


       
     
    
    }
return 0;
}
