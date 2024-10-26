---
title: 1852. Distinct Numbers in Each Subarray
categories: Leetcode
date: 2024-10-25 21:27:27
tags:
    - Array
    - Hash Table
    - Sliding Window
---

[1852. Distinct Numbers in Each Subarray](https://leetcode.com/problems/distinct-numbers-in-each-subarray/description/)

## Description

Given an integer array `nums` and an integer `k`, you are asked to construct the array `ans` of size `n-k+1` where `ans[i]` is the number of **distinct**  numbers in the subarray `nums[i:i+k-1] = [nums[i], nums[i+1], ..., nums[i+k-1]]`.

Return the array `ans`.

**Example 1:**

```bash
Input: nums = [1,2,3,2,2,1,3], k = 3
Output: [3,2,2,2,3]
Explanation: The number of distinct elements in each subarray goes as follows:
- nums[0:2] = [1,2,3] so ans[0] = 3
- nums[1:3] = [2,3,2] so ans[1] = 2
- nums[2:4] = [3,2,2] so ans[2] = 2
- nums[3:5] = [2,2,1] so ans[3] = 2
- nums[4:6] = [2,1,3] so ans[4] = 3
```

**Example 2:**

```bash
Input: nums = [1,1,1,1,2,3,4], k = 4
Output: [1,2,3,4]
Explanation: The number of distinct elements in each subarray goes as follows:
- nums[0:3] = [1,1,1,1] so ans[0] = 1
- nums[1:4] = [1,1,1,2] so ans[1] = 2
- nums[2:5] = [1,1,2,3] so ans[2] = 3
- nums[3:6] = [1,2,3,4] so ans[3] = 4
```

**Constraints:**

- `1 <= k <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^5`

## Hints/Notes

- sliding window

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size(), right = 0;
        unordered_map<int, int> m;
        while (right < n) {
            int num = nums[right];
            m[num]++;
            if (right >= k - 1) {
                res.push_back(m.size());
                int l = nums[right - k + 1];
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
