---
title: 916. Word Subsets
categories: Leetcode
date: 2025-03-13 15:17:55
tags:
    - Array
    - Hash Table
    - String
---

[916. Word Subsets](https://leetcode.com/problems/word-subsets/description/)

## Description

You are given two string arrays `words1` and `words2`.

A string `b` is a **subset**  of string `a` if every letter in `b` occurs in `a` including multiplicity.

- For example, `"wrr"` is a subset of `"warrior"` but is not a subset of `"world"`.

A string `a` from `words1` is **universal**  if for every string `b` in `words2`, `b` is a subset of `a`.

Return an array of all the **universal**  strings in `words1`. You may return the answer in **any order** .

**Example 1:**

```bash
Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]

Output: ["facebook","google","leetcode"]
```

**Example 2:**

```bash
Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["lc","eo"]

Output: ["leetcode"]
```

**Example 3:**

```bash
Input: words1 = ["acaac","cccbb","aacbb","caacc","bcbbb"], words2 = ["c","cc","b"]

Output: ["cccbb"]
```

**Constraints:**

- `1 <= words1.length, words2.length <= 10^4`
- `1 <= words1[i].length, words2[i].length <= 10`
- `words1[i]` and `words2[i]` consist only of lowercase English letters.
- All the strings of `words1` are **unique** .

## Hints/Notes

- 2025/03/02 Q3
- string
- [0x3F's solution](https://leetcode.com/problems/word-subsets/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> targets(26, 0);
        for (string& word : words2) {
            vector<int> curWord(26, 0);
            for (char& c : word) {
                curWord[c - 'a']++;
                targets[c - 'a'] = max(targets[c - 'a'], curWord[c - 'a']);
            }
        }
        vector<string> res;
        for (string& word : words1) {
            vector<int> curWord(26, 0);
            for (char& c : word) {
                curWord[c - 'a']++;
            }
            bool valid_word = true;
            for (int i = 0; i < targets.size(); i++) {
                if (targets[i] > curWord[i]) {
                    valid_word = false;
                    break;
                }
            }
            if (valid_word) {
                res.push_back(word);
            }
        }
        return res;
    }
};
```
