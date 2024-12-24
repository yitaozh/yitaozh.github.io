---
title: 76. Minimum Window Substring
categories: Leetcode
date: 2023-01-18 18:15:02
tags:
    - Hash Table
    - String
    - Sliding Window
---

[76\. Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/)

## Description

Difficulty: **Hard**

Related Topics: [Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

Given two strings `s` and `t` of lengths `m` and `n` respectively, return _the **minimum window**_ <span data-keyword="substring-nonempty">**_substring_**</span> _of_ `s` _such that every character in_ `t` _(**including duplicates**) is included in the window_. If there is no such substring, return _the empty string_ `""`.

The testcases will be generated such that the answer is **unique**.

**Example 1:**

```bash
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
```

**Example 2:**

```bash
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
```

**Example 3:**

```bash
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
```

**Constraints:**

* `m == s.length`
* `n == t.length`
* 1 <= m, n <= 10<sup>5</sup>
* `s` and `t` consist of uppercase and lowercase English letters.

**Follow up:** Could you find an algorithm that runs in `O(m + n)` time?

## Hints/Notes

* 2023/08/09
* Sliding window, keep taking new elements while trying to shrink the left boundry
* Use map to record if all required letters are included
* [0x3F's solution](https://leetcode.cn/problems/minimum-window-substring/solutions/2713911/liang-chong-fang-fa-cong-o52mn-dao-omnfu-3ezz/)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (char c: t) {
            need[c]++;
        }
        int valid = 0, left = 0, right = 0, start = 0, len = INT_MAX;
        while (right < s.size()) {
            char c = s[right++];
            window[c]++;
            if (need.count(c)) {
                if (need[c] == window[c]) {
                    valid++;
                }
            }
            while (valid == need.size()) {
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }
                c = s[left];
                left++;
                if (need.count(c)) {
                    if (need[c] == window[c]) {
                        valid--;
                    }
                    window[c]--;
                }
            }
        }
        return len == INT_MAX ? "": s.substr(start, len);
    }
};
```
