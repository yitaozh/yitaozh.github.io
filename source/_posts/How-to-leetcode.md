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

2. The [Explore](https://leetcode.com/explore/featured/) is a great place next. Finish all courses.

3. Use the daily problem and study plan tool

### The steps to tackle one problem

If not idea at all, just check the comments. No need to wait for 5, 10 minutes

### Advance

* Weekly contest, then codeforce
* Watch this [video series](https://www.youtube.com/@BackToBackSWE/videos) to learn how to speak the story

### Current leetcode blog

[【强化练习】用「分解问题」思维解题 I](https://labuladong.online/algo/problem-set/binary-tree-divide-1/)

### Last problem solved

~~New page.~~

[1490. 克隆 N 叉树](https://leetcode.com/problems/clone-n-ary-tree/)

### The problems not solved

1696 and 1425 in [【强化练习】单调队列的通用实现及经典习题](https://appktavsiei5995.pc.xiaoe-tech.com/p/t_pc/course_pc_detail/image_text/i_62a692efe4b01a48520b9b9b?product_id=p_627cd0eae4b0cedf38b0ef74&content_app_id=&type=8&parent_pro_id=p_62654124e4b09dda125f9a8d)

Biweekly Contest 130 t4: 3145

### The problems not recorded

None

### The best way to record the progression

Screenshot the next day's list

New question date: 2024-04-11

### The problems not noted

```bash
find source/_posts/ -name "[0-9]*" |  xargs grep -L "Hints"
```

### The problems not tagged

```bash
find source/_posts/ -name "[0-9]*" | xargs grep -A 1 "tags" | grep -e "---"
```

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
