---
title: 3333. Find the Original Typed String II
categories: Leetcode
date: 2024-11-20 14:45:46
tags:
    - String
    - Dynamic Programming
    - Prefix Sum
---

[3333. Find the Original Typed String II](https://leetcode.com/problems/find-the-original-typed-string-ii/description/)

## Description

Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and **may**  press a key for too long, resulting in a character being typed **multiple**  times.

You are given a string `word`, which represents the **final**  output displayed on Alice's screen. You are also given a **positive**  integer `k`.

Return the total number of possible original strings that Alice might have intended to type, if she was trying to type a string of size **at least**  `k`.

Since the answer may be very large, return it **modulo**  `10^9 + 7`.

**Example 1:**

```bash
Input: word = "aabbccdd", k = 7

Output: 5
```

Explanation:

The possible strings are: `"aabbccdd"`, `"aabbccd"`, `"aabbcdd"`, `"aabccdd"`, and `"abbccdd"`.

**Example 2:**

```bash
Input: word = "aabbccdd", k = 8

Output: 1
```

Explanation:

The only possible string is `"aabbccdd"`.

**Example 3:**

```bash
Input: word = "aaabbb", k = 3

Output: 8
```

**Constraints:**

- `1 <= word.length <= 5 * 10^5`
- `word` consists only of lowercase English letters.
- `1 <= k <= 2000`

## Hints/Notes

- 2024/11/02
- dp with preSum
- [0x3F's solution](https://leetcode.cn/problems/find-the-original-typed-string-ii/solutions/2966856/zheng-nan-ze-fan-qian-zhui-he-you-hua-dp-5mi9/)(checked)
- Biweekly Contest 142

## Solution

Language: **C++**

```C++
class Solution {
public:
    // what we want to calculate here:
    // the number of strings with len < k
    // the meaning of dp[i][j]: when we are at ith index of len,
    // we have j digits left, how many such strings we can form
    int possibleStringCount(string word, int k) {
        vector<int> lens;
        int n = word.size(), MOD = 1e9 + 7;
        for (int i = 0; i < n;) {
            int c = word[i], left = i;
            while (i < n && word[i] == c) {
                i++;
            }
            lens.push_back(i - left);
        }
        int len = lens.size();
        long res = 1;
        if (len == k) {
            return res;
        }
        for (int i = 0; i < len; i++) {
            res = (res * lens[i]) % MOD;
        }
        vector<long> preSum(k + 1, 0);
        // the range of dp[i][j]:
        // i is index, [0, len]
        // j is the remaining length [0, k - 1]
        vector<vector<int>> dp(len + 1, vector<int>(k, -1));
        for (int i = 0; i < k; i++) {
            dp[len][i] = 1;
            preSum[i + 1] = (preSum[i] + 1) % MOD;
        }
        // maxI = min(lens[idx],rem - (len - idx - 1));
        // dp[i][j] = dp[i + 1][j - 1] + dp[i + 1][j - 2] + ... + dp[i + 1][j - maxI]
        // so if we have a preSum, it would be preSum[j - 1] - preSum[j - maxI - 1]
        for (int i = len - 1; i >= 0; i--) {
            for (int j = 0; j < k; j++) {
                int maxI = min(lens[i], j - (len - i - 1));
                int start = j - maxI;
                dp[i][j] = (preSum[j] - preSum[start] + MOD) % MOD;
            }
            for (int j = 0; j < k; j++) {
                preSum[j + 1] = (preSum[j] + dp[i][j]) % MOD;
            }
        }
        return (res - dp[0][k - 1] + MOD) % MOD;
    }
};
```

The recursive solution:

```C++
class Solution {
public:
    // what we want to calculate here:
    // the number of strings with len < k
    // the meaning of dp[i][j]: when we are at kth index of len,
    // we have j digits left, how many such strings we can form
    vector<vector<int>> dp;
    vector<int> lens;
    int MOD = 1e9 + 7, len;

    int possibleStringCount(string word, int k) {
        dp.resize(k, vector<int>(k, -1));
        int n = word.size();
        for (int i = 0; i < n;) {
            int c = word[i], left = i;
            while (i < n && word[i] == c) {
                i++;
            }
            lens.push_back(i - left);
        }
        len = lens.size();
        long res = 1;
        for (int i = 0; i < len; i++) {
            res = (res * lens[i]) % MOD;
        }
        if (len >= k) {
            return res;
        }
        int less = dfs(0, k - 1);
        return (res - less + MOD) % MOD;
    }

    int dfs(int idx, int rem) {
        // it means we reached the end of the lens
        if (idx == len) {
            return 1;
        }
        // there needs at least one digit for one lens item
        if (len - idx > rem) {
            return 0;
        }
        if (dp[idx][rem] != -1) {
            return dp[idx][rem];
        }
        // now we are at lens[idx], how many number can we pick at this index?
        // if we pick at least one digit per index, then we will pick
        // lens.size() - index number
        // we can pick from 1 to rem - (lens.size() - index - 1)
        long long res = 0;
        for (int i = 1; i <= min(lens[idx],rem - (len - idx - 1)); i++) {
            res = (res + dfs(idx + 1, rem - i)) % MOD;
        }
        dp[idx][rem] = res;
        return res;1111111
    }
};
```
