---
title: 93. Restore IP Addresses
categories: Leetcode
date: 2025-03-28 11:14:53
tags:
    - String
    - Backtracking
---

[93. Restore IP Addresses](https://leetcode.com/problems/restore-ip-addresses/description/?envType=company&envId=microsoft&favoriteSlug=microsoft-thirty-days)

## Description

A **valid IP address**  consists of exactly four integers separated by single dots. Each integer is between `0` and `255` (**inclusive** ) and cannot have leading zeros.

- For example, `"0.1.2.201"` and `"192.168.1.1"` are **valid**  IP addresses, but `"0.011.255.245"`, `"192.168.1.312"` and `"192.168@1.1"` are **invalid**  IP addresses.

Given a string `s` containing only digits, return all possible valid IP addresses that can be formed by inserting dots into `s`. You are **not**  allowed to reorder or remove any digits in `s`. You may return the valid IP addresses in **any**  order.

**Example 1:**

```bash
Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]
```

**Example 2:**

```bash
Input: s = "0000"
Output: ["0.0.0.0"]
```

**Example 3:**

```bash
Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
```

**Constraints:**

- `1 <= s.length <= 20`
- `s` consists of digits only.

## Hints/Notes

- 2025/03/19 Q2
- backtracking
- [Leetcode solution](https://leetcode.com/problems/restore-ip-addresses/editorial/?envType=company&envId=microsoft&favoriteSlug=microsoft-thirty-days)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<string> res;

    bool valid(const string& s, int start, int length) {
        return length == 1 || (s[start] != '0' && (length < 3 || s.substr(start, length) <= "255"));
    }

    void dfs(const string& s, int idx, vector<int>& dots) {
        const int remainingLength = s.size() - idx;
        const int remainingNum = 4 - dots.size();

        if (remainingLength > remainingNum * 3 || remainingLength < remainingNum) {
            return;
        }
        if (dots.size() == 3) {
            if (valid(s, idx, remainingLength)) {
                string cur;
                int start = 0;
                for (int dot : dots) {
                    cur.append(s.substr(start, dot));
                    cur.push_back('.');
                    start += dot;
                }
                cur.append(s.substr(start));
                res.push_back(cur);
            }
            return;
        }
        for (int len = 1; len <= min(3, remainingLength); len++) {
            dots.push_back(len);
            if (valid(s, idx, len)) {
                dfs(s, idx + len, dots);
            }
            dots.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<int> dots;
        dfs(s, 0, dots);
        return res;
    }
};
```
