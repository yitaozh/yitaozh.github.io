---
title: 22. Generate Parentheses
categories: Leetcode
date: 2024-12-19 01:57:18
tags:
    - String
    - Dynamic Programming
    - Backtracking
---

[22. Generate Parentheses](https://leetcode.com/problems/generate-parentheses/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Given `n` pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

**Example 1:**

```bash
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
```

**Example 2:**

```bash
Input: n = 1
Output: ["()"]
```

**Constraints:**

- `1 <= n <= 8`

## Hints/Notes

- 2024/12/18
- backtracking
- [0x3F's solution](https://leetcode.cn/problems/generate-parentheses/solutions/2071015/hui-su-bu-hui-xie-tao-lu-zai-ci-pythonja-wcdw/)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int n;
    vector<string> res;
    string path;

    vector<string> generateParenthesis(int n) {
        if (!n) {
            return {};
        }
        this->n = n;
        path = string(n * 2, 0);
        dfs(n, 0);
        return res;
    }

    void dfs(int left, int right) {
        if (left == 0 && right == 0) {
            res.push_back(path);
            return;
        }
        int index = (n - left) * 2 - right;
        if (left > 0) {
            path[index] = '(';
            dfs(left - 1, right + 1);
        }
        if (right > 0) {
            path[index] = ')';
            dfs(left, right - 1);
        }
    }
};
```
