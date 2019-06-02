#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <cstring>

using namespace std;

int t[262145];

int main() {
    
    int n, m;
    cin >> n >> m;
    n = (1 << n);
    
    for (int i = 0; i < n; ++i) {
        cin >> t[i + n];
    }

    int ll = log2(n);
    for (int i = n - 1; i > 0; --i) {
        int l = log2(i);
        if ( (ll - l) % 2 == 1) {
            t[i] = t[2 * i] | t[2 * i + 1];
        }
        else {
            t[i] = t[2 * i] ^ t[2 * i + 1];
        }
    }


    for (int i = 0; i < m; ++i) {
        int p, b;
        cin >> p >> b;

        int j = n + p - 1;
        t[j] = b;
        j /= 2;
        while (j > 0) {
            if ( (ll - (int)log2(j)) % 2 == 1) {
                t[j] = t[2 * j] | t[2 * j + 1];
            }
            else {
                t[j] = t[2 * j] ^ t[2 * j + 1];
            }
            j /= 2;
        }

        cout << t[1] << endl;
    }

    return 0;
}
