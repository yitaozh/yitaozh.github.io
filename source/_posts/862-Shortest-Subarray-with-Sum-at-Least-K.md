---
title: 862. Shortest Subarray with Sum at Least K
categories: Leetcode
date: 2023-12-17 17:04:58
tags:
    - Array
    - Binary Search
    - Queue
    - Sliding Window
    - Heap (Priority Queue)
    - Prefix Sum
    - Monotonic Queue
---

[862\. Shortest Subarray with Sum at Least K](https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/)

## Description

Difficulty: **Hard**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Binary Search](https://leetcode.com/tag/https://leetcode.com/tag/binary-search//), [Queue](https://leetcode.com/tag/https://leetcode.com/tag/queue//), [Sliding Window](https://leetcode.com/tag/https://leetcode.com/tag/sliding-window//), [Heap (Priority Queue)](https://leetcode.com/tag/https://leetcode.com/tag/heap-priority-queue//), [Prefix Sum](https://leetcode.com/tag/https://leetcode.com/tag/prefix-sum//), [Monotonic Queue](https://leetcode.com/tag/https://leetcode.com/tag/monotonic-queue//)

Given an integer array `nums` and an integer `k`, return _the length of the shortest non-empty **subarray** of_ `nums` _with a sum of at least_ `k`. If there is no such **subarray**, return `-1`.

A **subarray** is a **contiguous** part of an array.

**Example 1:**

```bash
Input: nums = [1], k = 1
Output: 1
```

**Example 2:**

```bash
Input: nums = [1,2], k = 4
Output: -1
```

**Example 3:**

```bash
Input: nums = [2,-1,2], k = 3
Output: 3
```

**Constraints:**

* 1 <= nums.length <= 10<sup>5</sup>
* -10<sup>5</sup> <= nums[i] <= 10<sup>5</sup>
* 1 <= k <= 10<sup>9</sup>

## Hints/Notes

* preSum + monotonic queue

## Solution

Language: **C++**

```C++
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        vector<long> preSum(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            preSum[i + 1] = preSum[i] + nums[i];
        }
        int left = 0, right = 0, res = INT_MAX;
        deque<long> minQ;
        while (right <= nums.size()) {
            while (!minQ.empty() && preSum[right] < minQ.back()) {
                minQ.pop_back();
            }
            minQ.push_back(preSum[right]);
            while ((preSum[right] - minQ.front() >= k) && left < right) {
                res = min(res, right - left);
                if (preSum[left] == minQ.front()) {
                    minQ.pop_front();
                }
                left++;
            }
            right++;
        }
        return res == INT_MAX ? -1 : res;
    }
};
```
