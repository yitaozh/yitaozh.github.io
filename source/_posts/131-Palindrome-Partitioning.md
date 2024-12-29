---
title: 131. Palindrome Partitioning
categories: Leetcode
date: 2024-12-28 23:22:30
tags:
---

[131. Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Given a string `s`, partition `s` such that every substring of the partition is a **palindrome**. Return all possible palindrome partitioning of `s`.

**Example 1:**

```bash
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
```

**Example 2:**

```bash
Input: s = "a"
Output: [["a"]]
```

**Constraints:**

- `1 <= s.length <= 16`
- `s` contains only lowercase English letters.

## Hints/Notes

- 2024/12/28
- backtracking
- [0x3F's solution](https://leetcode.cn/problems/palindrome-partitioning/solutions/2059414/hui-su-bu-hui-xie-tao-lu-zai-ci-pythonja-fues/)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<string> path;
    vector<vector<string>> res;

    vector<vector<string>> partition(string s) {
        dfs(0, s);
        return res;
    }

    void dfs(int index, string& s) {
        if (index == s.size()) {
            res.push_back(path);
            return;
        }

        for (int i = index + 1; i <= s.size(); i++) {
            if (isPalindrome(s, index, i - 1)) {
                path.push_back(s.substr(index, i - index));
                dfs(i, s);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
```
