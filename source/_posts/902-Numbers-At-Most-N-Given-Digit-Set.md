---
title: 902. Numbers At Most N Given Digit Set
categories: Leetcode
date: 2024-11-26 18:01:19
tags:
    - Array
    - Math
    - String
    - Binary Search
    - Dynamic Programming
---

[902. Numbers At Most N Given Digit Set](https://leetcode.com/problems/numbers-at-most-n-given-digit-set/description/)

## Description

Given an array of `digits` which is sorted in **non-decreasing**  order. You can write numbers using each `digits[i]` as many times as we want. For example, if `digits = ['1','3','5']`, we may write numbers such as `'13'`, `'551'`, and `'1351315'`.

Return the number of positive integers that can be generated that are less than or equal to a given integer `n`.

**Example 1:**

```bash
Input: digits = ["1","3","5","7"], n = 100
Output: 20
Explanation:
The 20 numbers that can be written are:
1, 3, 5, 7, 11, 13, 15, 17, 31, 33, 35, 37, 51, 53, 55, 57, 71, 73, 75, 77.
```

**Example 2:**

```bash
Input: digits = ["1","4","9"], n = 1000000000
Output: 29523
Explanation:
We can write 3 one digit numbers, 9 two digit numbers, 27 three digit numbers,
81 four digit numbers, 243 five digit numbers, 729 six digit numbers,
2187 seven digit numbers, 6561 eight digit numbers, and 19683 nine digit numbers.
In total, this is 29523 integers that can be written using the digits array.
```

**Example 3:**

```bash
Input: digits = ["7"], n = 8
Output: 1
```

**Constraints:**

- `1 <= digits.length <= 9`
- `digits[i].length == 1`
- `digits[i]` is a digit from`'1'`to `'9'`.
- All the values in`digits` are **unique** .
- `digits` is sorted in**non-decreasing**  order.
- `1 <= n <= 10^9`

## Hints/Notes

- 2024/11/15
- digit dp
- [0x3F's solution](https://leetcode.cn/problems/numbers-at-most-n-given-digit-set/solutions/1900101/shu-wei-dp-tong-yong-mo-ban-xiang-xi-zhu-e5dg/)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    string s;
    vector<int> dp;
    set<int> st;
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        for (auto& d : digits) {
            st.insert(stoi(d));
        }
        s = to_string(n);
        dp.resize(s.size(), -1);
        int res = dfs(0, true, false);
        return res;
    }

    int dfs(int index, bool isLimit, bool isNum) {
        if (index == s.size()) {
            return isNum;
        }
        if (!isLimit && isNum && dp[index] != -1) {
            return dp[index];
        }
        int res = isNum ? 0 : dfs(index + 1, false, false);
        int up = isLimit ? s[index] - '0' : 9;
        // if we start from 0 here when isNum is false, we are taking
        // 0 as a value answer
        for (auto& d : st){
            if (d > up) {
                break;
            }
            res += dfs(index + 1, isLimit && d == up, true);
        }
        // check status during read and write memo both
        if (!isLimit && isNum) {
            dp[index] = res;
        }
        return res;
    }
};
```
