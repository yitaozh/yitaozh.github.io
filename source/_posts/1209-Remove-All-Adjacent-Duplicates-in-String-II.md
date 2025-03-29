---
title: 1209. Remove All Adjacent Duplicates in String II
categories: Leetcode
date: 2025-03-29 13:25:46
tags:
    - String
    - Stack
---

[1209. Remove All Adjacent Duplicates in String II](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/description/?envType=company&envId=oracle&favoriteSlug=oracle-six-months)

## Description

You are given a string `s` and an integer `k`, a `k` **duplicate removal**  consists of choosing `k` adjacent and equal letters from `s` and removing them, causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make `k` **duplicate removals**  on `s` until we no longer can.

Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is **unique** .

**Example 1:**

```bash
Input: s = "abcd", k = 2
Output: "abcd"
Explanation: There's nothing to delete.
```

**Example 2:**

```bash
Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
**Explanation:
** First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"
```

**Example 3:**

```bash
Input: s = "pbbcggttciiippooaais", k = 2
Output: "ps"
```

**Constraints:**

- `1 <= s.length <= 10^5`
- `2 <= k <= 10^4`
- `s` only contains lowercase English letters.

## Hints/Notes

- 2025/03/23 Q2
- stack
- [Leetcode solution](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/editorial)

## Solution

Language: **C++**

```C++
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> stk;
        for (char& c : s) {
            if (!stk.empty()) {
                if (stk.top().first == c) {
                    stk.top().second += 1;
                    if (stk.top().second >= k) {
                        stk.pop();
                    }
                } else {
                    stk.push({c, 1});
                }
            } else {
                stk.push({c, 1});
            }
        }
        string res;
        while (!stk.empty()) {
            auto [c, freq] = stk.top();
            stk.pop();
            res.append(string(freq, c));
        }
        ranges::reverse(res);
        return res;
    }
};
```
