#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
 
#define ll long long
#define ulong unsigned long long
 
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, m;
        cin >> n >> m;

        cout << "W";
        int j = 1;
        for (int i = 0; i < n; ++i) {
            for (; j < m; ++j) {
                cout << "B";
            }
            cout << "\n";
            j = 0;
        }
    }
}
