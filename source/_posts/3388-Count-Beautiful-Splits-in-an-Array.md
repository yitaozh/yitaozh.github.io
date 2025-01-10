---
title: 3388. Count Beautiful Splits in an Array
categories: Leetcode
date: 2025-01-10 00:40:51
tags:
    - Array
    - Dynamic Programming
---

[3388. Count Beautiful Splits in an Array](https://leetcode.com/problems/count-beautiful-splits-in-an-array/description/)

## Description

You are given an array `nums`.

A split of an array `nums` is **beautiful**  if:

- The array `nums` is split into three subarrays: `nums1`, `nums2`, and `nums3`, such that `nums` can be formed by concatenating `nums1`, `nums2`, and `nums3` in that order.
- The subarray `nums1` is a prefix of `nums2` **OR**  `nums2` is a prefix of `nums3`.

Return the **number of ways**  you can make this split.

**Example 1:**

```bash
Input: nums = [1,1,2,1]

Output: 2
```

Explanation:

The beautiful splits are:

- A split with `nums1 = [1]`, `nums2 = [1,2]`, `nums3 = [1]`.
- A split with `nums1 = [1]`, `nums2 = [1]`, `nums3 = [2,1]`.

**Example 2:**

```bash
Input: nums = [1,2,3,4]

Output: 0
```

Explanation:

There are 0 beautiful splits.

**Constraints:**

- `1 <= nums.length <= 5000`
- `0 <= nums[i] <= 50`

## Hints/Notes

- 2025/01/09
- z function
- [0x3F's solution](https://leetcode.cn/problems/count-beautiful-splits-in-an-array/solutions/3020939/liang-chong-fang-fa-lcp-shu-zu-z-shu-zu-dwbrd/)(checked)
- Weekly Contest 428

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> calc_z(vector<int> nums) {
        int n = nums.size();
        vector<int> z(n, 0);
        int box_l = 0, box_r = 0;
        for (int i = 1; i < n; i++) {
            if (i <= box_r) {
                z[i] = min(z[i - box_l], box_r - i + 1);
            }
            while (i + z[i] < n && nums[z[i]] == nums[i + z[i]]) {
                box_l = i;
                box_r = i + z[i];
                z[i]++;
            }
        }
        return z;
    }

    int beautifulSplits(vector<int>& nums) {
        int n = nums.size(), res = 0;
        vector<int> all = calc_z(nums);
        for (int i = 1; i < n; i++) {
            // this following code is wrong, because it skips the subarray
            // that nums1 is a prefix, but nums2 is short than nums1
            // if (all[i] >= i) {
            //     res += n - 2 * i;
            //     continue;
            // }
            vector<int> cur = calc_z(vector<int>(nums.begin() + i, nums.end()));
            for (int j = i + 1; j < n; j++) {
                // the 1st part: [0, i)
                // the 2nd part: [i, j)
                // the 3rd part: [j, n)
                if (i <= j - i && all[i] >= i || cur[j - i] >= j - i) {
                    res++;
                }
            }
        }
        return res;
    }
};
```
