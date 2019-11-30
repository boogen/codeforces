#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <unordered_map>
#include <set>
#include <queue>
#include <map>
#include <stack>
 
#define llong long long
#define ulong unsigned long long
 
using namespace std;
 
 
int p[4000001];
int t[4000001];
int f[4000001];
 
int n, m;
 
 
inline int getid(int x, int y) {
    return x * (m + 2) + y;
}
 
 
bool solve(int d) {
 
    memset(f, 0, sizeof(int) * (m + 2) * (n + 2));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i + d <= n && j + d <= m && i - d - 1 >= 0 && j - d - 1 >= 0 && p[getid(i, j)] == 0) {
                if ( (t[getid(i + d, j + d)] - t[getid(i + d, j - d - 1)] - t[getid(i - d - 1, j + d)] + t[getid(i - d - 1, j - d - 1)]) == 0) {
                    f[getid(i - d, j - d)]++;
                    f[getid(i + d + 1, j - d)]--;
                    f[getid(i - d, j + d + 1)]--;
                    f[getid(i + d + 1, j + d + 1)]++;
                }
            }
        }
    }
 
 
    for (int i = 1; i <= n + 1; ++i) 
        f[getid(i, 0)] += f[getid(i - 1, 0)];
    for (int j = 1; j <= m + 1; ++j)
        f[getid(0, j)] += f[getid(0, j - 1)];
 
    for (int i = 1; i <= n + 1; ++i) {
        for (int j = 1; j <= m + 1; ++j) {
            f[getid(i, j)] += f[getid(i - 1, j)] + f[getid(i, j - 1)] - f[getid(i - 1, j - 1)];
        }
    }
 
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= m; ++j)
            if (p[getid(i, j)] == 0 && f[getid(i, j)] <= 0)
                return false;
 
    return true;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
    cin >> n >> m;
    
 
    string line;
 
    for (int i = 0; i < n + 2; ++i)
        for (int j = 0; j < m + 2; ++j) 
            p[getid(i, j)] = 1;
 
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char c;
            cin >> c;
            if (c == 'X')
                p[getid(i, j)] = 0;
        }
    }
 
    t[0] = p[0];
    for (int i = 1; i <= n + 1; ++i) 
        t[getid(i, 0)] = p[getid(i, 0)] + t[getid(i - 1, 0)];
    for (int j = 1; j <= m + 1; ++j)
        t[getid(0, j)] = p[getid(0, j)] + t[getid(0, j - 1)];
 
 
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) 
            t[getid(i, j)] = p[getid(i, j)] + t[getid(i - 1, j)] + t[getid(i, j - 1)] - t[getid(i - 1, j - 1)];
 
 
    int l = 0;
    int r = (min(n, m) - 1) / 2 + 1;
 
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (solve(mid)) {
            l = mid;
        }
        else {
            r = mid;
        }
    }                                
 
    int d = l;
    cout << d << endl;
 
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i + d <= n && j + d <= m && i - d - 1 >= 0 && j - d - 1 >= 0 && p[getid(i, j)] == 0) {
                if ( (t[getid(i + d, j + d)] - t[getid(i + d, j - d - 1)] - t[getid(i - d - 1, j + d)] + t[getid(i - d - 1, j - d - 1)]) == 0) {
                    cout << 'X';
                }
                else 
                    cout << '.';
            }
            else
                cout << '.';
        }
        cout << endl;
    }
}
