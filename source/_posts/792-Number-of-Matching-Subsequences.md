---
title: 792. Number of Matching Subsequences
categories: Leetcode
date: 2025-03-22 03:23:54
tags:
    - Array
    - Hash Table
    - String
    - Binary Search
    - Dynamic Programming
    - Trie
    - Sorting
---

[792. Number of Matching Subsequences](https://leetcode.com/problems/number-of-matching-subsequences/description/)

## Description

Given a string `s` and an array of strings `words`, return the number of `words[i]` that is a subsequence of `s`.

A **subsequence**  of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

- For example, `"ace"` is a subsequence of `"abcde"`.

**Example 1:**

```bash
Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".
```

**Example 2:**

```bash
Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
Output: 2
```

**Constraints:**

- `1 <= s.length <= 5 * 10^4`
- `1 <= words.length <= 5000`
- `1 <= words[i].length <= 50`
- `s` and `words[i]` consist of only lowercase English letters.

## Hints/Notes

- 2025/02/27 Q2
- next letter pointer
- [0x3F's solution](https://leetcode.com/problems/number-of-matching-subsequences/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int numMatchingSubseq(string s, vector<string> words) {
        // we need 26 queues, so let's have a vector of queue
        vector<queue<pair<int, int>>> charToQueue(26);
        for (int i = 0; i < words.size(); i++) {
            char& c = words[i][0];
            charToQueue[c - 'a'].push({i, 0});
        }
        int res = 0;
        for (char& c : s) {
            auto& q = charToQueue[c - 'a'];
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [wordIdx, idx] = q.front();
                q.pop();
                if (idx == words[wordIdx].size() - 1) {
                    res++;
                } else {
                    char& next = words[wordIdx][idx + 1];
                    charToQueue[next - 'a'].push({wordIdx, idx + 1});
                }
            }
        }
        return res;
    }
};
```
