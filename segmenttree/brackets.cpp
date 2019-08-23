#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <unordered_map>
 
#define ulong unsigned long long
 
using namespace std;
 
int o[2 * 1048576 + 1];
int c[2 * 1048576 + 1];
int t[2 * 1048576 + 1];

 
int n;
string line;

void build(int id, int l, int r ) {
    if (r - l < 2) {
        if (line.at(l) == '(')
            o[id] = 1;
        if (line.at(l) == ')')
            c[id] = 1;
        return;
    }

    int mid = (l + r) / 2;

    build(2 * id, l, mid);
    build(2 * id + 1, mid, r);
    int tmp = min(o[2 * id], c[2 * id + 1]);
    o[id] = o[2 * id] + o[2 * id + 1] - tmp;
    c[id] = c[2 * id] + c[2 * id + 1] - tmp;
    t[id] = t[2 * id] + t[2 * id + 1] + 2 * tmp;

    
    
}

pair<pair<int, int>, int> query(int x, int y, int id, int l, int r) {
    if (x >= r || y <= l)
        return make_pair(make_pair(0, 0), 0);

    if (x <= l && r <= y) 
        return make_pair(make_pair(o[id], c[id]), t[id]);

    int mid = (l + r) / 2;
    pair<pair<int, int>, int> lt = query(x, y, 2 * id, l, mid);
    pair<pair<int, int>, int> rt = query(x, y, 2 * id + 1, mid, r);
    

    int tmp = min(lt.first.first, rt.first.second);
    int op = lt.first.first + rt.first.first - tmp;
    int cl = lt.first.second + rt.first.second - tmp;
    int tl = lt.second + rt.second + 2 * tmp;

    return make_pair(make_pair(op, cl), tl);
}
 
 
int main() {
    memset(o, 0, sizeof(o));
    memset(c, 0, sizeof(c));
    memset(t, 0, sizeof(t));
 
    getline(cin, line);
    n = line.length() ;
 
    build(1, 0, n);
 
    int m;
    cin >> m;
 
 
    for (int i = 0; i < m; ++i) {
    	int r, l;
    	cin >> l >> r;
    	l -= 1;
 
		cout << query(l, r, 1, 0, n).second << endl;
    }
}
