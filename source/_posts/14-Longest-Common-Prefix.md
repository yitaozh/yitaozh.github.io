---
title: 14. Longest Common Prefix
categories: Leetcode
date: 2025-01-16 00:05:01
tags:
    - String
    - Trie
---

[14. Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string `""`.

**Example 1:**

```bash
Input: strs = ["flower","flow","flight"]
Output: "fl"
```

**Example 2:**

```bash
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
```

**Constraints:**

- `1 <= strs.length <= 200`
- `0 <= strs[i].length <= 200`
- `strs[i]` consists of only lowercase English letters if it is non-empty.

## Hints/Notes

- 2025/01/15
- string
- [0x3F's solution](https://leetcode.cn/problems/longest-common-prefix/solutions/2801713/jian-dan-ti-jian-dan-zuo-pythonjavaccgoj-478q/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int res = INT_MAX;
        for (int i = 0; i < strs.size() - 1; i++) {
            res = min({res, (int)strs[i].size(), (int)strs[i + 1].size()});
            for (int j = 0; j < res; j++) {
                if (strs[i][j] != strs[i + 1][j]) {
                    res = j;
                    break;
                }
            }
            if (!res) {
                return "";
            }
        }
        return strs[0].substr(0, res);
    }
};
```
