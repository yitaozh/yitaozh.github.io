---
title: 220. Contains Duplicate III
categories: Leetcode
date: 2023-12-05 23:28:32
tags:
    - Array
    - Sliding Window
    - Sorting
    - Bucket Sort
    - Ordered Set
---

[220\. Contains Duplicate III](https://leetcode.com/problems/contains-duplicate-iii/)

## Description

Difficulty: **Hard**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Sliding Window](https://leetcode.com/tag/https://leetcode.com/tag/sliding-window//), [Sorting](https://leetcode.com/tag/https://leetcode.com/tag/sorting//), [Bucket Sort](https://leetcode.com/tag/https://leetcode.com/tag/bucket-sort//), [Ordered Set](https://leetcode.com/tag/https://leetcode.com/tag/ordered-set//)

You are given an integer array `nums` and two integers `indexDiff` and `valueDiff`.

Find a pair of indices `(i, j)` such that:

* `i != j`,
* `abs(i - j) <= indexDiff`.
* `abs(nums[i] - nums[j]) <= valueDiff`, and

Return `true` _if such pair exists or_ `false` _otherwise_.

**Example 1:**

```bash
Input: nums = [1,2,3,1], indexDiff = 3, valueDiff = 0
Output: true
Explanation: We can choose (i, j) = (0, 3).
We satisfy the three conditions:
i != j --> 0 != 3
abs(i - j) <= indexDiff --> abs(0 - 3) <= 3
abs(nums[i] - nums[j]) <= valueDiff --> abs(1 - 1) <= 0
```

**Example 2:**

```bash
Input: nums = [1,5,9,1,5,9], indexDiff = 2, valueDiff = 3
Output: false
Explanation: After trying all the possible pairs (i, j), we cannot satisfy the three conditions, so we return false.
```

**Constraints:**

* 2 <= nums.length <= 10<sup>5</sup>
* -10<sup>9</sup> <= nums[i] <= 10<sup>9</sup>
* `1 <= indexDiff <= nums.length`
* 0 <= valueDiff <= 10<sup>9</sup>

## Hints/Notes

* sliding window
* use map's lower_bound function
* it's not comparing max and min of a sub array, so don't use monotonic queue

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int left = 0, right = 0;
        map<int, int> m;
        while (right < nums.size()) {
            int val = nums[right];
            auto it = m.lower_bound(val);
            if (it != m.end() && abs(it->first - val) <= valueDiff) {
                return true;
            }
            if (it != m.begin()) {
                it--;
                if (abs(it->first - val) <= valueDiff) {
                    return true;
                }
            }
            m[val]++;
            right++;
            if (right - left > indexDiff) {
                m[nums[left]]--;
                if (m[nums[left]] == 0) {
                    m.erase(nums[left]);
                }
                left++;
            }
        }
        return false;
    }
};
```
