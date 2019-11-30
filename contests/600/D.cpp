#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <unordered_map>
#include <set>
#include <queue>
#include <map>
 
#define llong long long
#define ulong unsigned long long
 
using namespace std;

vector<int> e[200000 + 1];

int visited[200000 + 1];
int ma[200000 + 1];

int main() {
    int n,m;
    cin >> n >> m;


    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vector<pair<int, int> > islands;


    for (int i = 1; i <= n; ++i) {
        if (visited[i] == 1)
            continue;

        queue<int> q;
        q.push(i);
        visited[i] = 1;
        pair<int, int> island = make_pair(i, i);

        while(!q.empty()) {
            int v = q.front();
            q.pop();

            for (int j = 0; j < e[v].size(); ++j) {
                int w = e[v][j];
                if (visited[w] == 0) {
                    visited[w] = 1;
                    q.push(w);
                    island.first = min(island.first, w);
                    island.second = max(island.second, w);
                }
            }
        }

        islands.push_back(island);
    }
    sort(islands.begin(), islands.end());

    int result = 0;
    int end = 0;
    for (int i = 0; i < islands.size(); ++i) {
        if (islands[i].first < end)
            result++;

        end = max(islands[i].second, end);
    }

    cout << result << endl;
}
