---
title: 239. Sliding Window Maximum
categories: Leetcode
date: 2023-09-20 21:35:12
tags:
    - Array
    - Queue
    - Sliding Window
    - Heap (Priority Queue)
    - Monotonic Queue
---

# [239\. Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)

## Description

Difficulty: **Hard**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Queue](https://leetcode.com/tag/https://leetcode.com/tag/queue//), [Sliding Window](https://leetcode.com/tag/https://leetcode.com/tag/sliding-window//), [Heap (Priority Queue)](https://leetcode.com/tag/https://leetcode.com/tag/heap-priority-queue//), [Monotonic Queue](https://leetcode.com/tag/https://leetcode.com/tag/monotonic-queue//)

You are given an array of integers `nums`, there is a sliding window of size `k` which is moving from the very left of the array to the very right. You can only see the `k` numbers in the window. Each time the sliding window moves right by one position.

Return _the max sliding window_.

**Example 1:**

```bash
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```

**Example 2:**

```bash
Input: nums = [1], k = 1
Output: [1]
```

**Constraints:**

* 1 <= nums.length <= 10<sup>5</sup>
* -10<sup>4</sup> <= nums[i] <= 10<sup>4</sup>
* `1 <= k <= nums.length`

## Hints/Notes

* Monotonic Queue
* Corner case: we cannot use less than or equal to when pop previous elements, because it can potentially pop out the newly added value

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        list<int> window;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            while (!window.empty() && window.back() < nums[i]) {
                window.pop_back();
            }
            window.push_back(nums[i]);
            if (i >= k - 1) {
                res.push_back(window.front());
                if (window.front() == nums[i - k + 1]) {
                    window.pop_front();
                }
            }
        }
        return res;
    }
};
```
