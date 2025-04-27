---
title: 616. Add Bold Tag in String
categories: Leetcode
date: 2025-04-27 16:57:10
tags:
    - Array
    - Hash Table
    - String
    - Trie
    - String Matching
---

[616. Add Bold Tag in String](https://leetcode.com/problems/add-bold-tag-in-string/description/?envType=company&envId=tiktok&favoriteSlug=tiktok-six-months)

## Description

You are given a string `s` and an array of strings `words`.

You should add a closed pair of bold tag `<b>` and `</b>` to wrap the substrings in `s` that exist in `words`.

- If two such substrings overlap, you should wrap them together with only one pair of closed bold-tag.
- If two substrings wrapped by bold tags are consecutive, you should combine them.

Return `s` after adding the bold tags.

**Example 1:**

```bash
Input: s = "abcxyz123", words = ["abc","123"]
Output: "<b>abc</b>xyz<b>123</b>"
Explanation: The two strings of words are substrings of s as following: "abcxyz123".
We add <b> before each substring and </b> after each substring.
```

**Example 2:**

```bash
Input: s = "aaabbb", words = ["aa","b"]
Output: "<b>aaabbb</b>"
Explanation:
"aa" appears as a substring two times: "aaabbb" and "aaabbb".
"b" appears as a substring three times: "aaabbb", "aaabbb", and "aaabbb".
We add <b> before each substring and </b> after each substring: "<b>a<b>a</b>a</b><b>b</b><b>b</b><b>b</b>".
Since the first two <b>'s overlap, we merge them: "<b>aaa</b><b>b</b><b>b</b><b>b</b>".
Since now the four <b>'s are consecutive, we merge them: "<b>aaabbb</b>".
```

**Constraints:**

- `1 <= s.length <= 1000`
- `0 <= words.length <= 100`
- `1 <= words[i].length <= 1000`
- `s` and `words[i]` consist of English letters and digits.
- All the values of `words` are **unique** .

**Note:**  This question is the same as <a href="https://leetcode.com/problems/bold-words-in-string/description/" target="_blank">758. Bold Words in String</a>.

## Hints/Notes

- 2025/04/24 Q1
- string
- [Leetcode solution](https://leetcode.com/problems/add-bold-tag-in-string/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    string addBoldTag(string s, vector<string>& words) {
        int n = s.size();
        vector<bool> bold(n, false);
        for (auto& word : words) {
            int start = s.find(word);
            while (start != string::npos) {
                for (int i = start; i < start + word.size(); i++) {
                    bold[i] = true;
                }
                start = s.find(word, start + 1);
            }
        }
        string openTag = "<b>", closeTag = "</b>", res;
        for (int i = 0; i < n; i++) {
            if (bold[i] && (i == 0 || !bold[i - 1])) {
                res += openTag;
            }
            res.push_back(s[i]);
            if (bold[i] && (i == n - 1 || !bold[i + 1])) {
                res += closeTag;
            }
        }
        return res;
    }
};
```
