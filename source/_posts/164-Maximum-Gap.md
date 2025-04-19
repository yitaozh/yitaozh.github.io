---
title: 164. Maximum Gap
categories: Leetcode
date: 2025-04-19 13:10:15
tags:
    - Array
    - Sorting
    - Bucket Sort
    - Radix Sort
---

[164. Maximum Gap](https://leetcode.com/problems/maximum-gap/description/?envType=company&envId=doordash&favoriteSlug=doordash-more-than-six-months)

## Description

Given an integer array `nums`, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return `0`.

You must write an algorithm that runs in linear time and uses linear extra space.

**Example 1:**

```bash
Input: nums = [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
```

**Example 2:**

```bash
Input: nums = [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `0 <= nums[i] <= 10^9`

## Hints/Notes

- 2025/04/16 Q2
- bucket sort
- [0x3F's solution](https://leetcode.cn/problems/maximum-gap/solutions/2772242/xiang-xi-jie-shi-on-fen-tong-fa-pythonja-mi5s/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        int mx = ranges::max(nums), mi = ranges::min(nums), diff = mx - mi, n = nums.size();
        int range = ceil((double)diff / (n - 1));
        if (!range) {
            return 0;
        }
        vector<pair<int, int>> buckets(n, {INT_MAX, INT_MIN});
        for (auto& num : nums) {
            // first let's figure out which bucket to put this item
            int idx = (num - mi) / range;
            buckets[idx].first = min(buckets[idx].first, num);
            buckets[idx].second = max(buckets[idx].second, num);
        }
        int idx = 0, res = range;
        while (idx < n) {
            if (buckets[idx].first == INT_MAX) {
                idx++;
                continue;
            }
            int cur_mx = buckets[idx].second;
            idx++;
            while (idx < n && buckets[idx].first == INT_MAX) {
                idx++;
            }
            if (idx == n) {
                break;
            }
            int cur_mi = buckets[idx].first;
            res = max(res, cur_mi - cur_mx);
        }
        return res;
    }
};
```
