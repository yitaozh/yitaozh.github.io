---
title: 3325. Count Substrings With K-Frequency Characters I
categories: Leetcode
date: 2024-10-22 14:50:18
tags:
    - Hash Table
    - String
    - Sliding Window
---

[3325. Count Substrings With K-Frequency Characters I](https://leetcode.com/problems/count-substrings-with-k-frequency-characters-i/description/)

## Description

Given a string `s` and an integer `k`, return the total number of substrings of `s` where **at least one**  character appears **at least**  `k` times.

**Example 1:**

```bash
Input: s = "abacb", k = 2

Output: 4
```

Explanation:

The valid substrings are:

- `"aba"` (character `'a'` appears 2 times).
- `"abac"` (character `'a'` appears 2 times).
- `"abacb"` (character `'a'` appears 2 times).
- `"bacb"` (character `'b'` appears 2 times).

**Example 2:**

```bash
Input: s = "abcde", k = 1

Output: 15
```

Explanation:

All substrings are valid because every character appears at least once.

**Constraints:**

- `1 <= s.length <= 3000`
- `1 <= k <= s.length`
- `s` consists only of lowercase English letters.

## Hints/Notes

- 2024/10/09
- sliding window
- [0x3F's solution](https://leetcode.cn/problems/count-substrings-with-k-frequency-characters-i/solutions/2957691/on-hua-dong-chuang-kou-pythonjavacgo-by-1xgqm/)(checked)
- Weekly Contest 420

## Solution

Language: **C++**

Cleaner solutino

```C++
class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int left = 0, res = 0;
        int count[26]{};
        for (char& c : s) {
            count[c - 'a']++;
            while (count[c - 'a'] >= k) {
                char l = s[left++];
                count[l - 'a']--;
            }
            res += left;
        }
        return res;
    }
};
```

```C++
class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int left = 0, right = 0, n = s.size(), valid = 0, res = 0;
        map<int, int> m;
        while (right < n) {
            char r = s[right];
            m[r]++;
            if (m[r] >= k) {
                valid++;
            }
            while (left <= right && valid) {
                res += n - right;
                char l = s[left];
                m[l]--;
                if (m[l] == k - 1) {
                    valid--;
                }
                left++;
            }
            right++;
        }
        return res;
    }
};
```
