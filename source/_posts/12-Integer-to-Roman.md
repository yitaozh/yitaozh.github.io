---
title: 12. Integer to Roman
categories: Leetcode
date: 2025-03-14 02:14:57
tags:
    - Hash Table
    - Math
    - String
---

[12. Integer to Roman](https://leetcode.com/problems/integer-to-roman/description/)

## Description

Seven different symbols represent Roman numerals with the following values:

<table><thead><tr><th>Symbol</th><th>Value</th></tr></thead><tbody><tr><td>I</td><td>1</td></tr><tr><td>V</td><td>5</td></tr><tr><td>X</td><td>10</td></tr><tr><td>L</td><td>50</td></tr><tr><td>C</td><td>100</td></tr><tr><td>D</td><td>500</td></tr><tr><td>M</td><td>1000</td></tr></tbody></table>

Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. Converting a decimal place value into a Roman numeral has the following rules:

- If the value does not start with 4 or9, select the symbol of the maximal value that can be subtracted from the input, append that symbol to the result, subtract its value, and convert the remainder to a Roman numeral.
- If the value starts with 4 or 9 use the **subtractive form** representing one symbol subtracted from the following symbol, for example,4 is 1 (`I`) less than 5 (`V`): `IV`and 9 is 1 (`I`) less than 10 (`X`): `IX`.Only the following subtractive forms are used: 4 (`IV`), 9 (`IX`),40 (`XL`), 90 (`XC`), 400 (`CD`) and 900 (`CM`).
- Only powers of 10 (`I`, `X`, `C`, `M`) can be appended consecutively at most 3 times to represent multiples of 10. You cannot append 5(`V`), 50 (`L`), or 500 (`D`) multiple times. If you need to append a symbol 4 times use the **subtractive form** .

Given an integer, convert it to a Roman numeral.

**Example 1:**

```bash
Input: num = 3749

Output: "MMMDCCXLIX"

Explanation:

3000 = MMM as 1000 (M) + 1000 (M) + 1000 (M)
 700 = DCC as 500 (D) + 100 (C) + 100 (C)
  40 = XL as 10 (X) less of 50 (L)
   9 = IX as 1 (I) less of 10 (X)
Note: 49 is not 1 (I) less of 50 (L) because the conversion is based on decimal places
```

**Example 2:**

```bash
Input: num = 58

Output: "LVIII"

Explanation:

50 = L
 8 = VIII
```

**Example 3:**

```bash
Input: num = 1994

Output: "MCMXCIV"

Explanation:

1000 = M
 900 = CM
  90 = XC
   4 = IV
```

**Constraints:**

- `1 <= num <= 3999`

## Hints/Notes

- 2025/03/07 Q3
- string
- [0x3F's solution](https://leetcode.com/problems/integer-to-roman/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    string intToRoman(int num) {
        char ONE = 'I', FIVE = 'V', TEN = 'X', FIFTY = 'L', HUNDRED = 'C', FIVEHUNDRED = 'D', THOUSAND = 'M';
        string res;
        if (num >= 1000) {
            int thousand = num / 1000;
            string t(thousand, 'M');
            res += t;
            num %= 1000;
        }
        if (num >= 100) {
            int hundred = num / 100;
            string h;
            if (hundred == 4) {
                h = "CD";
            } else if (hundred == 9) {
                h = "CM";
            } else {
                if (hundred >= 5) {
                    h.push_back('D');
                    hundred -= 5;
                }
                h += string(hundred, 'C');
            }
            res += h;
            num %= 100;
        }
        if (num >= 10) {
            int tens = num / 10;
            string ten;
            if (tens == 4) {
                ten = "XL";
            } else if (tens == 9) {
                ten = "XC";
            } else {
                if (tens >= 5) {
                    ten.push_back('L');
                    tens -= 5;
                }
                ten += string(tens, 'X');
            }
            res += ten;
            num %= 10;
        }
        if (num > 0) {
            string digit;
            if (num == 4) {
                digit = "IV";
            } else if (num == 9) {
                digit = "IX";
            } else {
                if (num >= 5) {
                    digit.push_back('V');
                    num -= 5;
                }
                digit += string(num, 'I');
            }
            res += digit;
        }
        return res;
    }
};
```
