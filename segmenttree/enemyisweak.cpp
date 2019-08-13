#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

#define ulong unsigned long long

using namespace std;

ulong t[2 * 1000000 + 1];
ulong t2[2 * 1000000 + 1];

int n;

void modify(int p, ulong v,  ulong tree[]) {  

    for (tree[p += n] += v; p > 1; p >>= 1) tree[p>>1] += v;
}

unsigned long long query(int l, int r, unsigned long long tree[]) {  // sum on interval [l, r)
  unsigned long long res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += tree[l++];
    if (r&1) res += tree[--r];
  }
  return res;
}


int main() {
    memset(t, 0, sizeof(t));
    memset(t2, 0, sizeof(t));

    cin >> n;

    map<int, int> m;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        m[v[i]] = 0;
    }

    int i = 0;
    map<int, int>::iterator it;
    for (it = m.begin(); it != m.end(); ++it) {
        m[it->first] = i++;
    }

    
    ulong result = 0;
    for (int i = n - 1; i >= 0; --i) {
        int s = query(0, m[v[i]], t);
        
        modify(m[v[i]], 1, t);
        modify(m[v[i]], s, t2);


        result += query(0, m[v[i]], t2);
    }


    cout << result << endl;
    
}
