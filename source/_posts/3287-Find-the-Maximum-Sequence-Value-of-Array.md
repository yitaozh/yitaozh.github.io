---
title: 3287. Find the Maximum Sequence Value of Array
categories: Leetcode
date: 2024-10-10 00:10:45
tags:
    - Array
    - Dynamic Programming
    - Bit Manipulation
---

[3287. Find the Maximum Sequence Value of Array](https://leetcode.com/problems/find-the-maximum-sequence-value-of-array/description/)

## Description

You are given an integer array `nums` and a **positive**  integer `k`.

The **value**  of a sequence `seq` of size `2 * x` is defined as:

- `(seq[0] OR seq[1] OR ... OR seq[x - 1]) XOR (seq[x] OR seq[x + 1] OR ... OR seq[2 * x - 1])`.

Return the **maximum**  **value**  of any subsequence of `nums` having size `2 * k`.

**Example 1:**

```bash
Input: nums = [2,6,7], k = 1

Output: 5
```

Explanation:

The subsequence `[2, 7]` has the maximum value of `2 XOR 7 = 5`.

**Example 2:**

```bash
Input: nums = [4,2,5,6,7], k = 2

Output: 2
```

Explanation:

The subsequence `[4, 5, 6, 7]` has the maximum value of `(4 OR 5) XOR (6 OR 7) = 2`.

**Constraints:**

- `2 <= nums.length <= 400`
- `1 <= nums[i] < 2^7`
- `1 <= k <= nums.length / 2`

## Hints/Notes

- 2024/09/07
- forwarding dp
- [0x3F's solution](https://leetcode.cn/problems/find-the-maximum-sequence-value-of-array/solutions/2917604/qian-hou-zhui-fen-jie-er-wei-0-1-bei-bao-8icz/)
- Biweekly Contest 139

## Solution

Language: **C++**

```C++
class Solution {
public:
    // the meaning of suf[i][j][x]: for numbers up until i, can we form number x with j numbers
    // for nums[i](num):
    //  if we don't pick it, then suf[i][j][x] |= suf[i + 1][j][x]
    //  if we pick it, then suf[i][j][x | num] |= suf[i + 1][j - 1][x];
    vector<vector<array<bool, 128>>> suf;
    vector<vector<array<bool, 128>>> pre;

    int maxValue(vector<int>& nums, int k) {
        int n = nums.size();
        suf.resize(n + 1, vector<array<bool, 128>>(k + 1, array<bool, 128>{false}));
        pre.resize(n + 1, vector<array<bool, 128>>(k + 1, array<bool, 128>{false}));
        for (int i = 0; i < suf.size(); i++) {
                suf[i][0][0] = true;
                pre[i][0][0] = true;
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            int v = nums[i];
            for (int j = 0; j <= k; j++) {
                for (int x = 0; x < 128; x++) {
                    if (j) {
                        suf[i][j][x | v] |= suf[i + 1][j - 1][x];
                    }
                    suf[i][j][x] |= suf[i + 1][j][x];
                }
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            int v = nums[i];
            for (int j = 0; j <= k; j++) {
                for (int x = 0; x < 128; x++) {
                    if (j) {
                        pre[i + 1][j][x | v] |= pre[i][j - 1][x];
                    }
                    pre[i + 1][j][x] |= pre[i][j][x];
                }
            }
        }
        int res = 0;
        for (int i = k; i <= nums.size() - k; i++) {
            for (int j = 0; j < 128; j++) {
                if (!pre[i][k][j]) {
                    continue;
                }
                for (int l = 0; l < 128; l++) {
                    if (!suf[i][k][l]) {
                        continue;
                    }
                    res = max(res, j ^ l);
                }
            }
        }
        return res;
    }
};
```
