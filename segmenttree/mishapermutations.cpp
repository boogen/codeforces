#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <unordered_map>
 
#define ulong unsigned long long
 
using namespace std;

int a[200001];
int b[200001];
int c[200001];

int t1[2 * 200000 + 1];
int t2[2 * 200000 + 1];
int t[4 * 200000 + 1];

int n;


void build(int id, int l, int r) {
    if (r - l < 2) {
        t[id] = 1;
        return;
    }

    int mid = (l + r) / 2;
    
    build(2 * id, l, mid);
    build(2 * id + 1, mid, r);

    t[id] = t[2 * id] + t[2 * id + 1];
}


void remove(int x, int id, int l, int r) {
    if (x < l || x >= r)
        return;
    if (r - l < 2 && l == x) {
        t[id] = 0;
        return;
    }

    int mid = (l + r) / 2;
    remove(x, 2 * id, l, mid);
    remove(x, 2 * id + 1, mid, r);

    t[id] = t[2 * id] + t[2 * id + 1];
}


int find(int x, int id, int l, int r) {
    if (x == 1 && r - l < 2 && t[id] == 1) {
        return l;
    }
    if (r - l < 2) {
        return -1;
    }

    int mid = (l + r) / 2;


    if (x <= t[2 * id]) {
        return find(x, 2 * id, l, mid);
    }
    else {
        return find(x - t[2 * id], 2 * id + 1, mid, r);
    }
}


void modify(int p, int t[]) {
    for (t[p += n] += 1; p > 1; p >>= 1)  t[p>>1] += 1;
}


int query(int l, int r, int t[]) {
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res += t[l++];
        if (r&1) res += t[--r];
    }

    return res;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];


    for (int i = 0; i < n; ++i) {
        int smaller = query(0, a[i], t1);
        modify(a[i], t1);

        a[i] = a[i] - smaller;
    }

    for (int i = 0; i < n; ++i) {
        int smaller = query(0, b[i], t2);
        modify(b[i], t2);

        b[i] = b[i] - smaller;
    }

    int rest = 0;
    for (int i = n - 1; i >= 0; --i) {
        c[i] = (a[i] + b[i] + rest) % (n - i);
        rest = (a[i] + b[i] + rest) >= (n - i) ? 1 : 0;
    }
   
    build(1, 0, n);

    for (int i = 0; i < n; ++i) {
        int x = find(c[i] + 1, 1, 0, n);
        cout << x << " ";
        remove(x, 1, 0, n);
    }
    cout << endl;

        
}
