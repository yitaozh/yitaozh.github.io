---
title: 2379. Minimum Recolors to Get K Consecutive Black Blocks
categories: Leetcode
date: 2024-10-22 14:44:52
tags:
    - String
    - Sliding Window
---

[2379. Minimum Recolors to Get K Consecutive Black Blocks](https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/description/)

## Description

You are given a **0-indexed**  string `blocks` of length `n`, where `blocks[i]` is either `'W'` or `'B'`, representing the color of the `i^th` block. The characters `'W'` and `'B'` denote the colors white and black, respectively.

You are also given an integer `k`, which is the desired number of **consecutive**  black blocks.

In one operation, you can **recolor**  a white block such that it becomes a black block.

Return the **minimum**  number of operations needed such that there is at least **one**  occurrence of `k` consecutive black blocks.

**Example 1:**

```bash
Input: blocks = "WBBWWBBWBW", k = 7
Output: 3

Explanation:
One way to achieve 7 consecutive black blocks is to recolor the 0th, 3rd, and 4th blocks
so that blocks = "BBBBBBBWBW".
It can be shown that there is no way to achieve 7 consecutive black blocks in less than 3 operations.
Therefore, we return 3.
```

**Example 2:**

```bash
Input: blocks = "WBWBBBW", k = 2
Output: 0

Explanation:
No changes need to be made, since 2 consecutive black blocks already exist.
Therefore, we return 0.
```

**Constraints:**

- `n == blocks.length`
- `1 <= n <= 100`
- `blocks[i]` is either `'W'` or `'B'`.
- `1 <= k <= n`

## Hints/Notes

- 2024/10/06
- sliding window
- [0x3F's solution](https://leetcode.cn/problems/minimum-recolors-to-get-k-consecutive-black-blocks/solutions/1763639/on-hua-dong-chuang-kou-by-endlesscheng-s4fx/)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int res = INT_MAX, right = 0, cur = 0;
        while (right < blocks.size()) {
            cur += blocks[right] == 'W' ? 1 : 0;
            if (right >= k - 1) {
                res = min(res, cur);
                cur -= blocks[right - k + 1] == 'W' ? 1 : 0;
            }
            right++;
        }
        return res;
    }
};
```
