#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int ans = INT_MIN;
        stack<int> st;
        int i = 0;

        while (i < n) {
            if (st.empty() || arr[st.top()] <= arr[i]) {
                st.push(i++);
            } else {
                int top = st.top();
                st.pop();
                int height = arr[top];
                int width = st.empty() ? i : i - st.top();
                ans = max(ans, height * width);
            }
        }

        while (!st.empty()) {
            int top = st.top();
            st.pop();
            int height = arr[top];
            int width = st.empty() ? i : i - st.top() - 1;
            ans = max(ans, height * width);
        }

        cout << ans << endl;
    }

    return 0;
}
