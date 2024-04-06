---
title: 300. Longest Increasing Subsequence
categories: Leetcode
date: 2023-11-09 00:13:57
tags:
    - Array
    - Binary Search
    - Dynamic Programming
---

[300\. Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Binary Search](https://leetcode.com/tag/https://leetcode.com/tag/binary-search//), [Dynamic Programming](https://leetcode.com/tag/https://leetcode.com/tag/dynamic-programming//)

Given an integer array `nums`, return _the length of the longest **strictly increasing**_ <span data-keyword="subsequence-array" class=" cursor-pointer relative text-dark-blue-s text-sm"></span>_**subsequence**_.

**Example 1:**

```bash
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
```

**Example 2:**

```bash
Input: nums = [0,1,0,3,2,3]
Output: 4
```

**Example 3:**

```bash
Input: nums = [7,7,7,7,7,7,7]
Output: 1
```

**Constraints:**

* `1 <= nums.length <= 2500`
* -10<sup>4</sup> <= nums[i] <= 10<sup>4</sup>

**Follow up:** Can you come up with an algorithm that runs in `O(n log(n))` time complexity?

## Hints/Notes

* dp

## Solution

Language: **C++**

```C++
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        int longest = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    res[i] = max(res[i], res[j] + 1);
                }
            }
            longest = max(longest, res[i]);
        }
        return longest;
    }
};
```
