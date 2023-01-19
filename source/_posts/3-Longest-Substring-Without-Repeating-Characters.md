---
title: 3. Longest Substring Without Repeating Characters
categories: Leetcode
date: 2023-01-18 23:52:10
tags:
    - Hash Table
    - String
    - Sliding Window
---

# [3\. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

## Description

Difficulty: **Medium**

Related Topics: [Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

Given a string `s`, find the length of the **longest** <span data-keyword="substring-nonempty">**substring**</span> without repeating characters.

**Example 1:**

```
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
```

**Example 2:**

```
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
```

**Example 3:**

```
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
```

**Constraints:**

*   0 <= s.length <= 5 * 10<sup>4</sup>
*   `s` consists of English letters, digits, symbols and spaces.

## Solution

Language: **C++**

```C++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int res = 0, left = 0, right = 0;
        while (right < s.size()) {
            char c = s[right++];
            window[c]++;
            while (window[c] > 1) {
                // We should decrement d here no matter if d
                // is the same as c
                char d = s[left++];
                window[d]--;
            }
            res = max(res, right - left);
        }
        return res;
    }
};
```