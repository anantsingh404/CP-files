#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pqmin priority_queue<int, vector<int>, greater<int>>
#define pqmax priority_queue<int>
const int mod = 1e10;

long long custom_pow(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result *= base;
            if (result > 1e9) {
                return 1e10;
            }
        }
        base *= base;
        if (base > 1e9) {
            return 1e10;
        }
        exp /= 2;
    }
    return result;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        int64 num_elements, lower_bound, upper_bound;
        cin >> num_elements >> lower_bound >> upper_bound;

        vector<int64> elements(num_elements);
        for (auto &element : elements) {
            cin >> element;
        }

        sort(elements.begin(), elements.end());
        bool b = false;
          
        for (int i = 1; i < num_elements; i++) {
            if (elements[i] == elements[i - 1]) {
                b = true;
                break;
            }
        }

        if (b) {
            if (lower_bound <= 0 && 0 <= upper_bound) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            if (num_elements >= 13) {
                cout << "NO\n";
            } else {
                bool exceeded_limit = false;
                int64 product = 1;

                for (int i = 0; i < num_elements && !exceeded_limit; i++) {
                    for (int j = i + 1; j < num_elements && !exceeded_limit; j++) {
                        int64 temp_product = elements[i] ^ elements[j];

                        if (temp_product == 0) {
                            product = 0;
                            break;
                        }

                        if (product > upper_bound / temp_product) {
                            exceeded_limit = true;
                            break;
                        }

                        product *= temp_product;
                    }
                }

                if (exceeded_limit && product >= lower_bound && product <= upper_bound) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
            }
        }
    }

    return 0;
}