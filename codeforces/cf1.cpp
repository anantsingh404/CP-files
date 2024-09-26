#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //write your code here
    int n;
    cin>>n;
    while(n--)
    {
        int x;
        int y;
        cin>>x;cin>>y;
        if(y<-1)
        {
            cout<<"NO";
        }
        else{
            cout<<"YES";
        }
        cout<<endl;
    }

return 0;    
}
