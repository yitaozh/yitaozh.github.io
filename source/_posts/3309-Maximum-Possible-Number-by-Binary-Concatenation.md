---
title: 3309. Maximum Possible Number by Binary Concatenation
categories: Leetcode
date: 2024-10-19 16:18:10
tags:
    - Array
    - Bit Manipulation
    - Enumeration
---

[3309. Maximum Possible Number by Binary Concatenation](https://leetcode.com/problems/maximum-possible-number-by-binary-concatenation/description/)

## Description

You are given an array of integers `nums` of size 3.

Return the **maximum**  possible number whose binary representation can be formed by **concatenating**  the binary representation of **all**  elements in `nums` in some order.

**Note**  that the binary representation of any number does not contain leading zeros.

**Example 1:**

```bash
Input: nums = [1,2,3]

Output: 30
```

Explanation:

Concatenate the numbers in the order `[3, 1, 2]` to get the result `"11110"`, which is the binary representation of 30.

**Example 2:**

```bash
Input: nums = [2,8,16]

Output: 1296
```

Explanation:

Concatenate the numbers in the order `[2, 8, 16]` to get the result `"10100010000"`, which is the binary representation of 1296.

**Constraints:**

- `nums.length == 3`
- `1 <= nums[i] <= 127`

## Hints/Notes

- 2024/09/20
- bit manipulation
- [0x3F's solution](https://leetcode.cn/problems/maximum-possible-number-by-binary-concatenation/solutions/2940489/fei-bao-li-zuo-fa-onlogn-pai-xu-pythonja-540j/)(checked)
- Weekly Contest 418

## Solution

Language: **C++**

nlogn solution:

```C++
class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
        ranges::sort(nums, [](int a, int b) {
            int len_a = __lg(a) + 1;
            int len_b = __lg(b) + 1;
            return (a << len_b | b) > (b << len_a | a);
        });

        int ans = 0;
        for (int x : nums) {
            ans = ans << (__lg(x) + 1) | x;
        }
        return ans;
    }
};
```

```C++
class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (j == i) {
                    continue;
                }
                int k = 3 - i - j;
                int bit1 = __lg(nums[j]) + 1,
                    bit2 = __lg(nums[k]) + 1;
                int tmp =
                    (nums[i] << (bit1 + bit2)) + (nums[j] << bit2) + nums[k];
                res = max(tmp, res);
            }
        }
        return res;
    }
};
```
