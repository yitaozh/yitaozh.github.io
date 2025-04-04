---
title: 2592. Maximize Greatness of an Array
categories: Leetcode
date: 2025-04-04 14:29:39
tags:
    - Array
    - Two Pointers
    - Greedy
    - Sorting
---

[2592. Maximize Greatness of an Array](https://leetcode.com/problems/maximize-greatness-of-an-array/description/?envType=company&envId=oracle&favoriteSlug=oracle-six-months)

## Description

You are given a 0-indexed integer array `nums`. You are allowed to permute `nums` into a new array `perm` of your choosing.

We define the **greatness**  of `nums` be the number of indices `0 <= i < nums.length` for which `perm[i] > nums[i]`.

Return the **maximum**  possible greatness you can achieve after permuting `nums`.

**Example 1:**

```bash
Input: nums = [1,3,5,2,1,3,1]
Output: 4
Explanation: One of the optimal rearrangements is perm = [2,5,1,3,3,1,1].
At indices = 0, 1, 3, and 4, perm[i] > nums[i]. Hence, we return 4.
```

**Example 2:**

```bash
Input: nums = [1,2,3,4]
Output: 3
Explanation: We can prove the optimal perm is [2,3,4,1].
At indices = 0, 1, and 2, perm[i] > nums[i]. Hence, we return 3.
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `0 <= nums[i] <= 10^9`

## Hints/Notes

- 2025/03/29 Q3
- two pointers, check 0x4F's hash solution
- [0x3F's solution](https://leetcode.cn/problems/maximize-greatness-of-an-array/solutions/2177186/tian-ji-sai-ma-by-endlesscheng-buk1/?envType=company&envId=oracle&favoriteSlug=oracle-six-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        ranges::sort(nums);
        int left = 0, right = 0, n = nums.size(), res = 0;
        while (right < n) {
            int l = nums[left++];
            while (right < n && nums[right] <= l) {
                right++;
            }
            if (right < n) {
                res++;
                right++;
            }
        }
        return res;
    }
};
```
