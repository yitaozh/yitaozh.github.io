---
title: 316. Remove Duplicate Letters
categories: Leetcode
date: 2023-02-01 12:47:57
tags:
    - String
    - Stack
    - Greedy
    - Monotonic Stack
---

# [316\. Remove Duplicate Letters](https://leetcode.com/problems/remove-duplicate-letters/)

## Description

Difficulty: **Medium**

Related Topics: [String](https://leetcode.com/tag/string/), [Stack](https://leetcode.com/tag/stack/), [Greedy](https://leetcode.com/tag/greedy/), [Monotonic Stack](https://leetcode.com/tag/monotonic-stack/)

Given a string `s`, remove duplicate letters so that every letter appears once and only once. You must make sure your result is <span data-keyword="lexicographically-smaller-string">**the smallest in lexicographical order**</span> among all possible results.

**Example 1:**

```text
Input: s = "bcabc"
Output: "abc"
```

**Example 2:**

```text
Input: s = "cbacdcbc"
Output: "acdb"
```

**Constraints:**

* 1 <= s.length <= 10<sup>4</sup>
* `s` consists of lowercase English letters.

**Note:** This question is the same as 1081: [https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/](https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/)

## Hints/Notes

* With stack and set we can get the substring with no duplicate, but not necessarily the smallest
* Add a counter to count the frequency of letters, then we can pop the letters without worrying there's no more

## Solution

Language: **C++**

```C++
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(26, 0);
        vector<bool> inStack(26, false);
        stack<char> stk;
        for (char c : s) {
            count[c - 'a']++;
        }
        
        for (char c : s) {
            int idx = c - 'a';
            count[idx]--;
            
            if (inStack[idx]) {
                continue;
            }

            while (!stk.empty() && stk.top() > c) {
                char top = stk.top();
                if (count[top - 'a'] == 0) {
                    break;
                }
                inStack[top - 'a'] = false;
                stk.pop();
            }

            stk.push(c);
            inStack[c - 'a'] = true;
        }

        string res;
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```
