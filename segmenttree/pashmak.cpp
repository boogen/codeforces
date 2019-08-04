#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

unsigned long long t[2 * 1000000 + 1];

int n;

void modify(int p) {  // set value at position p

    for (t[p += n] += 1; p > 1; p >>= 1) t[p>>1] += 1;
}

unsigned long long query(int l, int r) {  // sum on interval [l, r)
  unsigned long long res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}

int main() {
    memset(t, 0, sizeof(t));

    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> L(n);
    vector<int> R(n);
    unordered_map<int, int> m;
   

    for (int i = 0; i < n; ++i) {
        m[a[i]]++;
        L[i] = m[a[i]];
    }

    m.clear();
    for (int i = n - 1; i >= 0; --i) {
        m[a[i]]++;
        R[i] = m[a[i]];
    }

    unsigned long long result = 0;
    for (int i = n - 1; i >= 0; --i) {
        result += query(0, L[i]);
        modify(R[i]);

    }
    cout << result << endl;
}
