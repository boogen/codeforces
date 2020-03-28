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

char tolower(char in) {
    if (in <= 'Z' && in >= 'A')
        return in - ('Z' - 'z');
    return in;
}

char vowels[] = {'a', 'o', 'y', 'e', 'u', 'i'};

int main() {
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); ++i) {
        char x = tolower(s.at(i));
        if (find(vowels, vowels + sizeof(vowels), x) == end(vowels)) {
            cout << "." << x;
        }
    }

    cout << endl;
}
