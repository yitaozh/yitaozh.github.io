---
title: 9. Palindrome Number
categories: Leetcode
date: 2025-01-15 17:09:26
tags:
    - Math
---

[9. Palindrome Number](https://leetcode.com/problems/palindrome-number/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

Given an integer `x`, return `true` if `x` is a **palindrome**, and `false` otherwise.

**Example 1:**

```bash
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
```

**Example 2:**

```bash
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
```

**Example 3:**

```bash
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
```

**Constraints:**

- `-2^31<= x <= 2^31- 1`

**Follow up:**  Could you solve it without converting the integer to a string?

## Hints/Notes

- 2025/01/XX
- No solution from 0x3F

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x > 0 && x % 10 == 0)) {
            return false;
        }
        int reversed = 0;
        while (x > reversed) {
            int digit = x % 10;
            x /= 10;
            reversed = reversed * 10 + digit;
        }
        return reversed == x || reversed / 10 == x;
    }
};
```
