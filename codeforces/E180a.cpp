#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define llm LLONG_MAX
#define lln LLONG_MIN
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()
#define pqmin priority_queue<int, vector<int>, greater<int>>
#define pqmax priority_queue<int>
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// Constants
const int inf = 1e9;
const ll linf = 1e18;

// Debugging
#define debug(x) cerr << #x << " = " << x << endl;
#define debug_vec(v) cerr << #v << " = "; for (auto x : v) cerr << x << " "; cerr << endl;

// Directions for grid traversal
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

// Utility Functions
template <typename T>
void printVec(const vector<T>& v) {
    for (const auto& x : v) cout << x << " ";
    cout << endl;
}

template <typename T>
void printMatrix(const vector<vector<T>>& mat) {
    for (const auto& row : mat) {
        for (const auto& x : row) cout << x << " ";
        cout << endl;
    }
}




//String Algorithms:

// Knuth-Morris-Pratt (KMP) Algorithm
// Usage: Efficiently finds all occurrences of a pattern in a text using the LPS array.
// Example: String searching, pattern matching, etc.
// Time Complexity: O(N + M), where N is the length of the text and M is the length of the pattern.
// Space Complexity: O(M), for the LPS array.

vector<int> computeLPS(string pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0); // LPS array
    int len = 0; // Length of the previous longest prefix suffix
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1]; // Fall back to the previous prefix
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

void KMP(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> lps = computeLPS(pattern);

    int i = 0; // Index for text
    int j = 0; // Index for pattern

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1]; // Continue searching for other occurrences
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1]; // Fall back in the pattern
            } else {
                i++;
            }
        }
    }
}
// Z-Algorithm
// Usage: Finds all occurrences of a pattern in a text by computing the Z-array.
// Example: String searching, pattern matching, etc.
// Time Complexity: O(N + M), where N is the length of the text and M is the length of the pattern.
// Space Complexity: O(N + M), for the concatenated string and Z-array.

vector<int> computeZ(string s) {
    int n = s.length();
    vector<int> Z(n, 0);
    int l = 0, r = 0;

    for (int i = 1; i < n; i++) {
        if (i <= r) {
            Z[i] = min(r - i + 1, Z[i - l]);
        }
        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) {
            Z[i]++;
        }
        if (i + Z[i] - 1 > r) {
            l = i;
            r = i + Z[i] - 1;
        }
    }

    return Z;
}

void ZAlgorithm(string text, string pattern) {
    string concat = pattern + "$" + text; // Concatenate pattern, delimiter, and text
    vector<int> Z = computeZ(concat);
    int m = pattern.length();

    for (int i = m + 1; i < Z.size(); i++) {
        if (Z[i] == m) {
            cout << "Pattern found at index " << i - m - 1 << endl;
        }
    }
}
// Suffix Array and LCP Array
// Usage: Used for efficient string matching, finding the longest repeated substring, and solving other string-related problems.
// Example: DNA sequencing, text indexing, etc.
// Time Complexity: 
// - Suffix Array Construction: O(N * log(N)), where N is the length of the string.
// - LCP Array Construction: O(N).
// Space Complexity: O(N), for the suffix array and LCP array.

vector<int> buildSuffixArray(string s) {
    s += "$"; // Append a unique character to ensure all suffixes are distinct
    int n = s.size();
    vector<int> suffixArray(n), rank(n), tempRank(n);

    // Initial ranking based on the first character
    for (int i = 0; i < n; i++) {
        suffixArray[i] = i;
        rank[i] = s[i];
    }

    for (int k = 1; k < n; k *= 2) {
        auto compare = [&](int i, int j) {
            if (rank[i] != rank[j]) return rank[i] < rank[j];
            int ri = (i + k < n) ? rank[i + k] : -1;
            int rj = (j + k < n) ? rank[j + k] : -1;
            return ri < rj;
        };

        sort(suffixArray.begin(), suffixArray.end(), compare);

        tempRank[suffixArray[0]] = 0;
        for (int i = 1; i < n; i++) {
            tempRank[suffixArray[i]] = tempRank[suffixArray[i - 1]] + compare(suffixArray[i - 1], suffixArray[i]);
        }
        rank = tempRank;
    }

    return suffixArray;
}

vector<int> buildLCPArray(string s, vector<int> &suffixArray) {
    int n = s.size();
    vector<int> rank(n), lcp(n, 0);

    for (int i = 0; i < n; i++) {
        rank[suffixArray[i]] = i;
    }

    int h = 0;
    for (int i = 0; i < n; i++) {
        if (rank[i] > 0) {
            int j = suffixArray[rank[i] - 1];
            while (i + h < n && j + h < n && s[i + h] == s[j + h]) {
                h++;
            }
            lcp[rank[i]] = h;
            if (h > 0) h--;
        }
    }

    return lcp;
}

//Dynamic Programming:

// Longest Increasing Subsequence (LIS)
// Usage: Finds the length of the longest subsequence in an array such that all elements of the subsequence are sorted in increasing order.
// Example: Sequence analysis, dynamic programming problems, etc.
// Time Complexity: O(N * log(N)), where N is the size of the array.
// Space Complexity: O(N), for the LIS array.

int LIS(vector<int>& nums) {
    vector<int> lis; // Stores the smallest ending element of increasing subsequences of different lengths

    for (int num : nums) {
        auto it = lower_bound(lis.begin(), lis.end(), num); // Find the position to replace or extend
        if (it == lis.end()) {
            lis.push_back(num); // Extend the LIS
        } else {
            *it = num; // Replace to maintain the smallest possible value
        }
    }

    return lis.size(); // The size of the LIS array is the length of the LIS
}
// Matrix Chain Multiplication
// Usage: Finds the minimum number of scalar multiplications needed to multiply a sequence of matrices.
// Example: Dynamic programming problems, optimization problems, etc.
// Time Complexity: O(N^3), where N is the number of matrices.
// Space Complexity: O(N^2), for the DP table.

int matrixChainMultiplication(vector<int>& dims) {
    int n = dims.size() - 1; // Number of matrices
    vector<vector<int>> dp(n, vector<int>(n, 0)); // DP table to store minimum costs

    // Length of the chain
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            // Try all possible splits
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dims[i] * dims[k + 1] * dims[j + 1];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[0][n - 1]; // Minimum cost to multiply matrices from 0 to n-1
}   

// 0/1 Knapsack Problem
// Usage: Finds the maximum value that can be obtained by selecting items with given weights and values, subject to a weight limit.
// Example: Resource allocation, optimization problems, etc.
// Time Complexity: O(N * W), where N is the number of items and W is the weight capacity.
// Space Complexity: O(W), for the DP array.

int knapsack01(vector<int>& weights, vector<int>& values, int W) {
    int n = weights.size();
    vector<int> dp(W + 1, 0); // DP array to store maximum values for each weight

    for (int i = 0; i < n; i++) {
        for (int w = W; w >= weights[i]; w--) {
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }

    return dp[W]; // Maximum value for weight capacity W
}

// Unbounded Knapsack Problem
// Usage: Finds the maximum value that can be obtained by selecting items with given weights and values, with unlimited repetitions allowed.
// Example: Resource allocation, optimization problems, etc.
// Time Complexity: O(N * W), where N is the number of items and W is the weight capacity.
// Space Complexity: O(W), for the DP array.

int unboundedKnapsack(vector<int>& weights, vector<int>& values, int W) {
    int n = weights.size();
    vector<int> dp(W + 1, 0); // DP array to store maximum values for each weight

    for (int i = 0; i < n; i++) {
        for (int w = weights[i]; w <= W; w++) {
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }

    return dp[W]; // Maximum value for weight capacity W
}
// Subset Sum Problem
// Usage: Determines if there exists a subset of the given set with a sum equal to a given target.
// Example: Partition problems, dynamic programming problems, etc.
// Time Complexity: O(N * S), where N is the number of elements and S is the target sum.
// Space Complexity: O(S), for the DP array.

bool subsetSum(vector<int>& nums, int target) {
    vector<bool> dp(target + 1, false); // DP array to store if a sum is possible
    dp[0] = true; // Base case: A sum of 0 is always possible

    for (int num : nums) {
        for (int sum = target; sum >= num; sum--) {
            dp[sum] = dp[sum] || dp[sum - num]; // Corrected variable name
        }
    }

    return dp[target]; // Return true if the target sum is possible
}
// Longest Common Subsequence (LCS)
// Usage: Finds the length of the longest subsequence common to two strings.
// Example: Text comparison, DNA sequence alignment, etc.
// Time Complexity: O(N * M), where N and M are the lengths of the two strings.
// Space Complexity: O(N * M), for the DP table.

int LCS(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // DP table

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1; // Characters match
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // Take the maximum
            }
        }
    }

    return dp[n][m]; // Length of the LCS
}

// Edit Distance (Levenshtein Distance)
// Usage: Finds the minimum number of operations (insertions, deletions, substitutions) required to convert one string into another.
// Example: Spell checking, DNA sequence alignment, etc.
// Time Complexity: O(N * M), where N and M are the lengths of the two strings.
// Space Complexity: O(N * M), for the DP table.

int editDistance(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // DP table

    // Initialize base cases
    for (int i = 0; i <= n; i++) dp[i][0] = i; // Deleting all characters from s1
    for (int j = 0; j <= m; j++) dp[0][j] = j; // Inserting all characters into s1

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // Characters match, no operation needed
            } else {
                dp[i][j] = 1 + min({dp[i - 1][j],    // Deletion
                                    dp[i][j - 1],    // Insertion
                                    dp[i - 1][j - 1] // Substitution
                                   });
            }
        }
    }

    return dp[n][m]; // Minimum edit distance
}

//Number Theory:

// Sieve of Eratosthenes
// Usage: Efficiently generates all prime numbers up to a given limit.
// Example: Prime number generation, number theory problems, etc.
// Time Complexity: O(N * log(log(N))), where N is the limit.
// Space Complexity: O(N), for the boolean array.

vector<int> sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true); // Boolean array to mark primes
    isPrime[0] = isPrime[1] = false;  // 0 and 1 are not prime numbers

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false; // Mark multiples of i as non-prime
            }
        }
    }

    // Collect all prime numbers
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}
// Modular Exponentiation
// Usage: Computes (base^exponent) % mod efficiently using the method of exponentiation by squaring.
// Example: Cryptography, modular arithmetic problems, etc.
// Time Complexity: O(log(exponent)).
// Space Complexity: O(1).

long long modularExponentiations(long long base, long long exponent) {
    long long result = 1; // Initialize result
    base = base % mod;    // Ensure base is within mod

    while (exponent > 0) {
        // If the current exponent bit is set, multiply the result by the base
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }

        // Square the base and reduce the exponent by half
        base = (base * base) % mod;
        exponent /= 2;
    }

    return result;
}

// Greatest Common Divisor (GCD) and Least Common Multiple (LCM)
// Usage: Computes the GCD and LCM of two numbers using the Euclidean algorithm.
// Example: Number theory problems, fraction simplification, etc.
// Time Complexity: O(log(min(A, B))), where A and B are the input numbers.
// Space Complexity: O(1).

// Function to compute GCD using the Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute LCM using the relationship: LCM(a, b) = (a * b) / GCD(a, b)
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b; // Avoids overflow by dividing first
}

// Extended Euclidean Algorithm
// Usage: Computes the GCD of two numbers and finds coefficients x and y such that ax + by = gcd(a, b).
// Example: Modular inverses, solving linear Diophantine equations, etc.
// Time Complexity: O(log(min(a, b))).
// Space Complexity: O(1).

int extendedGCD(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a; // GCD is a when b is 0
    }

    int x1, y1;
    int gcd = extendedGCD(b, a % b, x1, y1);

    // Update x and y using results of recursion
    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}

// Chinese Remainder Theorem (CRT)
// Usage: Solves a system of simultaneous congruences using the Chinese Remainder Theorem.
// Example: Modular arithmetic problems, cryptography, etc.
// Time Complexity: O(N), where N is the number of congruences.
// Space Complexity: O(1).

// Function to compute modular inverse using the Extended Euclidean Algorithm
int modularInverse(int a, int m) {
    int x, y;
    int g = extendedGCD(a, m, x, y);
    if (g != 1) {
        throw invalid_argument("Modular inverse does not exist");
    }
    return (x % m + m) % m;
}

// Function to solve a system of congruences using CRT
int chineseRemainderTheorem(vector<int>& nums, vector<int>& rems) {
    int prod = 1; // Product of all moduli
    int n = nums.size();

    for (int num : nums) {
        prod *= num;
    }

    int result = 0;

    for (int i = 0; i < n; i++) {
        int pp = prod / nums[i]; // Partial product
        result += rems[i] * modularInverse(pp, nums[i]) * pp;
        result %= prod;
    }

    return (result + prod) % prod; // Ensure the result is non-negative
}
// Fermat's Little Theorem (for modular inverses)
// Usage: Computes the modular inverse of a number modulo a prime using Fermat's Little Theorem.
// Example: Modular arithmetic problems, cryptography, etc.
// Time Complexity: O(log(mod - 1)), where mod is the prime modulus.
// Space Complexity: O(1).


// Modular Exponentiation (helper function)
// Computes (base^exponent) % mod efficiently using exponentiation by squaring.
long long modularExponentiation(long long base, long long exponent) {
    long long result = 1;
    base = base % mod;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exponent /= 2;
    }

    return result;
}

long long modularInverseFermat(long long a) {
    // Fermat's Little Theorem: a^(mod-1) ≡ 1 (mod mod)
    // Modular inverse: a^(mod-2) ≡ a^(-1) (mod mod)
    return modularExponentiation(a, mod - 2);
}


//Main Function:

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t; 
    while (t--) 
    {
      int a,x,y;
      cin>>a>>x>>y;
      if((a<x && a<y) || (a>x && a>y)) {
          cout<<"Yes"<<endl;
      } else {
          cout<<"No"<<endl;
      }


    }

    return 0;
}
