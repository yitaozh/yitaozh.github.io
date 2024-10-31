---
title: 2461. Maximum Sum of Distinct Subarrays With Length K
categories: Leetcode
date: 2024-10-24 23:53:42
tags:
    - Array
    - Hash Table
    - Sliding Window
---

[2461. Maximum Sum of Distinct Subarrays With Length K](https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/)

## Description

You are given an integer array `nums` and an integer `k`. Find the maximum subarray sum of all the subarrays of `nums` that meet the following conditions:

- The length of the subarray is `k`, and
- All the elements of the subarray are **distinct** .

Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return `0`.

A **subarray**  is a contiguous non-empty sequence of elements within an array.

**Example 1:**

```bash
Input: nums = [1,5,4,2,9,9,9], k = 3
Output: 15
Explanation: The subarrays of nums with length 3 are:
- [1,5,4] which meets the requirements and has a sum of 10.
- [5,4,2] which meets the requirements and has a sum of 11.
- [4,2,9] which meets the requirements and has a sum of 15.
- [2,9,9] which does not meet the requirements because the element 9 is repeated.
- [9,9,9] which does not meet the requirements because the element 9 is repeated.
We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions
```

**Example 2:**

```bash
Input: nums = [4,4,4], k = 3
Output: 0
Explanation: The subarrays of nums with length 3 are:
- [4,4,4] which does not meet the requirements because the element 4 is repeated.
We return 0 because no subarrays meet the conditions.
```

**Constraints:**

- `1 <= k <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^5`

## Hints/Notes

- sliding window
- [0x3F's solution](https://leetcode.cn/problems/maximum-sum-of-distinct-subarrays-with-length-k/solutions/1951940/hua-dong-chuang-kou-by-endlesscheng-m0gm/), the same

## Solution

Language: **C++**

```C++
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long res = 0, cur = 0;
        int right = 0, n = nums.size();
        unordered_map<int, int> m;
        while (right < n) {
            int num = nums[right];
            m[num]++;
            cur += num;
            if (right >= k - 1) {
                if (m.size() == k) {
                    res = max(res, cur);
                }
                int l = nums[right - k + 1];
                cur -= l;
                m[l]--;
                if (m[l] == 0) {
                    m.erase(l);
                }
            }
            right++;
        }
        return res;
    }
};
```
