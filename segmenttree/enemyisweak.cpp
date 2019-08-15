#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <unordered_map>

#define ulong unsigned long long

using namespace std;

ulong t[2 * 1000000 + 1];

int n;

void modify(int p, ulong v) {  

    for (t[p += n] += v; p > 1; p >>= 1) t[p>>1] += v;
}

ulong query(int l, int r) {  // sum on interval [l, r)
  ulong res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}


int main() {
    memset(t, 0, sizeof(t));

    cin >> n;

    unordered_map<int, int> m;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        m[v[i]] = 0;
    }

    vector<int> v2 = v;
    sort(v2.begin(), v2.end());
    int i = 0;

    for (int i = 0; i < n; ++i) {
        m[v2[i]] = i;
    }

    
    ulong result = 0;
    for (int i = n - 1; i >= 0; --i) {
        int x = m[v[i]];
        ulong small_right = query(0, x);
        ulong great_right = n - 1 - i - small_right;
        ulong greater = n - 1 - x;
        ulong great_left = greater - great_right;

        modify(x, 1);


        result += great_left * small_right;
    }


    cout << result << endl;
    
}
