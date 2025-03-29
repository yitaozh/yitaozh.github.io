---
title: 189. Rotate Array
categories: Leetcode
date: 2025-03-29 11:17:18
tags:
    - Array
    - Math
    - Two Pointers
---

[189. Rotate Array](https://leetcode.com/problems/rotate-array/description/?envType=company&envId=apple&favoriteSlug=apple-six-months)

## Description

Given an integer array `nums`, rotate the array to the right by `k` steps, where `k` is non-negative.

**Example 1:**

```bash
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
```

**Example 2:**

```bash
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `-2^31 <= nums[i] <= 2^31 - 1`
- `0 <= k <= 10^5`

**Follow up:**

- Try to come up with as many solutions as you can. There are at least **three**  different ways to solve this problem.
- Could you do it in-place with `O(1)` extra space?

## Hints/Notes

- 2025/03/19 Q3
- array
- [Leetcode solution](https://leetcode.com/problems/rotate-array/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        k = nums.size() - k;
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
```
