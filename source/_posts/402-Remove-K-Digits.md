---
title: 402. Remove K Digits
categories: Leetcode
date: 2023-12-16 14:40:28
tags:
    - String
    - Stack
    - Greedy
    - Monotonic Stack
---

[402\. Remove K Digits](https://leetcode.com/problems/remove-k-digits/)

## Description

Difficulty: **Medium**

Related Topics: [String](https://leetcode.com/tag/https://leetcode.com/tag/string//), [Stack](https://leetcode.com/tag/https://leetcode.com/tag/stack//), [Greedy](https://leetcode.com/tag/https://leetcode.com/tag/greedy//), [Monotonic Stack](https://leetcode.com/tag/https://leetcode.com/tag/monotonic-stack//)

Given string num representing a non-negative integer `num`, and an integer `k`, return _the smallest possible integer after removing_ `k` _digits from_ `num`.

**Example 1:**

```bash
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
```

**Example 2:**

```bash
Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200\. Note that the output must not contain leading zeroes.
```

**Example 3:**

```bash
Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
```

**Constraints:**

* 1 <= k <= num.length <= 10<sup>5</sup>
* `num` consists of only digits.
* `num` does not have any leading zeros except for the zero itself.

## Hints/Notes

* two pass, first make it monotonic, then remove extra tail elements

## Solution

Language: **C++**

```C++
class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() <= k) {
            return "0";
        }
        int removed = 0;
        stack<char> s;
        for (int i = 0; i < num.size(); i++) {
            while (!s.empty() && (s.top() > num[i]) && removed < k) {
                s.pop();
                removed++;
            }
            if (s.empty() && num[i] == '0') {
                continue;
            }
            s.push(num[i]);
        }
        while (k > removed && !s.empty()) {
            s.pop();
            removed++;
        }
        if (s.empty()) {
            return "0";
        }
        string res;
        while (!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
};
```
