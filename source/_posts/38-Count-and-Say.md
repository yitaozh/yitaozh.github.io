---
title: 38. Count and Say
categories: Leetcode
date: 2025-01-17 02:09:29
tags:
    - String
---

[38. Count and Say](https://leetcode.com/problems/count-and-say/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

The **count-and-say**  sequence is a sequence of digit strings defined by the recursive formula:

- `countAndSay(1) = "1"`
- `countAndSay(n)` is the run-length encoding of `countAndSay(n - 1)`.

<a href="http://en.wikipedia.org/wiki/Run-length_encoding" target="_blank">Run-length encoding</a> (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string `"3322251"` we replace `"33"` with `"23"`, replace `"222"` with `"32"`, replace `"5"` with `"15"` and replace `"1"` with `"11"`. Thus the compressed string becomes `"23321511"`.

Given a positive integer `n`, return the `n^th` element of the **count-and-say**  sequence.

**Example 1:**

```bash
Input: n = 4

Output: "1211"

Explanation:

countAndSay(1) = "1"
countAndSay(2) = RLE of "1" = "11"
countAndSay(3) = RLE of "11" = "21"
countAndSay(4) = RLE of "21" = "1211"
```

**Example 2:**

```bash
Input: n = 1

Output: "1"

Explanation:

This is the base case.
```

**Constraints:**

- `1 <= n <= 30`

**Follow up:**  Could you solve it iteratively?

## Hints/Notes

- 2025/01/17
- string
- [Leetcode solution](https://leetcode.com/problems/count-and-say/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for (int i = 1; i < n; i++) {
            int len = res.size();
            string nxt;
            for (int j = 0; j < len; ) {
                int start = j;
                while (j < len && res[j] == res[start]) {
                    j++;
                }
                nxt += to_string(j - start);
                nxt += res[start];
            }
            res = nxt;
        }
        return res;
    }
};
```
