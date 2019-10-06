#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <unordered_map>
 
#define ulong unsigned long long
 
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int c = a % b;
        a = b;
        b = c;
    }

    return a;
}


int a[1000000];
int t[4 * 100000 + 1];
int c[4 * 100000 + 1];
int n;

void build(int id, int l, int r) {
    if (r - l < 2) {
        t[id] = a[l];
        c[id] = 1;
        return;
    }

    int mid = (l + r) / 2;

    build(2 * id, l, mid);
    build(2 * id + 1, mid, r);
    int d = gcd(t[2 * id], t[2 * id + 1]);
    c[id] = 0;
    if (d == t[2 * id])
        c[id] += c[2 * id];
    if (d == t[2 * id + 1]) 
        c[id] += c[2 * id + 1];

    t[id] = d;
}

pair<int, int> query(int x, int y, int id, int l, int r) {
    if (x >= r || y <= l) {
        return make_pair(0, 0);
    }

    if (x <= l && r <= y) {
        return make_pair(t[id], c[id]);
    }

    int mid = (l + r) / 2;
    pair<int, int> ld = query(x, y, 2 * id, l, mid);
    pair<int, int> rd = query(x, y, 2 * id + 1, mid, r);

    pair<int, int> res;
    res.first = gcd(max(ld.first, rd.first), min(ld.first, rd.first));
    res.second = 0;
    if (res.first == ld.first) 
        res.second += ld.second;
    if (res.first == rd.first)
        res.second += rd.second;

    return res;
}

int main() {

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    build(1, 0, n);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int l, r;
        cin >> l >> r;
        l -= 1;
        pair<int, int> q = query(l, r, 1, 0, n);
        int c = 0;
        cout << (r - l) - q.second << endl;
    }
    return 0;
}
