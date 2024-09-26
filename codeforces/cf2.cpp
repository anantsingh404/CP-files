#include <bits/stdc++.h>
using namespace std;
bool solve(int n,string &x,string& y)
    {
        int i=0;
        int j=0;
        while(i<n && j<s2.size())
        {
             if(x[i]==y[j])
             {
                ++j;
             } 
             ++i;
        }
        return j==y.size();
    }
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //write your code here
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        cin>>a;
        cin>>b;
        int n=a.size();
        int m=b.size();
        int ans=n+m;
        for(int i=0;i<m;i++)
        { string temp;
          for(int j=i;j<m;j++)
          { temp.push_back(b[j]);
            int k=temp.size();
           
            if(solve(n,a,temp)){
               int x=n+m-k;
                ans=min(ans,x);
            }


          }

        }
        cout<<ans<<endl;
        

    }
    


return 0;    
}