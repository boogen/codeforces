#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <set>
 
#define ulong unsigned long long
#define ll long long
 
using namespace std;


vector<int> t[300001];
int s[300001];


int main() {

    int n, k;
    cin >> n >> k;

    string line;
    getline(cin, line);
    getline(cin, line);

    for (int i = 0; i < n; ++i) {
        s[i] = line.at(i) - '0';
    }
    for (int i = 1; i <= k; ++i) {
        int c;
        cin >> c;
        for (int j = 0; j < c; ++j) {
            t[j].push_back(i);
        }
    }


    set<int> c1;
    set<int> c2;
    c1.insert(1);
    for (int i = 1; i <= n; ++i) {
        if (t[i].size() == 2) {
            int sub1 = t[i][0];
            int sub2 = t[i][1];

            if (c1.find(sub1) != c1.end()) {
                c2.insert(sub2);
            }
            else if (c2.find(sub1) != c2.end()) {
                c1.insert(sub2);
            }
            else if (c1.find(sub2) != c1.end()) {
                c2.insert(sub1);
            }
            else if (c2.find(sub2) != c2.end()) {
                c1.insert(sub1);
            }
            else {
                cout << "weird flex but ok" << endl;
            }

            if (s[i] == 0) {
                cout << min(c1.size(), c2.size()) << "\n";
            }
            else {
                
            }
        }
        else if (t[i].size() == 1) {
            
        }
        else if (t[i].size() == 0) {
            
        }
    }
}
