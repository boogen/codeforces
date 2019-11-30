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
 
set<int> mp[300001];
 
ulong result[300001];
 
void merge(int xs, int ys, ulong w) {
    for (set<int>::iterator it = mp[xs].begin(); it != mp[xs].end(); it++) {
        ulong x = *it;
        if (mp[ys].find(x) == mp[ys].end()) {
            mp[ys].insert(x);
        }
        else {
            result[x] = w;
        }
    }
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
 
    vector<pair<ulong, pair<int, int> > > tree;
    find_union dsu(k + 1);
    for (int i = 0; i < edges.size(); ++i) {
        pair<int, int> ed = edges[i].second;
 
        if (dsu.find(ed.first) != dsu.find(ed.second)) {
            dsu.unite(ed.first, ed.second);
            tree.push_back(edges[i]);
        }
    }
 
 
    sort(tree.begin(), tree.end());
 
 
 
   
    for (int i = 0; i < q; ++i) {
        int a = queries[i].first;
        int b = queries[i].second;
        
        mp[a].insert(i);
        mp[b].insert(i);
    }
 
 
 
    set<int> xs, ys;
    find_union un(k + 1);
    for (int i = 0; i < tree.size(); ++i) {
        int a = tree[i].second.first;
        int b = tree[i].second.second;
        ulong w = tree[i].first;
 
        int x = un.find(a);
        int y = un.find(b);
 
        
        if (mp[x].size() < mp[y].size())  {
            merge(x, y, w);
            un.unite(x, y);
        }
        else {
            merge(y, x, w);
            un.unite(y, x);
        }
        
    }
 
    for (int i = 0; i < q; ++i)
        //    cout << result[i] << endl;
        printf("%I64d\n",result[i]);
 
    
}
