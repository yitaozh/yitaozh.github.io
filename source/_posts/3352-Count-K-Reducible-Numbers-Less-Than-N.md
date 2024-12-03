---
title: 3352. Count K-Reducible Numbers Less Than N
categories: Leetcode
date: 2024-12-03 17:12:55
tags:
    - Math
    - String
    - Dynamic Programming
    - Combinatorics
---

[3352. Count K-Reducible Numbers Less Than N](https://leetcode.com/problems/count-k-reducible-numbers-less-than-n/)

## Description

You are given an integer array `nums`. A **good** subsequence is defined as a subsequence of `nums` where the absolute difference between any **two**  consecutive elements in the subsequence is **exactly**  1.

Return the **sum**  of all possible **good subsequences**  of `nums`.

Since the answer may be very large, return it **modulo**  `10^9 + 7`.

**Note** that a subsequence of size 1 is considered good by definition.

**Example 1:**

```bash
Input: nums = [1,2,1]

Output: 14
```

Explanation:

- Good subsequences are: `[1]`, `[2]`, `[1]`, `[1,2]`, `[2,1]`, `[1,2,1]`.
- The sum of elements in these subsequences is 14.

**Example 2:**

```bash
Input: nums = [3,4,5]

Output: 40
```

Explanation:

- Good subsequences are: `[3]`, `[4]`, `[5]`, `[3,4]`, `[4,5]`, `[3,4,5]`.
- The sum of elements in these subsequences is 40.

**Constraints:**

- `1 <= nums.length <= 10^5`
- `0 <= nums[i] <= 10^5`

## Hints/Notes

- 2024/11/26
- digit dp
- [0x3F's solution](https://leetcode.cn/problems/count-k-reducible-numbers-less-than-n/solutions/2983541/xian-xing-dp-shu-wei-dppythonjavacgo-by-yw0dl/)
- Weekly Contest 423

## Solution

Language: **C++**

```C++
class Solution {
public:
    string s;
    vector<bool> reducible;
    vector<vector<int>> dp;
    int MOD = 1'000'000'007;

    int countKReducibleNumbers(string s, int k) {
        this->s = s;
        reducible.resize(s.size() + 1, false);
        reducible[1] = true;
        for (int i = 0; i < k - 1; i++) {
            for (int j = s.size(); j > 1; j--) {
                reducible[j] = reducible[j] || reducible[__builtin_popcount(j)];
            }
        }
        dp.resize(s.size(), vector<int>(s.size() + 1, -1));
        int res = dfs(0, 0, true);
        return res;
    }

    int dfs(int index, int count, bool isLimit) {
        if (index == s.size()) {
            return reducible[count] && !isLimit;
        }
        if (!isLimit && dp[index][count] != -1) {
            return dp[index][count];
        }
        long res = 0;
        int up = isLimit ? s[index] - '0' : 1;
        for (int i = 0; i <= up; i++) {
            res = (res + dfs(index + 1, count + i, isLimit && i == up)) % MOD;
        }
        if (!isLimit) {
            dp[index][count] = res;
        }
        return res;
    }
};
```
