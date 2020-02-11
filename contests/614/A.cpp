#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <set>
 
#define ulong unsigned long long
 
using namespace std;


int main() {

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc) {
        int n, s, k;
        cin >> n >> s >> k;
        set<int> closed;
        for (int i = 0; i < k; ++i) {
            int f;
            cin >> f;
            closed.insert(f);
        }

        for (int i = 0; i < 1002; ++i) {
            int f1 = s + i;
            int f2 = s - i;
            if (f1 <= n && closed.find(f1) == closed.end()) {
                cout << i << endl;
                break;
            }
            if (f2 > 0 && closed.find(f2) == closed.end()) {
                cout << i << endl;
                break;
            }
        }
    }
}
