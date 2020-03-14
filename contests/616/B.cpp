#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <set>
 
#define ulong unsigned long long
#define ll long long
 
using namespace std;

int d[400000];


void solve(int n) {

    int i = 0;
    while (i < n && d[i] >= i) {
        i++;
    }
    --i;
    while (i < n && d[i] >= (n - i - 1)) {
        i++;
    }
    if (i < n) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
    }
    
}

int main() {
    int t;
    cin >> t;

    for (int tc = 0; tc < t; ++tc) {
        int n;
        cin >> n;

        for (int i = 0; i < n; ++i) {
            cin >> d[i];
        }

        solve(n);
    }
}
