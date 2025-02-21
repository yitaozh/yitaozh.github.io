---
title: 229. Majority Element II
categories: Leetcode
date: 2025-02-20 23:59:20
tags:
    - Array
    - Hash Table
    - Sorting
    - Counting
---

[229. Majority Element II](https://leetcode.com/problems/majority-element-ii/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

Given an integer array of size `n`, find all elements that appear more than `⌊ n/3 ⌋` times.

**Example 1:**

```bash
Input: nums = [3,2,3]
Output: [3]
```

**Example 2:**

```bash
Input: nums = [1]
Output: [1]
```

**Example 3:**

```bash
Input: nums = [1,2]
Output: [1,2]
```

**Constraints:**

- `1 <= nums.length <= 5 * 10^4`
- `-10^9 <= nums[i] <= 10^9`

**Follow up:**  Could you solve the problem in linear time and in `O(1)` space?

## Hints/Notes

- 2025/02/11
- Boyer-Moore Voting Algorithm
- [Leetcode solution](https://leetcode.com/problems/majority-element-ii/editorial/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int mx1 = INT_MIN, mx2 = INT_MIN, count1 = 0, count2 = 0;
        for (int num : nums) {
            if (num == mx1) {
                count1++;
            } else if (num == mx2) {
                count2++;
            } else if (count1 == 0) {
                mx1 = num;
                count1++;
            } else if (count2 == 0) {
                mx2 = num;
                count2++;
            } else {
                count1--;
                count2--;
            }
        }
        count1 = 0; count2 = 0;
        for (int num : nums) {
            if (num == mx1) {
                count1++;
            } else if (num == mx2) {
                count2++;
            }
        }
        vector<int> res;
        if (count1 > n / 3) res.push_back(mx1);
        if (count2 > n / 3) res.push_back(mx2);
        return res;
    }
};
```
