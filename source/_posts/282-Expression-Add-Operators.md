---
title: 282. Expression Add Operators
categories: Leetcode
date: 2025-01-21 02:22:48
tags:
    - Math
    - String
    - Backtracking
---

[282. Expression Add Operators](https://leetcode.com/problems/expression-add-operators/description/)

## Description

Given a string `num` that contains only digits and an integer `target`, return **all possibilities**  to insert the binary operators `'+'`, `'-'`, and/or `'*'` between the digits of `num` so that the resultant expression evaluates to the `target` value.

Note that operands in the returned expressions **should not**  contain leading zeros.

**Example 1:**

```bash
Input: num = "123", target = 6
Output: ["1*2*3","1+2+3"]
Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.
```

**Example 2:**

```bash
Input: num = "232", target = 8
Output: ["2*3+2","2+3*2"]
Explanation: Both "2*3+2" and "2+3*2" evaluate to 8.
```

**Example 3:**

```bash
Input: num = "3456237490", target = 9191
Output: []
Explanation: There are no expressions that can be created from "3456237490" to evaluate to 9191.
```

**Constraints:**

- `1 <= num.length <= 10`
- `num` consists of only digits.
- `-2^31 <= target <= 2^31 - 1`

## Hints/Notes

- 2025/01/20
- backtracking
- No solution from 0x3F

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<long> vals;
    vector<string> res;
    vector<string> cur;
    int target;

    vector<string> addOperators(string num, int target) {
        this->target = target;
        dfs(num, 0, 0);
        return res;
    }

    void dfs(string& num, int index, long curVal) {
        if (index == num.size()) {
            if (curVal == target) {
                res.push_back(accumulate(cur.begin(), cur.end(), string("")));

            }
            return;
        }
        int end = num[index] == '0' ? index + 1 : num.size();
        if (!index) {
            for (int i = index + 1; i <= end; i++) {
                string valStr = num.substr(index, i - index);
                long val = stol(valStr);
                vals.push_back(val);
                cur.push_back(valStr);
                dfs(num, i, val);
                cur.pop_back();
                vals.pop_back();
            }
        } else {
            for (int i = index + 1; i <= end; i++) {
                string valStr = num.substr(index, i - index);
                long val = stol(valStr);
                cur.push_back("+");
                cur.push_back(valStr);
                vals.push_back(val);
                dfs(num, i, curVal + val);
                cur.pop_back();
                cur.pop_back();
                vals.pop_back();
                cur.push_back("-");
                cur.push_back(valStr);
                vals.push_back(-val);
                dfs(num, i, curVal - val);
                cur.pop_back();
                cur.pop_back();
                vals.pop_back();
                long prev = vals.back();
                vals.pop_back();
                cur.push_back("*");
                cur.push_back(valStr);
                vals.push_back(prev * val);
                dfs(num, i, curVal - prev + prev * val);
                cur.pop_back();
                cur.pop_back();
                vals.pop_back();
                vals.push_back(prev);
            }
        }
    }
};
```
