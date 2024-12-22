#include <bits/stdc++.h>
using namespace std;


long long arr[4]={-1,1,0,0};
long long brr[4]={0,0,-1,1};



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //Trie trie;
    //dsu dset(n);
    //vector<long long> lps = computeLPS(string);
    //SegmentTree segTree(array);
    long long n,m,yy;
    cin>>n>>m>>yy;
    long long p,q;
    cin>>p>>q;
    vector<vector<long long>>dp(n,vector<long long>(m,0));
    for(long long i=0;i<n;i++)
    {
        for(long long j=0;j<m;j++)
        {
            cin>>dp[i][j];
        }
    }
    --p;
    --q;
    long long sum=dp[p][q];
    queue<tuple<long long ,long long,long long>>pq;
    pq.push({dp[p][q],p,q});
    vector<vector<long long>>vis(n,vector<long long>(m,-1));
    vis[p][q]=1;
    while(!pq.empty())
    {
         long long k=pq.size();
         long long cc=0;
         for(long long i=0;i<k;i++)
         {    pair<long long,long long>p=pq.front();
              for(long long j=0;j<4;j++)
              {
                long long x=p.first+arr[j];
                long long y=p.second+brr[j];
                if(x>=0 && x<n && y>=0 && y<m && vis[x][y]==-1 && dp[x][y]*yy<sum)
                {
                    sum+=dp[x][y];
                    vis[x][y]=1;
                    ++cc;
                    pq.push({x,y});
                }
              }
            //  cout<<sum<<endl;
             pq.pop();
            pq.push(p);
         }
         if(cc==0)
         {
            break;
         }

    }
    cout<<sum<<endl;


    


    
    return 0;    
}
