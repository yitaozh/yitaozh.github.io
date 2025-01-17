---
title: 31. Next Permutation
categories: Leetcode
date: 2025-01-17 01:13:35
tags:
    - Array
    - Two Pointers
---

[31. Next Permutation](https://leetcode.com/problems/next-permutation/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

A **permutation**  of an array of integers is an arrangement of its members into a sequence or linear order.

- For example, for `arr = [1,2,3]`, the following are all the permutations of `arr`: `[1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1]`.

The **next permutation**  of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the **next permutation**  of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

- For example, the next permutation of `arr = [1,2,3]` is `[1,3,2]`.
- Similarly, the next permutation of `arr = [2,3,1]` is `[3,1,2]`.
- While the next permutation of `arr = [3,2,1]` is `[1,2,3]` because `[3,2,1]` does not have a lexicographical larger rearrangement.

Given an array of integers `nums`, find the next permutation of `nums`.

The replacement must be **<a href="http://en.wikipedia.org/wiki/In-place_algorithm" target="_blank">in place</a>**  and use only constant extra memory.

**Example 1:**

```bash
Input: nums = [1,2,3]
Output: [1,3,2]
```

**Example 2:**

```bash
Input: nums = [3,2,1]
Output: [1,2,3]
```

**Example 3:**

```bash
Input: nums = [1,1,5]
Output: [1,5,1]
```

**Constraints:**

- `1 <= nums.length <= 100`
- `0 <= nums[i] <= 100`

## Hints/Notes

- 2025/01/17
- Array
- [Leetcode solution](https://leetcode.com/problems/next-permutation/editorial/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i = 0;
        bool next = false;
        for (i = n - 1; i >= 1; i--) {
            if (nums[i] <= nums[i - 1]) {
                continue;
            }
            // it's not always swapping the last element, but the element
            // larger than nums[i - 1]
            int right = n - 1;
            while (right > i - 1) {
                if (nums[right] > nums[i - 1]) {
                    swap(nums[right], nums[i - 1]);
                    break;
                }
                right--;
            }
            // instead of sort we can just reverse here
            // sort(nums.begin() + i, nums.end());
            break;
        }
        reverse(nums.begin() + i, nums.end());
    }
};
```
