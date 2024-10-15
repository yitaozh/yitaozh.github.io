---
title: 3302. Find the Lexicographically Smallest Valid Sequence
categories: Leetcode
date: 2024-10-15 16:44:01
tags:
    - Two Pointers
    - String
    - Dynamic Programming
    - Greedy
---

[3302. Find the Lexicographically Smallest Valid Sequence](https://leetcode.com/problems/find-the-lexicographically-smallest-valid-sequence/description/)

## Description

You are given two strings `word1` and `word2`.

A string `x` is called **almost equal**  to `y` if you can change **at most**  one character in `x` to make it identical to `y`.

A sequence of indices `seq` is called **valid**  if:

- The indices are sorted in **ascending**  order.
- Concatenating the characters at these indices in `word1` in **the same**  order results in a string that is **almost equal**  to `word2`.

Return an array of size `word2.length` representing the lexicographically smallest **valid**  sequence of indices. If no such sequence of indices exists, return an **empty**  array.

**Note**  that the answer must represent the lexicographically smallest array, **not**  the corresponding string formed by those indices.

**Example 1:**

```bash
Input: word1 = "vbcca", word2 = "abc"

Output: [0,1,2]
```

Explanation:

The lexicographically smallest valid sequence of indices is `[0, 1, 2]`:

- Change `word1[0]` to `'a'`.
- `word1[1]` is already `'b'`.
- `word1[2]` is already `'c'`.

**Example 2:**

```bash
Input: word1 = "bacdc", word2 = "abc"

Output: [1,2,4]
```

Explanation:

The lexicographically smallest valid sequence of indices is `[1, 2, 4]`:

- `word1[1]` is already `'a'`.
- Change `word1[2]` to `'b'`.
- `word1[4]` is already `'c'`.

**Example 3:**

```bash
Input: word1 = "aaaaaa", word2 = "aaabc"

Output: []
```

Explanation:

There is no valid sequence of indices.

**Example 4:**

```bash
Input: word1 = "abc", word2 = "ab"

Output: [0,1]
```

**Constraints:**

- `1 <= word2.length < word1.length <= 3 * 10^5`
- `word1` and `word2` consist only of lowercase English letters.

## Hints/Notes

- two pointers
- Biweekly Contest 140

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        // the meaning of suf[i]: starting from the right end of word1, and up until
        // ith index, what's the minimum index in word2 we can match to
        vector<int> suf(n1 + 1);
        suf[n1] = n2;
        int j = n2 - 1;
        for (int i = n1 - 1; i >= 0; i--) {
            if (j >= 0 && word1[i] == word2[j]) {
                j--;
            }
            suf[i] = j + 1;
        }
        j = 0;
        bool found = false;
        vector<int> res;
        for (int i = 0; i < n1; i++) {
            if (word1[i] == word2[j]) {
                res.push_back(i);
                j++;
                if (j == n2) {
                    return res;
                }
            } else if (!found && suf[i + 1] <= j + 1) {
                found = true;
                res.push_back(i);
                j++;
                if (j == n2) {
                    return res;
                }
            }
        }
        return {};
    }
};
```
