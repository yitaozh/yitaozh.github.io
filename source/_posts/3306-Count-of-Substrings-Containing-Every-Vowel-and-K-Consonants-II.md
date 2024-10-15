---
title: 3306. Count of Substrings Containing Every Vowel and K Consonants II
categories: Leetcode
date: 2024-10-15 16:53:07
tags:
    - Hash Table
    - String
    - Sliding Window
---

[3306. Count of Substrings Containing Every Vowel and K Consonants II](https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/description/)

## Description

You are given a string `word` and a **non-negative**  integer `k`.

Return the total number of substrings of `word` that contain every vowel (`'a'`, `'e'`, `'i'`, `'o'`, and `'u'`) **at least**  once and **exactly**  `k` consonants.

**Example 1:**

```bash
Input: word = "aeioqq", k = 1

Output: 0
```

Explanation:

There is no substring with every vowel.

**Example 2:**

```bash
Input: word = "aeiou", k = 0

Output: 1
```

Explanation:

The only substring with every vowel and zero consonants is `word[0..4]`, which is `"aeiou"`.

**Example 3:**

```bash
Input: word = "ieaouqqieaouqq", k = 1

Output: 3
```

Explanation:

The substrings with every vowel and one consonant are:

- `word[0..5]`, which is `"ieaouq"`.
- `word[6..11]`, which is `"qieaou"`.
- `word[7..12]`, which is `"ieaouq"`.

**Constraints:**

- `5 <= word.length <= 2 * 10^5`
- `word` consists only of lowercase English letters.
- `0 <= k <= word.length - 5`

## Hints/Notes

- the **exactly** sliding window
- Weekly Contest 417

## Solution

Language: **C++**

```C++
class Solution {
public:
    string word_;
    unordered_set<int> vowels = {'a', 'e', 'i', 'o', 'u'};

    long long f(int k) {
        map<int, int> m;
        int left = 0, right = 0, numC = 0, valid = 0, n = word_.size();
        long long res = 0;
        while (right < n) {
            char r = word_[right];
            if (vowels.contains(r)) {
                m[r]++;
                if (m[r] == 1) {
                    valid++;
                }
            } else {
                numC++;
            }
            right++;
            while (valid == vowels.size() && numC >= k) {
                char l = word_[left];
                if (vowels.contains(l)) {
                    m[l]--;
                    if (m[l] == 0) {
                        valid--;
                    }
                } else {
                    numC--;
                }
                left++;
            }
            res += left;
        }
        return res;
    }

    long long countOfSubstrings(string word, int k) {
        word_ = word;
        return f(k) - f(k + 1);
    }
};
```
