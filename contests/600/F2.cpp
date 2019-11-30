#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <unordered_map>
#include <set>
#include <queue>
#include <map>
#include <ctime>
#include <climits>
#define llong long long
#define ulong unsigned long long
 
using namespace std;
 
vector<pair<int, ulong> > g[300001];
pair<int, ulong> dist[300001];
pair<int, int> queries[300001];

int done[300001];
 
 

int timer = 0;
int l;
int t1[100001];
int t2[100001];

int up[100001][20];
ulong mx[100001][20];

vector<int> tree[100001]; 
map<pair<int, int>, ulong> weights;

void dfs(int v, int p)
{
    t1[v] = ++timer;
    up[v][0] = p;
    mx[v][0] = weights[make_pair(min(v,p), max(v, p))];

    for (int i = 1; i <= l; ++i) {
        up[v][i] = up[up[v][i-1]][i-1];
    }

    for (int i = 1; i <= l; ++i) {
        mx[v][i] = max(mx[v][i - 1], mx[up[v][i-1]][i - 1]);
    }

    for (int i = 0; i < tree[v].size(); ++i) {
        int u = tree[v][i];
        if (u != p)
            dfs(u, v);
    }

    t2[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return t1[u] <= t1[v] && t2[u] >= t2[v];
}


ulong find_max(int u, int p) {
    ulong res = 0;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], p)) {
            res = max(res, mx[u][i]);
            u = up[u][i];            
        }
    }

    if (u != p) {
        res = max(res, mx[u][0]);
        u = p;
    }
    
    return res;
}



int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

 
struct find_union {
    vector<int> S;
 
    find_union(int n) : S(n) {
        for (int i = 0; i < n; ++i) 
            S[i] = i;
    }
 
    ulong find(int a) {
        return S[a] == a ? a : (S[a] = find(S[a]));
    }
 
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b) return false;
        S[a] = b;
        return true;
    }
};
 
int main() {
 
    int n,m,k,q;
    cin >> n >> m >> k >> q;
    l = ceil(log2(k));
    ulong inf = ULLONG_MAX;
 
    for (int i = 0; i < m; ++i) {
        int u,v,w;
        scanf("%d %d %d", &u, &v, &w);
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }
 
    for (int i = 0; i < q; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        queries[i] = make_pair(a, b);
    }
 
 
    //dijkstra
    priority_queue< pair<ulong, ulong>, vector<pair<ulong, ulong> > , greater<pair<ulong, ulong> > > qu; 
  
    for (int i = 1; i <= n; ++i) {
        dist[i].first = i;
        if (i <= k)
            dist[i].second = 0;
        else 
            dist[i].second = inf;
    }
 
    for (int i = 1; i <= k; ++i)  {
        qu.push(make_pair(0, i));
    } 


 
    while (!qu.empty()) {
        ulong u = qu.top().second; 
        qu.pop(); 

        if (done[u] == 0) {

            done[u] = 1;
  
            for (int i = 0; i < g[u].size(); ++i) {
                ulong v = g[u][i].first;
                if (done[v] == 0) {
                    ulong w = g[u][i].second; 
  
                    if (dist[v].second > dist[u].second + w) {
                        dist[v].first = dist[u].first;                
                        dist[v].second = dist[u].second + w;
                        qu.push(make_pair(dist[v].second, v)); 
                    } 
                }
            } 
        }
    }
 
 
    // remove duplicate edges
    map<pair<ulong, ulong>, ulong> e;
 
    for (ulong v = 1; v <= n; ++v) {
        for (ulong j = 0; j < g[v].size(); ++j) {
            ulong u = g[v][j].first;
            if (dist[v].first != dist[u].first) {
                ulong x = dist[v].first;
                ulong y = dist[u].first;
 
                pair<ulong, ulong> p = make_pair(min(x, y), max(x, y));
 
                ulong cost = dist[v].second + dist[u].second + g[v][j].second;
                
                if (e.find(p) == e.end()) {
                    e[p] = cost;
                }
                else if (e[p] > cost) {
                    e[p] = cost;
                }
            }
        }
    }
 
 
    
    vector<pair<ulong, pair<ulong, ulong> > > edges;
 
    for (map<pair<ulong, ulong>, ulong>::iterator it = e.begin(); it != e.end(); ++it) {
        edges.push_back(make_pair(it->second, it->first));
    }
 
 
    // mst kruskal
    sort(edges.begin(), edges.end());
 
    find_union dsu(k + 1);
    for (int i = 0; i < edges.size(); ++i) {
        pair<int, int> ed = edges[i].second;
 
        if (dsu.find(ed.first) != dsu.find(ed.second)) {
            dsu.unite(ed.first, ed.second);
            int u = ed.first;
            int v = ed.second;
            ulong w = edges[i].first;
            tree[u].push_back(v);
            tree[v].push_back(u);
            weights[make_pair(min(u, v), max(u, v))] = w;
        }
    }
 
 
    dfs(1, 1);
 
 
    
 
    for (int i = 0; i < q; ++i) {

        int a = queries[i].first;
        int b = queries[i].second;
        int p = lca(a, b);

        ulong r = max(find_max(a, p), find_max(b, p));

        //cout << r << endl;
        printf("%I64d\n",r);
    }
 
    
}
