#include <bits/stdc++.h>
using namespace std;
#define ll long  long
#define llm LLONG_MAX;
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

void solve() {
   


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //Trie trie;
    //dsu dset(n);
    //vector<int> lps = computeLPS(string);
    //SegmentTree segTree(array);
   
    ll t;
    cin >> t;
    while (t--) 
    {
        int len;
        long long lim;
        cin>>len>>lim;
        vector<long long>arr(len+2);
        vector<long long>grp(len+2);
        vector<long long>pre(len+2);
        vector<long long>val(len+2);
        vector<char>flg(len+2);
        vector<char>suf(len+2);
        vector<long long> rgr(len + 2);
        vector<long long> rpf(len + 2);
        vector<long long> rval(len + 2);
        vector<char> rfl(len + 2);
        long long mvl[2];
        mvl[0]=llm;
        mvl[1]=llm;
        long long rmv[2];
        rmv[0]=llm;
        rmv[1]=llm;
        int idx=1;
       
        while (idx<=len)
        {
            cin>>arr[idx];
            if(arr[idx]<=lim) 
            {
                grp[idx]=1;
            } 
            else
            {
                grp[idx]=0;
            }
            idx++;
        }
        idx = 1;
        pre[0] = 0;
        while(idx<=len)
         {
            pre[idx]=pre[idx-1]+grp[idx];
            val[idx]=2*pre[idx]-idx;
            if (idx%2==1) 
            {
                if (val[idx]>=1)
                {
                    flg[idx]=1;
                }
                 else 
                 {
                    flg[idx]=0;
                }
            }
             else
             {
                if(val[idx]>=0)
               {
                    flg[idx]=1;
                } 
                else 
                {
                    flg[idx]=0;
                }
             }
            idx++;
        }
        bool ok=false;
        
        idx=2;
        while(idx<=len-1) 
        {
            int lft=idx-1;
            int par=lft%2;
            if (flg[lft]==1)
             {
                if(val[lft]<mvl[par])
                 {
                    mvl[par]=val[lft];
                }
            }
            long long cur=val[idx];
            int curp=idx%2;
            if (mvl[curp]<=cur)
             {
                ok=true;
                break;
            }
            if (mvl[1-curp]<=cur-1)
             {
                ok=true;
                break;
            }
            idx++;
        }
        if(ok)
         {
            cout<<"YES"<<endl;
            continue;
        }
       
        idx=1;
        while(idx<=len)
         {
            rgr[idx]=grp[len-idx+1];
            idx++;
        }
        rpf[0]=0;
        idx=1;
        while(idx<=len)
         {
            rpf[idx]=rpf[idx -1]+rgr[idx];
            rval[idx]=2*rpf[idx]-idx;
            if (idx%2==1)
             {
                if(rval[idx]>=1) 
                {
                    rfl[idx]=1;
                }
                 else{
                    rfl[idx]=0;
                }
            } else 
            {
                if (rval[idx]==0)
                {
                    rfl[idx]=1;
                } 
                else 
                {
                    rfl[idx]=0;
                }
            }
            idx++;
        }
       
        idx = 2;
        while(idx<=len-1)
         {
            int lft=idx-1;
            int par=lft%2;

            if (rfl[lft]==1)
             {
                if(rval[lft]<rmv[par]) 
                {
                    rmv[par]=rval[lft];
                }
            }
            long long cur=rval[idx];
            int curp=idx%2;
            if(rmv[curp]<=cur)
             {
                ok = true;
                break;
            }
            if (rmv[1 - curp]<=cur-1)
           {
                ok = true;
                break;
            }
            idx++;
        }

        if (ok) {
            cout << "YES"<<endl;
            continue;
        }
        long long tot = pre[len];
        idx = 1;
        while (idx <= len) 
        {
            long long cnt=tot-pre[idx-1];
            long long seg=len-idx+1;
            long long dif=2*cnt-seg;

            if (seg%2==1)
             {
                if (dif>=1)
                 {
                    suf[idx]=1;
                } else 
                {
                    suf[idx]=0;
                }
            } 
            else 
            {
                if (dif>=0)
                 {
                    suf[idx]=1;
                } 
                else
                {
                    suf[idx]=0;
                }
            }
            idx++;
        }
        int lmin=len+1;
        idx=1;
        while(idx<=len-2)
         {
            if(flg[idx]==1)
             {
                lmin=idx;
                break;
            }
            idx++;
        }
        int rmax=0;
        idx=1;
        while(idx<=len) 
        {
            if (suf[idx]==1)
           {
                rmax = idx;
            }
            idx++;
        }

        if (lmin<=len)
         {
            if (rmax>=1)
             {
                if (lmin+2<=rmax) 
                {
                    ok=true;
                }
            }
        }

        if(ok)
        {
            cout << "YES"<<endl;
        } 
        else 
        {
            cout<<"NO"<<endl;
        }
    }
return 0;
}
