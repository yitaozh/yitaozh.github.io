---
title: 1056. Confusing Number
categories: Leetcode
date: 2023-01-20 17:37:19
tags:
    - Math
---

# [1056\. Confusing Number](https://leetcode.com/problems/confusing-number/)

## Description

Difficulty: **Easy**

Related Topics: [Math](https://leetcode.com/tag/https://leetcode.com/tag/math//)

A **confusing number** is a number that when rotated `180` degrees becomes a different number with **each digit valid**.

We can rotate digits of a number by `180` degrees to form new digits.

* When `0`, `1`, `6`, `8`, and `9` are rotated `180` degrees, they become `0`, `1`, `9`, `8`, and `6` respectively.
* When `2`, `3`, `4`, `5`, and `7` are rotated `180` degrees, they become **invalid**.

Note that after rotating a number, we can ignore leading zeros.

* For example, after rotating `8000`, we have `0008` which is considered as just `8`.

Given an integer `n`, return `true` _if it is a **confusing number**, or_ `false` _otherwise_.

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/03/23/1268_1.png)

```bash
Input: n = 6
Output: true
Explanation: We get 9 after rotating 6, 9 is a valid number, and 9 != 6.
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2019/03/23/1268_2.png)

```bash
Input: n = 89
Output: true
Explanation: We get 68 after rotating 89, 68 is a valid number and 68 != 89.
```

**Example 3:**

![](https://assets.leetcode.com/uploads/2019/03/26/1268_3.png)

```bash
Input: n = 11
Output: false
Explanation: We get 11 after rotating 11, 11 is a valid number but the value remains the same, thus 11 is not a confusing number
```

**Constraints:**

* 0 <= n <= 10<sup>9</sup>

## Hints/Notes

* No need to do the mapping, we can use switch during the loop

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool confusingNumber(int n) {
        int sum = 0, tmp = n;
        while (tmp > 0) {
            int r = tmp % 10;
            tmp /= 10;
            switch(r) {
                case 0:
                case 1:
                case 8:
                    sum = sum * 10 + r;
                    break;
                case 6:
                    sum = sum * 10 + 9;
                    break;
                case 9:
                    sum = sum * 10 + 6;
                    break;
                case 2:
                case 3:
                case 4:
                case 5:
                case 7:
                    return false;
            }
        }
        return !(sum == n);
    }
};
```
