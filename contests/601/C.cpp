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


vector<int> t[100001];
int m[100001];
map<pair<int, int >, vector<int> > cnt;
map<int, int> rep;

vector<int> g[100001];

int pr[100001];
int r[100001];

void add(int a, int b, int i) {
    cnt[make_pair(min(a, b), max(a, b))].push_back(i);
}

vector<int> get(int a, int b) {
    return cnt[make_pair(min(a, b), max(a, b))];
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 2; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, i);
        add(a, c, i);
        add(b, c, i);
        rep[a] += 1;
        rep[b] += 1;
        rep[c] += 1;
        t[i].push_back(a);
        t[i].push_back(b);
        t[i].push_back(c);
    }


    int v;
    pair<int, int> p;

    for (int i = 0; i < n - 2; ++i) {
        int a = t[i][0];
        int b = t[i][1];
        int c = t[i][2];
        vector<int> v = get(a, b);
        for (int j = 0; j < v.size(); ++j) {
            if (v[j] != i)
                g[i].push_back(v[j]);
        }
        v = get(b, c);
        for (int j = 0; j < v.size(); ++j) {
            if (v[j] != i)
                g[i].push_back(v[j]);
        }
        v = get(a, c);
        for (int j = 0; j < v.size(); ++j) {
            if (v[j] != i)
                g[i].push_back(v[j]);
        }
    }
    int start;
    for (int i = 0; i < n - 2; ++i) {
        int a = t[i][0];
        int b = t[i][1];
        int c = t[i][2];
        if (rep[a] == 1) {
            start = i;
            r[0] = a;
            pr[a] = 1;
            break;
        }
        if (rep[b] == 1) {
            start = i;
            pr[b] = 1;
            r[0] = b;
            break;
        }
        if (rep[c] == 1) {
            start = i;
            r[0] = c;
            pr[c] = 1;
            break;
        }
        
    }

    set<int> visited;
    visited.insert(start);
    int curr = start;
    vector<int> res;
    res.push_back(start);
    
    while (res.size() < n - 2) {
        for (int i = 0; i < g[curr].size(); ++i) {
            int v = g[curr][i];
            if (visited.find(v) == visited.end()) {
                visited.insert(v);
                res.push_back(v);
                curr = v;
                
            }
        }
    }


    for (int i = 1; i + 1 < n - 2; ++i) {
        int ind = res[i];
        int a = t[ind][0];
        int b = t[ind][1];
        int c = t[ind][2];
        if (get(a,b).size() == 1) {
            r[i + 1] = c;
            pr[c] = 1;
        }
        else if (get(a,c).size() == 1) {
            r[i + 1] = b;
            pr[b] = 1;
        }
        else if (get(b,c).size() == 1) {
            r[i + 1] = a;
            pr[a] = 1;
        }
        
    }

    int pos = 1;
    for (int i = 0; i < n - 2; ++i) {
        int ind = res[i];
        int a = t[ind][0];
        int b = t[ind][1];
        int c = t[ind][2];
        if (pr[a] == 0) {
            r[pos] = a;
            pr[a] = 1;
        }
        else if (pr[b] == 0) {
            r[pos] = b;
            pr[b] = 1;
        }
        else if (pr[c] == 0) {
            r[pos] = c;
            pr[c] = 1;
        }

        while (r[pos] > 0) pos++;
    }

    for (int i = 0; i < n; ++i)
        cout << r[i] << " ";
    cout << endl;
}
