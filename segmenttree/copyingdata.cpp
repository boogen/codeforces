#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <unordered_map>
 
#define ulong unsigned long long
 
using namespace std;
int n, m;

int a[100001];
int b[100001];

int t[4 * 100000 + 1];
int ind[4 * 100000 + 1];

void build(int id, int l, int r) {
    if (r - l < 2) {
        t[id] = 0;
        ind[id] = l;
        return;
    }

    int mid = (l + r) / 2;
    
    build(2 * id, l, mid);
    build(2 * id + 1, mid, r);
    
    t[id] = 0;
    ind[id] = l;
}

void insert(int x, int y, int id, int l, int r, int a, int c) {
    if (x >= r || y <= l) {
        return;
    }

    if (x <= l && r <= y) {
        t[id] = c;
        ind[id] = (l - x) + a;
        return;
    }

    int mid = (l + r) / 2;
    insert(x, y, 2 * id, l, mid, a, c);
    insert(x, y, 2 * id + 1, mid, r, a, c);
}

int query(int p, int id, int l, int r, int c, int val) {
    if (t[id] > c) {

        c = t[id];
        val = a[(p - l) + ind[id]];
    }


    if (r - l < 2) {
        return val;
    }

    int mid = (l + r) / 2;
    if (p < mid)
        return query(p, 2 * id, l, mid, c, val);
    else
        return query(p, 2 * id + 1, mid, r, c, val);
}


int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i) 
        cin >> b[i];

    build(1, 0, n);

    for (int i = 1; i <= m; ++i) {
        int q;
        cin >> q;
        if (q == 2) {
            int j;
            cin >> j;
            cout << query(j - 1, 1, 0, n, 0, b[j - 1]) << endl;
        }
        else {

            int x, y, k;
            cin >> x >> y >> k;
            
            insert(y - 1, y - 1 + k, 1, 0, n, x - 1, i);
        }
    }
    
}
