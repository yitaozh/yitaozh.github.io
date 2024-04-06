---
title: 49. Group Anagrams
categories: Leetcode
date: 2023-12-19 20:14:38
tags:
    - Array
    - Hash Table
    - String
    - Sorting
---

[49\. Group Anagrams](https://leetcode.com/problems/group-anagrams/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Hash Table](https://leetcode.com/tag/https://leetcode.com/tag/hash-table//), [String](https://leetcode.com/tag/https://leetcode.com/tag/string//), [Sorting](https://leetcode.com/tag/https://leetcode.com/tag/sorting//)

Given an array of strings `strs`, group **the anagrams** together. You can return the answer in **any order**.

An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

**Example 1:**

```bash
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
```

**Example 2:**

```bash
Input: strs = [""]
Output: [[""]]
```

**Example 3:**

```bash
Input: strs = ["a"]
Output: [["a"]]
```

**Constraints:**

* 1 <= strs.length <= 10<sup>4</sup>
* `0 <= strs[i].length <= 100`
* `strs[i]` consists of lowercase English letters.

## Hints/Notes

* encode the string, use map to record strings with the same encoding

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        for (string str : strs) {
            string encode = encodeStr(str);
            m[encode].push_back(str);
        }
        vector<vector<string>> res;
        for (auto it = m.begin(); it != m.end(); it++) {
            res.push_back(it->second);
        }
        return res;
    }

    string encodeStr(string str) {
        int count[26] = {0};
        for (char c : str) {
            count[c - 'a']++;
        }
        string s;
        for (int i = 0; i < 26; i++) {
            s += to_string(count[i]);
            s.push_back('a' + i);
        }
        return s;
    }
};
```
