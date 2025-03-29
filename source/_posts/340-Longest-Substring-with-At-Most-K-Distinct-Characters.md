---
title: 340. Longest Substring with At Most K Distinct Characters
categories: Leetcode
date: 2025-03-29 13:30:16
tags:
    - Hash Table
    - String
    - Sliding Window
---

[340. Longest Substring with At Most K Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/description/?envType=company&envId=oracle&favoriteSlug=oracle-six-months)

## Description

Given a string `s` and an integer `k`, return the length of the longest <button type="button" aria-haspopup="dialog" aria-expanded="false" aria-controls="radix-:rp:" data-state="closed" class="">substring</button> of `s` that contains at most `k` **distinct**  characters.

**Example 1:**

```bash
Input: s = "eceba", k = 2
Output: 3
Explanation: The substring is "ece" with length 3.
```

**Example 2:**

```bash
Input: s = "aa", k = 1
Output: 2
Explanation: The substring is "aa" with length 2.
```

**Constraints:**

- `1 <= s.length <= 5 * 10^4`
- `0 <= k <= 50`

## Hints/Notes

- 2025/03/23 Q3
- sliding window
- [Leetcode solution](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        map<char, int> freq;
        int left = 0, right = 0, n = s.size(), res = 0;
        while (right < n) {
            char& c = s[right++];
            freq[c]++;
            while (freq.size() > k) {
                char l = s[left++];
                freq[l]--;
                if (freq[l] == 0) {
                    freq.erase(l);
                }
            }
            res = max(res, right - left);
        }
        return res;
    }
};
```
