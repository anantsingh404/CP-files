#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=2e5+10;
long long values[mod];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin>>t;
    while(t--)
    {
      
      int rows, cols, k;
    cin >> rows ;
    cin>> cols;
    cin >> k;
    
    vector<int> subMatrixCounts;
    
    for (int r = 1; r <= rows; ++r) {
        for (int c = 1; c <= cols; ++c) {
            int minRow = max(r - k + 1, 1);

            int minCol = max(c - k + 1, 1);

            int maxRow = min(r, rows - k + 1);

            int maxCol = min(c, cols - k + 1);
            ll x=(maxRow - minRow + 1) * (maxCol - minCol + 1);
            subMatrixCounts.push_back(x);
        }
    }
    int numValues;
    cin >> numValues;
    sort(subMatrixCounts.begin(), subMatrixCounts.end(), greater<int>());
    
    
    
    long long result = 0;
    for (int i = 0; i < numValues; ++i) cin >> values[i];
    sort(values, values + numValues, greater<long long>());
    
    for (int i = 0; i < numValues; ++i)
    { 
        
        
        result += values[i] * subMatrixCounts[i];


        
    }
    
    cout << result << endl;
    



    }
    


     return 0;    
}
