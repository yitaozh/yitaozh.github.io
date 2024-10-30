---
title: 2953. Count Complete Substrings
categories: Leetcode
date: 2024-10-29 23:30:48
tags:
    - Hash Table
    - String
    - Sliding Window
---

[2953. Count Complete Substrings](https://leetcode.com/problems/count-complete-substrings/description/)

## Description

You are given a string `word` and an integer `k`.

A substring `s` of `word` is **complete**  if:

- Each character in `s` occurs **exactly**  `k` times.
- The difference between two adjacent characters is **at most**  `2`. That is, for any two adjacent characters `c1` and `c2` in `s`, the absolute difference in their positions in the alphabet is **at most**  `2`.

Return the number of **complete** substrings of `word`.

A **substring**  is a **non-empty**  contiguous sequence of characters in a string.

**Example 1:**

```bash
Input: word = "igigee", k = 2
Output: 3
```

Explanation: The complete substrings where each character appears exactly twice and the difference between adjacent characters is at most 2 are: **igig**ee, igig**ee** , **igigee**.

**Example 2:**

```bash
Input: word = "aaabbbccc", k = 3
Output: 6
```

Explanation: The complete substrings where each character appears exactly three times and the difference between adjacent characters is at most 2 are: **aaa**bbbccc, aaa**bbb**ccc, aaabbb**ccc**, **aaabbb**ccc, aaa**bbbccc**, **aaabbbccc**.

**Constraints:**

- `1 <= word.length <= 10^5`
- `word` consists only of lowercase English letters.
- `1 <= k <= word.length`

## Hints/Notes

- sliding window
- iterate over the number of characters

## Solution

Language: **C++**

```C++
class Solution {
public:
    int countCompleteSubstrings(string word, int k) {
        int res = 0;
        array<int, 26> m;
        for (int i = 1; i <= 26; i++) {
            int len = i * k, left = 0, right = 0, valid = 0;
            fill(m.begin(), m.end(), 0);
            while (right < word.size()) {
                int r = word[right] - 'a';
                m[r]++;
                if (m[r] == k) {
                    valid++;
                }
                if (right && abs(word[right - 1] - word[right]) > 2) {
                    while (left < right) {
                        int l = word[left++] - 'a';
                        if (m[l] == k) {
                            valid--;
                        }
                        m[l]--;
                    }
                }
                if (right - left == len - 1) {
                    if (valid == i) {
                        res++;
                    }
                    int l = word[left++] - 'a';
                    if (m[l] == k) {
                        valid--;
                    }
                    m[l]--;
                }
                right++;
            }
        }
        return res;
    }
};
```
