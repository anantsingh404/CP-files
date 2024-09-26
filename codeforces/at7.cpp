#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;
int check(int x)
{    if(x==0)
{
    return 1;
}
    int a=check(x/2);
    if(x%2)
    {
        return 3*a*a;
    }
    return a*a;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   int m;
   cin>>m;
   vector<int>ans;
   int count=0;
   int n=20;

   for(int i=0;i<=10;i++)
   {
    if(check(i)==m)
    {
        ++count;
        ans.push_back(i);
    }
   }
    
return 0;    
}
