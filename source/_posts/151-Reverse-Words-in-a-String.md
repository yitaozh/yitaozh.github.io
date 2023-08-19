---
title: 151. Reverse Words in a String
categories: Leetcode
date: 2023-01-23 11:54:35
tags:
    - Two Pointers
    - String
---

# [151\. Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/)

## Description

Difficulty: **Medium**

Related Topics: [Two Pointers](https://leetcode.com/tag/two-pointers/), [String](https://leetcode.com/tag/string/)

Given an input string `s`, reverse the order of the **words**.

A **word** is defined as a sequence of non-space characters. The **words** in `s` will be separated by at least one space.

Return _a string of the words in reverse order concatenated by a single space._

**Note** that `s` may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

**Example 1:**

```bash
Input: s = "the sky is blue"
Output: "blue is sky the"
```

**Example 2:**

```bash
Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
```

**Example 3:**

```bash
Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
```

**Constraints:**

* 1 <= s.length <= 10<sup>4</sup>
* `s` contains English letters (upper-case and lower-case), digits, and spaces `' '`.
* There is **at least one** word in `s`.

**Follow-up:** If the string data type is mutable in your language, can you solve it **in-place** with `O(1)` extra space?

## Hints/Notes

* Reverse the whole string first,  then each word
* The handling of spaces is the key to AC for this problem

## Solution

Language: **C++**

```C++
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int index = 0, len = s.size();
        for (int i = 0; i < len; i++) {
            if (s[i] != ' ') {
                if (index != 0) {
                    s[index++] = ' ';
                }
                int end = i;
                while (s[end] != ' ' && end < len) {
                    s[index++] = s[end++];
                }
                reverse(s.begin() + index - (end - i), s.begin() + index);
                i = end;
            }
        }
        s.erase(s.begin() + index, s.end());
        return s;
    }
};
```
