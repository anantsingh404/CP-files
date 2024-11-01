#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl (int i=0;i<n;i++)
const int mod=1e9+7;

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
        
      int n;
      cin>>n;
      vector<int>arr(n,0);
    
      for(int i=0;i<n;i++)
      {
        cin>>arr[i];
      }
      int i=0;
      int j=n-1;
      while(i<j && i<n-1 &&j>0 )
      {
        if(arr[i]==arr[i+1] || arr[j]==arr[j-1])
        {
            swap(arr[i+1],arr[j-1]);
            
        }
       i++;
       j--;
      }
      int count=0;
      for(int i=0;i<n-1;i++)
      {
        if(arr[i]==arr[i+1])
        {
            ++count;
        }
      }
      cout<<count<<endl;
      


    }
return 0;
}
