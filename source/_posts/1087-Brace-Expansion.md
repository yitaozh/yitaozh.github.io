---
title: 1087. Brace Expansion
categories: Leetcode
date: 2025-03-19 22:40:24
tags:
    - String
    - Backtracking
    - Breadth-First Search
---

[1087. Brace Expansion](https://leetcode.com/problems/brace-expansion/description/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Description

You are given a string `s` representing a list of words. Each letter in the word has one or more options.

- If there is one option, the letter is represented as is.
- If there is more than one option, then curly braces delimit the options. For example, `"{a,b,c}"` represents options `["a", "b", "c"]`.

For example, if `s = "a{b,c}"`, the first character is always `'a'`, but the second character can be `'b'` or `'c'`. The original list is `["ab", "ac"]`.

Return all words that can be formed in this manner, **sorted**  in lexicographical order.

**Example 1:**

```bash
Input: s = "{a,b}c{d,e}f"
Output: ["acdf","acef","bcdf","bcef"]
```

**Example 2:**

```bash
Input: s = "abcd"
Output: ["abcd"]
```

**Constraints:**

- `1 <= s.length <= 50`
- `s` consists of curly brackets `'{}'`, commas`','`, and lowercase English letters.
- `s` is guaranteed to be a valid input.
- There are no nested curly brackets.
- All characters inside a pair of consecutive opening and ending curly brackets are different.

## Hints/Notes

- 2025/02/23 Q3
- backtracking
- [Leetcode solution](https://leetcode.com/problems/brace-expansion/editorial/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<string> res;
    vector<string> expand(string s) {
        string cur;
        dfs(0, cur, s);
        ranges::sort(res);
        return res;
    }

    void dfs(int index, string& cur, string& s) {
        if (index == s.size()) {
            res.push_back(cur);
            return;
        }

        if (s[index] == '{') {
            size_t end = s.find_first_of('}', index);
            vector<string> choices = getChoices(s.substr(index + 1, end - index - 1));
            for (auto& choice : choices) {
                int len = choice.size();
                cur += choice;
                dfs(end + 1, cur, s);
                while (len-- > 0) {
                    cur.pop_back();
                }
            }
        } else {
            int len = 0;
            while (index < s.size() && s[index] != '{') {
                cur.push_back(s[index++]);
                len++;
            }
            dfs(index, cur, s);
            while (len-- > 0) {
                cur.pop_back();
            }
        }
    }

    vector<string> getChoices(string s) {
        int start_pos = 0, end_pos = 0;
        vector<string> res;
        while ((end_pos = s.find(',', start_pos)) != string::npos) {
            string cur = s.substr(start_pos, end_pos - start_pos);
            start_pos = end_pos + 1;
            res.push_back(cur);
        }
        res.push_back(s.substr(start_pos));
        return res;
    }
};
```
