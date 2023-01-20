---
title: 1056. Confusing Number
categories: Leetcode
date: 2023-01-20 17:37:19
tags:
    - Math
---

# [1069\. Confusing Number](https://leetcode.com/problems/confusing-number/)

## Description

Difficulty: **Easy**

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool confusingNumber(int n) {
        unordered_map<int, int> mapping;
        int sum = 0, tmp = n;
        while (tmp > 0) {
            int r = tmp % 10;
            tmp /= 10;
            switch(r) {
                case 0:
                case 1:
                case 8:
                    sum = sum * 10 + r;
                    break;
                case 6:
                    sum = sum * 10 + 9;
                    break;
                case 9:
                    sum = sum * 10 + 6;
                    break;
                case 2:
                case 3:
                case 4:
                case 5:
                case 7:
                    return false;
            }
        }
        return !(sum == n);
    }
};
```