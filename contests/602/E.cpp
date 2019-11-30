#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <unordered_map>
#include <set>
#include <queue>
#include <map>
#include <stack>
 
#define llong long long
#define ulong unsigned long long
 
using namespace std;
vector<vector<int> > mp;
set<pair<int, int> > border;
int visited[3000001];

int t[3000001];
int n, m;

bool solve(int d) {
    queue<pair<pair<int, int>, int> > q;
    memset(visited, 0, sizeof(visited));
    memset(t, 0, sizeof(t));
    vector<pair<int, int> > trees;

    int count = 0;

    for (set<pair<int, int> >::iterator it = border.begin(); it != border.end(); ++it) {
        q.push(make_pair(*it, 0));
        visited[it->first * m + it->second] = 1;
        count++;
        if (d == 0)
            trees.push_back(*it);
    }

    while (!q.empty()) {
        pair<pair<int, int>, int> v = q.front();
        q.pop();
        int x = v.first.first;
        int y = v.first.second;
        int days = v.second;


        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                pair<int, int> p = make_pair(x + i, y + j);
                if (mp[x + i][y + j] == 1 && visited[p.first * m + p.second] == 0) {
                    visited[p.first * m + p.second] = 1;
                    count++;
                    q.push(make_pair(p, days + 1));
                    if (days + 1 >= d) {
                        trees.push_back(p);
                    }
                }
            }
        }

    }

    int count2 = 0;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < trees.size(); ++i) {
        q.push(make_pair(trees[i], d));
        t[trees[i].first * m + trees[i].second] = 1;
        visited[trees[i].first * m + trees[i].second] = 1;
        count2++;
    }

    while (!q.empty()) {
        pair<pair<int, int>, int> v = q.front();
        q.pop();
        int x = v.first.first;
        int y = v.first.second;
        int days = v.second;
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                pair<int, int> p = make_pair(x + i, y + j);
                if (mp[x + i][y + j] == 1 && visited[p.first * m + p.second] == 0) {
                    visited[p.first * m + p.second] = 1;
                    count2++;
                    if (days - 1 > 0)
                        q.push(make_pair(p, days - 1));
                }
            }
        }
        
    }

    return count == count2;
    
}

int main() {

    cin >> n >> m;
    string line;
    getline(cin, line);
    vector<int> row;
    for (int j = 0; j < m + 2; ++j) {
        row.push_back(0);
    }
    mp.push_back(row);
    for (int i = 0; i < n; ++i) {
        vector<int> row;
        row.push_back(0);

        for (int j = 0; j < m; ++j) {
            char c;
            scanf(" %c", &c);
            row.push_back(c == 'X' ? 1 : 0);            
        }
        row.push_back(0);
        mp.push_back(row);
    }
    mp.push_back(row);

    

    for (int x = 1; x <= n; ++x)
        for (int y = 1; y <= m; ++y) 
            if (mp[x][y] == 1)  {
                bool found = false;
                for (int i = -1; i <= 1; ++i) {
                    for (int j = -1; j <= 1; ++j) {
                        if (i != 0 || j != 0) {
                            if (mp[x + i][y + j] == 0) {
                                border.insert(make_pair(x, y));
                                found = true;
                                break;
                            }
                        }
                    }
                    if (found)
                        break;
                }
            }



    int l = 0;
    int r = (min(n, m) - 1) / 2 + 1;

    while (l < r) {
        int mid = (l + r) / 2;
        if (solve(mid)) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }                                


    cout << (l - 1) << endl;
    solve(l - 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (mp[i][j] == 0) {
                printf(".");
            }
            else if (t[i * m + j] == 1 ) {
                printf("X");
            }
            else {
                printf(".");
            }
        }
        printf("\n");
    }
}
