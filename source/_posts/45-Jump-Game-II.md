---
title: 45. Jump Game II
categories: Leetcode
date: 2024-12-21 01:11:37
tags:
    - Array
    - Dynamic Programming
    - Greedy
---

[45. Jump Game II](https://leetcode.com/problems/jump-game-ii/description/?envType=problem-list-v2&envId=plakya4j)

## Description

You are given a **0-indexed**  array of integers `nums` of length `n`. You are initially positioned at `nums[0]`.

Each element `nums[i]` represents the maximum length of a forward jump from index `i`. In other words, if you are at `nums[i]`, you can jump to any `nums[i + j]` where:

- `0 <= j <= nums[i]` and
- `i + j < n`

Return the minimum number of jumps to reach `nums[n - 1]`. The test cases are generated such that you can reach `nums[n - 1]`.

**Example 1:**

```bash
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
```

**Example 2:**

```bash
Input: nums = [2,3,0,1,4]
Output: 2
```

**Constraints:**

- `1 <= nums.length <= 10^4`
- `0 <= nums[i] <= 1000`
- It's guaranteed that you can reach `nums[n - 1]`.

## Hints/Notes

- 2024/12/20
- greedy
- [0x3F's solution](https://leetcode.cn/problems/jump-game-ii/solutions/2926993/tu-jie-yi-zhang-tu-miao-dong-tiao-yue-yo-h2d4/)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), cur_r = 0, next_r = 0, res = 0;
        for (int i = 0; i < n; i++) {
            next_r = max(next_r, i + nums[i]);
            if (i == cur_r && i != n - 1) {
                cur_r = next_r;
                res++;
            }
        }
        return res;
    }
};
```
