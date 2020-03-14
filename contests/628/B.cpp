#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <set>
 
#define ulong unsigned long long
#define ll long long
 
using namespace std;


int main() {
    int tc;
    cin >> tc;
    while (tc-- > 0) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());
        int cnt = 1;
        for (int i = 1; i < n; ++i) {
            if (a[i] > a[i - 1]) { 
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}
