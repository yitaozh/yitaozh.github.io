---
title: 387. First Unique Character in a String
categories: Leetcode
date: 2023-12-19 20:23:25
tags:
    - Hash Table
    - String
    - Queue
    - Counting
---

[387\. First Unique Character in a String](https://leetcode.com/problems/first-unique-character-in-a-string/)

## Description

Difficulty: **Easy**

Related Topics: [Hash Table](https://leetcode.com/tag/https://leetcode.com/tag/hash-table//), [String](https://leetcode.com/tag/https://leetcode.com/tag/string//), [Queue](https://leetcode.com/tag/https://leetcode.com/tag/queue//), [Counting](https://leetcode.com/tag/https://leetcode.com/tag/counting//)

Given a string `s`, _find the first non-repeating character in it and return its index_. If it does not exist, return `-1`.

**Example 1:**

```bash
Input: s = "leetcode"
Output: 0
```

**Example 2:**

```bash
Input: s = "loveleetcode"
Output: 2
```

**Example 3:**

```bash
Input: s = "aabb"
Output: -1
```

**Constraints:**

* 1 <= s.length <= 10<sup>5</sup>
* `s` consists of only lowercase English letters.

## Hints/Notes

* map

## Solution

Language: **C++**

```C++
class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> m;
        for (char c : s) {
            m[c]++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (m[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};
```
