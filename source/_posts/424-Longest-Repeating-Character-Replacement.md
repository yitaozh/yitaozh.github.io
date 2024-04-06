---
title: 424. Longest Repeating Character Replacement
categories: Leetcode
date: 2023-12-04 23:03:07
tags:
    - Hash Table
    - String
    - Sliding Window
---

[424\. Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/)

## Description

Difficulty: **Medium**

Related Topics: [Hash Table](https://leetcode.com/tag/https://leetcode.com/tag/hash-table//), [String](https://leetcode.com/tag/https://leetcode.com/tag/string//), [Sliding Window](https://leetcode.com/tag/https://leetcode.com/tag/sliding-window//)

You are given a string `s` and an integer `k`. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most `k` times.

Return _the length of the longest substring containing the same letter you can get after performing the above operations_.

**Example 1:**

```bash
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
```

**Example 2:**

```bash
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
```

**Constraints:**

* 1 <= s.length <= 10<sup>5</sup>
* `s` consists of only uppercase English letters.
* `0 <= k <= s.length`

## Hints/Notes

* sliding window
* need to think more about correctness

## Solution

Language: **C++**

```C++
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int left = 0, right = 0, res = 0, windowMaxCount = 0;
        while (right < s.size()) {
            count[s[right] - 'A']++;
            windowMaxCount = max(windowMaxCount, count[s[right] - 'A']);
            while (left <= right && right - left + 1 - windowMaxCount > k) {
                count[s[left++] - 'A']--;
            }
            right++;
            res = max(res, right - left);
        }
        return res;
    }
};
```
