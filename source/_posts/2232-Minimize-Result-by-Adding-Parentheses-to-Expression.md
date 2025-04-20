---
title: 2232. Minimize Result by Adding Parentheses to Expression
categories: Leetcode
date: 2025-04-19 23:30:38
tags:
    - String
    - Enumeration
---

[2232. Minimize Result by Adding Parentheses to Expression](https://leetcode.com/problems/minimize-result-by-adding-parentheses-to-expression/description/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Description

You are given a **0-indexed**  string `expression` of the form `"<num1>+<num2>"` where `<num1>` and `<num2>` represent positive integers.

Add a pair of parentheses to `expression` such that after the addition of parentheses, `expression` is a **valid**  mathematical expression and evaluates to the **smallest**  possible value. The left parenthesis **must**  be added to the left of `'+'` and the right parenthesis **must**  be added to the right of `'+'`.

Return `expression` after adding a pair of parentheses such that `expression` evaluates to the **smallest**  possible value. If there are multiple answers that yield the same result, return any of them.

The input has been generated such that the original value of `expression`, and the value of `expression` after adding any pair of parentheses that meets the requirements fits within a signed 32-bit integer.

**Example 1:**

```bash
Input: expression = "247+38"
Output: "2(47+38)"
Explanation: The `expression` evaluates to 2 * (47 + 38) = 2 * 85 = 170.
Note that "2(4)7+38" is invalid because the right parenthesis must be to the right of the `'+'`.
It can be shown that 170 is the smallest possible value.
```

**Example 2:**

```bash
Input: expression = "12+34"
Output: "1(2+3)4"
Explanation: The expression evaluates to 1 * (2 + 3) * 4 = 1 * 5 * 4 = 20.
```

**Example 3:**

```bash
Input: expression = "999+999"
Output: "(999+999)"
Explanation: The `expression` evaluates to 999 + 999 = 1998.
```

**Constraints:**

- `3 <= expression.length <= 10`
- `expression` consists of digits from `'1'` to `'9'` and `'+'`.
- `expression` starts and ends with digits.
- `expression` contains exactly one `'+'`.
- The original value of `expression`, and the value of `expression` after adding any pair of parentheses that meets the requirements fits within a signed 32-bit integer.

## Hints/Notes

- 2025/04/19 Q3
- string
- [Leetcode solution](https://leetcode.cn/problems/minimize-result-by-adding-parentheses-to-expression/solutions/1418037/xiang-biao-da-shi-tian-jia-gua-hao-hou-d-5ox4/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    string minimizeResult(string expression) {
        int add_idx = expression.find('+'), n = expression.size();
        string res;
        int resNum = INT_MAX;
        for (int i = 0; i < add_idx; i++) {
            for (int j = add_idx + 2; j <= n; j++) {
                int mul1 = i ? stoi(expression.substr(0, i)) : 1;
                int add1 = stoi(expression.substr(i, add_idx - i));
                int add2 = stoi(expression.substr(add_idx + 1, j - 1 - add_idx));
                int mul2 = j == n ? 1 : stoi(expression.substr(j));
                int curRes = mul1 * mul2 * (add1 + add2);
                if (curRes < resNum) {
                    res = expression.substr(0, i) + "(" + expression.substr(i, j - i) + ")" + expression.substr(j, n);
                    resNum = curRes;
                }
            }
        }
        return res;
    }
};
```
