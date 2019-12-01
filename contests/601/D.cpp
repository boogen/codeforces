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

int m[1000][1000];
vector<char> signs;
char result[1000][1000];

void solve() {

    int r, c, k;
    cin >> r >> c >> k;
    int rice = 0;
    for (int i = 0; i < r; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < c; ++j) {
            if (s.at(j) == 'R') {
                m[i][j] = 1;
                rice++;
            }
            else
                m[i][j] = 0;

        }
        
    }



    int avg = rice / k;
    int rest = rice % k;

    vector<pair<int, int> > path;


    for (int j = 0; j < c; ++j) {
        if (j % 2 == 0) {
            for (int i = 0; i < r; ++i) {
                path.push_back(make_pair(i, j));
            }
        }
        else {
            for (int i = r - 1; i >= 0; --i) {
                path.push_back(make_pair(i, j));
            }
        }
    }

    int id = 0;
    int cnt = avg;
    if (rest > 0) {
        cnt++;
        rest--;
    }
    
    for (int i = 0; i < path.size(); ++i) {
        int x = path[i].first;
        int y = path[i].second;
        result[x][y] = signs[id];
        if (m[x][y] == 1) {
            cnt--;
            if (cnt == 0) {
                if (id + 1 < k) 
                    id++;
                cnt = avg;
                if (rest > 0) {
                    cnt++;
                    rest--;
                }
            }
        }
    }

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << result[i][j];
        }
        cout << endl;
    }
}

int main() {
    for (char i = 'a'; i <= 'z'; ++i)
        signs.push_back(i);
    for (char i = 'A'; i <= 'Z'; ++i)
        signs.push_back(i);
    for (char i = '0'; i <= '9'; ++i)
        signs.push_back(i);


    int t;
    cin >> t;
    while (t-- > 0) 
        solve();
}
