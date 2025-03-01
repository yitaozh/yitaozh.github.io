---
title: 3224. Minimum Array Changes to Make Differences Equal
categories: Leetcode
date: 2024-07-26 01:01:12
tags:
    - Array
    - Hash Table
    - Prefix Sum
---

[3224. Minimum Array Changes to Make Differences Equal](https://leetcode.com/problems/minimum-array-changes-to-make-differences-equal/description/)

## Description

You are given an integer array `nums` of size `n` where `n` is **even** , and an integer `k`.

You can perform some changes on the array, where in one change you can replace **any**  element in the array with **any**  integer in the range from `0` to `k`.

You need to perform some changes (possibly none) such that the final array satisfies the following condition:

- There exists an integer `X` such that `abs(a[i] - a[n - i - 1]) = X` for all `(0 <= i < n)`.

Return the **minimum**  number of changes required to satisfy the above condition.

**Example 1:**

```bash
Input: nums = [1,0,1,2,4,3], k = 4

Output: 2
```

Explanation:
We can perform the following changes:

- Replace `nums[1]` by 2. The resulting array is nums = [1,**2**,1,2,4,3].
- Replace `nums[3]` by 3. The resulting array is nums = [1,2,1,**3**,4,3].

The integer `X` will be 2.

**Example 2:**

```bash
Input: nums = [0,1,2,3,3,6,5,4], k = 6

Output: 2
```

Explanation:
We can perform the following operations:

- Replace `nums[3]` by 0. The resulting array is nums = [0,1,2,**0**,3,6,5,4].
- Replace `nums[4]` by 4. The resulting array is nums = [0,1,2,0,**4**,6,5,4].

The integer `X` will be 4.

**Constraints:**

- `2 <= n == nums.length <= 10^5`
- `n` is even.
- `0 <= nums[i] <= k <= 10^5`

## Hints/Notes

- 2024/07/27
- diff and preSum array
- [0x3F's solution](https://leetcode.cn/problems/minimum-array-changes-to-make-differences-equal/solutions/2851502/mei-ju-x-fen-lei-tao-lun-pythonjavacgo-b-puh2/)(checked)
- Biweekly contest 135

## Solution

Language: **C++**

```C++
class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        vector<int> diffs(k + 1, 0);
        vector<int> mins(k + 1, 0);
        int n = nums.size();
        for (int i = 0; n - i - 1 > i; i++) {
            int diff = abs(nums[i] - nums[n - i - 1]);
            diffs[diff]++;
            int mi = min(nums[i], nums[n - i - 1]), mx = max(nums[i], nums[n - i - 1]);
            // if we change mi along, then it would be changed to 0, the diff would be mx
            // if we change mx alone, then, it would be changed to k, the diff would be k - mi
            // if we want to change only one number to suit the need, then the X would be less than max(mx, k - mi)
            // if the x is larger than max(mx, k - mi), we need to change twice
            mins[max(mx, k - mi)]++;
        }
        int res = INT_MAX, sum = 0;
        for (int i = 0; i <= k; i++) {
            res = min(res, n / 2 - diffs[i] + sum);
            sum += mins[i];
        }
        return res;
    }
};
```
