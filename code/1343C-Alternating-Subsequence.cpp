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
#define TEST

#ifdef TEST
string dir = "./";
string inputFile = dir + "1343C.input.txt";
string outputFile = dir + "1343C.output.txt";
string expectFile = dir + "1343C.expect.txt";

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

void solve(vector<int>& nums) {
    long long pos_size = 0, pos_res = 0;
    for (int i = 0; i < nums.size(); ) {
        if (nums[i] < 0) {
            i++;
            continue;
        }
        int tmp = INT_MIN;
        pos_size++;
        for (; i < nums.size() && nums[i] > 0; i++) {
            tmp = max(tmp, nums[i]);
        }
        pos_res += tmp;
        tmp = INT_MIN;
        for (; i < nums.size() && nums[i] < 0; i++) {
            tmp = max(tmp, nums[i]);
        }
        if (tmp != INT_MIN) {
            pos_size++;
            pos_res += tmp;
        }
    }

    long long neg_size = 0, neg_res = 0;
    for (int i = 0; i < nums.size(); ) {
        if (nums[i] > 0) {
            i++;
            continue;
        }
        int tmp = INT_MIN;
        neg_size++;
        for (; i < nums.size() && nums[i] < 0; i++) {
            tmp = max(tmp, nums[i]);
        }
        neg_res += tmp;
        tmp = INT_MIN;
        for (; i < nums.size() && nums[i] > 0; i++) {
            tmp = max(tmp, nums[i]);
        }
        if (tmp != INT_MIN)  {
            neg_size++;
            neg_res += tmp;
        }
    }
    if (pos_size > neg_size) {
        out << pos_res << endl;
    } else if (pos_size < neg_size) {
        out << neg_res << endl;
    } else {
        out << max(pos_res, neg_res) << endl;
    }

}

int main() {
    int tc;
    in >> tc;
    for (int t = 1; t <= tc; t++) {
        int size;
        in >> size;
        vector<int> nums;
        for (int i = 0; i < size; i++) {
            int num;
            in >> num;
            nums.push_back(num);
        }
        solve(nums);
    }
    return 0;
}