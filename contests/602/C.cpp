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

char a[2001];
vector<int> segments;
int n;

void count_segments() {
    segments.clear();
    vector<int> st;
    for (int i = 0; i < n; ++i) {
        if (!st.empty() && st.back() == '(' && a[i] == ')') {
            st.pop_back();
            if (st.empty()) 
                segments.push_back(i);
        }
        else {
            st.push_back(a[i]);
        }
    }
    
}

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc) {
        int k;
        cin >> n >> k;

        string line;
        getline(cin, line);
        getline(cin, line);        

        for (int i = 0; i < n; ++i) 
            a[i] = line.at(i);

        vector<pair<char, int> > s;
        for (int i = 0; i < n; ++i) {
            if (!s.empty() && s.back().first == '(' && a[i] == ')') {
                s.pop_back();
            }
            else {
                s.push_back(make_pair(a[i], i));
            }
        }

        vector<pair<int, int> > result;

        if (!s.empty()) {
            int start = 0;
            int end = s.size() - 1;
            while (start < end) {
                int a = start + 1;
                int b = end - 1;

                while (a < b && s[a - 1].second + 1 == s[a].second && s[b].second + 1  == s[b + 1].second) {
                    a++;
                    b--;
                }
                a--;
                b++;

                result.push_back(make_pair(s[start].second, s[end].second));
                if (s[a].second + 1 < s[b].second - 1)
                    result.push_back(make_pair(s[a].second + 1, s[b].second - 1));
                

                start = a + 1;
                end = b - 1;
            }

            for (int i = 0; i < s.size(); ++i) {
                int j = s[i].second;
                if (a[j] == '(')
                    a[j] = ')';
                else
                    a[j] = '(';
            }
        }



        count_segments();

        while (segments.size() != k) {
            if (segments.size() < k) {
                int prev = 0;
                for (int i = 0; i < segments.size(); ++i) {
                    int seg = segments[i];
                    
                    if (seg - prev > 1) {
                        result.push_back(make_pair(prev + 1, seg));
                        result.push_back(make_pair(prev + 2, seg));
                        for (int j = seg; j > prev; --j) {
                            a[j] = a[j - 1];
                        }
                        a[prev + 1] = ')';
                        break;
                    }
                    prev = seg + 1;
                }
            }
            else if (segments.size() > k) {
                int diff = segments.size() - k;

                int s = 0;
                int e = diff - 1;
            
                result.push_back(make_pair(segments[s], segments[e] + 1));
                if (segments[s] < segments[e]) {
                    result.push_back(make_pair(segments[s] + 1, segments[e]));
                }
                a[segments[s]] = '(';
                a[segments[e] + 1] = ')';

            }

            count_segments();
        }
        cout << result.size() << endl;
        for (int i = 0; i < result.size(); ++i) {
            cout << (result[i].first + 1) << " " << (result[i].second + 1) << endl;
        }
    }
}
