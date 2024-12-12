---
title: 3337. Total Characters in String After Transformations II
categories: Leetcode
date: 2024-11-20 15:04:50
tags:
    - Hash Table
    - Math
    - String
    - Dynamic Programming
    - Counting
---

[3337. Total Characters in String After Transformations II](https://leetcode.com/problems/total-characters-in-string-after-transformations-ii/description/)

## Description

You are given a string `s` consisting of lowercase English letters, an integer `t` representing the number of **transformations**  to perform, and an array `nums` of size 26. In one **transformation** , every character in `s` is replaced according to the following rules:

- Replace `s[i]` with the **next**  `nums[s[i] - 'a']` consecutive characters in the alphabet. For example, if `s[i] = 'a'` and `nums[0] = 3`, the character `'a'` transforms into the next 3 consecutive characters ahead of it, which results in `"bcd"`.
- The transformation **wraps**  around the alphabet if it exceeds `'z'`. For example, if `s[i] = 'y'` and `nums[24] = 3`, the character `'y'` transforms into the next 3 consecutive characters ahead of it, which results in `"zab"`.

Return the length of the resulting string after **exactly**  `t` transformations.

Since the answer may be very large, return it **modulo**  `10^9 + 7`.

**Example 1:**

```bash
Input: s = "abcyy", t = 2, nums = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2]

Output: 7
```

Explanation:

- **First Transformation (t = 1):**

  - `'a'` becomes `'b'` as `nums[0] == 1`
  - `'b'` becomes `'c'` as `nums[1] == 1`
  - `'c'` becomes `'d'` as `nums[2] == 1`
  - `'y'` becomes `'z'` as `nums[24] == 1`
  - `'y'` becomes `'z'` as `nums[24] == 1`
  - String after the first transformation: `"bcdzz"`

- **Second Transformation (t = 2):**

  - `'b'` becomes `'c'` as `nums[1] == 1`
  - `'c'` becomes `'d'` as `nums[2] == 1`
  - `'d'` becomes `'e'` as `nums[3] == 1`
  - `'z'` becomes `'ab'` as `nums[25] == 2`
  - `'z'` becomes `'ab'` as `nums[25] == 2`
  - String after the second transformation: `"cdeabab"`

- **Final Length of the string:**  The string is `"cdeabab"`, which has 7 characters.

**Example 2:**

```bash
Input: s = "azbk", t = 1, nums = [2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2]

Output: 8
```

Explanation:

- **First Transformation (t = 1):**

  - `'a'` becomes `'bc'` as `nums[0] == 2`
  - `'z'` becomes `'ab'` as `nums[25] == 2`
  - `'b'` becomes `'cd'` as `nums[1] == 2`
  - `'k'` becomes `'lm'` as `nums[10] == 2`
  - String after the first transformation: `"bcabcdlm"`

- **Final Length of the string:**  The string is `"bcabcdlm"`, which has 8 characters.

**Constraints:**

- `1 <= s.length <= 10^5`
- `s` consists only of lowercase English letters.
- `1 <= t <= 10^9`
- `nums.length == 26`
- `1 <= nums[i] <= 25`

## Hints/Notes

- 2024/11/06
- matrix calculation
- matrix fast pow
- [0x3F's solution](https://leetcode.cn/problems/total-characters-in-string-after-transformations-ii/solution/ju-zhen-kuai-su-mi-you-hua-dppythonjavac-cd2j/)
- Weekly Contest 421

## Solution

Language: **C++**

```C++
class Solution {
public:
    static const int MOD = 1e9 + 7, SIZE = 26;
    using matrix = array<array<int, SIZE>, SIZE>;

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        matrix m{};
        for (int i = 0; i < SIZE; i++) {
            int num = nums[i];
            for (int j = i + 1; j < i + 1 + num; j++) {
                m[i][j % SIZE] = 1;
            }
        }

        m = pow(m, t);

        int digits[SIZE] = {0};
        for (char c : s) {
            digits[c - 'a']++;
        }

        long long res = 0;
        for (int i = 0; i < SIZE; i++) {
            res = (res + reduce(m[i].begin(), m[i].end(), 0L) * digits[i]) %
                  MOD;
        }
        return res;
    }

    matrix pow(matrix m, int n) {
        matrix res{};
        for (int i = 0; i < SIZE; i++) {
            res[i][i] = 1;
        }
        while (n) {
            if (n & 1) {
                res = mul(m, res);
            }
            m = mul(m, m);
            n >>= 1;
        }
        return res;
    }

    matrix mul(matrix a, matrix b) {
        matrix c{};
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < SIZE; k++) {
                    c[i][j] = (c[i][j] + (long)a[i][k] * b[k][j]) % MOD;
                }
            }
        }
        return c;
    }
};
```
