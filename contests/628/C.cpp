#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <set>
 
#define ulong unsigned long long
#define ll long long
 
using namespace std;

vector<pair<int, int> > t[100001];
vector<pair<int, int> > e;
int c[100001];

int main() {
    int n;
    cin >> n;

    
    for (int i = 0 ; i < n - 1; ++i) {
        c[i] = -1;
        int u, v;
        cin >> u >> v;
        e.push_back(make_pair(u, v));
        t[u].push_back(make_pair(v, i));
        t[v].push_back(make_pair(u, i));
    }


    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (t[i].size() > 2) {
            for (int j = 0; j < t[i].size(); ++j) {
                c[t[i][j].second] = cnt++;
            }
            break;
        }
    }


    for (int i = 0; i < n - 1; ++i) {
        if (c[i] == -1) 
            c[i] = cnt++;
        cout << c[i] << "\n";
    }
}
