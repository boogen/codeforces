#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <unordered_map>
#include <set>
#include <queue>
#include <map>
 
#define llong long long
#define ulong unsigned long long
 
using namespace std;

int a[100000 + 1];


bool valid(int start, int end) {
    map<int, int> count;
    
    for (int j = start; j <= end; ++j) {
        count[a[j]] += 1;
        if (count[a[j]] > 1) 
            return false;
        if (a[j] < 0 && count[-a[j]] == 0)
            return false;
    }

    return true;
    
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) 
        cin >> a[i];


    vector<int> d;
    llong sum = 0;
    int start = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        if (sum == 0) {
            if (valid(start, i)) {
                d.push_back(i - start + 1);

                start = i + 1;
            }
            else {
                cout << "-1" << endl;
                return 0;
            }
        }
    }

    if (sum != 0) {
        cout << "-1" << endl;
        return 0;
    }

    cout << d.size() << endl;
    for (int i = 0; i < d.size(); ++i) {
        cout << d[i] << " ";
    }
    cout << endl;
}
