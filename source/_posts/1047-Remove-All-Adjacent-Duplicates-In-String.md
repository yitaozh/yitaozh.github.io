---
title: 1047. Remove All Adjacent Duplicates In String
categories: Leetcode
date: 2025-02-03 00:09:44
tags:
    - String
    - Stack
---

[1047. Remove All Adjacent Duplicates In String](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

You are given a string `s` consisting of lowercase English letters. A **duplicate removal**  consists of choosing two **adjacent**  and **equal**  letters and removing them.

We repeatedly make **duplicate removals**  on `s` until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is **unique** .

**Example 1:**

```bash
Input: s = "abbaca"
Output: "ca"
Explanation:
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
```

**Example 2:**

```bash
Input: s = "azxxzy"
Output: "ay"
```

**Constraints:**

- `1 <= s.length <= 10^5`
- `s` consists of lowercase English letters.

## Hints/Notes

- 2025/02/02 Q3
- stack
- [Leetcode solution](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/editorial/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        for (char& c : s) {
            if (!res.empty() && res.back() == c) {
                res.pop_back();
            } else {
                res.push_back(c);
            }
        }
        return res;
    }
};
```
