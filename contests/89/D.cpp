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




ll foo[11][101][101];
ll hor[11][101][101];

ll mod = 1e8;

int main() {
    int n1, n2, k1, k2;
    
    cin >> n1 >> n2 >> k1 >> k2;

    for (int i = 1; i <= k1; ++i) {
        foo[i][i][0] = 1;
    }
    for (int i = 1; i <= k2; ++i) {
        hor[i][0][i] = 1;
    }


    for (int i = 0; i <= n1; ++i) {
        for (int j = 0; j <= n2; ++j) {

            for (int k = 1; k <= min(i, k1); ++k) {
                for (int x = 1; x <= min(k2, j); ++x) {
                    foo[k][i][j] = (foo[k][i][j] + hor[x][i - k][j]) % mod;
                }
            }


            for (int k = 1; k <= min(j, k2); ++k) {
                for (int x = 1; x <= min(k1, i); ++x) 
                    hor[k][i][j] = (hor[k][i][j] + foo[x][i][j - k]) % mod;
            }

        }
    }

    ll ans = 0;

    for (int i = 1; i <= k1; ++i)
        ans = (ans + foo[i][n1][n2]) % mod;

    for (int i = 1; i <= k2; ++i) 
        ans = (ans + hor[i][n1][n2]) % mod;

    cout << ans << endl;
    

}
