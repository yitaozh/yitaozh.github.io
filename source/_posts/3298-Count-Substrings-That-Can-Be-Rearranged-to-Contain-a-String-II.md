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

- 2024/09/14
- sliding window
- t3 is the same question with less number
- [0x3F's solution](https://leetcode.cn/problems/count-substrings-that-can-be-rearranged-to-contain-a-string-ii/solutions/2925828/on-hua-dong-chuang-kou-qiu-ge-shu-python-0x7a/)(checked)
- Weekly Contest 416 T4

## Solution

Language: **C++**

```C++
class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        vector<int> target(26, 0);
        for (int i = 0; i < word2.size(); i++) {
            target[word2[i] - 'a']++;
        }
        int left = 0, right = 0, valid = 0;
        for (int i = 0; i < target.size(); i++) {
            valid += target[i] > 0 ? 1 : 0;
        }
        long long res = 0;
        while (right < word1.size()) {
            char c = word1[right];
            target[c - 'a']--;
            if (0 == target[c - 'a']) {
                valid--;
            }
            while (valid == 0) {
                char l = word1[left++];
                if (0 == target[l - 'a']) {
                    valid++;
                }
                target[l - 'a']++;
            }
            // so, for subString with left index in [prev_l, left),
            // they can have substring with right index from right all the way to the end
            res += left;
            right++;
        }
        return res;
    }
};
```
