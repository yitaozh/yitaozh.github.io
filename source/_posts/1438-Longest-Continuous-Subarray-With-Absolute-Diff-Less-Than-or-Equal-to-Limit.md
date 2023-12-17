---
title: >-
  1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to
  Limit
categories: Leetcode
date: 2023-12-17 16:26:40
tags:
  - Array
  - Queue
  - Sliding Window
  - Heap (Priority Queue)
  - Ordered Set
  - Monotonic Queue
---

# [1438\. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit](https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Queue](https://leetcode.com/tag/https://leetcode.com/tag/queue//), [Sliding Window](https://leetcode.com/tag/https://leetcode.com/tag/sliding-window//), [Heap (Priority Queue)](https://leetcode.com/tag/https://leetcode.com/tag/heap-priority-queue//), [Ordered Set](https://leetcode.com/tag/https://leetcode.com/tag/ordered-set//), [Monotonic Queue](https://leetcode.com/tag/https://leetcode.com/tag/monotonic-queue//)

Given an array of integers `nums` and an integer `limit`, return the size of the longest **non-empty** subarray such that the absolute difference between any two elements of this subarray is less than or equal to `limit`_._

**Example 1:**

```bash
Input: nums = [8,2,4,7], limit = 4
Output: 2
Explanation: All subarrays are:
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4\.
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4\.
Therefore, the size of the longest subarray is 2.
```

**Example 2:**

```bash
Input: nums = [10,1,2,4,7,2], limit = 5
Output: 4
Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.
```

**Example 3:**

```bash
Input: nums = [4,2,2,2,4,4,2,2], limit = 0
Output: 3
```

**Constraints:**

* 1 <= nums.length <= 10<sup>5</sup>
* 1 <= nums[i] <= 10<sup>9</sup>
* 0 <= limit <= 10<sup>9</sup>

## Hints/Notes

* monotonic queue

## Solution

Language: **C++**

```C++
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> minQ;
        deque<int> maxQ;
        int left = 0, right = 0, res = 0;
        while (right < nums.size()) {
            while (!minQ.empty() && minQ.back() > nums[right]) {
                minQ.pop_back();
            }
            while (!maxQ.empty() && maxQ.back() < nums[right]) {
                maxQ.pop_back();
            }
            minQ.push_back(nums[right]);
            maxQ.push_back(nums[right]);
            while ((maxQ.front() - minQ.front() > limit) && left < right) {
                if (nums[left] == minQ.front()) {
                    minQ.pop_front();
                }
                if (nums[left] == maxQ.front()) {
                    maxQ.pop_front();
                }
                left++;
            }
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};
```
