
#include <bits/stdc++.h>
using namespace std;

long long SpecialSum(int N, int M, vector<int> A, vector<int> B, vector<int> K) {
    long long sum = 0;
    for (int i = 0; i < N; ++i) {
        int left = max(1, i + 1 - K[i]) - 1;  
        int right = min(M, i + 1 + K[i]) - 1;  
        int max_b = INT_MIN;
        for (int j = left; j <= right; ++j) {
            if (B[j] > max_b) {
                max_b = B[j];
            }
        }
        sum += (long long)A[i] * max_b;
    }
    return sum;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        vector<int> B(M);
        for (int i = 0; i < M; ++i) {
            cin >> B[i];
        }
        vector<int> K(N);
        for (int i = 0; i < N; ++i) {
            cin >> K[i];
        }
        cout << SpecialSum(N, M, A, B, K) << endl;
    }
    return 0;
}