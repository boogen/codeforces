#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <set>
 
#define ulong unsigned long long
#define ll long long
 
using namespace std;

int c = 16;


int main() {
    ulong u, v;
    cin >> u >> v;


    if (u > v) {
        cout << "-1" << endl;
        return 0;
    }

    if ((v - u) % 2 == 1) {
        cout << "-1" << endl;
        return 0;
    }

    if (u == v && v == 0) {
        cout << "0\n";
        return 0;
    }

    if (u == v) {
        cout << "1\n";
        cout << u << endl;
        return 0;
    }

    ulong x = (v - u) / 2;
  

    if ( (x & u) != 0 ) {
        cout << "3\n";
        cout << u << " " << x << " " << x << endl;
    }
    else {
        cout << "2\n";
        cout << (u + x) << " " << x << endl;
    }
}
