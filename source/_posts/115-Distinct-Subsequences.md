---
title: 115. Distinct Subsequences
categories: Leetcode
date: 2024-07-16 00:11:46
tags:
    - String
    - Dynamic Programming
---

[115. Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/description/)

## Description

Given two strings s and t, return <i>the number of distinct</i> <b><i>subsequences</i></b><i> of </i>s<i> which equals </i>t.

The test cases are generated so that the answer fits on a 32-bit signed integer.

**Example 1:**

```bash
Input: s = "rabbbit", t = "rabbit"
Output: 3
```

Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.

**rabb** b **it**

**ra** b **bbit**

**rab** b **bit**

**Example 2:**

```bash
Input: s = "babgbag", t = "bag"
Output: 5
```

Explanation:
As shown below, there are 5 ways you can generate "bag" from s.

**ba** b **g** bag

**ba** bgba **g**

**b** abgb **ag**

ba **b** gb **ag**

babg **bag**

**Constraints:**

- `1 <= s.length, t.length <= 1000`
- `s` and `t` consist of English letters.

## Hints/Notes

- 2024/07/11
- dp
- No solution from 0x3F

## Solution

Language: **C++**

```C++
class Solution {
public:
    string s_, t_;
    vector<vector<int>> dp;

    int numDistinct(string s, string t) {
        dp.resize(s.size(), vector<int>(t.size(), -1));
        s_ = s;
        t_ = t;
        int res = traverse(0, 0);
        return res;
    }

    int traverse(int idx1, int idx2) {
        if (idx2 == t_.size()) {
            return 1;
        }
        if (idx1 == s_.size()) {
            return 0;
        }
        if (dp[idx1][idx2] != -1) {
            return dp[idx1][idx2];
        }
        int ans = 0;
        if (s_[idx1] == t_[idx2]) {
            ans += traverse(idx1 + 1, idx2 + 1);
        }
        ans += traverse(idx1 + 1, idx2);
        dp[idx1][idx2] = ans;
        return ans;
    }
};
```
