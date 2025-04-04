---
title: 697. Degree of an Array
categories: Leetcode
date: 2025-04-04 13:30:40
tags:
    - Array
    - Hash Table
---

[697. Degree of an Array](https://leetcode.com/problems/degree-of-an-array/description/)

## Description

Given a non-empty array of non-negative integers `nums`, the <b>degree</b> of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of `nums`, that has the same degree as `nums`.

**Example 1:**

```bash
Input: nums = [1,2,2,3,1]
Output: 2
Explanation:
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.
```

**Example 2:**

```bash
Input: nums = [1,2,2,3,1,4,2]
Output: 6
Explanation:
The degree is 3 because the element 2 is repeated 3 times.
So [2,2,3,1,4,2] is the shortest subarray, therefore returning 6.
```

**Constraints:**

- `nums.length` will be between 1 and 50,000.
- `nums[i]` will be an integer between 0 and 49,999.

## Hints/Notes

- 2025/03/27 Q3
- map
- [Leetcode solution](https://leetcode.com/problems/degree-of-an-array/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> count;
        int maxFreq = 0;
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
            maxFreq = max(maxFreq, count[nums[i]]);
        }
        int left = 0, right = 0, n = nums.size(), res = INT_MAX;
        count = {};
        while (right < n) {
            count[nums[right]]++;
            while (count[nums[right]] >= maxFreq) {
                res = min(res, right - left + 1);
                count[nums[left++]]--;
            }
            right++;
        }
        return res;
    }
};
```
