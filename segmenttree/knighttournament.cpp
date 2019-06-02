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


pair<int, int> t[1048577];
int n, m;

void update(int l, int r, int x, int fight) {
    for (l += n - 1, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
            t[l] = make_pair(fight, x);
            l++;
        }
        if (r & 1) {
            r--;
            t[r] = make_pair(fight, x);
        }
    }
    
}

int main() {
    cin >> n >> m;


    for (int i = 0; i < 2 * n + 1; ++i) {
        t[i] = make_pair(m + 1, 0);
    }


    vector<pair<pair<int, int>, int> > input;
    
    for (int i = 0; i < m; ++i) {
        int l, r, x;

        cin >> l >> r >> x;
        input.push_back(make_pair(make_pair(l, r), x));
    } 

    for (int i = m - 1; i >= 0; --i) {
        int l = input[i].first.first;
        int r = input[i].first.second;
        int x = input[i].second;

        
        update(l, x - 1, x, i);
        update(x + 1, r, x, i);
    }

    for (int i = 0; i < n; ++i) {
        int x = i + n;
        pair<int, int> m = t[x];

        while (x > 0) {
            x >>= 1;
            m = min(m, t[x]);
        }

        cout << m.second << " ";
    }

    cout << endl;

}
