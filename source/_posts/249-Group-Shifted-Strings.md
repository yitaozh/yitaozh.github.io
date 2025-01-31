---
title: 249. Group Shifted Strings
categories: Leetcode
date: 2025-01-31 17:39:21
tags:
    - Array
    - Hash Table
    - String
---

[249. Group Shifted Strings](https://leetcode.com/problems/group-shifted-strings/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

Perform the following shift operations on a string:

- **Right shift** : Replace every letter with the **successive**  letter of the English alphabet, where 'z' is replaced by 'a'. For example, `"abc"` can be right-shifted to `"bcd"`or `"xyz"` can be right-shifted to `"yza"`.
- **Left shift** : Replace every letter with the **preceding**  letter of the English alphabet, where 'a' is replaced by 'z'. For example, `"bcd"` can be left-shifted to `"abc"<font face="Times New Roman"> or ``"yza"` can be left-shifted to `"xyz"`.

We can keep shifting the string in both directions to form an **endless**  **shifting sequence** .

- For example, shift `"abc"` to form the sequence: `... <-> "abc" <-> "bcd" <-> ... <-> "xyz" <-> "yza" <-> ... <-> "zab" <-> "abc" <-> ...`

You are given an array of strings `strings`, group together all `strings[i]` that belong to the same shifting sequence. You may return the answer in **any order** .

**Example 1:**

```bash
Input: strings = ["abc","bcd","acef","xyz","az","ba","a","z"]

Output: [["acef"],["a","z"],["abc","bcd","xyz"],["az","ba"]]
```

**Example 2:**

```bash
Input: strings = ["a"]

Output: [["a"]]
```

**Constraints:**

- `1 <= strings.length <= 200`
- `1 <= strings[i].length <= 50`
- `strings[i]` consists of lowercase English letters.

## Hints/Notes

- 2025/01/31
- hash table
- [Leetcode solution](https://leetcode.com/problems/group-shifted-strings/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        // how to check if the same group:
        unordered_map<string, vector<string>> m;
        for (auto& s : strings) {
            if (s.size() == 1) {
                m["a"].push_back(s);
            } else {
                string key = getKey(s);
                m[key].push_back(s);
            }
        }
        vector<vector<string>> res;
        for (auto& [_, v] : m) {
            res.push_back(v);
        }
        return res;
    }

    string getKey(string& s) {
        string res;
        res.push_back('a');
        for (int i = 1; i < s.size(); i++) {
            int c =  s[i] - s[i - 1] + res[i - 1] - 'a';
            c = (c + 26) % 26;
            res.push_back(c + 'a');
        }
        return res;
    }
};
```
