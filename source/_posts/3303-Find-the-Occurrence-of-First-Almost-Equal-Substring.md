---
title: 3303. Find the Occurrence of First Almost Equal Substring
categories: Leetcode
date: 2024-10-15 16:50:34
tags:
    - String
    - String Matching
---

[3303. Find the Occurrence of First Almost Equal Substring](https://leetcode.com/problems/find-the-occurrence-of-first-almost-equal-substring/description/)

## Description

You are given two strings `s` and `pattern`.

A string `x` is called **almost equal**  to `y` if you can change **at most**  one character in `x` to make it identical to `y`.

Return the **smallest**  starting index of a substring in `s` that is **almost equal**  to `pattern`. If no such index exists, return `-1`.
A **substring**  is a contiguous <b>non-empty</b> sequence of characters within a string.

**Example 1:**

```bash
Input: s = "abcdefg", pattern = "bcdffg"

Output: 1
```

Explanation:

The substring `s[1..6] == "bcdefg"` can be converted to `"bcdffg"` by changing `s[4]` to `"f"`.

**Example 2:**

```bash
Input: s = "ababbababa", pattern = "bacaba"

Output: 4
```

Explanation:

The substring `s[4..9] == "bababa"` can be converted to `"bacaba"` by changing `s[6]` to `"c"`.

**Example 3:**

```bash
Input: s = "abcd", pattern = "dba"

Output: -1
```

**Example 4:**

```bash
Input: s = "dde", pattern = "d"

Output: 0
```

**Constraints:**

- `1 <= pattern.length < s.length <= 10^5`
- `s` and `pattern` consist only of lowercase English letters.

**Follow-up:**  Could you solve the problem if **at most**  `k` **consecutive**  characters can be changed?

## Hints/Notes

- 2024/09/17
- z function
- [0x3F's solution](https://leetcode.cn/problems/find-the-occurrence-of-first-almost-equal-substring/solutions/2934098/qian-hou-zhui-fen-jie-z-shu-zu-pythonjav-0est/)(checked)
- Biweekly Contest 140
- Not suitable for interview

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> calc_z(string s) {
        int n = s.size();
        vector<int> z(n, 0);
        int box_l = 0, box_r = 0;
        for (int i = 1; i < n; i++) {
            if (i <= box_r) {
                z[i] = min(z[i - box_l], box_r - i + 1);
            }
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                box_l = i;
                box_r = i + z[i];
                z[i]++;
            }
        }
        return z;
    }


    // how to use z function:
    // pattern: size m, string: size: n
    // make pattern a prefix of string
    // pass in the string to calc_z
    // iterate through the returned vector's range[m, n - m]
    int minStartingIndex(string s, string pattern) {
        vector<int> pre = calc_z(pattern + s);
        reverse(s.begin(), s.end()); reverse(pattern.begin(), pattern.end());
        vector<int> suf = calc_z(pattern + s);
        int n = s.size(), m = pattern.size();
        for (int i = m; i <= s.size(); i++) {
            if (pre[i] + suf[n + m - i] >= m - 1) {
                return i - m;
            }
        }
        return -1;
    }
};
```
