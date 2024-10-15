---
title: 3298. Count Substrings That Can Be Rearranged to Contain a String II
categories: Leetcode
date: 2024-10-15 16:39:17
tags:
    - Hash Table
    - String
    - Sliding Window
---

[3298. Count Substrings That Can Be Rearranged to Contain a String II](https://leetcode.com/problems/count-substrings-that-can-be-rearranged-to-contain-a-string-ii/description/)

## Description

You are given two strings `word1` and `word2`.

A string `x` is called **valid**  if `x` can be rearranged to have `word2` as a prefix.

Return the total number of **valid**  substrings of `word1`.

**Note**  that the memory limits in this problem are **smaller**  than usual, so you **must**  implement a solution with a linear runtime complexity.

**Example 1:**

```bash
Input: word1 = "bcca", word2 = "abc"

Output: 1
```

Explanation:

The only valid substring is `"bcca"` which can be rearranged to `"abcc"` having `"abc"` as a prefix.

**Example 2:**

```bash
Input: word1 = "abcabc", word2 = "abc"

Output: 10
```

Explanation:

All the substrings except substrings of size 1 and size 2 are valid.

**Example 3:**

```bash
Input: word1 = "abcabc", word2 = "aaabc"

Output: 0
```

**Constraints:**

- `1 <= word1.length <= 10^6`
- `1 <= word2.length <= 10^4`
- `word1` and `word2` consist only of lowercase English letters.

## Hints/Notes

- sliding window
- t3 is the same question with less number
- Weekly Contest 416

## Solution

Language: **C++**

```C++
class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        unordered_map<int, int> target;
        for (int i = 0; i < word2.size(); i++) {
            target[word2[i]]++;
        }
        int left = 0, right = 0, valid = 0;
        long long res = 0;
        unordered_map<int, int> cur;
        while (right < word1.size()) {
            char c = word1[right];
            if (target.contains(c)) {
                cur[c]++;
                if (cur[c] == target[c]) {
                    valid++;
                }
            }
            int prev_l = left;
            while (left <= right && valid == target.size()) {
                char l = word1[left++];
                if (target.contains(l)) {
                    cur[l]--;
                    if (cur[l] < target[l]) {
                        valid--;
                    }
                }
            }
            // so, for subString with left index in [prev_l, left),
            // they can have substring with right index from right all the way to the end
            res += (left - prev_l) * (word1.size() - right);
            right++;
        }
        return res;
    }
};
```
