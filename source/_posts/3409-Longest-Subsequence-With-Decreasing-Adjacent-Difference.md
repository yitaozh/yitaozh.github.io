---
title: 3409. Longest Subsequence With Decreasing Adjacent Difference
categories: Leetcode
date: 2025-01-10 17:26:12
tags:
    - Array
    - Dynamic Programming
---

[3409. Longest Subsequence With Decreasing Adjacent Difference](https://leetcode.com/problems/longest-subsequence-with-decreasing-adjacent-difference/description/)

## Description

You are given an array of integers `nums`.

Your task is to find the length of the **longest** subsequence `seq` of `nums`, such that the **absolute differences**  between consecutive elements form a **non-increasing sequence**  of integers. In other words, for a subsequence seq<sub>0</sub>, seq<sub>1</sub>, seq<sub>2</sub>, ..., seq<sub>m</sub> of `nums`, |seq<sub>1</sub> - seq<sub>0</sub>| >= |seq<sub>2</sub> - seq<sub>1</sub>| >= ... >= |seq<sub>m</sub> - seq<sub>m - 1</sub>|.

Return the length of such a subsequence.

**Example 1:**

```bash
Input: nums = [16,6,3]

Output: 3
```

Explanation:

The longest subsequence is `[16, 6, 3]` with the absolute adjacent differences `[10, 3]`.

**Example 2:**

```bash
Input: nums = [6,5,3,4,2,1]

Output: 4
```

Explanation:

The longest subsequence is `[6, 4, 2, 1]` with the absolute adjacent differences `[2, 2, 1]`.

**Example 3:**

```bash
Input: nums = [10,20,10,19,10,20]

Output: 5
```

Explanation:

The longest subsequence is `[10, 20, 10, 19, 10]` with the absolute adjacent differences `[10, 10, 9, 9]`.

**Constraints:**

- `2 <= nums.length <= 10^4`
- `1 <= nums[i] <= 300`

## Hints/Notes

- 2025/01/12
- dp
- [0x3F's solution](https://leetcode.cn/problems/longest-subsequence-with-decreasing-adjacent-difference/solutions/3038930/zhuang-tai-she-ji-you-hua-pythonjavacgo-qy2bu/)
- Biweekly Contest 147

## Solution

Language: **C++**

```C++
class Solution {
public:
    // the meaning of dp[i][j]: the max subarray size with nums[i] as the
    // final number, and the delta is larger or equal to j
    vector<vector<int>> dp;

    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int mx = ranges::max(nums), mi = ranges::min(nums), delta = mx - mi;
        dp.resize(n, vector<int>(delta + 2, 1));
        vector<int> last(mx + 1, -1);
        int res = 0;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            for (int j = delta; j >= 0; j--) {
                dp[i][j] = max(dp[i][j], dp[i][j + 1]);
                if (x - j >= 0 && last[x - j] >= 0) {
                    dp[i][j] = max(dp[i][j], dp[last[x - j]][j] + 1);
                }
                if (x + j <= mx && last[x + j] >= 0) {
                    dp[i][j] = max(dp[i][j], dp[last[x + j]][j] + 1);
                }
                res = max(res, dp[i][j]);
            }
            last[x] = i;
        }
        return res;
    }
};
```
