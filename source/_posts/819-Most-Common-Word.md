---
title: 819. Most Common Word
categories: Leetcode
date: 2025-03-14 12:54:50
tags:
    - Array
    - Hash Table
    - String
    - Counting
---

[819. Most Common Word](https://leetcode.com/problems/most-common-word/description/)

## Description

Given a string `paragraph` and a string array of the banned words `banned`, return the most frequent word that is not banned. It is **guaranteed**  there is **at least one word**  that is not banned, and that the answer is **unique** .

The words in `paragraph` are **case-insensitive**  and the answer should be returned in **lowercase** .

**Example 1:**

```bash
Input: paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.", banned = ["hit"]
Output: "ball"
Explanation:
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph.
Note that words in the paragraph are not case sensitive,
that punctuation is ignored (even if adjacent to words, such as "ball,"),
and that "hit" isn't the answer even though it occurs more because it is banned.
```

**Example 2:**

```bash
Input: paragraph = "a.", banned = []
Output: "a"
```

**Constraints:**

- `1 <= paragraph.length <= 1000`
- paragraph consists of English letters, space `' '`, or one of the symbols: `"!?',;."`.
- `0 <= banned.length <= 100`
- `1 <= banned[i].length <= 10`
- `banned[i]` consists of only lowercase English letters.

## Hints/Notes

- 2025/03/13 Q1
- string
- [0x3F's solution](https://leetcode.com/problems/most-common-word/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> banned_set(banned.begin(), banned.end());
        unordered_map<string, int> freq;
        int n = paragraph.size(), maxFreq = 0;
        string res;
        for (int i = 0; i < n; ) {
            if (isalpha(paragraph[i])) {
                int start = i;
                while (isalpha(paragraph[i])) {
                    if ('A' <= paragraph[i] && paragraph[i] <= 'Z') {
                        paragraph[i] = paragraph[i] + 'a' - 'A';
                    }
                    i++;
                }
                string curWord = paragraph.substr(start, i - start);
                if (banned_set.contains(curWord)) {
                    continue;
                }
                if (++freq[curWord] > maxFreq) {
                    maxFreq = freq[curWord];
                    res = curWord;
                }
            } else {
                i++;
            }
        }
        return res;
    }
};
```
