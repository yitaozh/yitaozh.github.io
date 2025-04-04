---
title: 3163. String Compression III
categories: Leetcode
date: 2024-05-29 11:31:21
tags:
    - String
---

[3163. String Compression III](https://leetcode.com/problems/string-compression-iii/description/)

## Description

Given a string `word`, compress it using the following algorithm:

- Begin with an empty string `comp`. While `word` is **not**  empty, use the following operation:

- Remove a maximum length prefix of `word` made of a single character `c` repeating **at most**  9 times.
- Append the length of the prefix followed by `c` to `comp`.

Return the string `comp`.

**Example 1:**

```bash
Input: word = "abcde"

Output: "1a1b1c1d1e"

Explanation:

Initially, `comp = ""`. Apply the operation 5 times, choosing `"a"`, `"b"`, `"c"`, `"d"`, and `"e"` as the prefix in each operation.

For each prefix, append `"1"` followed by the character to `comp`.
```

**Example 2:**

```bash
Input: word = "aaaaaaaaaaaaaabb"

Output: "9a5a2b"

Explanation:

Initially, `comp = ""`. Apply the operation 3 times, choosing `"aaaaaaaaa"`, `"aaaaa"`, and `"bb"` as the prefix in each operation.

- For prefix `"aaaaaaaaa"`, append `"9"` followed by `"a"` to `comp`.
- For prefix `"aaaaa"`, append `"5"` followed by `"a"` to `comp`.
- For prefix `"bb"`, append `"2"` followed by `"b"` to `comp`.
```

**Constraints:**

- `1 <= word.length <= 2 * 10^5`
- `word` consists only of lowercase English letters.

## Hints/Notes

- 2024/02/29
- [0x3F's solution](https://leetcode.cn/problems/string-compression-iii/solutions/2790666/mo-ni-pythonjavacgo-by-endlesscheng-3hk7/)
- Weekly Contest 399

## Solution

Language: **C++**

```C++
class Solution {
public:
    string compressedString(string word) {
        string res;
        int index = 0;
        while (index != word.size()) {
            char c = word[index];
            int i = index;
            for (; i < min(index + 9, (int)word.size()); i++) {
                if (word[i] != c) {
                    break;
                }
            }
            res += to_string(i - index) + c;
            index = i;
        }
        return res;
    }
};
```
