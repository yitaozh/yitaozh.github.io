---
title: 3144. Minimum Substring Partition of Equal Character Frequency
categories: Leetcode
date: 2024-05-22 10:08:48
tags:
    - Hash Table
    - String
    - Dynamic Programming
    - Counting
---

[3144. Minimum Substring Partition of Equal Character Frequency](https://leetcode.com/problems/minimum-substring-partition-of-equal-character-frequency/description/)

Given a string `s`, you need to partition it into one or more **balanced**  substrings. For example, if `s == "ababcc"` then `("abab", "c", "c")`, `("ab", "abc", "c")`, and `("ababcc")` are all valid partitions, but `("a", "bab" , "cc")`, `("aba" , "bc", "c")`, and `("ab", "abcc")` are not. The unbalanced substrings are bolded.

Return the **minimum**  number of substrings that you can partition `s` into.

**Note:**  A **balanced**  string is a string where each character in the string occurs the same number of times.

**Example 1:**

```bash
Input: s = "fabccddg"

Output: 3

Explanation:

We can partition the string `s` into 3 substrings in one of the following ways: `("fab, "ccdd", "g")`, or `("fabc", "cd", "dg")`.
```

**Example 2:**

```bash
Input: s = "abababaccddb"

Output: 2

Explanation:

We can partition the string `s` into 2 substrings like so: `("abab", "abaccddb")`.
```

**Constraints:**

- `1 <= s.length <= 1000`
- `s` consists only of English lowercase letters.

## Hints/Notes

- dynamic programming
- for dp, the less we need to memorize the better

## Solution

Language: **C++**

```C++
class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        vector<int> dp(s.size() + 1, 1001);
        return traverse(0, s, dp);
    }

    int traverse(int index, string& s, vector<int>& dp) {
        if (index >= s.size()) {
            return 0;
        }
        if (dp[index] != 1001) {
            return dp[index];
        }
        int res = 1001;
        unordered_map<int, int> m;
        int count = 0;
        for (int i = index; i < s.size(); i++) {
            m[s[i] - 'a']++;
            if (m[s[i] - 'a'] == 1) {
                count++;
            }
            if ((i - index + 1) % count != 0) {
                continue;
            }
            int freq = m[s[i] - 'a'];
            bool balanced = true;
            for (auto it : m) {
                if (it.second != freq) {
                    balanced = false;
                    break;
                }
            }
            if (balanced) {
                res = min(res, traverse(i + 1, s, dp) + 1);
            }
        }
        dp[index] = res;
        return res;
    }
};
```
