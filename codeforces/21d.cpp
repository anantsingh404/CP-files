#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin>>t;
    while(t--)
    {
        int total, maxSum;
        cin >> total >> maxSum; 
        
        long long int count = 0;

        int side1 = 1;
        
        while (side1 <= maxSum) 
        {
            int mini=min(maxSum-side1,total/side1);


            int maxSide2 = mini;
            int side2 = 1;
            
            while (side2 <= maxSide2) 
            {   
                
                int temp=min(maxSum - side1 - side2, (total - side1 * side2) / (side1 + side2));
                int maxSide3 = temp;
                count += max(0, maxSide3);
                ++side2;

                
            }
            
            ++side1;
        }

        cout <<count<<endl;
 
      }
return 0;    
}
