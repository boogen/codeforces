#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <set>
#include <queue>
#include <map> 

#define ulong unsigned long long
#define ll long long
 
using namespace std;


const int maxn = 10e5+1;
vector<int> g[maxn];
int depth[maxn];
int sq;
int parent[maxn];
int marked[maxn];

void dfs(int u, int d) {
    depth[u] = d;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];

        if (depth[v] == 0) {
            parent[v] = u;
            dfs(v, d + 1);
        }
        else if (depth[v] - depth[u] + 1 >= sq) {
            cout << "2" << endl;
            cout << (depth[v] - depth[u] + 1) << endl;
            int x = v;
            while (x != u) {
                cout << x << " ";
                x = parent[x];
            }
            cout << u << endl;
            exit(0);
        }
    }

    if (!marked[u]) {
        for (int i = 0; i < g[u].size(); ++i) {
            int v = g[u][i];
            marked[v] = 1;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    sq = ceil(sqrt((double)n));

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 1);

    cout << "1" << endl;
    int c = 0;
    for (int i = 1; i <= n; ++i) {
        if (!marked[i] && c < sq) {
            cout << i << " ";
            c++;
        }
    }
    cout << endl;
}
