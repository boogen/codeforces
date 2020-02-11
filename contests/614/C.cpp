#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <set>
 
#define ulong unsigned long long
 
using namespace std;

int a[3][100010];


bool check(int c) {
    if (a[1][c] + a[2][c] == 2) 
        return true;

    if (a[1][c - 1] + a[2][c] == 2)
        return true;

    if (a[2][c - 1] + a[1][c] == 2)
        return true;

    if (a[1][c] + a[2][c + 1] == 2)
        return true;
    
    if (a[2][c] + a[1][c + 1] == 2)
        return true;

    return false;
}

int main() {

    int n, q;
    cin >> n >> q;


    set<int> b;
    for (int i = 0; i < q; ++i) {
        int r,c;
        cin >> r >> c;
        a[r][c] = 1 - a[r][c];
        if (check(c)) 
            b.insert(c);
        else
            b.erase(c);

        if (check(c - 1)) 
            b.insert(c - 1);
        else
            b.erase(c - 1);

        if (check(c + 1))
            b.insert(c + 1);
        else 
            b.erase(c + 1);

        if (b.empty()) 
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
