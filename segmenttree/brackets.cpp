#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <unordered_map>
 
#define ulong unsigned long long
 
using namespace std;
 
int lf[2 * 1048576 + 1];
int rt[2 * 1048576 + 1];
int all[2 * 1048576 + 1];
 
int n;
 
 
int main() {
    memset(lf, 0, sizeof(lf));
    memset(rt, 0, sizeof(rt));
    memset(all, 0, sizeof(all));
 
    string line;
    getline(cin, line);
    n = line.length() - 1;
    n = (1 << (int)ceil(log2(n)));
 
    for (int i = 0; i < line.size(); ++i) {
    	if (line.at(i) == '(') {
    		lf[i + n] = 1;
    	}
    	else if (line.at(i) == ')') {
    		rt[i + n] = 1;
    	}
    }
 
    for (int i = n - 1; i >= 0; --i) {
    	int closed =min(lf[2 * i], rt[2 * i + 1]);
    	all[i] = 2 * closed + all[2 * i] + all[2 * i + 1];
    	lf[i] = lf[2 * i] - closed + lf[2 * i + 1];
    	rt[i] = rt[2 * i + 1] - closed + rt[2 * i];
    }
 
    int m;
    cin >> m;
 
 
    for (int i = 0; i < m; ++i) {
    	int r, l;
    	cin >> l >> r;
    	l -= 1;
 
    	vector<int> seg;
    	vector<int> s2;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l&1) seg.push_back(l++);
			if (r&1) s2.push_back(--r);
		}
 
 
		reverse(s2.begin(), s2.end());
 
		seg.insert( seg.end(), s2.begin(), s2.end() );
 
		int res = 0;
		if (seg.size() > 0) {
			res = all[seg[0]];
			int a = lf[seg[0]];
			for (int j = 1; j < seg.size(); ++j) {
				int ind = seg[j];
				res += 2 * min(a, rt[ind]) + all[ind];
				a = max(0, a - rt[ind]);
				a += lf[ind];
			}
		}
		cout << res << endl;
    }
}
