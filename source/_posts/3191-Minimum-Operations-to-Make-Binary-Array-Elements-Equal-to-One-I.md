---
title: 3191. Minimum Operations to Make Binary Array Elements Equal to One I
categories: Leetcode
date: 2024-06-27 23:24:06
tags:
    - Array
    - Bit Manipulation
    - Queue
    - Sliding Window
    - Prefix Sum
---

[3191. Minimum Operations to Make Binary Array Elements Equal to One I](https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/description/)

## Description

You are given a binary array `nums`.

You can do the following operation on the array **any**  number of times (possibly zero):

- Choose **any** 3 **consecutive** elements from the array and **flip** **all** of them.

**Flipping** an element means changing its value from 0 to 1, and from 1 to 0.

Return the **minimum**  number of operations required to make all elements in `nums` equal to 1. If it is impossible, return -1.

**Example 1:**

```bash
Input: nums = [0,1,1,1,0,0]

Output: 3
```

Explanation:

We can do the following operations:

- Choose the elements at indices 0, 1 and 2. The resulting array is nums = [**1** ,**0** ,**0** ,1,0,0].
- Choose the elements at indices 1, 2 and 3. The resulting array is nums = [1,**1** ,**1** ,**0** ,0,0].
- Choose the elements at indices 3, 4 and 5. The resulting array is nums = [1,1,1,**1** ,**1** ,**1** ].

**Example 2:**

```bash
Input: nums = [0,1,1,1]

Output: -1
```

Explanation:

It is impossible to make all elements equal to 1.

**Constraints:**

- `3 <= nums.length <= 10^5`
- `0 <= nums[i] <= 1`

## Hints/Notes

- Biweekly Contest 133

## Solution

Language: **C++**

```C++
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int numOps = 0;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] == 0) {
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                numOps++;
            }
        }
        int size = nums.size();
        return nums[size - 2] && nums[size - 1] ? numOps : -1;
    }
};
```
