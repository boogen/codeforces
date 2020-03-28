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

int res[100000];

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> dig;
    map<int, int> d;
    for (int i = 0; i < n; ++i) {
        int x = s.at(i) - '0';
        d[x]++;
        dig.push_back(x);
    }
    int inf = 10e7;
    int digit;
    vector<map<int, int> > prices;
    vector<int> costs;
    for (int i = 0; i <= 9; ++i) {
        map<int, int> price;
        int cost = 0;

        int v = k - d[i];
        if (v < 0) {
            prices.push_back(price);
            costs.push_back(cost);
            continue;
        }

        int j = 0;
        for (j = 1; j <= 9 && v > 0; ++j) {
            int r = i + j;
            if (r <= 9) {
                cost += min(v, d[r]) * j;
                price[r] = min(v, d[r]);
                v = max(0, v - d[r]);
            }


            int l = i - j;
            if (l >= 0) {
                cost += min(v, d[l]) * j;
                price[l] = min(v, d[l]);

                v = max(0, v - d[l]);
            }
        }

        prices.push_back(price);
        if (v > 0) 
            costs.push_back(inf);
        else
            costs.push_back(cost);
    }

    int min_cost = *min_element(costs.begin(), costs.end()) ;
    cout << min_cost << endl;

    vector<vector<int> > results;
    for (int i = 0; i <= 9; ++i) {
        if (costs[i] == min_cost) {
            map<int, int> price = prices[i];
            vector<int> res;
            for (int j = 0; j < n; ++j) {
                int x = dig[j];
                if (x > i && price[x] > 0) {
                    price[x]--;
                    res.push_back(i);
                }
                else {
                    res.push_back(x);
                }
            }
            for (int j = n - 1; j >= 0; --j) {
                int x = dig[j];
                if (x < i && price[x] > 0) {
                    price[x]--;
                    res[j] = i;
                }
            }
            results.push_back(res);
        }
    }

    sort(results.begin(), results.end());
    for (int i = 0; i < n; ++i) {
        cout << results[0][i];
    }
    cout << endl;
            
    
}
