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
//#define TEST

#ifdef TEST
string dir = "./";
string inputFile = dir + "608B.input.txt";
string outputFile = dir + "608B.output.txt";
string expectFile = dir + "608B.expect.txt";

ifstream in(inputFile);
ofstream out(outputFile);

ifstream output(outputFile);
ifstream expect(expectFile);
#else
istream &in = cin;
ostream &out = cout;
#endif

string emptyStr = "nullptr";

class Prepare {
public:
    Prepare() {
        prepare();
    }

    static void prepare() {
#ifdef TEST
        if (!in.is_open()) {
            cout << "empty input file" << endl;
            exit(-1);
        }
        if (!expect.is_open()) {
            cout << "empty expect file" << endl;
            exit(-1);
        }
#endif
    }
};

class Check {
public:
    ~Check() {
        // compare
#ifdef TEST
          for (int i = 1; !output.eof(); ++i) {
            if (output.eof()) {
                break;
            }
            string l, r;
            getline(output, l);
            getline(expect, r);
            while (!l.empty() && l.back() == ' ') {
                l.pop_back();
            }
            while (!r.empty() && r.back() == ' ') {
                r.pop_back();
            }
            if (l.empty() && r.empty()) {
                break;
            }
            if (l == emptyStr) {
                break;
            }
            if (l == r) {
                cout << "case: " << i << " pass" << endl;
            } else if (l != r) {
                cout << "case: " << i << " wrong " << "output[" << l << "], while expect[" << r << "]" << endl;
                continue;
            }
        }
#endif
    }
};

static Prepare pre;
static Check check;

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