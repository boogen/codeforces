#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <set>
 
#define ulong unsigned long long
#define ll long long
 
using namespace std;

pair<ll, ll> points[100];
ll d[100];
ll x, y, ax, ay, bx, by;
ll sx, sy, t;
int n;


int check(int index) {
    
    ll d0 = abs(points[index].first - sx) + abs(points[index].second - sy);
    int cnt = 0;
    ll cost = d0;
    int i = index;

    if (cost <= t) {
        cnt++;
    }
    while (i > 0 && cost + d[i] <= t) {
        cost += d[i];
        i--;
        cnt++;
    }

    if ( cost + 2 * (cost - d0) <= t) {
        cost += (cost - d0);

        int i = index + 1;
        while ( i < n && cost + d[i] <= t) {
            cost += d[i];
            i++;
            cnt++;
        }
    }

    return cnt;
    
}

int main() {

    cin >> x >> y >> ax >> ay >> bx >> by;
    cin >> sx >> sy >> t;


    points[0] = make_pair(x, y);
    n = 1;
    ll m = (1LL << 62);
    for (; n < 100; ++n) {
        if (points[n - 1].first > (m - bx) / ax)
            break;
        ll xi  = points[n - 1].first * ax + bx;
        if (points[n - 1].second > (m - by) / ay)
            break;
        ll yi = points[n - 1].second * ay + by;
        points[n] = make_pair(xi, yi);
    }

    d[0] = 0;
    for (int i = 1; i < n; ++i) {
        d[i] = points[i].first - points[i - 1].first + points[i].second - points[i - 1].second;
    }

    ll min = (1LL << 62);
    int index = -1;
    for (int i = 0 ; i < n; ++i) {
        ll dd = abs(points[i].first - sx) + abs(points[i].second - sy);
        if (dd < min) {
            min = dd;
            index = i;
        }
    }


    cout << (index + 1 < n ? max(check(index), check(index + 1)) : check(index)) << endl;

}
