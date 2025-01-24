---
title: 680. Valid Palindrome II
categories: Leetcode
date: 2025-01-15 00:41:26
tags:
    - Two Pointers
    - String
    - Greedy
---

[680. Valid Palindrome II](https://leetcode.com/problems/valid-palindrome-ii/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

Given a string `s`, return `true` if the `s` can be palindrome after deleting **at most one**  character from it.

**Example 1:**

```bash
Input: s = "aba"
Output: true
```

**Example 2:**

```bash
Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
```

**Example 3:**

```bash
Input: s = "abc"
Output: false
```

**Constraints:**

- `1 <= s.length <= 10^5`
- `s` consists of lowercase English letters.

## Hints/Notes

- 2025/01/14
- string
- [Leetcode solution](https://leetcode.com/problems/valid-palindrome-ii/editorial/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        bool deleted = false;
        while (left < right) {
            if (s[left] != s[right]) {
                if (deleted) {
                    return false;
                } else {
                    return check(s, left + 1, right) || check(s, left, right - 1);
                }
            }
            left++;
            right--;
        }
        return true;
    }

    bool check(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
```
