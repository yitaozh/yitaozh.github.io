---
title: 152. Maximum Product Subarray
categories: Leetcode
date: 2024-12-30 11:40:50
tags:
    - Array
    - Dynamic Programming
---

[152. Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Given an integer array `nums`, find a subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a **32-bit**  integer.

**Example 1:**

```bash
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
```

**Example 2:**

```bash
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
```

**Constraints:**

- `1 <= nums.length <= 2 * 10^4`
- `-10 <= nums[i] <= 10`
- The product of any subarray of `nums` is **guaranteed**  to fit in a **32-bit**  integer.

## Hints/Notes

- 2024/12/30
- rewrite with dp
- [0x3F's solution](https://leetcode.cn/problems/maximum-product-subarray/solutions/2968916/dong-tai-gui-hua-jian-ji-gao-xiao-python-i778/)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), res = INT_MIN;
        for (int i = 0; i < n; ) {
            if (nums[i] == 0) {
                res = max(nums[i++], res);
                continue;
            }
            int start = i;
            while (i < n && nums[i] != 0) {
                i++;
            }
            res = max(res, maxP(start, i - 1, nums));
        }
        return res;
    }

    int maxP(int start, int end, vector<int>& nums) {
        if (start == end) {
            return nums[start];
        }
        int res = 1;
        for (int i = start; i <= end; i++) {
            res *= nums[i];
        }
        if (res > 0) {
            return res;
        }
        int cur = 1, res1, res2;
        for (int i = start; i <= end; i++) {
            cur *= nums[i];
            if (nums[i] < 0) {
                res1 = res / cur;
                break;
            }
        }
        cur = 1;
        for (int i = end; i >= start; i--) {
            cur *= nums[i];
            if (nums[i] < 0) {
                res2 = res / cur;
                break;
            }
        }
        return max(res1, res2);
    }
};
```
