---
title: 1768. Merge Strings Alternately
categories: Leetcode
date: 2025-01-27 13:08:13
tags:
    - Two Pointers
    - String
---

[1768. Merge Strings Alternately](https://leetcode.com/problems/merge-strings-alternately/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

You are given two strings `word1` and `word2`. Merge the strings by adding letters in alternating order, starting with `word1`. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.

**Example 1:**

```bash
Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation:The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
```

**Example 2:**

```bash
Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation:Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b
word2:    p   q   r   s
merged: a p b q   r   s
```

**Example 3:**

```bash
Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation:Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q
merged: a p b q c   d
```

**Constraints:**

- `1 <= word1.length, word2.length <= 100`
- `word1` and `word2` consist of lowercase English letters.

## Hints/Notes

- 2025/01/26
- two pointers
- [0x3F's solution](https://leetcode.cn/problems/merge-strings-alternately/solutions/2794711/jian-dan-ti-jian-dan-zuo-pythonjavaccgoj-mqmy/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l1 = 0, l2 = 0;
        string res;
        while (l1 < word1.size() || l2 < word2.size()) {
            if (l1 < word1.size()) {
                res.push_back(word1[l1++]);
            }
            if (l2 < word2.size()) {
                res.push_back(word2[l2++]);
            }
        }
        return res;
    }
};
```
