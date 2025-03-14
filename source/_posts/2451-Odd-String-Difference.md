---
title: 2451. Odd String Difference
categories: Leetcode
date: 2025-03-14 13:24:09
tags:
    - Array
    - Hash Table
    - String
---

[2451. Odd String Difference](https://leetcode.com/problems/odd-string-difference/description/)

## Description

You are given an array of equal-length strings `words`. Assume that the length of each string is `n`.

Each string `words[i]` can be converted into a **difference integer array**  `difference[i]` of length `n - 1` where `difference[i][j] = words[i][j+1] - words[i][j]` where `0 <= j <= n - 2`. Note that the difference between two letters is the difference between their **positions**  in the alphabet i.e.the position of `'a'` is `0`, `'b'` is `1`, and `'z'` is `25`.

- For example, for the string `"acb"`, the difference integer array is `[2 - 0, 1 - 2] = [2, -1]`.

All the strings in words have the same difference integer array, **except one** . You should find that string.

Return the string in `words` that has different **difference integer array** .

**Example 1:**

```bash
Input: words = ["adc","wzy","abc"]
Output: "abc"
Explanation:
- The difference integer array of "adc" is [3 - 0, 2 - 3] = [3, -1].
- The difference integer array of "wzy" is [25 - 22, 24 - 25]= [3, -1].
- The difference integer array of "abc" is [1 - 0, 2 - 1] = [1, 1].
The odd array out is [1, 1], so we return the corresponding string, "abc".
```

**Example 2:**

```bash
Input: words = ["aaa","bob","ccc","ddd"]
Output: "bob"
Explanation: All the integer arrays are [0, 0] except for "bob", which corresponds to [13, -13].
```

**Constraints:**

- `3 <= words.length <= 100`
- `n == words[i].length`
- `2 <= n <= 20`
- `words[i]` consists of lowercase English letters.

## Hints/Notes

- 2025/03/13 Q3
- string
- No solution

## Solution

Language: **C++**

```C++
class Solution {
public:
    string oddString(vector<string>& words) {
        vector<int> diff;
        for (int i = 1; i < words[0].size(); i++) {
            diff.push_back(words[0][i] - words[0][i - 1]);
        }
        int notMatchFreq = 0;
        string res;
        for (int i = 1; i < words.size(); i++) {
            string& word = words[i];
            for (int j = 1; j < word.size(); j++) {
                if (word[j] != word[j - 1] + diff[j - 1]) {
                    res = word;
                    notMatchFreq++;
                    break;
                }
            }
        }
        return notMatchFreq == 1 ? res : words[0];
    }
};s
```
