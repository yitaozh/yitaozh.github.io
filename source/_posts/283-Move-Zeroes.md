---
title: 283. Move Zeroes
categories: Leetcode
date: 2023-01-17 13:47:44
tags:
    - Array
    - Two Pointers
---

[283\. Move Zeroes](https://leetcode.com/problems/move-zeroes/)

## Description

Difficulty: **Easy**

Related Topics: [Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/)

Given an integer array `nums`, move all `0`'s to the end of it while maintaining the relative order of the non-zero elements.

**Note** that you must do this in-place without making a copy of the array.

**Example 1:**

```bash
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
```

**Example 2:**

```bash
Input: nums = [0]
Output: [0]
```

**Constraints:**

* 1 <= nums.length <= 10<sup>4</sup>
* -2<sup>31</sup> <= nums[i] <= 2<sup>31</sup> - 1

**Follow up:** Could you minimize the total number of operations done?

## Hints/Notes

* 2023/08/04
* Remove the element first, then set the remaining to zero
* [0x3F's solution](https://leetcode.cn/problems/move-zeroes/solutions/2969353/kuai-man-zhi-zhen-wei-shi-yao-ke-yi-ba-s-1h8x/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)(checked)

## Solution

Language: **C++**

Cleaner solution:

```C++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0;
        for (int& x : nums) {
            if (x) {
                swap(nums[idx++], x);
            }
        }
    }
};
```

My solution:

```C++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = removeElement(nums, 0);
        for (int i = len; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }

    int removeElement(vector<int>& nums, int val) {
        int fast = 0, slow = 0, len = nums.size();
        while (fast < nums.size()) {
            if (nums[fast] != val) {
                nums[slow++] = nums[fast];
            }
            fast++;
        }
        return slow;
    }
};
```
