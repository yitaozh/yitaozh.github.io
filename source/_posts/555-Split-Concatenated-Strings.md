---
title: 555. Split Concatenated Strings
categories: Leetcode
date: 2025-03-14 13:40:46
tags:
    - Array
    - String
    - Greedy
---

[555. Split Concatenated Strings](https://leetcode.com/problems/split-concatenated-strings/description/)

## Description

You are given an array of strings `strs`. You could concatenate these strings together into a loop, where for each string, you could choose to reverse it or not. Among all the possible loops

Return the lexicographically largest string after cutting the loop, which will make the looped string into a regular one.

Specifically, to find the lexicographically largest string, you need to experience two phases:

- Concatenate all the strings into a loop, where you can reverse some strings or not and connect them in the same order as given.
- Cut and make one breakpoint in any place of the loop, which will make the looped string into a regular one starting from the character at the cutpoint.

And your job is to find the lexicographically largest one among all the possible regular strings.

**Example 1:**

```bash
Input: strs = ["abc","xyz"]
Output: "zyxcba"
Explanation: You can get the looped string "-abcxyz-", "-abczyx-", "-cbaxyz-", "-cbazyx-", where '-' represents the looped status.
The answer string came from the fourth looped one, where you could cut from the middle character 'a' and get "zyxcba".
```

**Example 2:**

```bash
Input: strs = ["abc"]
Output: "cba"
```

**Constraints:**

- `1 <= strs.length <= 1000`
- `1 <= strs[i].length <= 1000`
- `1 <= sum(strs[i].length) <= 1000`
- `strs[i]` consists of lowercase English letters.

## Hints/Notes

- 2025/02/04 Q2
- string
- No solution from 0x3F or Leetcode

## Solution

Language: **C++**

```C++
class Solution {
public:
    string res;

    void solve(vector<string>& strs, int i, bool flag) {
        string temp = strs[i];
        if (flag) reverse(temp.begin(), temp.end());
        int size = temp.size();
        string str1, str2;
        for (int j = i + 1; j < strs.size(); j++) str1 += strs[j];
        for (int j = 0; j < i; j++) str2 += strs[j];
        for (int k = 0; k < size; k++) {
            string cur = temp.substr(k) + str1 + str2 + temp.substr(0, k);
            res = res.empty() ? cur : max(cur, res);
        }
    }

    void findMaxStrings(vector<string>& strs) {
        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            reverse(temp.begin(), temp.end());
            strs[i] = strs[i] > temp ? strs[i] : temp;
        }
    }

    string splitLoopedString(vector<string>& strs) {
        int n = strs.size();
        if (!n) return "";
        findMaxStrings(strs);
        for (int i = 0; i < n; i++) {
            solve(strs, i, true);
            solve(strs, i, false);
        }
        return res;
    }
};
```
