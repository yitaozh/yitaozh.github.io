---
title: 97. Interleaving String
categories: Leetcode
date: 2024-12-27 02:39:50
tags:
    - String
    - Dynamic Programming
---

[97. Interleaving String](https://leetcode.com/problems/interleaving-string/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Given strings `s1`, `s2`, and `s3`, find whether `s3` is formed by an **interleaving**  of `s1` and `s2`.

An **interleaving**  of two strings `s` and `t` is a configuration where `s` and `t` are divided into `n` and `m` substrings respectively, such that:

- s = s<sub>1</sub> + s<sub>2</sub> + ... + s<sub>n</sub>
- t = t<sub>1</sub> + t<sub>2</sub> + ... + t<sub>m</sub>
- `|n - m| <= 1`
- The **interleaving**  is s<sub>1</sub> + t<sub>1</sub> + s<sub>2</sub> + t<sub>2</sub> + s<sub>3</sub> + t<sub>3</sub> + ...` or `t<sub>1</sub> + s<sub>1</sub> + t<sub>2</sub> + s<sub>2</sub> + t<sub>3</sub> + s<sub>3</sub> + ...

**Note:**  `a + b` is the concatenation of strings `a` and `b`.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/09/02/interleave.jpg" style="width: 561px; height: 203px;">

```bash
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Explanation: One way to obtain s3 is:
Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
Since s3 can be obtained by interleaving s1 and s2, we return true.
```

**Example 2:**

```bash
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Explanation: Notice how it is impossible to interleave s2 with any other string to obtain s3.
```

**Example 3:**

```bash
Input: s1 = "", s2 = "", s3 = ""
Output: true
```

**Constraints:**

- `0 <= s1.length, s2.length <= 100`
- `0 <= s3.length <= 200`
- `s1`, `s2`, and `s3` consist of lowercase English letters.

**Follow up:**  Could you solve it using only `O(s2.length)` additional memory space?

## Hints/Notes

- 2024/12/26
- dp
- No solution from 0x3F

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<int>> dp;

    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if (m + n != s3.size()) {
            return false;
        }
        dp.resize(m + 1, vector<int>(n + 1, -1));
        return dfs(0, 0, s1, s2, s3);
    }

    bool dfs(int i, int j, string& s1, string& s2, string& s3) {
        if (i == s1.size() && j == s2.size()) {
            return true;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int res = 0;
        if (i < s1.size() && s1[i] == s3[i + j]) {
            res = dfs(i + 1, j, s1, s2, s3);
        }
        if (res) {
            dp[i][j] = res;
            return res;
        }
        if (j < s2.size() && s2[j] == s3[i + j]) {
            res = dfs(i, j + 1, s1, s2, s3);
        }
        dp[i][j] = res;
        return res;
    }
};
```
