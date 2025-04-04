---
title: 2062. Count Vowel Substrings of a String
categories: Leetcode
date: 2025-03-31 00:41:00
tags:
    - Hash Table
    - String
---

[2062. Count Vowel Substrings of a String](https://leetcode.com/problems/count-vowel-substrings-of-a-string/description/?envType=company&envId=oracle&favoriteSlug=oracle-six-months)

## Description

A **substring**  is a contiguous (non-empty) sequence of characters within a string.

A **vowel substring**  is a substring that **only**  consists of vowels (`'a'`, `'e'`, `'i'`, `'o'`, and `'u'`) and has **all five**  vowels present in it.

Given a string `word`, return the number of **vowel substrings**  in `word`.

**Example 1:**

```bash
Input: word = "aeiouu"
Output: 2
Explanation: The vowel substrings of word are as follows (underlined):
- "**aeiou** u"
- "**aeiouu** "
```

**Example 2:**

```bash
Input: word = "unicornarihan"
Output: 0
Explanation: Not all 5 vowels are present, so there are no vowel substrings.
```

**Example 3:**

```bash
Input: word = "cuaieuouac"
Output: 7
Explanation: The vowel substrings of word are as follows (underlined):
- "c**uaieuo** uac"
- "c**uaieuou** ac"
- "c**uaieuoua** c"
- "cu**aieuo** uac"
- "cu**aieuou** ac"
- "cu**aieuoua** c"
- "cua**ieuoua** c"
```

**Constraints:**

- `1 <= word.length <= 100`
- `word` consists of lowercase English letters only.

## Hints/Notes

- 2025/03/29 Q1
- sliding window
- [Leetcode solution](https://leetcode.cn/problems/count-vowel-substrings-of-a-string/solutions/1101813/tong-ji-zi-fu-chuan-zhong-de-yuan-yin-zi-evp9/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

    int countVowelSubstrings(string word) {
        int res = 0, n = word.size();
        for (int i = 0; i < n; ) {
            char& c = word[i];
            if (vowels.contains(c)) {
                int start = i;
                while (i < n && vowels.contains(word[i])) {
                    i++;
                }
                res += helper(word, start, i);
            } else {
                i++;
            }
        }
        return res;
    }

    int helper(string& word, int start, int end) {
        map<char, int> count;
        int left = start, right = start, res = 0;
        while (right < end) {
            count[word[right]]++;
            while (count.size() >= 5) {
                res += end - right;
                char& l = word[left++];
                count[l]--;
                if (count[l] == 0) {
                    count.erase(l);
                }
            }
            right++;
        }
        return res;
    }
};
```
