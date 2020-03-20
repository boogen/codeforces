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

const int maxa = 1e6+10;
const int maxn = 1e5+10;


int a[maxn];

vector<int> divs[maxa];
int primes[maxa];

vector<int> g[maxa];

int vis[maxa];
int dis[maxa];
int par[maxa];

vector<int> pr;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }


    for (int i = 2; i < maxa; ++i) {
        if (primes[i] == 0) {
            divs[i].push_back(i);
            for (int j = 2 * i; j < maxa; j += i) {
                primes[j] = 1;
                divs[j].push_back(i);
            }
        }
    }

    map<int, int> m;

    for (int i = 0; i < n; ++i) {
        int x = a[i];
        for (int j = 0; j < divs[a[i]].size(); ++j) {
            int d = divs[a[i]][j];
            while (x % (d * d) == 0) {
                x = x / (d * d);
            }
        }

        if (x == 1) {
            cout << "1" << endl;
            return 0;
        }

        a[i] = x;
        m[x]++;

        if (divs[x].size() == 1) {
            g[1].push_back(x);
            g[x].push_back(1);
        }
        else if (divs[x].size() == 2) {
            int d1 = divs[x][0];
            int d2 = divs[x][1];

            g[d1].push_back(d2);
            g[d2].push_back(d1);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (m[a[i]] % 2 == 0) {
            cout << "2" << endl;
            return 0;
        }
    }
    int ans = 1e9;

    for (int i = 1; i * i < maxa; ++i) {
        if (primes[i] == 0 && g[i].size() > 0) {
            memset(vis, 0, sizeof(vis));
            vis[i] = 1;
            par[i] = 0;
            dis[i] = 0;

            queue<int> q;
            q.push(i);
            while (q.size()) {
                int v = q.front();
                q.pop();
                for (int j = 0; j < g[v].size(); ++j) {
                    int u = g[v][j];
                    if (vis[u] == 0) {
                        vis[u] = 1;
                        dis[u] = dis[v] + 1;
                        par[u] = v;
                        q.push(u);
                    }
                    else if (u != par[v]) {
                        ans = min(ans, dis[u] + dis[v] + 1);
                    }
                }
            }
        }
    }

    if (ans == 1e9) 
        ans = -1;

    cout << ans << endl;
    
}
