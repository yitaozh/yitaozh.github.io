---
title: 1456. Maximum Number of Vowels in a Substring of Given Length
categories: Leetcode
date: 2024-10-21 17:46:17
tags:
    - String
    - Sliding Window
---

[1456. Maximum Number of Vowels in a Substring of Given Length](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/)

## Description

Given a string `s` and an integer `k`, return the maximum number of vowel letters in any substring of `s` with length `k`.

**Vowel letters**  in English are `'a'`, `'e'`, `'i'`, `'o'`, and `'u'`.

**Example 1:**

```bash
Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
```

**Example 2:**

```bash
Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
```

**Example 3:**

```bash
Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.
```

**Constraints:**

- `1 <= s.length <= 10^5`
- `s` consists of lowercase English letters.
- `1 <= k <= s.length`

## Hints/Notes

- 2024/10/02
- sliding window
- [0x3F's solution](https://leetcode.cn/problems/maximum-number-of-vowels-in-a-substring-of-given-length/solutions/2809359/tao-lu-jiao-ni-jie-jue-ding-chang-hua-ch-fzfo/)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

    int maxVowels(string s, int k) {
        int res = 0, right = 0, tmp = 0;
        while (right < s.size()) {
            char r = s[right];
            if (vowels.contains(r)) {
                tmp++;
            }
            if (right >= k) {
                char l = s[right - k];
                if (vowels.contains(l)) {
                    tmp--;
                }
            }
            res = max(res, tmp);
            right++;
        }
        return res;
    }
};
```
