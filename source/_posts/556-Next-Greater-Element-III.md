---
title: 556. Next Greater Element III
categories: Leetcode
date: 2025-03-22 23:18:58
tags:
    - Math
    - Two Pointers
    - String
---

[556. Next Greater Element III](https://leetcode.com/problems/next-greater-element-iii/description/?envType=company&envId=doordash&favoriteSlug=doordash-six-months)

## Description

Given a positive integer `n`, find the smallest integer which has exactly the same digits existing in the integer `n` and is greater in value than `n`. If no such positive integer exists, return `-1`.

**Note**  that the returned integer should fit in **32-bit integer** , if there is a valid answer but it does not fit in **32-bit integer** , return `-1`.

**Example 1:**

```bash
Input: n = 12
Output: 21
```

**Example 2:**

```bash
Input: n = 21
Output: -1
```

**Constraints:**

- `1 <= n <= 2^31 - 1`

## Hints/Notes

- 2025/03/16 Q1
- string
- [Leetcode solution](https://leetcode.com/problems/next-greater-element-iii/editorial/?envType=company&envId=doordash&favoriteSlug=doordash-six-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        int idx = str.size() - 2;
        while (idx >= 0) {
            if (str[idx] < str[idx + 1]) {
                // we need to flip here
                int j;
                for (j = str.size() - 1; j >= idx + 1; j--) {
                    if (str[j] > str[idx]) {
                        break;
                    }
                }
                swap(str[idx], str[j]);
                reverse(str.begin() + idx + 1, str.end());
                break;
                // next step:
                // 2, 4, 3, 1
                // 3, 1, 2, 4
            }
            idx--;
        }
        if (str == to_string(n)) {
            return -1;
        }
        int res;
        try {
            res = stoi(str);
        } catch (out_of_range& e) {
            return -1;
        }
        return res;
    }
};
```
