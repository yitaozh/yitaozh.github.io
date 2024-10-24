---
title: 3282. Reach End of Array With Max Score
categories: Leetcode
date: 2024-10-08 15:57:32
tags:
    - Array
    - Greedy
---

[3282. Reach End of Array With Max Score](https://leetcode.com/problems/reach-end-of-array-with-max-score/description/)

## Description

You are given an integer array `nums` of length `n`.

Your goal is to start at index `0` and reach index `n - 1`. You can only jump to indices **greater**  than your current index.

The score for a jump from index `i` to index `j` is calculated as `(j - i) * nums[i]`.

Return the **maximum**  possible <b>total score</b> by the time you reach the last index.

**Example 1:**

```bash
Input: nums = [1,3,1,5]

Output: 7
```

Explanation:

First, jump to index 1 and then jump to the last index. The final score is `1 * 1 + 2 * 3 = 7`.

**Example 2:**

```bash
Input: nums = [4,3,1,3,2]

Output: 16
```

Explanation:

Jump directly to the last index. The final score is `4 * 4 = 16`.

**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^5`

## Hints/Notes

- Draw the metric, it's the sum of rectangles
- Weekly Contest 414

## Solution

Language: **C++**

```C++
class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long res = 0;
        int idx = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[idx]) {
                res += (long)nums[idx] * (i - idx);
                idx = i;
            }
        }
        res += (long)(nums[idx]) * (nums.size() - 1 - idx);
        return res;
    }
};
```
