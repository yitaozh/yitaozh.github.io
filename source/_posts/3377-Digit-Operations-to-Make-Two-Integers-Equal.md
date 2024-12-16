---
title: 3377. Digit Operations to Make Two Integers Equal
categories: Leetcode
date: 2024-12-15 23:31:26
tags:
    - Math
    - Graph
    - Heap (Priority Queue)
    - Number Theory
    - Shortest Path
---

[3377. Digit Operations to Make Two Integers Equal](https://leetcode.com/problems/digit-operations-to-make-two-integers-equal/description/)

## Description

You are given two integers `n` and `m` that consist of the **same**  number of digits.

You can perform the following operations **any**  number of times:

- Choose **any**  digit from `n` that is not 9 and **increase**  it by 1.
- Choose **any**  digit from `n` that is not 0 and **decrease**  it by 1.

The integer `n` must not be a prime number at any point, including its original value and after each operation.

The cost of a transformation is the sum of **all**  values that `n` takes throughout the operations performed.

Return the **minimum**  cost to transform `n` into `m`. If it is impossible, return -1.

**Example 1:**

```bash
Input: n = 10, m = 12

Output: 85
```

Explanation:

We perform the following operations:

- Increase the first digit, now n = **2**0.
- Increase the second digit, now n = 2**1**.
- Increase the second digit, now n = 2**2**.
- Decrease the first digit, now n = **1**2.

**Example 2:**

```bash
Input: n = 4, m = 8

Output: -1
```

Explanation:

It is impossible to make `n` equal to `m`.

**Example 3:**

```bash
Input: n = 6, m = 2

Output: -1
```

Explanation:

Since 2 is already a prime, we can't make `n` equal to `m`.

**Constraints:**

- `1 <= n, m < 10^4`
- `n` and `m` consist of the same number of digits.

## Hints/Notes

- 2024/12/10
- dijkstra's algorithm
- pre-calculate the prime numbers
- [0x3F's solution](https://leetcode.cn/problems/digit-operations-to-make-two-integers-equal/solutions/3013737/dijkstra-zui-duan-lu-pythonjavacgo-by-en-ofby/)(checked)
- Biweekly Contest 145

## Solution

Language: **C++**

```C++
const int MX = 10000;
bool np[MX];

int init = [] {
    np[1] = true;
    for (int i = 2; i < MX; i++) {
        if (!np[i]) {
            for (int j = i * i; j < MX; j += i) {
                np[j] = true;
            }
        }
    }
    return 0;
}();

class Solution {
public:
    int minOperations(int n, int m) {
        int res = 0;
        if (!np[n] || !np[m]) {
            return -1;
        }
        int len = to_string(n).size();
        vector<int> dis(pow(10, len), INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(n, n);
        while (!pq.empty()) {
            auto [dis_x, x] = pq.top();
            pq.pop();
            if (x == m) {
                return dis_x;
            }
            if (dis[x] < dis_x) {
                continue;
            }
            int pow10 = 1;
            for (int v = x; v; v /= 10) {
                int d = v % 10;
                if (d > 0) {
                    int y = x - pow10;
                    int dis_y = dis_x + y;
                    if (np[y] && dis_y < dis[y]) {
                        pq.emplace(dis_y, y);
                        dis[y] = dis_y;
                    }
                }
                if (d < 9) {
                    int y = x + pow10;
                    int dis_y = dis_x + y;
                    if (np[y] && dis_y < dis[y]) {
                        pq.emplace(dis_y, y);
                        dis[y] = dis_y;
                    }
                }
                pow10 *= 10;
            }
        }
        return -1;
    }
};
```
