#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <set>
#include <iostream> 

#define ulong unsigned long long
 
using namespace std;


int main() {

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc) {
        int a[100001];
        int p[100001];
        memset(p, 0, sizeof(p));
        int n;
        cin >> n;

        set<int> b;
        a[0] = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            b.insert(i);
        }

        for (int i = 1; i <= n; ++i) {
            if (a[i] != a[i - 1]) {
                b.erase(a[i]);
                p[i] = a[i];
            }
        }

        bool possible = true;
        set<int>::iterator it = b.begin();
        for (int i = 1; i <= n; ++i) {
            if (p[i] == 0) {
                if (it == b.end()) {
                    possible = false;
                    break;
                }
                int m = (*it);
                if (m > a[i]) {
                    possible = false;
                    break;
                }

                p[i] = m;
                it++;
            }
        }

        if (possible) {
            for (int i = 1; i <= n; ++i) {
                printf("%d ", p[i]);
            }
            cout << endl;
        }
        else {
            cout << "-1" << endl;
        }
    }
}
