---
title: 303. Range Sum Query - Immutable
categories: Leetcode
date: 2023-01-19 15:51:00
tags:
    - Array
    - Design
    - Prefix Sum
---

# [303\. Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/)

## Description

Difficulty: **Easy**

Related Topics: [Array](https://leetcode.com/tag/array/), [Design](https://leetcode.com/tag/design/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/)

Given an integer array `nums`, handle multiple queries of the following type:

1.  Calculate the **sum** of the elements of `nums` between indices `left` and `right` **inclusive** where `left <= right`.

Implement the `NumArray` class:

*   `NumArray(int[] nums)` Initializes the object with the integer array `nums`.
*   `int sumRange(int left, int right)` Returns the **sum** of the elements of `nums` between indices `left` and `right` **inclusive** (i.e. `nums[left] + nums[left + 1] + ... + nums[right]`).

**Example 1:**

```
Input
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
Output
[null, 1, -1, -3]

Explanation
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3
```

**Constraints:**

*   1 <= nums.length <= 10<sup>4</sup>
*   -10<sup>5</sup> <= nums[i] <= 10<sup>5</sup>
*   `0 <= left <= right < nums.length`
*   At most 10<sup>4</sup> calls will be made to `sumRange`.

## Solution

Language: **C++**

```C++
class NumArray {
public:
    vector<int> preSum;

    NumArray(vector<int>& nums) {
        preSum.push_back(0);
        for (int num : nums) {
            preSum.push_back(preSum.back() + num);
        }
    }
    
    int sumRange(int left, int right) {
        return preSum[right + 1] - preSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
```