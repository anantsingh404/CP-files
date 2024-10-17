#include <bits/stdc++.h>
using namespace std;
#define ll long long





int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //Trie trie;
    //dsu dset(n);
    //vector<int> lps = computeLPS(string);
    //SegmentTree segTree(array);
   
     ll t;
    cin >> t;
    while (t--) {
        string s; 
        string t;
        cin>>s;
        cin>>t;

        int j=0;
        int mini=min(s.size(),t.size());
        //cout<<s<<" "<<t<<endl;
        for(int i=0;i<mini;i++)
        {
           if (s[i] != t[i]) {
                break;  // Stop when characters mismatch
            }
            j = i + 1;

        }
        //cout<<j<<endl;
        if(j==0)
        {
            cout<<s.size()+t.size()<<endl;
            continue;
        }
        cout<<(s.size()+t.size()-j+1)<<endl;



    }
return 0;
}
