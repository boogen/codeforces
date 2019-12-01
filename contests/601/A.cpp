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

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int a1, b1;
        cin >> a1 >> b1;

        int a, b;
        a = min(a1, b1);
        b = max(a1, b1);


        int diff = b - a;
        int count = diff / 5;
        diff -= count * 5;
        count += diff / 2;
        
        diff = diff - (diff / 2) * 2;
        count += diff;

        cout << count << endl;
    }
}
