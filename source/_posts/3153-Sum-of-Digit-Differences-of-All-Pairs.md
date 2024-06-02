---
title: 3153. Sum of Digit Differences of All Pairs
categories: Leetcode
date: 2024-05-23 11:42:12
tags:
    - Array
    - Hash Table
    - Math
    - Counting
---

[3153. Sum of Digit Differences of All Pairs](https://leetcode.com/problems/sum-of-digit-differences-of-all-pairs/description/)

## Description

You are given an array `nums` consisting of **positive**  integers where all integers have the **same**  number of digits.

The **digit difference**  between two integers is the count of different digits that are in the **same**  position in the two integers.

Return the **sum**  of the **digit differences**  between **all**  pairs of integers in `nums`.

**Example 1:**

```bash
Input: nums = [13,23,12]

Output: 4

Explanation:
We have the following:<br>
- The digit difference between **1** 3 and **2** 3 is 1.<br>
- The digit difference between 1**3**  and 1**2**  is 1.<br>
- The digit difference between **23**  and **12**  is 2.<br>
So the total sum of digit differences between all pairs of integers is `1 + 1 + 2 = 4`.
```

**Example 2:**

```bash
Input: nums = [10,10,10,10]

Output: 0

Explanation:
All the integers in the array are the same. So the total sum of digit differences between all pairs of integers will be 0.
```

**Constraints:**

- `2 <= nums.length <= 10^5`
- `1 <= nums[i] < 10^9`
- All integers in `nums` have the same number of digits.

## Hints/Notes

- Weekly contest 398

## Solution

Language: **C++**

```C++
class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        vector<vector<int>> bits(10, vector<int>(10, 0));
        int index;
        for (int num : nums) {
            index = 0;
            while (num != 0) {
                int val = num % 10;
                bits[index][val]++;
                num /= 10;
                index++;
            }
        }
        long long sum = 0;
        for (int i = 0; i < index; i++) {
            for (int j = 0; j < 10; j++) {
                if (bits[i][j] == 0) continue;
                for (int k = j + 1; k < 10; k++) {
                    sum += bits[i][j] * bits[i][k];
                }
            }
        }
        return sum;
    }
};
```
