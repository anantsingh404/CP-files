#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl (int i=0;i<n;i++)
const int mod=1e9+7;




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

int find_max(vector<int>& v,int a,int b)
{
    if(a<0||b>=v.size())
    {
        return 0;
    }
    int maxi=0;
    int k=0;
    for(int i=a;i<=b;i++)
    {
        k=k+v[i];
        if(k>0)
        {
            maxi=max(maxi,k);
        }
        else k=0;
    }
    return maxi;
}

int find_mini(vector<int>&v,int a,int b)
{
    if(a<0||b>=v.size())return 0;
    int mini=0;
    int k=0;
    for(int i=a;i<=b;i++)
    {
        k=k+v[i];
        if(k<0)
        {
            mini=min(mini,k);
        }
        else k=0;
    }
    return mini;
}

int find_mini2(vector<int>&v,int k)
{
    int mini1=0;
    int mini2=0;
    int s=0;
    for(int i=k-1;i>=0;i--)
    {
        s=s+v[i];
        mini1=min(mini1,s);
    }
    s=0;
    for(int i=k+1;i<v.size();i++)
    {
        s=s+v[i];
        mini2=min(mini2,s);
    }
    return mini1+mini2+v[k];
}

int find_maxi2(vector<int>&v,int k)
{
    int maxi1=0;
    int s=0;
    for(int i=k-1;i>=0;i--)
    {
        s=s+v[i];
        maxi1=max(maxi1,s);
    }
    int maxi2=0;
    s=0;
    for(int i=k+1;i<v.size();i++)
    {
        s=s+v[i];
        maxi2=max(maxi2,s);
    }
    return maxi1+maxi2+v[k];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin>>t;
    while ((t--))
    {
        int n;
        cin>>n;
        vector<int>v(n);
        int k=-1;
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            if(v[i]!=-1 && v[i]!=1)
            {
                k=i;
            }
        }
        int mini,maxi;
        int mini2,maxi2;
        if(k==-1)
        {
            mini=find_mini(v,0,n-1);
            maxi=find_max(v,0,n-1);
        }
        else 
        {
            mini=find_mini(v,0,k-1);
            mini=min(mini,find_mini(v,k+1,n-1));
            maxi=find_max(v,0,k-1);
            maxi=max(maxi,find_max(v,k+1,n-1));
            mini2=find_mini2(v,k);
            maxi2=find_maxi2(v,k);
        }
        set<int>s;
        s.insert(0);
        for(int i=mini;i<=maxi;i++)
        {
            s.insert(i);
        }
        if(k!=-1)
        for(int i=mini2;i<=maxi2;i++)
        {
            s.insert(i);
        }
        cout<<s.size()<<endl;
        for(auto i:s)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    
}