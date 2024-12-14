---
title: How to leetcode
date: 2022-12-20 15:11:52
categories: Thoughts
---

### The motivation

A good software developer doesn't necessarily need to be a good IOer, but in general a good IOer is more likely to be a good software developer. This logic makes coding more and more important in tech interview.

### The daily routine

Now I need to review first, review 3 days per day until I can catch the current date. Only do new exercise when I need to refresh the calendar of memoCard.

After that, do 2 days exercise per day. Until I can catch the current date.

After that, 2 new problems daily during workday(preferably in the morning). Then do the revision whenever possible.

### The environment

I am currently using leetcode website.

### How to leetcode

[论如何 4 个月高效刷满 500 题并形成长期记忆](https://zhuanlan.zhihu.com/p/492026165)

1. 始终保持匀速前进，既不松懈倦怠，亦不急于求成

2. 定时归纳总结, 按类训练

3. 深度理解人的记忆规律，高频率高效复习

4. 拥抱孤独，过滤外界杂音，平稳心态

### The order to solve problems

1. Go through [LABULADONG 的算法网站](https://labuladong.github.io/algo/) once first.
1. [灵神题单](https://github.com/EndlessCheng/codeforces-go/blob/master/leetcode/SOLUTIONS.md)
1. The [Explore](https://leetcode.com/explore/featured/) is a great place next. Finish all courses.
1. Use the daily problem and study plan tool

### The steps to tackle one problem

* If no idea at all, just check the hints. No need to wait for 5, 10 minutes

### Advance

* Weekly contest, then codeforce
* Watch this [video series](https://www.youtube.com/@BackToBackSWE/videos) to learn how to speak the story

### Current leetcode blog

[经典动态规划：高楼扔鸡蛋](https://labuladong.online/algo/dynamic-programming/egg-drop/)

### Last problem solved

New page.

### The problems not solved

1696 and 1425 in [【强化练习】单调队列的通用实现及经典习题](https://appktavsiei5995.pc.xiaoe-tech.com/p/t_pc/course_pc_detail/image_text/i_62a692efe4b01a48520b9b9b?product_id=p_627cd0eae4b0cedf38b0ef74&content_app_id=&type=8&parent_pro_id=p_62654124e4b09dda125f9a8d)

Biweekly Contest 130 t4: 3145 2900

Biweekly Contest 135 t4: 3225 3100

Weekly Contest 409 t4: 3245 3100 pre-requisite: BIT

Biweekly Contest 143 t3: 3348 3200

Weekly Contest 424 t4: 3357 3000

### The problems pending rewrite

CF 1237D

### The problems not recorded

N/A

### The best way to record the progression

Screenshot the next day's list

### The problems not noted

```bash
find source/_posts/ -name "[0-9]*" |  xargs grep -L "Hints"
```

### The problems not tagged

```bash
find source/_posts/ -name "[0-9]*" | xargs grep -A 1 "tags" | grep -e "---"
```

### Notes

String algorithms:

* KMP is to calculate the prefix array, it can be used to calculated the occurrence of pattern in text
* Z algorithm is to calculate the longest common prefix. example: lc 3303
* Manacher is to calculate the longest palindrome at each index. example: lc 3327

General notes

* reference is much faster due to no copy and initialization
* initialize the array if possible

How to iterate a map(C++20)

```C++
for (auto&[k, v] : m) {

}
```

sort(C++20)

```C++
ranges::sort(nums)
```

get max element(C++20)

```C++
ranges::max_element(vector/map)
```

make decimal binary

```C++
// s is string of a decimal num
string res = bitset<32>(stoi(s)).to_string();
return res.substr(res.find('1'));
```

binary search(C++20)

```C++
ranges::lower_bound(vector, val);
```

get min/max length of a vector of strings(C++20)

```C++
minLen = ranges::min(wordDict, {}, &string::length).length();
maxLen = ranges::max(wordDict, {}, &string::length).length();
```

### Templates:

String hash:

```C++
class Solution {
public:
    struct HashObj {
        const int MOD = 1'070'777'777;
        vector<__int128> P, H;
        template<typename Container> HashObj(Container &s, const int BASE) {
            int n = s.size();
            P.resize(n + 1); H.resize(n + 1);
            P[0] = 1; H[0] = 0;
            for (int i = 1; i <= n; i++) {
                P[i] = P[i - 1] * BASE % MOD;
            }
            // hash(s) = s[0] * base^(n-1) + s[1] * base^(n-2) + ... + s[n-2] * base + s[n-1]
            for (int i = 1; i <= n; i++) {
                H[i] = (H[i - 1] * BASE + s[i - 1]) % MOD;
            }
        }

        long long query(int l, int r) {
            if (l > r) return 0;
            return (H[r + 1] - H[l] * P[r - l + 1] % MOD + MOD) % MOD;
        }
    };

    int main(string target) {
        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        const int BASE = uniform_int_distribution<>(8e8, 9e8)(rng);
        HashObj t(target, BASE);
        ...
        return 0;
    }
}
```

BIT/Fenwick tree: LC 307

Segment tree: lc 3165

Digit dp: lc 2376

Digit dp with lower bound and is_num: 1067

pre-calculate number of prime numbers: LC 3233

### C++ template

For online GDB

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

istream &in = cin;
ostream &out = cout;

void solve(int m, int n) {
    if (m % 2 == 0 || n % 2 == 0) {
        out << m * n / 2 << endl;
        return;
    }
    out << (n - 1) / 2 * m + m / 2 << endl;
}

int main() {
    int tc;
    in >> tc;
    for (int i = 0; i < tc; i++) {
        int size;
        in >> size;
        solve(size);
    }
    return 0;
}
```

For local debugging:

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
string inputFile = dir + "input.txt";
string outputFile = dir + "output.txt";
string expectFile = dir + "expect.txt";

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

void solve(int m, int n) {
    if (m % 2 == 0 || n % 2 == 0) {
        out << m * n / 2 << endl;
        return;
    }
    out << (n - 1) / 2 * m + m / 2 << endl;
}

int main() {
    int tc;
    in >> tc;
    for (int i = 0; i < tc; i++) {
        int size;
        in >> size;
        solve(size);
    }
    return 0;
}
```

### To compare and run the test

```bash
touch input.txt
touch expect.txt
```

```bash
g++ main.cpp -std=c++17 -DTEST
```
