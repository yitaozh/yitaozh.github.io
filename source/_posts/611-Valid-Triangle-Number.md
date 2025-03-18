---
title: 611. Valid Triangle Number
categories: Leetcode
date: 2025-03-18 00:45:30
tags:
    - Array
    - Two Pointers
    - Binary Search
    - Greedy
    - Sorting
---

[611. Valid Triangle Number](https://leetcode.com/problems/valid-triangle-number/description/?envType=company&envId=linkedin&favoriteSlug=linkedin-six-months)

## Description

Given an integer array `nums`, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

**Example 1:**

```bash
Input: nums = [2,2,3,4]
Output: 3
Explanation: Valid combinations are:
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
```

**Example 2:**

```bash
Input: nums = [4,2,3,4]
Output: 4
```

**Constraints:**

- `1 <= nums.length <= 1000`
- `0 <= nums[i] <= 1000`

## Hints/Notes

- 2025/02/16 Q2
- two pointers
- [Leetcode solution](https://leetcode.com/problems/valid-triangle-number/editorial/?envType=company&envId=linkedin&favoriteSlug=linkedin-six-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        // triangle: a + b > c
        ranges::sort(nums);
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            // if (i && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size(); j++) {
                // if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                // now we need to find the max index with nums[k] < nums[i] + nums[j]
                // range of k: [j + 1, num.size() - 1]
                int left = j, right = nums.size(), target = nums[i] + nums[j];
                while (left + 1 < right) {
                    int mid = (left + right) / 2;
                    if (nums[mid] >= target) {
                        right = mid;
                    } else {
                        left = mid;
                    }
                }
                // so all right has value >= target, right can be at j + 1
                res += right - j - 1;
            }
        }
        return res;
    }
};
```
