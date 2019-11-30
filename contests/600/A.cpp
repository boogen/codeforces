#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <unordered_map>
#include <set>
#include <queue>
 
#define ulong unsigned long long
 
using namespace std;


int a[100000 + 1];
int b[100000 + 1];


int main() {
    int t;
    cin >> t;

    for (int tt = 0; tt < t; tt++) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }


        vector<int> d;
        int k = 0;
        for (int i = 0; i < n; ++i) {
            
            if (b[i] - a[i] != k) {
                k = b[i] - a[i];
                if (k != 0) 
                    d.push_back(k);

            }
        }
        if (d.size() == 0) {
            cout << "YES" << endl;
        }
        else if (d.size() > 1) {
            cout << "NO" << endl;
        }
        else if (d[0] <= 0) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }

        
        
    }
}
