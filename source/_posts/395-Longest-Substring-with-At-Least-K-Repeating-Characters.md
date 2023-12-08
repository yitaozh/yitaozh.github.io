---
title: 395. Longest Substring with At Least K Repeating Characters
categories: Leetcode
date: 2023-12-07 21:38:07
tags:
    - Hash Table
    - String
    - Divide and Conquer
    - Sliding Windows
---

# [395\. Longest Substring with At Least K Repeating Characters](https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/)

## Description

Difficulty: **Medium**

Related Topics: [Hash Table](https://leetcode.com/tag/https://leetcode.com/tag/hash-table//), [String](https://leetcode.com/tag/https://leetcode.com/tag/string//), [Divide and Conquer](https://leetcode.com/tag/https://leetcode.com/tag/divide-and-conquer//), [Sliding Window](https://leetcode.com/tag/https://leetcode.com/tag/sliding-window//)

Given a string `s` and an integer `k`, return _the length of the longest substring of_ `s` _such that the frequency of each character in this substring is greater than or equal to_ `k`.

if no such substring exists, return 0.

**Example 1:**

```bash
Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
```

**Example 2:**

```bash
Input: s = "ababbc", k = 2
Output: 5
Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
```

**Constraints:**

* 1 <= s.length <= 10<sup>4</sup>
* `s` consists of only lowercase English letters.
* 1 <= k <= 10<sup>5</sup>

## Hints/Notes

* sliding window

## Solution

Language: **C++**

```C++
class Solution {
public:
    int longestSubstring(string s, int k) {
        int maxLen = 0;
        for (int i = 1; i <= 26; i++) {
            maxLen = max(maxLen, longest(s, k, i));
        }
        return maxLen;
    }

    int longest(string &s, int k, int count) {
        int left = 0, right = 0, currCount = 0, currValid = 0, maxLen = 0;
        vector<int> freq(26, 0);
        while (right < s.size()) {
            if (freq[s[right] - 'a'] == 0) {
                currCount++;
            }
            freq[s[right] - 'a']++;
            if (freq[s[right] - 'a'] == k) {
                currValid++;
            }
            if (currCount == currValid) {
                maxLen = max(maxLen, right - left + 1);
            }
            while (left < right && currCount > count) {
                if (freq[s[left] - 'a'] == k) {
                    currValid--;
                }
                freq[s[left] -'a']--;
                if (freq[s[left] - 'a'] == 0) {
                    currCount--;
                }
                left++;
            }
            right++;
        }
        return maxLen;
    };
};
```
