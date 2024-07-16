---
title: 140. Word Break II
categories: Leetcode
date: 2024-07-16 00:24:20
tags:
    - Array
    - Hash Table
    - String
    - Dynamic Programming
    - Backtracking
    - Trie
    - Memoization
---

[140. Word Break II](https://leetcode.com/problems/word-break-ii/description/)

## Description

Given a string `s` and a dictionary of strings `wordDict`, add spaces in `s` to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in **any order** .

**Note**  that the same word in the dictionary may be reused multiple times in the segmentation.

**Example 1:**

```bash
Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]
```

**Example 2:**

```bash
Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
Explanation: Note that you are allowed to reuse a dictionary word.
```

**Example 3:**

```bash
Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: []
```

**Constraints:**

- `1 <= s.length <= 20`
- `1 <= wordDict.length <= 1000`
- `1 <= wordDict[i].length <= 10`
- `s` and `wordDict[i]` consist of only lowercase English letters.
- All the strings of `wordDict` are **unique** .
- Input is generated in a way that the length of the answer doesn't exceed10^5.

## Hints/Notes

- N/A

## Solution

Language: **C++**

```C++
class Solution {
public:
    unordered_set<string> words;
    vector<string> res;
    string cur, s_;
    int minLen = INT_MAX, maxLen = 0;

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (auto& word : wordDict) {
            words.insert(word);
            minLen = min(minLen, (int)word.size());
            maxLen = max(maxLen, (int)word.size());
        }
        s_ = s;
        traverse(0);
        return res;
    }

    void traverse(int index) {
        if (index == s_.size()) {
            cur.pop_back();
            res.push_back(cur);
            cur.push_back(' ');
        }
        for (int i = minLen; i <= maxLen; i++) {
            if (i + index > s_.size()) {
                break;
            }
            string tmp = s_.substr(index, i);
            if (words.contains(tmp)) {
                cur += tmp + " ";
                traverse(index + i);
                int len = tmp.size();
                for (int k = 0; k <= len; k++) {
                    cur.pop_back();
                }
            }
        }
    }
};
```
