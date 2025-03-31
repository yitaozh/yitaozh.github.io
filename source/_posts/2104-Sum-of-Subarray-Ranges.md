---
title: 2104. Sum of Subarray Ranges
categories: Leetcode
date: 2025-03-31 11:50:30
tags:
    - Array
    - Stack
    - Monotonic Stack
---

[2104. Sum of Subarray Ranges](https://leetcode.com/problems/sum-of-subarray-ranges/description/?envType=company&envId=apple&favoriteSlug=apple-six-months)

## Description

You are given an integer array `nums`. The **range**  of a subarray of `nums` is the difference between the largest and smallest element in the subarray.

Return the **sum of all**  subarray ranges of `nums`.

A subarray is a contiguous **non-empty**  sequence of elements within an array.

**Example 1:**

```bash
Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
```

**Example 2:**

```bash
Input: nums = [1,3,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[3], range = 3 - 3 = 0
[3], range = 3 - 3 = 0
[1,3], range = 3 - 1 = 2
[3,3], range = 3 - 3 = 0
[1,3,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.
```

**Example 3:**

```bash
Input: nums = [4,-2,-3,4,1]
Output: 59
Explanation: The sum of all subarray ranges of nums is 59.
```

**Constraints:**

- `1 <= nums.length <= 1000`
- `-10^9 <= nums[i] <= 10^9`

**Follow-up:**  Could you find a solution with `O(n)` time complexity?

## Hints/Notes

- 2025/03/26 Q2
- monotonic queue
- [0x3F's solution](https://leetcode.cn/problems/sum-of-subarray-ranges/solutions/1153054/cong-on2-dao-ondan-diao-zhan-ji-suan-mei-o1op/?envType=company&envId=apple&favoriteSlug=apple-six-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long res = 0;
        int n = nums.size();
        stack<int> maxVal, minVal;
        for (int i = 0; i <= n; i++) {
            while (!maxVal.empty() && (i == n || nums[maxVal.top()] < nums[i])) {
                int prevMaxIdx = maxVal.top();
                maxVal.pop();
                int left = maxVal.empty() ? -1 : maxVal.top();
                res += (long long)nums[prevMaxIdx] * (prevMaxIdx - left) * (i - prevMaxIdx);
            }
            maxVal.push(i);
            while (!minVal.empty() && (i == n || nums[minVal.top()] > nums[i])) {
                int prevMaxIdx = minVal.top();
                minVal.pop();
                int left = minVal.empty() ? -1 : minVal.top();
                res -= (long long)nums[prevMaxIdx] * (prevMaxIdx - left) * (i - prevMaxIdx);
            }
            minVal.push(i);
        }
        return res;
    }
};
```
