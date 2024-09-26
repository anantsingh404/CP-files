
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //write your code here
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>m1(n);
        vector<int>m2(n);
        for(int i=0;i<n;i++)
        {
            cin>>m1[i];
        }
         for(int i=0;i<n;i++)
        {
            cin>>m2[i];
        }
        int sum1=0;
        int sum2=0;
        for(int i=0;i<n;i++)
        {   int maxi=max(m1[i],m2[i]);
            int x=sum1+maxi;
            int y=sum2+maxi;
            int p=min(x,sum2);
            int q=min(y,sum1);
            if(p<=q)
            {
               sum2=y; 
            }
            else{
                sum1=x;
            }
        }
        cout<<min(sum1,sum2)<<endl;
    }
    


return 0;    
}
