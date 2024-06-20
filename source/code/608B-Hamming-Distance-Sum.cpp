#include <iostream>
#include <utility>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>

#include <fstream>

using namespace std;

istream &in = cin;
ostream &out = cout;

void solve(string a, string b) {
    int m = a.size(), n = b.size();
    long long res = 0;
    for (int i = 0; i < m; i++) {
        for (int j = i; j < n - m + i + 1; j++) {
            res += abs(a[i] - b[j]);
        }
    }
    out << res << endl;
}

int main() {
    string a, b;
    in >> a >> b;
    solve(a, b);
    return 0;
}