---
title: 3316. Find Maximum Removals From Source String
categories: Leetcode
date: 2024-10-19 16:38:31
tags:
    - Array
    - Hash Table
    - Two Pointers
    - String
    - Dynamic Programming
---

[3316. Find Maximum Removals From Source String](https://leetcode.com/problems/find-maximum-removals-from-source-string/description/)

## Description

You are given a string `source` of size `n`, a string `pattern` that is a subsequence of `source`, and a **sorted**  integer array `targetIndices` that contains **distinct**  numbers in the range `[0, n - 1]`.

We define an **operation**  as removing a character at an index `idx` from `source` such that:

- `idx` is an element of `targetIndices`.
- `pattern` remains a subsequence of `source` after removing the character.

Performing an operation **does not**  change the indices of the other characters in `source`. For example, if you remove `'c'` from `"acb"`, the character at index 2 would still be `'b'`.

Return the **maximum**  number of operations that can be performed.

**Example 1:**

```bash
Input: source = "abbaa", pattern = "aba", targetIndices = [0,1,2]

Output: 1
```

Explanation:

We can't remove `source[0]` but we can do either of these two operations:

- Remove `source[1]`, so that `source` becomes `"a_baa"`.
- Remove `source[2]`, so that `source` becomes `"ab_aa"`.

**Example 2:**

```bash
Input: source = "bcda", pattern = "d", targetIndices = [0,3]

Output: 2
```

Explanation:

We can remove `source[0]` and `source[3]` in two operations.

**Example 3:**

```bash
Input: source = "dda", pattern = "dda", targetIndices = [0,1,2]

Output: 0
```

Explanation:

We can't remove any character from `source`.

**Example 4:**

```bash
Input: source = "yeyeykyded", pattern = "yeyyd", targetIndices = [0,2,3,4]

Output: 2
```

Explanation:

We can remove `source[2]` and `source[3]` in two operations.

**Constraints:**

- `1 <= n == source.length <= 3 * 10^3`
- `1 <= pattern.length <= n`
- `1 <= targetIndices.length <= n`
- `targetIndices` is sorted in ascending order.
- The input is generated such that `targetIndices` contains distinct elements in the range `[0, n - 1]`.
- `source` and `pattern` consist only of lowercase English letters.
- The input is generated such that `pattern` appears as a subsequence in `source`.

## Hints/Notes

- Biweekly Contest 141

## Solution

Language: **C++**

```C++
class Solution {
public:
    // the meaning of dp[i][j]:
    //  when we are at ith index of source and jth index of pattern
    //  the maximum number of removals we can achieve later
    vector<vector<int>> dp;
    string source_, pattern_;

    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        int m = source.size(), n = pattern.size();
        set<int> targets(targetIndices.begin(), targetIndices.end());
        source_ = source; pattern_ = pattern;
        dp.resize(m, vector<int>(n, INT_MIN));
        int res = dfs(0, 0, targets);
        return res;
    }

    int dfs(int idx1, int idx2, set<int>& targets) {
        // all pattern matched, all deletions afterwards can be applied
        if (idx2 == pattern_.size()) {
            auto it = targets.lower_bound(idx1);
            return distance(it, targets.end());
        }
        // we cannot match the pattern, return -n as a sign of failure
        if (idx1 == source_.size()) {
            return -targets.size();
        }
        if (dp[idx1][idx2] != INT_MIN) {
            return dp[idx1][idx2];
        }
        int res = 0;
        // delete or just skip
        if (targets.contains(idx1)) {
            res = 1 + dfs(idx1 + 1, idx2, targets);
        } else {
            res = dfs(idx1 + 1, idx2, targets);
        }
        // match
        if (source_[idx1] == pattern_[idx2]) {
            res = max(res, dfs(idx1 + 1, idx2 + 1, targets));
        }
        dp[idx1][idx2] = res;
        return res;
    }
};
```
