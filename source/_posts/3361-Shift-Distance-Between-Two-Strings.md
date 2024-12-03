---
title: 3361. Shift Distance Between Two Strings
categories: Leetcode
date: 2024-12-03 17:39:43
tags:
    - Array
    - String
    - Prefix Sum
---

[3361. Shift Distance Between Two Strings](https://leetcode.com/problems/shift-distance-between-two-strings/description/)

## Description

You are given two strings `s` and `t` of the same length, and two integer arrays `nextCost` and `previousCost`.

In one operation, you can pick any index `i` of `s`, and perform **either one**  of the following actions:

- Shift `s[i]` to the next letter in the alphabet. If `s[i] == 'z'`, you should replace it with `'a'`. This operation costs `nextCost[j]` where `j` is the index of `s[i]` in the alphabet.
- Shift `s[i]` to the previous letter in the alphabet. If `s[i] == 'a'`, you should replace it with `'z'`. This operation costs `previousCost[j]` where `j` is the index of `s[i]` in the alphabet.

The **shift distance**  is the **minimum**  total cost of operations required to transform `s` into `t`.

Return the **shift distance**  from `s` to `t`.

**Example 1:**

```bash
Input: s = "abab", t = "baba", nextCost = [100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0], previousCost = [1,100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]

Output: 2
```

Explanation:

- We choose index `i = 0` and shift `s[0]` 25 times to the previous character for a total cost of 1.
- We choose index `i = 1` and shift `s[1]` 25 times to the next character for a total cost of 0.
- We choose index `i = 2` and shift `s[2]` 25 times to the previous character for a total cost of 1.
- We choose index `i = 3` and shift `s[3]` 25 times to the next character for a total cost of 0.

**Example 2:**

```bash
Input: s = "leet", t = "code", nextCost = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1], previousCost = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]
```

Output: 31

Explanation:

- We choose index `i = 0` and shift `s[0]` 9 times to the previous character for a total cost of 9.
- We choose index `i = 1` and shift `s[1]` 10 times to the next character for a total cost of 10.
- We choose index `i = 2` and shift `s[2]` 1 time to the previous character for a total cost of 1.
- We choose index `i = 3` and shift `s[3]` 11 times to the next character for a total cost of 11.

**Constraints:**

- `1 <= s.length == t.length <= 10^5`
- `s` and `t` consist only of lowercase English letters.
- `nextCost.length == previousCost.length == 26`
- `0 <= nextCost[i], previousCost[i] <= 10^9`

## Hints/Notes

- 2024/11/30
- [0x3F's solution](https://leetcode.cn/problems/shift-distance-between-two-strings/solutions/2998657/qian-zhui-he-on-zuo-fa-pythonjavacgo-by-b4hfx/)
- Biweekly Contest 144

## Solution

Language: **C++**

```C++
class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost,
                            vector<int>& previousCost) {
        long long dp[26][26] = {0};
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < i; j++) {
                long long next = 0, prev = 0;
                int start = i, end = j;
                while (start < end + 26) {
                    next += nextCost[start % 26];
                    start++;
                }
                start = i;
                while (start > end) {
                    prev += previousCost[start % 26];
                    start--;
                }
                dp[i][j] = min(next, prev);
            }
            for (int j = i + 1; j < 26; j++) {
                long long next = 0, prev = 0;
                int start = i, end = j;
                while (start < end) {
                    next += nextCost[start % 26];
                    start++;
                }
                start = i + 26;
                while (start > end) {
                    prev += previousCost[start % 26];
                    start--;
                }
                dp[i][j] = min(next, prev);
            }
        }
        long long res = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            res += dp[s[i] - 'a'][t[i] - 'a'];
        }
        return res;
    }
};
```
