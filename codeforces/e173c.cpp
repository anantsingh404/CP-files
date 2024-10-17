#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mod=1e9+7;





int compute(int num)
{
    int ans=1;
    int temp=2;
    while(num>0)
    {
        if(num%2==1)
        {
           ans=(1ll*ans*temp)%mod;
        }
        temp=(1ll*temp*temp)%mod;
        num=num/2;
    }
    return ans;

}

int main() {
   
    //Trie trie;
    //dsu dset(n);
    //vector<int> lps = computeLPS(string);
    //SegmentTree segTree(array);
   
     int t;
    cin>>t;
    
        vector<int>dp1(t);
        vector<int>dp2(t);
        for(int i=0;i<t;i++)
        {
            cin>>dp1[i];
        }
        for(int i=0;i<t;i++)
        {
            cin>>dp2[i];
        }
        int i=0;
        while(i<t)
        {   int x=compute(dp2[i]);
            cout<<x<<endl;
            i++;
        }


    
}
