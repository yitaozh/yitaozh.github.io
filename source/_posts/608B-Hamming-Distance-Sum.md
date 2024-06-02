---
title: 608B. Hamming Distance Sum
categories: Leetcode
date: 2024-05-30 23:35:17
tags:
    - Combinatorics
    - String
---

[B. Hamming Distance Sum](https://codeforces.com/problemset/problem/608/B)

## Description

输入长度均 ≤2e5 的字符串 s 和 t，只包含 '0' 和 '1'。并且 t 的长度大于等于 s 的长度。

定义 D(a,b) = |a[0]-b[0]| + |a[1]-b[1]| + ... + |a[n-1]-b[n-1]|。
例如 D("0011", "0110") = |0-0| + |0-1| + |1-1| + |1-0| = 0 + 1 + 0 + 1 = 2。

设 s 的长度为 n，对于 t 的所有长为 n 的连续子串 t'，计算 D(s,t')。
输出所有 D(s,t') 的和。

进阶：额外输入 k，计算 s 所有长为 k 的子串与 t 的所有长为 k 的子串的 D 之和。

## Hints/Notes

- think how each element contribute to the final result

## Solution

Language: **C++**

```C++
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
```
