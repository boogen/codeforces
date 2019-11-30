#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <unordered_map>
 
#define ulong unsigned long long
 
using namespace std;


int main() {

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc) {
        int small_r = 1000000001;
        int great_l = 0;
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int l, r;
            cin >> l >> r;
            if (r < small_r)
                small_r = r;
            if (l > great_l)
                great_l = l;
        }

        if (small_r > great_l)
            cout << "0" << endl;
        else 
            cout << (great_l - small_r) << endl;
    }
}
