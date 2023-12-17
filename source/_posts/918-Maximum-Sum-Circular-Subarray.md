---
title: 918. Maximum Sum Circular Subarray
categories: Leetcode
date: 2023-12-17 17:39:21
tags:
    - Array
    - Divide and Conquer
    - Dynamic Programming
    - Queue
    - Monotonic Queue
---

# [918\. Maximum Sum Circular Subarray](https://leetcode.com/problems/maximum-sum-circular-subarray/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Divide and Conquer](https://leetcode.com/tag/https://leetcode.com/tag/divide-and-conquer//), [Dynamic Programming](https://leetcode.com/tag/https://leetcode.com/tag/dynamic-programming//), [Queue](https://leetcode.com/tag/https://leetcode.com/tag/queue//), [Monotonic Queue](https://leetcode.com/tag/https://leetcode.com/tag/monotonic-queue//)

Given a **circular integer array** `nums` of length `n`, return _the maximum possible sum of a non-empty **subarray** of_ `nums`.

A **circular array** means the end of the array connects to the beginning of the array. Formally, the next element of `nums[i]` is `nums[(i + 1) % n]` and the previous element of `nums[i]` is `nums[(i - 1 + n) % n]`.

A **subarray** may only include each element of the fixed buffer `nums` at most once. Formally, for a subarray `nums[i], nums[i + 1], ..., nums[j]`, there does not exist `i <= k1`, `k2 <= j` with `k1 % n == k2 % n`.

**Example 1:**

```bash
Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.
```

**Example 2:**

```bash
Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
```

**Example 3:**

```bash
Input: nums = [-3,-2,-3]
Output: -2
Explanation: Subarray [-2] has maximum sum -2.
```

**Constraints:**

* `n == nums.length`
* 1 <= n <= 3 * 10<sup>4</sup>
* -3 \* 10<sup>4</sup> <= nums[i] <= 3 \* 10<sup>4</sup>

## Hints/Notes

* preSum + monotonic queue

## Solution

Language: **C++**

```C++
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        vector<int> preSum(nums.size() * 2 + 1, 0);
        for (int i = 1; i < preSum.size(); i++) {
            preSum[i] = preSum[i - 1] + nums[i % nums.size()];
        }
        deque<int> minQ;
        int left = 1, right = 1, res = INT_MIN;
        while (right < preSum.size()) {
            res = max(res, preSum[right] - (minQ.empty() ? 0 : minQ.front()));
            if (right - left == nums.size()) {
                if (minQ.front() == preSum[left]) {
                    minQ.pop_front();
                }
                left++;
            }
            while (!minQ.empty() && minQ.back() > preSum[right]) {
                minQ.pop_back();
            }
            minQ.push_back(preSum[right]);
            right++;
        }
        return res;
    }
};
```
