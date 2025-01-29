---
title: 394. Decode String
categories: Leetcode
date: 2025-01-29 16:24:24
tags:
    - String
    - Stack
    - Recursion
---

[394. Decode String](https://leetcode.com/problems/decode-string/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

Given an encoded string, return its decoded string.

The encoding rule is: `k[encoded_string]`, where the `encoded_string` inside the square brackets is being repeated exactly `k` times. Note that `k` is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, `k`. For example, there will not be input like `3a` or `2[4]`.

The test cases are generated so that the length of the output will never exceed `10^5`.

**Example 1:**

```bash
Input: s = "3[a]2[bc]"
Output: "aaabcbc"
```

**Example 2:**

```bash
Input: s = "3[a2[c]]"
Output: "accaccacc"
```

**Example 3:**

```bash
Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
```

**Constraints:**

- `1 <= s.length <= 30`
- `s` consists of lowercase English letters, digits, and square brackets `'[]'`.
- `s` is guaranteed to be **a valid**  input.
- All the integers in `s` are in the range `[1, 300]`.

## Hints/Notes

- 2025/01/29
- stack
- [Leetcode solution](https://leetcode.com/problems/decode-string/editorial/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        stack<char> stk;
        for (char& c : s) {
            if (c == ']') {
                string str;
                while (stk.top() != '[') {
                    str = stk.top() + str;
                    stk.pop();
                }
                stk.pop();
                int num = 0, mul = 1;
                while (!stk.empty() && isdigit(stk.top())) {
                    int cur = stk.top() - '0';
                    stk.pop();
                    num = num + mul * cur;
                    mul *= 10;
                }
                string decoded;
                for (int i = 0; i < num; i++) {
                    decoded += str;
                }
                for (char& d : decoded) {
                    stk.push(d);
                }
            } else {
                stk.push(c);
            }
        }
        string res;
        while (!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }
        ranges::reverse(res);
        return res;
    }
};
```
