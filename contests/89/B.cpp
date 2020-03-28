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

int main() {
    int n;
    cin >> n;

    for (int i = -n; i <= n; ++i) {
        int x = n - abs(i);
        for (int j = -n; j <= x; ++j) {
            if (abs(j) <= x) {
                cout << (x - abs(j));
                if (j < x) 
                    cout << " "; 
            }
            else {
                cout << "  ";
            }
        }        
        cout << endl;
    }
}
