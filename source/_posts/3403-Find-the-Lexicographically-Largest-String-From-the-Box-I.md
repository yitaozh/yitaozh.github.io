---
title: 3403. Find the Lexicographically Largest String From the Box I
categories: Leetcode
date: 2025-01-10 10:51:01
tags:
    - Two Pointers
    - String
    - Enumeration
---

[3403. Find the Lexicographically Largest String From the Box I](https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i/description/)

## Description

You are given a string `word`, and an integer `numFriends`.

Alice is organizing a game for her `numFriends` friends. There are multiple rounds in the game, where in each round:

- `word` is split into `numFriends` **non-empty**  strings, such that no previous round has had the **exact**  same split.
- All the split words are put into a box.

Find the lexicographically largest string from the box after all the rounds are finished.

**Example 1:**

```bash
Input: word = "dbca", numFriends = 2

Output: "dbc"
```

Explanation:

All possible splits are:

- `"d"` and `"bca"`.
- `"db"` and `"ca"`.
- `"dbc"` and `"a"`.

**Example 2:**

```bash
Input: word = "gggg", numFriends = 4

Output: "g"
```

Explanation:

The only possible split is: `"g"`, `"g"`, `"g"`, and `"g"`.

**Constraints:**

- `1 <= word.length <= 5* 10^3`
- `word` consists only of lowercase English letters.
- `1 <= numFriends <= word.length`

## Hints/Notes

- 2025/01/11
- enumeration
- [0x3F's solution](https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i/)(checked)
- Weekly Contest 430

## Solution

Language: **C++**

```C++
class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) {
            return word;
        }
        int n = word.size();
        int max_len = n - numFriends + 1;
        string res;
        for (int i = 0; i < n; i++) {
            int len = min(max_len, n - i);
            string tmp = word.substr(i, len);
            if (tmp > res) {
                res = tmp;
            }
        }
        return res;
    }
};
```
