#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <set>
 
#define ulong unsigned long long
 
using namespace std;


int main() {
    int n;
    cin >> n;
    double res = 0;
    for (int i = 1; i <= n; ++i) {
        res += 1.0 / (double)i;
    }

    cout << res << endl;
}
