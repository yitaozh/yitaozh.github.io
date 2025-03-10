---
title: 3472. Longest Palindromic Subsequence After at Most K Operations
categories: Leetcode
date: 2025-03-10 02:33:47
tags:
    - String
    - Dynamic Programming
---

[3472. Longest Palindromic Subsequence After at Most K Operations](https://leetcode.com/problems/longest-palindromic-subsequence-after-at-most-k-operations/description/)

## Description

You are given a string `s` and an integer `k`.

In one operation, you can replace the character at any position with the next or previous letter in the alphabet (wrapping around so that `'a'` is after `'z'`). For example, replacing `'a'` with the next letter results in `'b'`, and replacing `'a'` with the previous letter results in `'z'`. Similarly, replacing `'z'` with the next letter results in `'a'`, and replacing `'z'` with the previous letter results in `'y'`.

Return the length of the **longest palindromic subsequence**  of `s` that can be obtained after performing **at most**  `k` operations.

**Example 1:**

```bash
Input: s = "abced", k = 2

Output: 3
```

Explanation:

- Replace `s[1]` with the next letter, and `s` becomes `"acced"`.
- Replace `s[4]` with the previous letter, and `s` becomes `"accec"`.

The subsequence `"ccc"` forms a palindrome of length 3, which is the maximum.

**Example 2:**

```bash
Input: s = "aaazzz", k = 4

Output: 6
```

Explanation:

- Replace `s[0]` with the previous letter, and `s` becomes `"zaazzz"`.
- Replace `s[4]` with the next letter, and `s` becomes `"zaazaz"`.
- Replace `s[3]` with the next letter, and `s` becomes `"zaaaaz"`.

The entire string forms a palindrome of length 6.

**Constraints:**

- `1 <= s.length <= 200`
- `1 <= k <= 200`
- `s` consists of only lowercase English letters.

## Hints/Notes

- 2025/03/01
- dp
- [0x3F's solution](https://leetcode.cn/problems/longest-palindromic-subsequence-after-at-most-k-operations/solutions/3591706/qu-jian-dppythonjavacgo-by-endlesscheng-sd78/)
- Weekly Contest 439

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<vector<int>>> dp;

    int longestPalindromicSubsequence(string s, int k) {
        int n = s.size();
        dp.resize(n, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        int res = dfs(s, 0, n - 1, k);
        return res;
    }

    int dfs(string& s, int start, int end, int k) {
        if (start > end) {
            return 0;
        }
        if (start == end) {
            return 1;
        }
        if (dp[start][end][k] != -1) {
            return dp[start][end][k];
        }

        int& res = dp[start][end][k];
        int needed1 = abs((s[start] - s[end] + 26) % 26);
        int needed2 = abs((s[end] - s[start] + 26) % 26);
        int needed = min(needed1, needed2);
        if (needed <= k) {
            res = 2 + dfs(s, start + 1, end - 1, k - needed);
        }
        res = max({res, dfs(s, start, end - 1, k), dfs(s, start + 1, end, k)});
        return res;
    }
};
```
