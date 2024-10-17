#include <bits/stdc++.h>
using namespace std;



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


const int INF = 1e9;  // A large number to represent infinity
int N, M, Q;
vector<vector<pair<int, int>>> adj;  // Adjacency list (city, distance)
set<int> closed_roads;  // Set to keep track of closed roads
vector<tuple<int, int, int>> roads;  // Store roads (A, B, C)

void dijkstra(int start, vector<int>& distances) {
    distances.assign(N + 1, INF);  // Initialize distances to infinity
    distances[start] = 0;  // Distance from start to itself is 0

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});  // {distance, city}

    while (!pq.empty()) {
        auto [curr_dist, u] = pq.top();
        pq.pop();

        if (curr_dist > distances[u]) continue;  // If we have already found a shorter path

        for (const auto& [v, weight] : adj[u]) {
            if (closed_roads.count((u << 16) | v) || closed_roads.count((v << 16) | u)) {
                continue;  // Skip closed roads
            }
            if (curr_dist + weight < distances[v]) {
                distances[v] = curr_dist + weight;
                pq.push({distances[v], v});
            }
        }
    }
}
*/
int dp[100][501][501];
int n;
int sum;
vector<pair<int,int>>vp;
int solve(int idx,int sum1,int sum2)
{
    if(idx>=n && sum1==sum/3 && sum2==sum/3)
    {
        return 0;
    }
    if(idx>=n || sum1>sum/3 || sum2>sum/3)
    {
        return INT_MAX;
    }
    if(dp[idx][sum1][sum2]!=-1)
    {
        return dp[idx][sum1][sum2];
    }
    long long ans=INT_MAX;
    if(vp[idx].first==1)
    {
        ans=min(ans,1ll*solve(idx+1,sum1+vp[idx].second,sum2));
        ans=min(ans,1ll*1+solve(idx+1,sum1,sum2+vp[idx].second));
        ans=min(ans,1ll*1+solve(idx+1,sum1,sum2));
    }
    if(vp[idx].first==2)
    {
        ans=min(ans,1ll*1+solve(idx+1,sum1+vp[idx].second,sum2));
        ans=min(ans,1ll*solve(idx+1,sum1,sum2+vp[idx].second));
        ans=min(ans,1ll*1+solve(idx+1,sum1,sum2));
    }
     if(vp[idx].first==3)
    {
        ans=min(ans,1ll*1+solve(idx+1,sum1+vp[idx].second,sum2));
        ans=min(ans,1ll*1ll*1+solve(idx+1,sum1,sum2+vp[idx].second));
        ans=min(ans,1ll*solve(idx+1,sum1,sum2));
    }
    return dp[idx][sum1][sum2]=ans;

}
int main() {
    
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<501;j++)
        {
            for(int k=0;k<501;k++)
            {
                dp[i][j][k]=-1;
            }
        }
    }
    //int sum=0;
    
    for(int i=0;i<n;i++)
    {
        int x;
        int y;
        cin>>x;
        cin>>y;
        sum+=y;
        vp.push_back({x,y});
    }
    if(sum%3)
    {
        cout<<-1<<endl;
    }
    else{
        int x=solve(0,0,0);
        if(x>=INT_MAX)
        {
            x=-1;
        }
        cout<<x<<endl;
    }
}
