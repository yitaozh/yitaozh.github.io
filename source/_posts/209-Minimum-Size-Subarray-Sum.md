---
title: 209. Minimum Size Subarray Sum
categories: Leetcode
date: 2025-03-13 13:09:09
tags:
    - Array
    - Binary Search
    - Sliding Window
    - Prefix Sum
---

[209. Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/description/)

## Description

Given an array of positive integers `nums` and a positive integer `target`, return the **minimal length**  of a subarray whose sum is greater than or equal to `target`. If there is no such subarray, return `0` instead.

**Example 1:**

```bash
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
```

**Example 2:**

```bash
Input: target = 4, nums = [1,4,4]
Output: 1
```

**Example 3:**

```bash
Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
```

**Constraints:**

- `1 <= target <= 10^9`
- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^4`

**Follow up:**  If you have figured out the `O(n)` solution, try coding another solution of which the time complexity is `O(n log(n))`.

## Hints/Notes

- 2025/03/02 Q1
- preSum
- [0x3F's solution](https://leetcode.cn/problems/minimum-size-subarray-sum/solutions/1959532/biao-ti-xia-biao-zong-suan-cuo-qing-kan-k81nh/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, n = nums.size(), curSum = 0, res = INT_MAX;
        for (int right = 0; right < n; right++) {
            curSum += nums[right];
            while (curSum >= target) {
                res = min(res, right - left + 1);
                curSum -= nums[left];
                left++;
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
```
