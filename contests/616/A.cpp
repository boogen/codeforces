#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <set>
 
#define ulong unsigned long long
#define ll long long
 
using namespace std;


int main() {
    int t;
    cin >> t;

    for (int tc = 0; tc < t; ++tc) {
        int n;
        cin >> n;
        string s;
        getline(cin, s);
        getline(cin, s);
        vector<int> nr;
        for (int i = 0; i < n; ++i) {
            nr.push_back(s.at(i) - '0');
        }


        while (n > 0 && nr[n - 1] % 2 == 0) {
            nr.pop_back();
            n--;
        }
        if (n == 0) {
            cout << "-1" << endl;
            continue;
        }
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nr[i];
        }

        if (sum % 2 != 0) {
            for (int i = 0; i < n; ++i) {
                if (nr[i] % 2 == 1) {
                    nr.erase(nr.begin() + i);
                    n--;
                    break;
                }
            }
        }

        while (n > 0 && nr[0] == 0) {
            nr.erase(nr.begin());
            n--;
        }
        sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nr[i];
        }
        if (n == 0 || sum % 2 == 1  || nr[n - 1] % 2 == 0) {
            cout << "-1" << endl;
        }
        else {
            for (int i = 0; i < n; ++i) {
                cout << nr[i];
            }
            cout << endl;
        }
    }

    
}
