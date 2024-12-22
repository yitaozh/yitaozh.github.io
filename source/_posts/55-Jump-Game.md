---
title: 55. Jump Game
categories: Leetcode
date: 2024-12-22 01:18:36
tags:
    - Array
    - Dynamic Programming
    - Greedy
---

[55. Jump Game](https://leetcode.com/problems/jump-game/description/?envType=problem-list-v2&envId=plakya4j)

## Description

You are given an integer array `nums`. You are initially positioned at the array's **first index** , and each element in the array represents your maximum jump length at that position.

Return `true` if you can reach the last index, or `false` otherwise.

**Example 1:**

```bash
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
```

**Example 2:**

```bash
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
```

**Constraints:**

- `1 <= nums.length <= 10^4`
- `0 <= nums[i] <= 10^5`

## Hints/Notes

- 2024/12/21
- greedy
- [0x3F's solution](https://leetcode.cn/problems/jump-game/solutions/2798996/liang-chong-li-jie-fang-shi-wei-hu-zui-y-q67s/)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int end = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > end) {
                return false;
            }
            end = max(end, i + nums[i]);
        }
        return true;
    }
};
```
