---
title: 859. Buddy Strings
categories: Leetcode
date: 2025-03-22 15:56:48
tags:
    - Hash Table
    - String
---

[859. Buddy Strings](https://leetcode.com/problems/buddy-strings/description/?envType=company&envId=doordash&favoriteSlug=doordash-six-months)

## Description

Given two strings `s` and `goal`, return `true` if you can swap two letters in `s` so the result is equal to `goal`, otherwise, return `false`.

Swapping letters is defined as taking two indices `i` and `j` (0-indexed) such that `i != j` and swapping the characters at `s[i]` and `s[j]`.

- For example, swapping at indices `0` and `2` in `"abcd"` results in `"cbad"`.

**Example 1:**

```bash
Input: s = "ab", goal = "ba"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.
```

**Example 2:**

```bash
Input: s = "ab", goal = "ab"
Output: false
Explanation: The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.
```

**Example 3:**

```bash
Input: s = "aa", goal = "aa"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal to goal.
```

**Constraints:**

- `1 <= s.length, goal.length <= 2 * 10^4`
- `s` and `goal` consist of lowercase letters.

## Hints/Notes

- 2025/02/28 Q3
- string
- [Leetcode solution](https://leetcode.com/problems/buddy-strings/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = s.size();
        if (goal.size() != n) {
            return false;
        }
        if (s == goal) {
            int count[26]{};
            for (int i = 0; i < n; i++) {
                count[s[i] - 'a']++;
                if (count[s[i] - 'a'] > 1) {
                    return true;
                }
            }
            return false;
        } else {
            int prev = -1;
            bool found = false;
            for (int i = 0; i < n; i++) {
                if (s[i] != goal[i]) {
                    if (found) {
                        return false;
                    }
                    if (prev == -1) {
                        prev = i;
                    } else {
                        if (s[prev] == goal[i] && s[i] == goal[prev]) {
                            found = true;
                        } else {
                            return false;
                        }
                    }
                }
            }
            return found;
        }
    }
};
```
