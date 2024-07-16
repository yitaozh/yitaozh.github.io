---
title: 139. Word Break
categories: Leetcode
date: 2024-07-16 00:22:21
tags:
    - Array
    - Hash Table
    - String
    - Dynamic Programming
    - Trie
    - Memoization
---

[139. Word Break](https://leetcode.com/problems/word-break/description/)

## Description

Given a string `s` and a dictionary of strings `wordDict`, return `true` if `s` can be segmented into a space-separated sequence of one or more dictionary words.

**Note**  that the same word in the dictionary may be reused multiple times in the segmentation.

**Example 1:**

```bash
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
```

**Example 2:**

```bash
Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
```

**Example 3:**

```bash
Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
```

**Constraints:**

- `1 <= s.length <= 300`
- `1 <= wordDict.length <= 1000`
- `1 <= wordDict[i].length <= 20`
- `s` and `wordDict[i]` consist of only lowercase English letters.
- All the strings of `wordDict` are **unique** .

## Hints/Notes

- N/A

## Solution

Language: **C++**

```C++
class Solution {
public:
    string s_;
    int minLen = INT_MAX, maxLen = 0;
    unordered_set<string> words;
    map<int, bool> m;

    bool wordBreak(string s, vector<string>& wordDict) {
        for (auto& word : wordDict) {
            words.insert(word);
            maxLen = max(maxLen, (int)word.size());
            minLen = min(minLen, (int)word.size());
        }
        s_ = s;
        bool found = traverse(0);
        return found;
    }

    bool traverse(int index) {
        if (index == s_.size()) {
            return true;
        }

        if (m.contains(index)) {
            return m[index];
        }

        bool res = false;
        for (int i = maxLen; i >= minLen; i--) {
            if (i + index > s_.size()) {
                continue;
            }
            string tmp = s_.substr(index, i);
            if (words.contains(tmp)) {
                res |= traverse(index + i);
                if (res) {
                    break;
                }
            }
        }
        m[index] = res;
        return res;
    }
};
```
