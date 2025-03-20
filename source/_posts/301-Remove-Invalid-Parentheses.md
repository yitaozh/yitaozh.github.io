---
title: 301. Remove Invalid Parentheses
categories: Leetcode
date: 2025-03-20 01:29:52
tags:
    - String
    - Backtracking
    - Breadth-First Search
---

[301. Remove Invalid Parentheses](https://leetcode.com/problems/remove-invalid-parentheses/description/)

## Description

Given a string `s` that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

Return a list of **unique strings**  that are valid with the minimum number of removals. You may return the answer in **any order** .

**Example 1:**

```bash
Input: s = "()())()"
Output: ["(())()","()()()"]
```

**Example 2:**

```bash
Input: s = "(a)())()"
Output: ["(a())()","(a)()()"]
```

**Example 3:**

```bash
Input: s = ")("
Output: [""]
```

**Constraints:**

- `1 <= s.length <= 25`
- `s` consists of lowercase English letters and parentheses `'('` and `')'`.
- There will be at most `20` parentheses in `s`.

## Hints/Notes

- 2025/02/24 Q3
- backtracking
- [Leetcode solution](https://leetcode.com/problems/remove-invalid-parentheses/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    unordered_set<string> res;
    int l_remove = 0, r_remove = 0;
    string cur;

    vector<string> removeInvalidParentheses(string s) {
        for (char& c : s) {
            if (c == '(') {
                l_remove++;
            } else if (c == ')') {
                if (l_remove > 0) {
                    l_remove--;
                } else {
                    r_remove++;
                }
            }
        }
        dfs(0, 0, l_remove, r_remove, s);
        return vector<string>(res.begin(), res.end());
    }

    void dfs(int index, int open, int l_remove, int r_remove, string& s) {
        if (index == s.size()) {
            if (l_remove == 0 && r_remove == 0 && open == 0) {
                res.insert(cur);
            }
            return;
        }
        char c = s[index];
        if (c == '(' && l_remove > 0) {
            dfs(index + 1, open, l_remove - 1, r_remove, s);
        }
        if (c == ')' && r_remove > 0) {
            dfs(index + 1, open, l_remove, r_remove - 1, s);
        }

        cur.push_back(c);
        if (c == '(') {
            dfs(index + 1, open + 1, l_remove, r_remove, s);
        } else if (c == ')') {
            if (open > 0) {
                dfs(index + 1, open - 1, l_remove, r_remove, s);
            }
        } else {
            dfs(index + 1, open, l_remove, r_remove, s);
        }
        cur.pop_back();
    }
};
```
