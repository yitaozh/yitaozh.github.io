---
title: 1593. Split a String Into the Max Number of Unique Substrings
categories: Leetcode
date: 2024-10-21 17:29:02
tags:
    - Hash Table
    - String
    - Backtracking
---

[1593. Split a String Into the Max Number of Unique Substrings](https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/description/?envType=daily-question&envId=2024-10-21)

## Description

Given a string`s`, return the maximum number of unique substrings that the given string can be split into.

You can split string`s` into any list of **non-empty substrings** , where the concatenation of the substrings forms the original string.However, you must split the substrings such that all of them are **unique** .

A **substring**  is a contiguous sequence of characters within a string.

**Example 1:**

```bash
Input: s = "ababccc"
Output: 5
```

Explanation:

One way to split maximally is ['a', 'b', 'ab', 'c', 'cc']. Splitting like ['a', 'b', 'a', 'b', 'c', 'cc'] is not valid as you have 'a' and 'b' multiple times.

**Example 2:**

```bash
Input: s = "aba"
Output: 2
```

Explanation:

One way to split maximally is ['a', 'ba'].

**Example 3:**

```bash
Input: s = "aa"
Output: 1
```

Explanation:

It is impossible to split the string any further.

**Constraints:**

- `1 <= s.length<= 16`
- `s` contains only lower case English letters.

## Hints/Notes

- set

## Solution

Language: **C++**

```C++
class Solution {
public:
    unordered_set<string> us;
    int res; string s_;
    int maxUniqueSplit(string s) {
        res = INT_MIN; s_ = s;
        dfs(0);
        return res;
    }

    void dfs(int index) {
        if (index == s_.size()) {
            res = max(res, (int)us.size());
            return;
        }
        for (int i = index + 1; i <= s_.size(); i++) {
            string tmp = s_.substr(index, i - index);
            if (!us.contains(tmp)) {
                us.insert(tmp);
                dfs(i);
                us.erase(tmp);
            }
        }
    }
};
```
