---
title: 2422. Merge Operations to Turn Array Into a Palindrome
categories: Leetcode
date: 2025-04-09 16:37:01
tags:
    - Array
    - Two Pointers
    - Greedy
---

[2422. Merge Operations to Turn Array Into a Palindrome](https://leetcode.com/problems/merge-operations-to-turn-array-into-a-palindrome/description/)

## Description

You are given an array `nums` consisting of **positive**  integers.

You can perform the following operation on the array **any**  number of times:

- Choose any two **adjacent**  elements and **replace**  them with their **sum** .

- For example, if `nums = [1,2,3,1]`, you can apply one operation to make it `[1,5,1]`.

Return the **minimum**  number of operations needed to turn the array into a **palindrome** .

**Example 1:**

```bash
Input: nums = [4,3,2,1,2,3,1]
Output: 2
Explanation: We can turn the array into a palindrome in 2 operations as follows:
- Apply the operation on the fourth and fifth element of the array, nums becomes equal to [4,3,2,**3** ,3,1].
- Apply the operation on the fifth and sixth element of the array, nums becomes equal to [4,3,2,3,**4** ].
The array [4,3,2,3,4] is a palindrome.
It can be shown that 2 is the minimum number of operations needed.
```

**Example 2:**

```bash
Input: nums = [1,2,3,4]
Output: 3
Explanation: We do the operation 3 times in any position, we obtain the array [10] at the end which is a palindrome.
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^6`

## Hints/Notes

- 2025/04/08 Q2
- greedy
- No solution from 0x3F or Leetcode

## Solution

Language: **C++**

```C++
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<long> sums(nums.begin(), nums.end());
        int l = 0, r = sums.size() - 1, res = 0;
        while (l < r) {
            if (sums[l] == sums[r]) {
                l++;
                r--;
            } else if (sums[l] < sums[r]) {
                sums[l + 1] += sums[l];
                l++;
                res++;
            } else {
                sums[r - 1] += sums[r];
                r--;
                res++;
            }
        }
        return res;
    }
};
```
