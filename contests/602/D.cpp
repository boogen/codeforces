#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <set>
#include <iostream> 

#define ulong unsigned long long
 
using namespace std;


int b[200001];
pair<int, int> a[200001];
pair<int, pair<int, int> > q[200001]; 

int t[4 * 200000 + 1];

int result[200001];

void insert(int x, int id, int l, int r) {
    if (x < l || x >= r) 
        return;

    if (r - l < 2) {
        t[id] = 1;
        return;
    }



    int mid = (l + r) / 2;
    insert(x, 2 * id, l, mid);
    insert(x, 2 * id + 1, mid, r);

    t[id] = t[2 * id] + t[2 * id + 1];
}

int find(int k, int id, int l, int r) {
    if (r - l < 2)
        return l;

    int mid = (l + r) / 2;

    if (k <= t[2 * id]) {
        return find(k, 2 * id, l, mid);
    }
    else {
        return find(k - t[2*id], 2 * id + 1, mid, r);
    }
}


struct comparator
{
    inline bool operator() (const pair<int, int>& p1, const pair<int, int>& p2)
    {
        if (p1.first != p2.first) {
            return p1.first > p2.first;
        }
        else {
            return p1.second < p2.second;
        }
    }
};


int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[i] = make_pair(x, i);
        b[i] = x;
    }
    sort(a, a + n, comparator());

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int k, p;
        cin >> k >> p;
        q[i] = make_pair(k, make_pair(p, i));
    }

    sort(q, q + m);

    int prev = 0;
    for (int i = 0; i < m; ++i) {
        int k = q[i].first;
        int p = q[i].second.first;
        if (k > prev) {
            for (int j = prev; j < k; ++j) {
                insert(a[j].second, 1, 0, n);
            }
            
        }
        prev = k;

        int pos = find(p, 1, 0, n);
        result[q[i].second.second] = b[pos];
    }


    for (int i = 0; i < m; ++i) {
        cout << result[i] << endl;
    }
}
