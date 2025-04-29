---
title: 3474. Lexicographically Smallest Generated String
categories: Leetcode
date: 2025-04-05 12:59:36
tags:
    - String
    - Greedy
    - String Matching
---

[3474. Lexicographically Smallest Generated String](https://leetcode.com/problems/lexicographically-smallest-generated-string/description/?envType=company&envId=tiktok&favoriteSlug=tiktok-thirty-days)

## Description

You are given two strings, `str1` and `str2`, of lengths `n` and `m`, respectively.

A string `word` of length `n + m - 1` is defined to be **generated**  by `str1` and `str2` if it satisfies the following conditions for **each**  index `0 <= i <= n - 1`:

- If `str1[i] == 'T'`, the **substring**  of `word` with size `m` starting at index `i` is **equal**  to `str2`, i.e., `word[i..(i + m - 1)] == str2`.
- If `str1[i] == 'F'`, the **substring**  of `word` with size `m` starting at index `i` is **not equal**  to `str2`, i.e., `word[i..(i + m - 1)] != str2`.

Return the **lexicographically smallest**  possible string that can be **generated**  by `str1` and `str2`. If no string can be generated, return an empty string `""`.

**Example 1:**

```bash
Input: str1 = "TFTF", str2 = "ab"

Output: "ababa"
```

Explanation:

<h4>The table below represents the string `"ababa"`</h4>

<table><tbody><tr><th style="border: 1px solid black; --darkreader-inline-border-top: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-right: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-bottom: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-left: var(--darkreader-border-000000, #d2c3ad);" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">Index</th><th style="border: 1px solid black; --darkreader-inline-border-top: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-right: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-bottom: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-left: var(--darkreader-border-000000, #d2c3ad);" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">T/F</th><th style="border: 1px solid black; --darkreader-inline-border-top: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-right: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-bottom: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-left: var(--darkreader-border-000000, #d2c3ad);" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">Substring of length `m`</th></tr><tr><td style="border: 1px solid black; --darkreader-inline-border-top: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-right: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-bottom: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-left: var(--darkreader-border-000000, #d2c3ad);" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">0</td><td style="border: 1px solid black; --darkreader-inline-border-top: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-right: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-bottom: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-left: var(--darkreader-border-000000, #d2c3ad);" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">`'T'`</td><td style="border: 1px solid black; --darkreader-inline-border-top: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-right: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-bottom: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-left: var(--darkreader-border-000000, #d2c3ad);" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">"ab"</td></tr><tr><td style="border: 1px solid black; --darkreader-inline-border-top: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-right: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-bottom: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-left: var(--darkreader-border-000000, #d2c3ad);" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">1</td><td style="border: 1px solid black; --darkreader-inline-border-top: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-right: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-bottom: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-left: var(--darkreader-border-000000, #d2c3ad);" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">`'F'`</td><td style="border: 1px solid black; --darkreader-inline-border-top: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-right: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-bottom: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-left: var(--darkreader-border-000000, #d2c3ad);" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">"ba"</td></tr><tr><td style="border: 1px solid black; --darkreader-inline-border-top: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-right: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-bottom: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-left: var(--darkreader-border-000000, #d2c3ad);" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">2</td><td style="border: 1px solid black; --darkreader-inline-border-top: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-right: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-bottom: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-left: var(--darkreader-border-000000, #d2c3ad);" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">`'T'`</td><td style="border: 1px solid black; --darkreader-inline-border-top: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-right: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-bottom: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-left: var(--darkreader-border-000000, #d2c3ad);" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">"ab"</td></tr><tr><td style="border: 1px solid black; --darkreader-inline-border-top: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-right: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-bottom: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-left: var(--darkreader-border-000000, #d2c3ad);" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">3</td><td style="border: 1px solid black; --darkreader-inline-border-top: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-right: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-bottom: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-left: var(--darkreader-border-000000, #d2c3ad);" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">`'F'`</td><td style="border: 1px solid black; --darkreader-inline-border-top: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-right: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-bottom: var(--darkreader-border-000000, #d2c3ad); --darkreader-inline-border-left: var(--darkreader-border-000000, #d2c3ad);" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="">"ba"</td></tr></tbody></table>

The strings `"ababa"` and `"ababb"` can be generated by `str1` and `str2`.

Return `"ababa"` since it is the lexicographically smaller string.

**Example 2:**

```bash
Input: str1 = "TFTF", str2 = "abc"

Output: ""
```

Explanation:

No string that satisfies the conditions can be generated.

**Example 3:**

```bash
Input: str1 = "F", str2 = "d"

Output: "a"
```

**Constraints:**

- `1 <= n == str1.length <= 10^4`
- `1 <= m == str2.length <= 500`
- `str1` consists only of `'T'` or `'F'`.
- `str2` consists only of lowercase English characters.

## Hints/Notes

- 2025/04/01 Q2
- greedy
- [0x3F's solution](https://leetcode.cn/problems/lexicographically-smallest-generated-string/solutions/3592764/liang-chong-fang-fa-tan-xin-bao-li-pi-pe-gxyn/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    string generateString(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        string res(m + n - 1, ' ');
        set<int> trueIndices;
        vector<bool> locked(m + n - 1, false);
        for (int i = 0; i < m; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < n; j++) {
                    if (res[i + j] != ' ' && res[i + j] != str2[j]) {
                        return "";
                    }
                    res[i + j] = str2[j];
                    locked[i + j] = true;
                }
                trueIndices.insert(i);
            }
        }
        trueIndices.insert(m + n);
        for (int i = 0; i < res.size(); i++) {
            if (res[i] == ' ') {
                res[i] = 'a';
            }
        }
        for (int i = 0; i < str1.size(); i++) {
            // whenver we see a F, we should modify the current substring
            // which index to modify? assume the size is m
            // F, F, T, F, F
            // as soon as we see the next T, we cannot modify the
            if (str1[i] == 'F' && res.substr(i, n) == str2) {
                int next_true = *trueIndices.lower_bound(i);
                // the subarray range is between [i, i + m - 1]
                int rightmost_index = min(i + n - 1, next_true - 1);
                while (rightmost_index >= i && locked[rightmost_index]) {
                    rightmost_index--;
                }
                if (rightmost_index < i) {
                    return "";
                }
                res[rightmost_index]++;
            }
        }

        return res;
    }
};
```
