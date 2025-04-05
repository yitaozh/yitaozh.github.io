---
title: 159. Longest Substring with At Most Two Distinct Characters
categories: Leetcode
date: 2025-04-05 16:16:33
tags:
    - Hash Table
    - String
    - Sliding Window
---

[159. Longest Substring with At Most Two Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/description/?envType=company&envId=tiktok&favoriteSlug=tiktok-six-months)

## Description

Given a string `s`, return the length of the longest <button type="button" aria-haspopup="dialog" aria-expanded="false" aria-controls="radix-:rp:" data-state="closed" class="">substring</button> that contains at most **two distinct characters** .

**Example 1:**

```bash
Input: s = "eceba"
Output: 3
Explanation: The substring is "ece" which its length is 3.
```

**Example 2:**

```bash
Input: s = "ccaabbb"
Output: 5
Explanation: The substring is "aabbb" which its length is 5.
```

**Constraints:**

- `1 <= s.length <= 10^5`
- `s` consists of English letters.

## Hints/Notes

- 2025/04/02 Q2
- sliding window
- [Leetcode solution](https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/editorial)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int num_distinct = 0, left = 0, right = 0, res = 0, n = s.size();
        int count[52]{};
        while (right < n) {
            int idx = getIndex(s[right]);
            if (count[idx] == 0) {
                num_distinct++;
            }
            count[idx]++;
            while (num_distinct > 2) {
                int l_idx = getIndex(s[left]);
                count[l_idx]--;
                if (count[l_idx] == 0) {
                    num_distinct--;
                }
                left++;
            }
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }

    int getIndex(char& c) {
        if (isupper(c)) {
            return c - 'A' + 26;
        } else {
            return c - 'a';
        }
    }
};
```
