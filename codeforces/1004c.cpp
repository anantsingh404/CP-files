#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl (ll i=0;i<n;i++)
const ll mod=1e9+7;




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


//Disjoint set template

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
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2]; // Update internal node
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



bool canTransform(long long a, ll b) 
{    
    vector<vector<ll>>h(35,vector<ll>(45,0));
    h[b][0] = 1;
    vector<vector<ll>>i(35,vector<ll>(45,0));
    vector<ll>d(25,0);
    ll e=0;
    ll g = 45;
    ll c = a - b;
    ll f=0;
    if (c == 0) 
    {
        d[e++] = 0;
        f = max(e,1ll*15);
    }
    else 
    {
        while (c>0) 
        {
            d[e++]=c%10;
            c=c/10;
        }
    }
    f=max(e,1ll*15);
    ll j = 0;
    ll m=0;
    while (j < f) 
    {
        ll k = 0;
        while (k <= b)
         {
            ll l = 0;
            while (l < g) 
            {
                i[k][l] = 0;
                l++;
            }
            k++;
        }
        if(j<e)
        {
            m=d[j];
        }
        else{
            m=0;
        }

        
        k = 0;
        while (k <= b) {
            ll l = 0;
            while (l < g) 
            {
                ll n = h[k][l];
                if (n == 0) 
                {
                    l++;
                    continue;
                }
                ll o = 0;
                while (o <= k) 
                {
                    ll p = m + l + o;
                    ll q = p % 10;
                    ll r = p / 10;
                    if (r >= g) 
                    {
                        o++;
                        continue;
                    }
                    ll s = k - o;
                    ll  t = n;
                    if (q == 7)
                    {
                         t=t|2;
                    }
                    i[s][r]=i[s][r]|t;
                    o++;
                }
                l++;
            }
            k++;
        }
        k = 0;
        while (k<=b)
        {
            ll l=0;
            while (l<g)
            {
                h[k][l]=i[k][l];
                l++;
            }
            k++;
        }
        j++;
    }
    if((h[0][0]&2)!=0)
    {
        return true;
    }
    return false;
}

int  main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a;
    cin >> a;
    while (a--) 
    {
        long long b;
        cin >> b;
        ll aa=b;
        ll c = -1, d = 1;
        bool ans=false;
        while (aa > 0)
         {
            if (aa % 10 == 7)
            { 
                 ans=true;
                 break;
            }
            aa =aa/10;
        }
        if(ans==true)
        {
            cout<<0<<endl;
            continue;
        }
       
        while (d <= 31)
         {
            if (canTransform(b, d))
             {
                c = d;
                break;
            }
            d++;
        }
        cout<<c<<endl;
    }
    return 0;
}