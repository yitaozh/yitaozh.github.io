---
title: 41. First Missing Positive
categories: Leetcode
date: 2025-04-05 12:15:19
tags:
    - Array
    - Hash Table
---

[41. First Missing Positive](https://leetcode.com/problems/first-missing-positive/description/?envType=company&envId=oracle&favoriteSlug=oracle-six-months)

## Description

Given an unsorted integer array `nums`. Return the smallest positive integer that is not present in `nums`.

You must implement an algorithm that runs in `O(n)` time and uses `O(1)` auxiliary space.

**Example 1:**

```bash
Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
```

**Example 2:**

```bash
Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
```

**Example 3:**

```bash
Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `-2^31 <= nums[i] <= 2^31 - 1`

## Hints/Notes

- 2025/03/31 Q3
- hash map
- [Good solution](https://leetcode.cn/problems/first-missing-positive/solutions/7703/tong-pai-xu-python-dai-ma-by-liweiwei1419/?envType=company&envId=oracle&favoriteSlug=oracle-six-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] != i + 1) {
                if (nums[i] <= 0 || nums[i] > n || nums[i] == nums[nums[i] - 1]) {
                    break;
                }
                // nums[i] should be put on index nums[i] - 1
                int idx = nums[i] - 1;
                swap(nums[idx], nums[i]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};
```
