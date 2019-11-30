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
int b[4000001];
int f[4000001];
 
int n, m;
 
 
inline int getid(int x, int y) {
    return x * (m + 2) + y;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
    cin >> n >> m;
    
 
    string line;
 
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char c;
            cin >> c;
            if (c == 'X')
                p[getid(i, j)] = 1;
        }
    }

    for (int i = 0; i <= n + 1; ++i) 
        for (int j = 1; j <= m + 1; ++j)
            t[getid(i, j)] = p[getid(i, j)] + t[getid(i, j - 1)];

    for (int j = 0; j <= m + 1; ++j)
        for (int i = 1; i <= n + 1; ++i)
            t[getid(i, j)] += t[getid(i - 1, j)];

    

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (p[getid(i, j)] == 1) {
                int d = min(min(i - 1, n - i), min(j - 1, m - j));

                int l = 0;
                int r = d + 1;
                while (r - l > 1) {
                    int mid = (r + l) / 2;

                    int count = t[getid(i + mid, j + mid)] - t[getid(i + mid, j - mid -1)] - t[getid(i - mid - 1, j + mid)] + t[getid(i - mid - 1, j - mid - 1)];
                    int side = 2 * mid + 1;
                    if (count == side * side)
                        l = mid;
                    else
                        r = mid;
                }
                b[getid(i, j)] = l;
            }
        }
    }


    int l = 0;
    int r = min(n, m);
    while (r - l > 1) {
        memset(f, 0, sizeof(f));
        int mid = (l + r) / 2;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (b[getid(i, j)] >= mid) {
                    f[getid(i - mid, j - mid)]++;
                    f[getid(i + mid + 1, j - mid)]--;
                    f[getid(i - mid, j + mid + 1)]--;
                    f[getid(i + mid + 1, j + mid + 1)]++;
                    
                }
            }
        }

        for (int i = 0; i <= n + 1; ++i)
            for (int j = 1; j <= m + 1; ++j)
                f[getid(i, j)] += f[getid(i, j - 1)];

        for (int j = 0; j <= m + 1; ++j)
            for (int i = 1; i <= n + 1; ++i)
                f[getid(i, j)] += f[getid(i - 1, j)];


        bool result = true;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (p[getid(i, j)] == 1 && f[getid(i, j)] <= 0)
                    result = false;

        if (result)
            l = mid;
        else
            r = mid;
    }
    
    cout << l << endl;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (p[getid(i, j)] == 1 && b[getid(i, j)] >= l)
                cout << "X";
            else
                cout << ".";
        }
        cout << endl;
            
    }
    
}
