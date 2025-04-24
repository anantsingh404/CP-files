#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define llm LLONG_MAX
#define lln LLONG_MIN
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()
#define pqmin priority_queue<int, vector<int>, greater<int>>
#define pqmax priority_queue<int>
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// Constants
const int inf = 1e9;
const ll linf = 1e18;

// Debugging
#define debug(x) cerr << #x << " = " << x << endl;
#define debug_vec(v) cerr << #v << " = "; for (auto x : v) cerr << x << " "; cerr << endl;

// Directions for grid traversal
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

// Utility Functions
template <typename T>
void printVec(const vector<T>& v) {
    for (const auto& x : v) cout << x << " ";
    cout << endl;
}

template <typename T>
void printMatrix(const vector<vector<T>>& mat) {
    for (const auto& row : mat) {
        for (const auto& x : row) cout << x << " ";
        cout << endl;
    }
}

//Advanced Graph Algorithms:

// 1. Depth First Search (DFS)
// Usage: Used to traverse or search through graph data structures. It explores as far as possible along each branch before backtracking.
// Example: Finding connected components, topological sorting, solving puzzles like mazes, etc.
// Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
// Space Complexity: O(V), for the visited array and recursion stack.

void DFS(int node, vector<bool> &visited, vector<vector<int>> &adjList) {
    visited[node] = true;
    cout << node << " "; // Process the current node

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, visited, adjList);
        }
    }
}
// 2. Breadth First Search (BFS)
// Usage: Used to traverse or search through graph data structures level by level. It is optimal for finding the shortest path in an unweighted graph.
// Example: Finding shortest paths, solving puzzles like sliding puzzles, etc.
// Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
// Space Complexity: O(V), for the visited array and queue.

void BFS(int start, vector<vector<int>> &adjList) {
    vector<bool> visited(adjList.size(), false);
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

// 3. Dijkstra's Algorithm
// Usage: Finds the shortest path from a source vertex to all other vertices in a graph with non-negative edge weights.
// Example: Network routing, GPS navigation systems, etc.
// Time Complexity: O((V + E) * log(V)), where V is the number of vertices and E is the number of edges.
// Space Complexity: O(V), for the distance array and priority queue.

void dijkstra(int start, vector<vector<pair<int, int>>> &adj) {
    int V = adj.size();
    vector<int> dist(V, INT_MAX); // Distance array to store shortest distances
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap

    dist[start] = 0;
    pq.push({0, start}); // Push the source node with distance 0

    while (!pq.empty()) {
        int u = pq.top().second; // Current node
        int d = pq.top().first;  // Current distance
        pq.pop();

        if (d > dist[u]) continue; // Skip if the distance is not optimal

        for (auto &[v, weight] : adj[u]) { // Traverse all neighbors
            if (dist[u] + weight < dist[v]) { // Relaxation step
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v}); // Push the updated distance
            }
        }
    }

    // Print shortest distances
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t\t" << (dist[i] == INT_MAX ? "INF" : to_string(dist[i])) << "\n";
    }
}

// 4. Bellman-Ford Algorithm
// Usage: Finds the shortest path from a source vertex to all other vertices in a graph, even with negative edge weights. It also detects negative weight cycles.
// Example: Currency arbitrage, graphs with negative weights, etc.
// Time Complexity: O(V * E), where V is the number of vertices and E is the number of edges.
// Space Complexity: O(V), for the distance array.

bool bellmanFord(int src, int V, vector<tuple<int, int, int>> &edges) {
    vector<int> dist(V, INT_MAX); // Distance array to store shortest distances
    dist[src] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        for (auto &[u, v, weight] : edges) {
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative weight cycles
    for (auto &[u, v, weight] : edges) {
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains a negative weight cycle\n";
            return false;
        }
    }

    // Print shortest distances
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t\t" << (dist[i] == INT_MAX ? "INF" : to_string(dist[i])) << "\n";
    }

    return true;
}

// 5. Floyd-Warshall Algorithm
// Usage: Finds shortest paths between all pairs of vertices in a graph. It works for both positive and negative edge weights but not for negative weight cycles.
// Example: Network analysis, finding transitive closure, etc.
// Time Complexity: O(V^3), where V is the number of vertices.
// Space Complexity: O(V^2), for the distance matrix.

void floydWarshall(vector<vector<int>> &graph) {
    int V = graph.size();
    vector<vector<int>> dist = graph; // Distance matrix initialized with graph weights

    for (int k = 0; k < V; k++) { // Intermediate vertex
        for (int i = 0; i < V; i++) { // Source vertex
            for (int j = 0; j < V; j++) { // Destination vertex
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
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

// 6. Topological Sort
// Usage: Used to order vertices in a Directed Acyclic Graph (DAG) such that for every directed edge (u, v), vertex u comes before vertex v.
// Example: Task scheduling, resolving dependencies, etc.
// Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
// Space Complexity: O(V), for the visited array and stack.

void topologicalSortUtil(int v, vector<bool> &visited, stack<int> &Stack, vector<vector<int>> &adjList) {
    visited[v] = true;

    for (int neighbor : adjList[v]) {
        if (!visited[neighbor]) {
            topologicalSortUtil(neighbor, visited, Stack, adjList);
        }
    }

    Stack.push(v); // Push the current vertex to the stack
}

void topologicalSort(int V, vector<vector<int>> &adjList) {
    stack<int> Stack;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, visited, Stack, adjList);
        }
    }

    // Print the topological order
    cout << "Topological Order: ";
    while (!Stack.empty()) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
    cout << endl;
}

// 7. Kruskal's Algorithm
// Usage: Finds the Minimum Spanning Tree (MST) of a graph using a greedy approach.
// Example: Network design, clustering, etc.
// Time Complexity: O(E * log(E)), where E is the number of edges (due to sorting).
// Space Complexity: O(V), where V is the number of vertices (for the Union-Find data structure).

struct Edge {
    int u, v, weight;
    bool operator<(const Edge &other) const {
        return weight < other.weight; // Sort edges by weight
    }
};

class Kruskal {
private:
    vector<int> parent, rank;

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]); // Path compression
        }
        return parent[u];
    }

    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }

public:
    Kruskal(int V) {
        parent.resize(V);
        rank.resize(V, 0);
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }
    }

    int findMST(int V, vector<Edge> &edges) {
        sort(edges.begin(), edges.end()); // Sort edges by weight
        int mstWeight = 0;
        int edgeCount = 0;

        for (const auto &edge : edges) {
            if (find(edge.u) != find(edge.v)) {
                unionSets(edge.u, edge.v);
                mstWeight += edge.weight;
                edgeCount++;
                cout << "Edge: " << edge.u << " - " << edge.v << " Weight: " << edge.weight << endl;
                if (edgeCount == V - 1) break; // Stop when MST is complete
            }
        }

        return mstWeight;
    }
};

// 8. Prim's Algorithm
// Usage: Finds the Minimum Spanning Tree (MST) of a graph using a greedy approach, starting from an arbitrary vertex.
// Example: Network design, clustering, etc.
// Time Complexity: O((V + E) * log(V)), where V is the number of vertices and E is the number of edges.
// Space Complexity: O(V), for the priority queue and visited array.

void primsAlgorithm(int V, vector<vector<pair<int, int>>> &adj) {
    vector<int> key(V, INT_MAX); // Minimum weight edge for each vertex
    vector<bool> inMST(V, false); // To track vertices included in MST
    vector<int> parent(V, -1); // To store the MST
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap

    key[0] = 0; // Start from vertex 0
    pq.push({0, 0}); // {weight, vertex}

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true; // Include vertex in MST

        for (auto &[v, weight] : adj[u]) {
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    // Print the MST
    cout << "Edge\tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\t" << key[i] << "\n";
    }
}

// 9. Tarjan's Algorithm
// Usage: Finds strongly connected components (SCCs) in a directed graph.
// Example: Circuit analysis, dependency resolution, etc.
// Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
// Space Complexity: O(V), for the recursion stack and auxiliary arrays.

void tarjanDFS(int u, int &time, vector<int> &disc, vector<int> &low, stack<int> &st, vector<bool> &inStack, vector<vector<int>> &adjList) {
    disc[u] = low[u] = ++time; // Initialize discovery and low values
    st.push(u);
    inStack[u] = true;

    for (int v : adjList[u]) {
        if (disc[v] == -1) { // If v is not visited
            tarjanDFS(v, time, disc, low, st, inStack, adjList);
            low[u] = min(low[u], low[v]);
        } else if (inStack[v]) { // If v is in the stack, it's part of the current SCC
            low[u] = min(low[u], disc[v]);
        }
    }

    // If u is the root of an SCC
    if (low[u] == disc[u]) {
        cout << "SCC: ";
        while (true) {
            int v = st.top();
            st.pop();
            inStack[v] = false;
            cout << v << " ";
            if (v == u) break;
        }
        cout << endl;
    }
}

void tarjanSCC(int V, vector<vector<int>> &adjList) {
    vector<int> disc(V, -1), low(V, -1); // Discovery and low values
    vector<bool> inStack(V, false); // To check if a node is in the stack
    stack<int> st;
    int time = 0;

    for (int i = 0; i < V; i++) {
        if (disc[i] == -1) {
            tarjanDFS(i, time, disc, low, st, inStack, adjList);
        }
    }
}

// 10. Kosaraju's Algorithm
// Usage: Another algorithm to find strongly connected components (SCCs) in a directed graph.
// Example: Circuit analysis, dependency resolution, etc.
// Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
// Space Complexity: O(V), for the visited array and stack.

void dfs1(int node, vector<bool> &visited, stack<int> &Stack, vector<vector<int>> &adjList) {
    visited[node] = true;
    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfs1(neighbor, visited, Stack, adjList);
        }
    }
    Stack.push(node); // Push the node to the stack after visiting all its neighbors
}

void dfs2(int node, vector<bool> &visited, vector<vector<int>> &transposeAdjList) {
    visited[node] = true;
    cout << node << " "; // Process the current node
    for (int neighbor : transposeAdjList[node]) {
        if (!visited[neighbor]) {
            dfs2(neighbor, visited, transposeAdjList);
        }
    }
}

void kosaraju(int V, vector<vector<int>> &adjList) {
    stack<int> Stack;
    vector<bool> visited(V, false);

    // Step 1: Perform DFS and store the finish order in a stack
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs1(i, visited, Stack, adjList);
        }
    }

    // Step 2: Transpose the graph
    vector<vector<int>> transposeAdjList(V);
    for (int u = 0; u < V; u++) {
        for (int v : adjList[u]) {
            transposeAdjList[v].push_back(u);
        }
    }

    // Step 3: Perform DFS on the transposed graph in the order of the stack
    fill(visited.begin(), visited.end(), false);
    cout << "Strongly Connected Components:\n";
    while (!Stack.empty()) {
        int node = Stack.top();
        Stack.pop();
        if (!visited[node]) {
            dfs2(node, visited, transposeAdjList);
            cout << endl;
        }
    }
}

// 11. A* Algorithm
// Usage: Finds the shortest path in a graph using heuristics to optimize the search.
// Example: Pathfinding in games, robotics, etc.
// Time Complexity: O(E * log(V)), where E is the number of edges and V is the number of vertices.
// Space Complexity: O(V), for the priority queue and heuristic storage.

struct Node {
    int vertex;
    int g; // Cost from start to current node
    int h; // Heuristic cost to the goal
    int f; // Total cost (f = g + h)

    bool operator<(const Node &other) const {
        return f > other.f; // Min-heap based on f value
    }
};

int heuristic(int u, int goal) {
    // Define your heuristic function here (e.g., Manhattan distance, Euclidean distance, etc.)
    return abs(u - goal);
}

void aStar(int start, int goal, vector<vector<pair<int, int>>> &adj) {
    int V = adj.size();
    vector<int> g(V, INT_MAX); // Cost from start to each vertex
    priority_queue<Node> pq;

    g[start] = 0;
    pq.push({start, 0, heuristic(start, goal), heuristic(start, goal)});

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        if (current.vertex == goal) {
            cout << "Shortest path cost: " << current.g << endl;
            return;
        }

        for (auto &[neighbor, weight] : adj[current.vertex]) {
            int tentative_g = current.g + weight;
            if (tentative_g < g[neighbor]) {
                g[neighbor] = tentative_g;
                int h = heuristic(neighbor, goal);
                pq.push({neighbor, tentative_g, h, tentative_g + h});
            }
        }
    }

    cout << "No path found to the goal." << endl;
}

// 12. Union-Find (Disjoint Set Union - DSU)
// Usage: Used to find and merge connected components in a graph efficiently.
// Example: Kruskal's algorithm, dynamic connectivity, etc.
// Time Complexity: O(α(N)) per operation, where α is the inverse Ackermann function (nearly constant).
// Space Complexity: O(N), where N is the number of elements.

class UnionFind {
    private:
        vector<int> parent, rank;
    
    public:
        UnionFind(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; i++) {
                parent[i] = i; // Each element is its own parent initially
            }
        }
    
        int find(int u) {
            if (parent[u] != u) {
                parent[u] = find(parent[u]); // Path compression
            }
            return parent[u];
        }
    
        void unionSets(int u, int v) {
            int rootU = find(u);
            int rootV = find(v);
    
            if (rootU != rootV) {
                if (rank[rootU] > rank[rootV]) {
                    parent[rootV] = rootU;
                } else if (rank[rootU] < rank[rootV]) {
                    parent[rootU] = rootV;
                } else {
                    parent[rootV] = rootU;
                    rank[rootU]++;
                }
            }
        }
    
        bool connected(int u, int v) {
            return find(u) == find(v);
        }
    };

// 13. Tarjan's Algorithm for Bridges
// Usage: Finds all bridges in a graph. A bridge is an edge that, if removed, increases the number of connected components.
// Example: Network reliability, articulation points, etc.
// Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
// Space Complexity: O(V), for the recursion stack and auxiliary arrays.

void tarjanBridgeDFS(int u, int parent, vector<int> &disc, vector<int> &low, vector<vector<int>> &adjList, vector<pair<int, int>> &bridges, int &time) {
    disc[u] = low[u] = ++time; // Initialize discovery and low values

    for (int v : adjList[u]) {
        if (v == parent) continue; // Skip the edge to the parent

        if (disc[v] == -1) { // If v is not visited
            tarjanBridgeDFS(v, u, disc, low, adjList, bridges, time);

            low[u] = min(low[u], low[v]); // Update low value of u

            if (low[v] > disc[u]) { // If the condition for a bridge is met
                bridges.push_back({u, v});
            }
        } else { // If v is already visited and not the parent
            low[u] = min(low[u], disc[v]);
        }
    }
}

void findBridges(int V, vector<vector<int>> &adjList) {
    vector<int> disc(V, -1), low(V, -1); // Discovery and low values
    vector<pair<int, int>> bridges; // To store the bridges
    int time = 0;

    for (int i = 0; i < V; i++) {
        if (disc[i] == -1) {
            tarjanBridgeDFS(i, -1, disc, low, adjList, bridges, time);
        }
    }

    // Print all bridges
    cout << "Bridges in the graph:\n";
    for (auto &[u, v] : bridges) {
        cout << u << " - " << v << endl;
    }
}

// 14. Tarjan's Algorithm for Articulation Points
// Usage: Finds all articulation points in a graph. An articulation point is a vertex that, if removed, increases the number of connected components.
// Example: Network reliability, fault tolerance, etc.
// Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
// Space Complexity: O(V), for the recursion stack and auxiliary arrays.

void tarjanArticulationDFS(int u, int parent, vector<int> &disc, vector<int> &low, vector<bool> &visited, vector<bool> &isArticulation, vector<vector<int>> &adjList, int &time) {
    disc[u] = low[u] = ++time; // Initialize discovery and low values
    visited[u] = true;
    int children = 0; // Count of children in the DFS tree

    for (int v : adjList[u]) {
        if (!visited[v]) { // If v is not visited
            children++;
            tarjanArticulationDFS(v, u, disc, low, visited, isArticulation, adjList, time);

            low[u] = min(low[u], low[v]); // Update low value of u

            // If u is a root and has more than one child, it's an articulation point
            if (parent == -1 && children > 1) {
                isArticulation[u] = true;
            }

            // If u is not a root and low[v] >= disc[u], it's an articulation point
            if (parent != -1 && low[v] >= disc[u]) {
                isArticulation[u] = true;
            }
        } else if (v != parent) { // Update low value for back edge
            low[u] = min(low[u], disc[v]);
        }
    }
}

void findArticulationPoints(int V, vector<vector<int>> &adjList) {
    vector<int> disc(V, -1), low(V, -1); // Discovery and low values
    vector<bool> visited(V, false), isArticulation(V, false); // Track visited nodes and articulation points
    int time = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            tarjanArticulationDFS(i, -1, disc, low, visited, isArticulation, adjList, time);
        }
    }

    // Print all articulation points
    cout << "Articulation Points in the graph:\n";
    for (int i = 0; i < V; i++) {
        if (isArticulation[i]) {
            cout << i << endl;
        }
    }
}

// 15. Edmonds-Karp Algorithm
// Usage: Finds the maximum flow in a flow network using the Ford-Fulkerson method with BFS.
// Example: Network flow problems, bipartite matching, etc.
// Time Complexity: O(V * E^2), where V is the number of vertices and E is the number of edges.
// Space Complexity: O(V + E), for the adjacency list and BFS queue.

bool bfs(vector<vector<int>> &residualGraph, int source, int sink, vector<int> &parent) {
    int V = residualGraph.size();
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;
    parent[source] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++) {
            if (!visited[v] && residualGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
                if (v == sink) return true;
            }
        }
    }
    return false;
}

int edmondsKarp(vector<vector<int>> &capacity, int source, int sink) {
    int V = capacity.size();
    vector<vector<int>> residualGraph = capacity;
    vector<int> parent(V);
    int maxFlow = 0;

    while (bfs(residualGraph, source, sink, parent)) {
        int pathFlow = INT_MAX;

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

// 16. Dinic's Algorithm
// Usage: Finds the maximum flow in a flow network using a level graph and blocking flow.
// Example: Network flow problems, bipartite matching, etc.
// Time Complexity: O(V^2 * E), where V is the number of vertices and E is the number of edges.
// Space Complexity: O(V + E), for the level graph and adjacency list.

class Dinic {
    private:
        vector<vector<int>> capacity, adjList;
        vector<int> level, ptr;
        int V;
    
        bool bfs(int source, int sink) {
            fill(level.begin(), level.end(), -1);
            queue<int> q;
            q.push(source);
            level[source] = 0;
    
            while (!q.empty()) {
                int u = q.front();
                q.pop();
    
                for (int v : adjList[u]) {
                    if (level[v] == -1 && capacity[u][v] > 0) {
                        level[v] = level[u] + 1;
                        q.push(v);
                    }
                }
            }
            return level[sink] != -1;
        }
    
        int dfs(int u, int sink, int flow) {
            if (u == sink) return flow;
            for (int &i = ptr[u]; i < adjList[u].size(); i++) {
                int v = adjList[u][i];
                if (level[v] == level[u] + 1 && capacity[u][v] > 0) {
                    int pushed = dfs(v, sink, min(flow, capacity[u][v]));
                    if (pushed > 0) {
                        capacity[u][v] -= pushed;
                        capacity[v][u] += pushed;
                        return pushed;
                    }
                }
            }
            return 0;
        }
    
    public:
        Dinic(int vertices) : V(vertices) {
            capacity.assign(V, vector<int>(V, 0));
            adjList.resize(V);
            level.resize(V);
            ptr.resize(V);
        }
    
        void addEdge(int u, int v, int cap) {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            capacity[u][v] += cap; // Allow multiple edges
        }
    
        int maxFlow(int source, int sink) {
            int totalFlow = 0;
    
            while (bfs(source, sink)) {
                fill(ptr.begin(), ptr.end(), 0);
                while (int flow = dfs(source, sink, INT_MAX)) {
                    totalFlow += flow;
                }
            }
    
            return totalFlow;
        }
    };

// 17. Johnson's Algorithm
// Usage: Finds shortest paths between all pairs of vertices in a graph with negative edge weights but no negative weight cycles.
// Example: Network analysis, routing, etc.
// Time Complexity: O(V^2 + V * E), where V is the number of vertices and E is the number of edges.
// Space Complexity: O(V^2), for the distance matrix.

void johnsonsAlgorithm(int V, vector<vector<pair<int, int>>> &adjList) {
    // Step 1: Add a new vertex and connect it to all other vertices with weight 0
    vector<vector<pair<int, int>>> modifiedAdjList = adjList;
    for (int i = 0; i < V; i++) {
        modifiedAdjList.push_back({{i, 0}});
    }

    // Step 2: Run Bellman-Ford from the new vertex to find potential values
    vector<int> h(V + 1, INT_MAX);
    h[V] = 0;
    for (int i = 0; i < V; i++) {
        for (int u = 0; u <= V; u++) {
            for (auto &[v, weight] : modifiedAdjList[u]) {
                if (h[u] != INT_MAX && h[u] + weight < h[v]) {
                    h[v] = h[u] + weight;
                }
            }
        }
    }

    // Step 3: Reweight the edges
    vector<vector<pair<int, int>>> reweightedAdjList(V);
    for (int u = 0; u < V; u++) {
        for (auto &[v, weight] : adjList[u]) {
            reweightedAdjList[u].push_back({v, weight + h[u] - h[v]});
        }
    }

    // Step 4: Run Dijkstra's algorithm for each vertex
    vector<vector<int>> dist(V, vector<int>(V, INT_MAX));
    for (int i = 0; i < V; i++) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[i][i] = 0;
        pq.push({0, i});

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[i][u]) continue;

            for (auto &[v, weight] : reweightedAdjList[u]) {
                if (dist[i][u] + weight < dist[i][v]) {
                    dist[i][v] = dist[i][u] + weight;
                    pq.push({dist[i][v], v});
                }
            }
        }
    }

    // Step 5: Adjust the distances back to the original weights
    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (dist[u][v] != INT_MAX) {
                dist[u][v] += h[v] - h[u];
            }
        }
    }

    // Print the shortest distances
    cout << "Shortest distances between all pairs of vertices:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

// 18. Eulerian Path and Circuit
// Usage: Finds a path or circuit that visits every edge of a graph exactly once.
// Example: Route planning, DNA sequencing, etc.
// Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
// Space Complexity: O(V + E), for the adjacency list and stack.

bool isEulerian(vector<vector<int>> &adjList, int &startNode) {
    int V = adjList.size();
    vector<int> degree(V, 0);
    int oddCount = 0;

    for (int i = 0; i < V; i++) {
        degree[i] = adjList[i].size();
        if (degree[i] % 2 != 0) {
            oddCount++;
            startNode = i; // Start from an odd-degree vertex if it exists
        }
    }

    if (oddCount == 0) {
        return true; // Eulerian Circuit
    } else if (oddCount == 2) {
        return true; // Eulerian Path
    } else {
        return false; // Not Eulerian
    }
}

void findEulerianPathOrCircuit(vector<vector<int>> &adjList) {
    int startNode = 0;
    if (!isEulerian(adjList, startNode)) {
        cout << "The graph is not Eulerian.\n";
        return;
    }

    stack<int> st;
    vector<int> path;
    vector<vector<int>> tempAdjList = adjList;

    st.push(startNode);
    while (!st.empty()) {
        int u = st.top();
        if (!tempAdjList[u].empty()) {
            int v = tempAdjList[u].back();
            tempAdjList[u].pop_back();
            for (auto it = tempAdjList[v].begin(); it != tempAdjList[v].end(); ++it) {
                if (*it == u) {
                    tempAdjList[v].erase(it);
                    break;
                }
            }
            st.push(v);
        } else {
            path.push_back(u);
            st.pop();
        }
    }

    cout << "Eulerian Path/Circuit: ";
    for (int node : path) {
        cout << node << " ";
    }
    cout << endl;
}

// 19. Hamiltonian Path and Circuit
// Usage: Finds a path or circuit that visits every vertex of a graph exactly once.
// Example: Traveling Salesman Problem (TSP), puzzle solving, etc.
// Time Complexity: O(V!), where V is the number of vertices (due to backtracking).
// Space Complexity: O(V), for the visited array and recursion stack.

bool isHamiltonianUtil(int node, vector<vector<int>> &adjList, vector<bool> &visited, vector<int> &path, int V) {
    if (path.size() == V) {
        // Check if the last vertex connects to the first to form a circuit
        return true;
    }

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            visited[neighbor] = true;
            path.push_back(neighbor);

            if (isHamiltonianUtil(neighbor, adjList, visited, path, V)) {
                return true;
            }

            // Backtrack
            visited[neighbor] = false;
            path.pop_back();
        }
    }

    return false;
}

void findHamiltonianPathOrCircuit(vector<vector<int>> &adjList) {
    int V = adjList.size();
    vector<bool> visited(V, false);
    vector<int> path;

    for (int start = 0; start < V; start++) {
        visited[start] = true;
        path.push_back(start);

        if (isHamiltonianUtil(start, adjList, visited, path, V)) {
            cout << "Hamiltonian Path/Circuit: ";
            for (int node : path) {
                cout << node << " ";
            }
            cout << endl;
            return;
        }

        // Backtrack
        visited[start] = false;
        path.pop_back();
    }

    cout << "No Hamiltonian Path or Circuit found.\n";
}

// 20. Shortest Path Faster Algorithm (SPFA)
// Usage: An optimization of the Bellman-Ford algorithm for finding shortest paths in a graph.
// Example: Graphs with negative weights, network routing, etc.
// Time Complexity: O(V * E) in the worst case, where V is the number of vertices and E is the number of edges.
// Space Complexity: O(V), for the distance array and queue.

bool SPFA(int V, int source, vector<vector<pair<int, int>>> &adjList, vector<int> &dist) {
    vector<bool> inQueue(V, false); // To track if a vertex is in the queue
    queue<int> q;

    dist.assign(V, INT_MAX); // Initialize distances to infinity
    dist[source] = 0;
    q.push(source);
    inQueue[source] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inQueue[u] = false;

        for (auto &[v, weight] : adjList[u]) {
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                if (!inQueue[v]) {
                    q.push(v);
                    inQueue[v] = true;
                }
            }
        }
    }

    // Check for negative weight cycles
    for (int u = 0; u < V; u++) {
        for (auto &[v, weight] : adjList[u]) {
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                cout << "Graph contains a negative weight cycle\n";
                return false;
            }
        }
    }

    return true;
}

// 21. Kahn's Algorithm
// Usage: Another algorithm for topological sorting of a Directed Acyclic Graph (DAG).
// Example: Task scheduling, dependency resolution, etc.
// Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
// Space Complexity: O(V), for the in-degree array and queue.

void kahnsAlgorithm(int V, vector<vector<int>> &adjList) {
    vector<int> inDegree(V, 0); // Array to store in-degrees of vertices
    queue<int> q; // Queue to process vertices with in-degree 0
    vector<int> topologicalOrder; // To store the topological order

    // Calculate in-degrees of all vertices
    for (int u = 0; u < V; u++) {
        for (int v : adjList[u]) {
            inDegree[v]++;
        }
    }

    // Push all vertices with in-degree 0 into the queue
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    // Process vertices in the queue
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topologicalOrder.push_back(u);

        for (int v : adjList[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    // Check if the graph is a DAG
    if (topologicalOrder.size() != V) {
        cout << "The graph is not a Directed Acyclic Graph (DAG).\n";
        return;
    }

    // Print the topological order
    cout << "Topological Order: ";
    for (int node : topologicalOrder) {
        cout << node << " ";
    }
    cout << endl;
}

// 22. Cycle Detection in Graphs
// Usage: Detects cycles in a graph using DFS or Union-Find.
// Example: Deadlock detection, dependency resolution, etc.
// Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
// Space Complexity: O(V), for the visited array and recursion stack.

bool detectCycleDFS(int node, vector<vector<int>> &adjList, vector<bool> &visited, vector<bool> &recStack) {
    visited[node] = true;
    recStack[node] = true;

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            if (detectCycleDFS(neighbor, adjList, visited, recStack)) {
                return true;
            }
        } else if (recStack[neighbor]) {
            return true; // Cycle detected
        }
    }

    recStack[node] = false; // Remove the node from the recursion stack
    return false;
}

bool detectCycleInDirectedGraph(int V, vector<vector<int>> &adjList) {
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (detectCycleDFS(i, adjList, visited, recStack)) {
                return true;
            }
        }
    }

    return false;
}
bool detectCycleUnionFind(int V, vector<pair<int, int>> &edges) {
    vector<int> parent(V, -1);

    // Use std::function to define the type of the lambda
    std::function<int(int)> find = [&](int u) {
        if (parent[u] == -1) return u;
        return parent[u] = find(parent[u]); // Path compression
    };

    auto unionSets = [&](int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            parent[rootU] = rootV;
        } else {
            return true; // Cycle detected
        }
        return false;
    };

    for (auto &[u, v] : edges) {
        if (unionSets(u, v)) {
            return true;
        }
    }

    return false;
}
// 23. Bipartite Graph Check
// Usage: Checks if a graph is bipartite using BFS or DFS.
// Example: Graph coloring, matching problems, etc.
// Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
// Space Complexity: O(V), for the color array and queue.

bool isBipartiteBFS(int V, vector<vector<int>> &adjList) {
    vector<int> color(V, -1); // -1 means uncolored, 0 and 1 are the two colors

    for (int i = 0; i < V; i++) {
        if (color[i] == -1) { // If the node is not yet colored
            queue<int> q;
            q.push(i);
            color[i] = 0; // Assign the first color

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adjList[u]) {
                    if (color[v] == -1) { // If the neighbor is not colored
                        color[v] = 1 - color[u]; // Assign the opposite color
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false; // If the neighbor has the same color, it's not bipartite
                    }
                }
            }
        }
    }

    return true;
}

bool isBipartiteDFSUtil(int node, vector<vector<int>> &adjList, vector<int> &color) {
    for (int neighbor : adjList[node]) {
        if (color[neighbor] == -1) { // If the neighbor is not colored
            color[neighbor] = 1 - color[node]; // Assign the opposite color
            if (!isBipartiteDFSUtil(neighbor, adjList, color)) {
                return false;
            }
        } else if (color[neighbor] == color[node]) {
            return false; // If the neighbor has the same color, it's not bipartite
        }
    }
    return true;
}

bool isBipartiteDFS(int V, vector<vector<int>> &adjList) {
    vector<int> color(V, -1); // -1 means uncolored, 0 and 1 are the two colors

    for (int i = 0; i < V; i++) {
        if (color[i] == -1) { // If the node is not yet colored
            color[i] = 0; // Assign the first color
            if (!isBipartiteDFSUtil(i, adjList, color)) {
                return false;
            }
        }
    }

    return true;
}

// 24. Maximum Bipartite Matching
// Usage: Finds the maximum matching in a bipartite graph using augmenting paths or flow algorithms.
// Example: Job assignment, resource allocation, etc.
// Time Complexity: O(V * E), where V is the number of vertices and E is the number of edges.
// Space Complexity: O(V), for the visited array.

bool bpmDFS(int u, vector<vector<int>> &bpGraph, vector<bool> &visited, vector<int> &matchR) {
    for (int v : bpGraph[u]) {
        if (!visited[v]) {
            visited[v] = true;

            if (matchR[v] == -1 || bpmDFS(matchR[v], bpGraph, visited, matchR)) {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}

int maxBipartiteMatching(vector<vector<int>> &bpGraph, int U, int V) {
    vector<int> matchR(V, -1); // Match for vertices on the right set
    int result = 0;

    for (int u = 0; u < U; u++) {
        vector<bool> visited(V, false);
        if (bpmDFS(u, bpGraph, visited, matchR)) {
            result++;
        }
    }

    return result;
}

// Trie (Prefix Tree)
// Usage: Efficiently stores and retrieves strings, useful for autocomplete, spell checking, and prefix matching.
// Example: Dictionary implementation, search suggestions, etc.
// Time Complexity: 
// - Insert: O(L), where L is the length of the word.
// - Search: O(L), where L is the length of the word.
// - StartsWith: O(L), where L is the length of the prefix.
// Space Complexity: O(N * A), where N is the total number of characters in all words and A is the alphabet size.

class TrieNode {
    public:
        TrieNode* children[26];
        bool isEndOfWord;
    
        TrieNode() {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            isEndOfWord = false;
        }
    };
    
    class Trie {
    private:
        TrieNode* root;
    
    public:
        Trie() {
            root = new TrieNode();
        }
    
        // Insert a word into the Trie
        void insert(string word) {
            TrieNode* node = root;
            for (char c : word) {
                int index = c - 'a';
                if (node->children[index] == nullptr) {
                    node->children[index] = new TrieNode();
                }
                node = node->children[index];
            }
            node->isEndOfWord = true;
        }
    
        // Search for a word in the Trie
        bool search(string word) {
            TrieNode* node = root;
            for (char c : word) {
                int index = c - 'a';
                if (node->children[index] == nullptr) {
                    return false;
                }
                node = node->children[index];
            }
            return node->isEndOfWord;
        }
    
        // Check if any word in the Trie starts with the given prefix
        bool startsWith(string prefix) {
            TrieNode* node = root;
            for (char c : prefix) {
                int index = c - 'a';
                if (node->children[index] == nullptr) {
                    return false;
                }
                node = node->children[index];
            }
            return true;
        }
    };

// Segment Tree
// Usage: Efficiently performs range queries and updates on an array.
// Example: Range sum queries, range minimum/maximum queries, etc.
// Time Complexity: 
// - Build: O(N), where N is the size of the array.
// - Update: O(log N).
// - Query: O(log N).
// Space Complexity: O(4 * N), for the segment tree storage.

class SegmentTree {
    private:
        vector<int> st; // Segment tree
        vector<int> data; // Original data
        int n; // Size of the data
    
        // Build the segment tree
        void build(int node, int start, int end) {
            if (start == end) {
                st[node] = data[start];
            } else {
                int mid = (start + end) / 2;
                build(2 * node + 1, start, mid); // Left child
                build(2 * node + 2, mid + 1, end); // Right child
                st[node] = st[2 * node + 1] + st[2 * node + 2]; // Combine results
            }
        }
    
        // Update a value in the segment tree
        void update(int node, int start, int end, int idx, int value) {
            if (start == end) {
                data[idx] = value; // Update the original data
                st[node] = value; // Update the segment tree
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
    
        // Query a range in the segment tree
        int query(int node, int start, int end, int l, int r) {
            if (r < start || end < l) return 0; // Out of range
            if (l <= start && end <= r) return st[node]; // Node is completely within range
            int mid = (start + end) / 2;
            int left_sum = query(2 * node + 1, start, mid, l, r); // Left child
            int right_sum = query(2 * node + 2, mid + 1, end, l, r); // Right child
            return left_sum + right_sum; // Combine results
        }
    
    public:
        SegmentTree(vector<int>& input) {
            data = input;
            n = input.size();
            st.resize(4 * n); // Size of segment tree
            build(0, 0, n - 1); // Build the segment tree
        }
    
        // Update a value in the array
        void update(int idx, int value) {
            update(0, 0, n - 1, idx, value);
        }
    
        // Query a range in the array
        int query(int l, int r) {
            return query(0, 0, n - 1, l, r);
        }
    };

// Fenwick Tree (Binary Indexed Tree - BIT)
// Usage: Efficiently performs prefix sum queries and point updates on an array.
// Example: Range sum queries, frequency counting, etc.
// Time Complexity: 
// - Update: O(log N), where N is the size of the array.
// - Query: O(log N).
// Space Complexity: O(N), for the Fenwick Tree storage.

class FenwickTree {
    private:
        vector<int> bit; // Fenwick Tree
        int n; // Size of the array
    
    public:
        FenwickTree(int size) {
            n = size;
            bit.assign(n + 1, 0); // Initialize with 0
        }
    
        // Point update: Add value to the element at index idx
        void update(int idx, int value) {
            while (idx <= n) {
                bit[idx] += value;
                idx += idx & -idx; // Move to the next index
            }
        }
    
        // Prefix sum query: Get the sum of elements from index 1 to idx
        int query(int idx) {
            int sum = 0;
            while (idx > 0) {
                sum += bit[idx];
                idx -= idx & -idx; // Move to the parent index
            }
            return sum;
        }
    
        // Range sum query: Get the sum of elements from index l to r
        int rangeQuery(int l, int r) {
            return query(r) - query(l - 1);
        }
    };

//String Algorithms:

// Knuth-Morris-Pratt (KMP) Algorithm
// Usage: Efficiently finds all occurrences of a pattern in a text using the LPS array.
// Example: String searching, pattern matching, etc.
// Time Complexity: O(N + M), where N is the length of the text and M is the length of the pattern.
// Space Complexity: O(M), for the LPS array.

vector<int> computeLPS(string pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0); // LPS array
    int len = 0; // Length of the previous longest prefix suffix
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1]; // Fall back to the previous prefix
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

void KMP(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> lps = computeLPS(pattern);

    int i = 0; // Index for text
    int j = 0; // Index for pattern

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1]; // Continue searching for other occurrences
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1]; // Fall back in the pattern
            } else {
                i++;
            }
        }
    }
}
// Z-Algorithm
// Usage: Finds all occurrences of a pattern in a text by computing the Z-array.
// Example: String searching, pattern matching, etc.
// Time Complexity: O(N + M), where N is the length of the text and M is the length of the pattern.
// Space Complexity: O(N + M), for the concatenated string and Z-array.

vector<int> computeZ(string s) {
    int n = s.length();
    vector<int> Z(n, 0);
    int l = 0, r = 0;

    for (int i = 1; i < n; i++) {
        if (i <= r) {
            Z[i] = min(r - i + 1, Z[i - l]);
        }
        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) {
            Z[i]++;
        }
        if (i + Z[i] - 1 > r) {
            l = i;
            r = i + Z[i] - 1;
        }
    }

    return Z;
}

void ZAlgorithm(string text, string pattern) {
    string concat = pattern + "$" + text; // Concatenate pattern, delimiter, and text
    vector<int> Z = computeZ(concat);
    int m = pattern.length();

    for (int i = m + 1; i < Z.size(); i++) {
        if (Z[i] == m) {
            cout << "Pattern found at index " << i - m - 1 << endl;
        }
    }
}
// Suffix Array and LCP Array
// Usage: Used for efficient string matching, finding the longest repeated substring, and solving other string-related problems.
// Example: DNA sequencing, text indexing, etc.
// Time Complexity: 
// - Suffix Array Construction: O(N * log(N)), where N is the length of the string.
// - LCP Array Construction: O(N).
// Space Complexity: O(N), for the suffix array and LCP array.

vector<int> buildSuffixArray(string s) {
    s += "$"; // Append a unique character to ensure all suffixes are distinct
    int n = s.size();
    vector<int> suffixArray(n), rank(n), tempRank(n);

    // Initial ranking based on the first character
    for (int i = 0; i < n; i++) {
        suffixArray[i] = i;
        rank[i] = s[i];
    }

    for (int k = 1; k < n; k *= 2) {
        auto compare = [&](int i, int j) {
            if (rank[i] != rank[j]) return rank[i] < rank[j];
            int ri = (i + k < n) ? rank[i + k] : -1;
            int rj = (j + k < n) ? rank[j + k] : -1;
            return ri < rj;
        };

        sort(suffixArray.begin(), suffixArray.end(), compare);

        tempRank[suffixArray[0]] = 0;
        for (int i = 1; i < n; i++) {
            tempRank[suffixArray[i]] = tempRank[suffixArray[i - 1]] + compare(suffixArray[i - 1], suffixArray[i]);
        }
        rank = tempRank;
    }

    return suffixArray;
}

vector<int> buildLCPArray(string s, vector<int> &suffixArray) {
    int n = s.size();
    vector<int> rank(n), lcp(n, 0);

    for (int i = 0; i < n; i++) {
        rank[suffixArray[i]] = i;
    }

    int h = 0;
    for (int i = 0; i < n; i++) {
        if (rank[i] > 0) {
            int j = suffixArray[rank[i] - 1];
            while (i + h < n && j + h < n && s[i + h] == s[j + h]) {
                h++;
            }
            lcp[rank[i]] = h;
            if (h > 0) h--;
        }
    }

    return lcp;
}
// Aho-Corasick Algorithm
// Usage: Finds all occurrences of multiple patterns in a text efficiently using a trie and failure links.
// Example: Spam filtering, dictionary matching, bioinformatics, etc.
// Time Complexity: 
// - Build: O(M), where M is the total length of all patterns.
// - Search: O(N + M), where N is the length of the text and M is the total length of all patterns.
// Space Complexity: O(M * A), where A is the alphabet size.

class AhoCorasick {
    private:
        struct TrieNode {
            vector<TrieNode*> children;
            TrieNode* failureLink;
            vector<int> output; // Stores indices of patterns ending at this node
    
            TrieNode() : children(26, nullptr), failureLink(nullptr) {}
        };
    
        TrieNode* root;
        vector<string> patterns;
    
    public:
        AhoCorasick() {
            root = new TrieNode();
        }
    
        // Insert a pattern into the trie
        void insert(const string& pattern, int index) {
            TrieNode* node = root;
            for (char c : pattern) {
                int idx = c - 'a';
                if (!node->children[idx]) {
                    node->children[idx] = new TrieNode();
                }
                node = node->children[idx];
            }
            node->output.push_back(index);
        }
    
        // Build the failure links
        void build() {
            queue<TrieNode*> q;
            root->failureLink = root;
    
            for (int i = 0; i < 26; i++) {
                if (root->children[i]) {
                    root->children[i]->failureLink = root;
                    q.push(root->children[i]);
                } else {
                    root->children[i] = root; // Point to root for missing links
                }
            }
    
            while (!q.empty()) {
                TrieNode* current = q.front();
                q.pop();
    
                for (int i = 0; i < 26; i++) {
                    if (current->children[i]) {
                        TrieNode* failure = current->failureLink;
                        while (!failure->children[i]) {
                            failure = failure->failureLink;
                        }
                        current->children[i]->failureLink = failure->children[i];
                        current->children[i]->output.insert(
                            current->children[i]->output.end(),
                            failure->children[i]->output.begin(),
                            failure->children[i]->output.end()
                        );
                        q.push(current->children[i]);
                    }
                }
            }
        }
    
        // Search for patterns in the text
        void search(const string& text) {
            TrieNode* node = root;
    
            for (int i = 0; i < text.size(); i++) {
                int idx = text[i] - 'a';
                while (!node->children[idx]) {
                    node = node->failureLink;
                }
                node = node->children[idx];
    
                for (int patternIndex : node->output) {
                    cout << "Pattern " << patterns[patternIndex] << " found at index " << i - patterns[patternIndex].size() + 1 << endl;
                }
            }
        }
    
        // Add patterns and build the trie
        void addPatterns(const vector<string>& inputPatterns) {
            patterns = inputPatterns;
            for (int i = 0; i < patterns.size(); i++) {
                insert(patterns[i], i);
            }
            build();
        }
    };

//Dynamic Programming:

// Longest Increasing Subsequence (LIS)
// Usage: Finds the length of the longest subsequence in an array such that all elements of the subsequence are sorted in increasing order.
// Example: Sequence analysis, dynamic programming problems, etc.
// Time Complexity: O(N * log(N)), where N is the size of the array.
// Space Complexity: O(N), for the LIS array.

int LIS(vector<int>& nums) {
    vector<int> lis; // Stores the smallest ending element of increasing subsequences of different lengths

    for (int num : nums) {
        auto it = lower_bound(lis.begin(), lis.end(), num); // Find the position to replace or extend
        if (it == lis.end()) {
            lis.push_back(num); // Extend the LIS
        } else {
            *it = num; // Replace to maintain the smallest possible value
        }
    }

    return lis.size(); // The size of the LIS array is the length of the LIS
}
// Matrix Chain Multiplication
// Usage: Finds the minimum number of scalar multiplications needed to multiply a sequence of matrices.
// Example: Dynamic programming problems, optimization problems, etc.
// Time Complexity: O(N^3), where N is the number of matrices.
// Space Complexity: O(N^2), for the DP table.

int matrixChainMultiplication(vector<int>& dims) {
    int n = dims.size() - 1; // Number of matrices
    vector<vector<int>> dp(n, vector<int>(n, 0)); // DP table to store minimum costs

    // Length of the chain
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            // Try all possible splits
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dims[i] * dims[k + 1] * dims[j + 1];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[0][n - 1]; // Minimum cost to multiply matrices from 0 to n-1
}   

// 0/1 Knapsack Problem
// Usage: Finds the maximum value that can be obtained by selecting items with given weights and values, subject to a weight limit.
// Example: Resource allocation, optimization problems, etc.
// Time Complexity: O(N * W), where N is the number of items and W is the weight capacity.
// Space Complexity: O(W), for the DP array.

int knapsack01(vector<int>& weights, vector<int>& values, int W) {
    int n = weights.size();
    vector<int> dp(W + 1, 0); // DP array to store maximum values for each weight

    for (int i = 0; i < n; i++) {
        for (int w = W; w >= weights[i]; w--) {
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }

    return dp[W]; // Maximum value for weight capacity W
}

// Unbounded Knapsack Problem
// Usage: Finds the maximum value that can be obtained by selecting items with given weights and values, with unlimited repetitions allowed.
// Example: Resource allocation, optimization problems, etc.
// Time Complexity: O(N * W), where N is the number of items and W is the weight capacity.
// Space Complexity: O(W), for the DP array.

int unboundedKnapsack(vector<int>& weights, vector<int>& values, int W) {
    int n = weights.size();
    vector<int> dp(W + 1, 0); // DP array to store maximum values for each weight

    for (int i = 0; i < n; i++) {
        for (int w = weights[i]; w <= W; w++) {
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }

    return dp[W]; // Maximum value for weight capacity W
}
// Subset Sum Problem
// Usage: Determines if there exists a subset of the given set with a sum equal to a given target.
// Example: Partition problems, dynamic programming problems, etc.
// Time Complexity: O(N * S), where N is the number of elements and S is the target sum.
// Space Complexity: O(S), for the DP array.

bool subsetSum(vector<int>& nums, int target) {
    vector<bool> dp(target + 1, false); // DP array to store if a sum is possible
    dp[0] = true; // Base case: A sum of 0 is always possible

    for (int num : nums) {
        for (int sum = target; sum >= num; sum--) {
            dp[sum] = dp[sum] || dp[sum - num]; // Corrected variable name
        }
    }

    return dp[target]; // Return true if the target sum is possible
}
// Longest Common Subsequence (LCS)
// Usage: Finds the length of the longest subsequence common to two strings.
// Example: Text comparison, DNA sequence alignment, etc.
// Time Complexity: O(N * M), where N and M are the lengths of the two strings.
// Space Complexity: O(N * M), for the DP table.

int LCS(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // DP table

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1; // Characters match
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // Take the maximum
            }
        }
    }

    return dp[n][m]; // Length of the LCS
}

// Edit Distance (Levenshtein Distance)
// Usage: Finds the minimum number of operations (insertions, deletions, substitutions) required to convert one string into another.
// Example: Spell checking, DNA sequence alignment, etc.
// Time Complexity: O(N * M), where N and M are the lengths of the two strings.
// Space Complexity: O(N * M), for the DP table.

int editDistance(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // DP table

    // Initialize base cases
    for (int i = 0; i <= n; i++) dp[i][0] = i; // Deleting all characters from s1
    for (int j = 0; j <= m; j++) dp[0][j] = j; // Inserting all characters into s1

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // Characters match, no operation needed
            } else {
                dp[i][j] = 1 + min({dp[i - 1][j],    // Deletion
                                    dp[i][j - 1],    // Insertion
                                    dp[i - 1][j - 1] // Substitution
                                   });
            }
        }
    }

    return dp[n][m]; // Minimum edit distance
}

//Number Theory:

// Sieve of Eratosthenes
// Usage: Efficiently generates all prime numbers up to a given limit.
// Example: Prime number generation, number theory problems, etc.
// Time Complexity: O(N * log(log(N))), where N is the limit.
// Space Complexity: O(N), for the boolean array.

vector<int> sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true); // Boolean array to mark primes
    isPrime[0] = isPrime[1] = false;  // 0 and 1 are not prime numbers

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false; // Mark multiples of i as non-prime
            }
        }
    }

    // Collect all prime numbers
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}
// Modular Exponentiation
// Usage: Computes (base^exponent) % mod efficiently using the method of exponentiation by squaring.
// Example: Cryptography, modular arithmetic problems, etc.
// Time Complexity: O(log(exponent)).
// Space Complexity: O(1).

long long modularExponentiation(long long base, long long exponent) {
    long long result = 1; // Initialize result
    base = base % mod;    // Ensure base is within mod

    while (exponent > 0) {
        // If the current exponent bit is set, multiply the result by the base
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }

        // Square the base and reduce the exponent by half
        base = (base * base) % mod;
        exponent /= 2;
    }

    return result;
}

// Greatest Common Divisor (GCD) and Least Common Multiple (LCM)
// Usage: Computes the GCD and LCM of two numbers using the Euclidean algorithm.
// Example: Number theory problems, fraction simplification, etc.
// Time Complexity: O(log(min(A, B))), where A and B are the input numbers.
// Space Complexity: O(1).

// Function to compute GCD using the Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute LCM using the relationship: LCM(a, b) = (a * b) / GCD(a, b)
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b; // Avoids overflow by dividing first
}

// Extended Euclidean Algorithm
// Usage: Computes the GCD of two numbers and finds coefficients x and y such that ax + by = gcd(a, b).
// Example: Modular inverses, solving linear Diophantine equations, etc.
// Time Complexity: O(log(min(a, b))).
// Space Complexity: O(1).

int extendedGCD(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a; // GCD is a when b is 0
    }

    int x1, y1;
    int gcd = extendedGCD(b, a % b, x1, y1);

    // Update x and y using results of recursion
    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}

// Chinese Remainder Theorem (CRT)
// Usage: Solves a system of simultaneous congruences using the Chinese Remainder Theorem.
// Example: Modular arithmetic problems, cryptography, etc.
// Time Complexity: O(N), where N is the number of congruences.
// Space Complexity: O(1).

// Function to compute modular inverse using the Extended Euclidean Algorithm
int modularInverse(int a, int m) {
    int x, y;
    int g = extendedGCD(a, m, x, y);
    if (g != 1) {
        throw invalid_argument("Modular inverse does not exist");
    }
    return (x % m + m) % m;
}

// Function to solve a system of congruences using CRT
int chineseRemainderTheorem(vector<int>& nums, vector<int>& rems) {
    int prod = 1; // Product of all moduli
    int n = nums.size();

    for (int num : nums) {
        prod *= num;
    }

    int result = 0;

    for (int i = 0; i < n; i++) {
        int pp = prod / nums[i]; // Partial product
        result += rems[i] * modularInverse(pp, nums[i]) * pp;
        result %= prod;
    }

    return (result + prod) % prod; // Ensure the result is non-negative
}
// Fermat's Little Theorem (for modular inverses)
// Usage: Computes the modular inverse of a number modulo a prime using Fermat's Little Theorem.
// Example: Modular arithmetic problems, cryptography, etc.
// Time Complexity: O(log(mod - 1)), where mod is the prime modulus.
// Space Complexity: O(1).

long long modularInverseFermat(long long a) {
    // Fermat's Little Theorem: a^(mod-1) ≡ 1 (mod mod)
    // Modular inverse: a^(mod-2) ≡ a^(-1) (mod mod)
    return modularExponentiation(a, mod - 2);
}

// Modular Exponentiation (helper function)
// Computes (base^exponent) % mod efficiently using exponentiation by squaring.
long long modularExponentiation(long long base, long long exponent) {
    long long result = 1;
    base = base % mod;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exponent /= 2;
    }

    return result;
}

//Main Function:

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

   

    return 0;
}
