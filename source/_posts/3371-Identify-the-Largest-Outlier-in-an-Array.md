---
title: 3371. Identify the Largest Outlier in an Array
categories: Leetcode
date: 2024-12-15 23:03:08
tags:
    - Array
    - Hash Table
    - Counting
    - Enumeration
---

[3371. Identify the Largest Outlier in an Array](https://leetcode.com/problems/identify-the-largest-outlier-in-an-array/description/)

## Description

You are given an integer array `nums`. This array contains `n` elements, where **exactly**  `n - 2` elements are **special** **numbers** . One of the remaining **two**  elements is the sum of these **special numbers** , and the other is an **outlier** .

An **outlier**  is defined as a number that is neither one of the original special numbers nor the element representing the sum of those numbers.

**Note**  that special numbers, the sum element, and the outlier must have **distinct**  indices, but may share the **same**  value.

Return the **largest** potential **outlier**  in `nums`.

**Example 1:**

```bash
Input: nums = [2,3,5,10]

Output: 10
```

Explanation:

The special numbers could be 2 and 3, thus making their sum 5 and the outlier 10.

**Example 2:**

```bash
Input: nums = [-2,-1,-3,-6,4]

Output: 4
```

Explanation:

The special numbers could be -2, -1, and -3, thus making their sum -6 and the outlier 4.

**Example 3:**

```bash
Input: nums = [1,1,1,1,1,5,5]

Output: 5
```

Explanation:

The special numbers could be 1, 1, 1, 1, and 1, thus making their sum 5 and the other 5 as the outlier.

**Constraints:**

- `3 <= nums.length <= 10^5`
- `-1000 <= nums[i] <= 1000`
- The input is generated such that at least **one**  potential outlier exists in `nums`.

## Hints/Notes

- 2024/12/06
- map
- [0x3F's solution](https://leetcode.cn/problems/identify-the-largest-outlier-in-an-array/solutions/3006328/mei-ju-yi-chang-zhi-pythonjavacgo-by-end-wb3g/)(checked)
- Weekly Contest 426

## Solution

Language: **C++**

```C++
class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int sum = reduce(nums.begin(), nums.end());
        unordered_map<int, int> m;
        for (int num : nums) {
            m[num]++;
        }
        int res = INT_MIN;
        for (int num: nums) {
            if ((sum - num) % 2) {
                continue;
            }
            m[num]--;
            if (m[(sum - num) / 2] > 0) {
                res = max(res, num);
            }
            m[num]++;
        }
        return res;
    }
};
```
