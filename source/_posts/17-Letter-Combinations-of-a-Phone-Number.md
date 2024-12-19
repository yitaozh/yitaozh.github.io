---
title: 17. Letter Combinations of a Phone Number
categories: Leetcode
date: 2024-12-19 01:24:29
tags:
    - Hash Table
    - String
    - Backtracking
---

[17. Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Given a string containing digits from `2-9` inclusive, return all possible letter combinations that the number could represent. Return the answer in **any order** .

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

<img alt="" src="https://assets.leetcode.com/uploads/2022/03/15/1200px-telephone-keypad2svg.png" style="width: 300px; height: 243px;">

**Example 1:**

```bash
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

**Example 2:**

```bash
Input: digits = ""
Output: []
```

**Example 3:**

```bash
Input: digits = "2"
Output: ["a","b","c"]
```

**Constraints:**

- `0 <= digits.length <= 4`
- `digits[i]` is a digit in the range `['2', '9']`.

## Hints/Notes

- 2024/12/18
- backtracking or for loop
- [0x3F's solution](https://leetcode.cn/problems/letter-combinations-of-a-phone-number/solutions/2059416/hui-su-bu-hui-xie-tao-lu-zai-ci-pythonja-3orv/)(checked)

## Solution

Language: **C++**

Backtracking

```C++
class Solution {
public:
    vector<string> res;
    string path, digits;
    int n;
    string MAPPING[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        n = digits.size();
        this->digits = digits;
        path = string(n, 0);
        dfs(0);
        return res;
    }

    void dfs(int index) {
        if (index == n) {
            res.push_back(path);
            return;
        }
        for (char c : MAPPING[digits[index] - '0']) {
            path[index] = c;
            dfs(index + 1);
        }
    }
};
```

```C++
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) {
            return res;
        }
        unordered_map<char, vector<char>> m = {
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}},
        };
        res.push_back("");
        for (auto& d : digits) {
            vector<string> next;
            for (auto& s : res) {
                for (auto& c: m[d]) {
                    next.push_back(s + c);
                }
            }
            res = move(next);
        }
        return res;
    }
};
```
