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
    // the meaning of dp[i][j]: when we are at kth index of len,
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
        for (int i = 0; i < len; i++) {
            res = (res * lens[i]) % MOD;
        }
        if (len >= k) {
            return res;
        }
        vector<long> preSum(k + 1, 0);
        // the range of dp[i][j]:
        // i is index, [0, len]
        // j is the remaining length [0, k - 1]
        vector<vector<int>> dp(len + 1, vector<int>(k, -1));
        for (int i = 0; i < k; i++) {
            // the initialization: we reached the index == len
            // the return value is 1
            dp[len][i] = 1;
            preSum[i + 1] = (preSum[i] + 1) % MOD;
        }
        // maxI = min(lens[idx], rem - (len - idx - 1));
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
