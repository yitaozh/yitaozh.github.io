---
title: 3334. Find the Maximum Factor Score of Array
categories: Leetcode
date: 2024-11-20 14:51:09
tags:
    - Array
    - Math
    - Number Theory
---

[3334. Find the Maximum Factor Score of Array](https://leetcode.com/problems/find-the-maximum-factor-score-of-array/description/)

## Description

You are given an integer array `nums`.

The **factor score**  of an array is defined as the product of the LCM and GCD of all elements of that array.

Return the **maximum factor score**  of `nums` after removing **at most**  one element from it.

**Note**  that both the LCM and GCD of a single number are the number itself, and the factor score of an **empty**  array is 0.

**Example 1:**

```bash
Input: nums = [2,4,8,16]

Output: 64
```

Explanation:

On removing 2, the GCD of the rest of the elements is 4 while the LCM is 16, which gives a maximum factor score of `4 * 16 = 64`.

**Example 2:**

```bash
Input: nums = [1,2,3,4,5]

Output: 60
```

Explanation:

The maximum factor score of 60 can be obtained without removing any elements.

**Example 3:**

```bash
Input: nums = [3]

Output: 9
```

**Constraints:**

- `1 <= nums.length <= 100`
- `1 <= nums[i] <= 30`

## Hints/Notes

- 2024/11/03
- prefix and suffix
- [0x3F's solution]( https://leetcode.cn/problems/find-the-maximum-factor-score-of-array/solution/fei-bao-li-zuo-fa-qian-hou-zhui-fen-jie-27f8y/)(checked)
- Weekly Contest 421

## Solution

Language: **C++**

Prefix and suffix:

```C++
class Solution {
public:
    long long maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> suflcm(n + 1, 1);
        vector<long long> sufgcd(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            suflcm[i] = lcm(suflcm[i + 1], nums[i]);
            sufgcd[i] = gcd(sufgcd[i + 1], nums[i]);
        }
        long long res = suflcm[0] * sufgcd[0];
        long long l = 1, g = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, lcm(l, suflcm[i + 1]) * gcd(g, sufgcd[i + 1]));
            l = lcm(nums[i], l);
            g = gcd(nums[i], g);
        }
        return res;
    }
};
```

Force brutal:

```C++
class Solution {
public:
    long long maxScore(vector<int>& nums) {
        long long res = 0;
        int n = nums.size();
        if (n == 1) {
            return nums[0] * nums[0];
        }
        long long l = nums[0], g = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            l = lcm(l, nums[i]);
            g = gcd(g, nums[i]);
        }
        res = l * g;
        for (int i = 0; i < nums.size(); i++) {
            long long l = -1, g = -1;
            for (int j = 0; j < nums.size(); j++) {
                if (i != j) {
                    if (l == -1) {
                        l = nums[j];
                        g = nums[j];
                    } else {
                        l = lcm(l, nums[j]);
                        g = gcd(g, nums[j]);
                    }
                }
            }
            res = max(res, l * g);
        }
        return res;
    }
};
```
