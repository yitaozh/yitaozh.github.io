---
title: 3350. Adjacent Increasing Subarrays Detection II
categories: Leetcode
date: 2024-12-03 16:57:32
tags:
    - Array
    - Binary Search
---

[3350. Adjacent Increasing Subarrays Detection II](https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/description/)

## Description

Given an array `nums` of `n` integers, your task is to find the **maximum**  value of `k` for which there exist **two**  adjacent subarrays of length `k` each, such that both subarrays are **strictly** **increasing**. Specifically, check if there are **two**  subarrays of length `k` starting at indices `a` and `b` (`a < b`), where:

- Both subarrays `nums[a..a + k - 1]` and `nums[b..b + k - 1]` are **strictly increasing**.
- The subarrays must be **adjacent** , meaning `b = a + k`.

Return the **maximum**  possible value of `k`.

A **subarray**  is a contiguous **non-empty** sequence of elements within an array.

**Example 1:**

```bash
Input: nums = [2,5,7,8,9,2,3,4,3,1]

Output: 3
```

Explanation:

- The subarray starting at index 2 is `[7, 8, 9]`, which is strictly increasing.
- The subarray starting at index 5 is `[2, 3, 4]`, which is also strictly increasing.
- These two subarrays are adjacent, and 3 is the **maximum** possible value of `k` for which two such adjacent strictly increasing subarrays exist.

**Example 2:**

```bash
Input: nums = [1,2,3,4,4,4,4,5,6,7]

Output: 2
```

Explanation:

- The subarray starting at index 0 is `[1, 2]`, which is strictly increasing.
- The subarray starting at index 2 is `[3, 4]`, which is also strictly increasing.
- These two subarrays are adjacent, and 2 is the **maximum**  possible value of `k` for which two such adjacent strictly increasing subarrays exist.

**Constraints:**

- `2 <= nums.length <= 2 * 10^5`
- `-10^9 <= nums[i] <= 10^9`

## Hints/Notes

- 2024/11/24
- [0x3F's solution](https://leetcode.cn/problems/adjacent-increasing-subarrays-detection-ii/solutions/2983500/on-yi-ci-bian-li-jian-ji-xie-fa-pythonja-ye0a/)
- Weekly/Biweekly Contest 423

## Solution

Language: **C++**

```C++
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int prev = 0, count = 0, n = nums.size(), res = 0;
        for (int i = 0; i < n; i++) {
            count++;
            if (i == n - 1 || nums[i] >= nums[i + 1]) {
                res = max(res, max(count / 2, min(count, prev)));
                prev = count;
                count = 0;
            }
        }
        return res;
    }
};
```

分组循环：

```C++
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int prev = 0, n = nums.size(), res = 0;
        for (int i = 0; i < n; i++) {
            int start = i;
            while (i + 1 < n && nums[i] < nums[i + 1]) {
                i++;
            }
            int cur = i - start + 1;
            res = max(res, max(cur / 2, min(cur, prev)));
            prev = cur;
        }
        return res;
    }
};
```