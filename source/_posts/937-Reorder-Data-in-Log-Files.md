---
title: 937. Reorder Data in Log Files
categories: Leetcode
date: 2025-04-19 22:27:28
tags:
    - Array
    - String
    - Sorting
---

[937. Reorder Data in Log Files](https://leetcode.com/problems/reorder-data-in-log-files/description/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Description

You are given an array of `logs`. Each log is a space-delimited string of words, where the first word is the **identifier** .

There are two types of logs:

- <b>Letter-logs</b>: All words (except the identifier) consist of lowercase English letters.
- **Digit-logs** : All words (except the identifier) consist of digits.

Reorder these logs so that:

- The **letter-logs**  come before all **digit-logs** .
- The **letter-logs**  are sorted lexicographically by their contents. If their contents are the same, then sort them lexicographically by their identifiers.
- The **digit-logs**  maintain their relative ordering.

Return the final order of the logs.

**Example 1:**

```bash
Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
Explanation:
The letter-log contents are all different, so their ordering is "art can", "art zero", "own kit dig".
The digit-logs have a relative order of "dig1 8 1 5 1", "dig2 3 6".
```

**Example 2:**

```bash
Input: logs = ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
Output: ["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]
```

**Constraints:**

- `1 <= logs.length <= 100`
- `3 <= logs[i].length <= 100`
- All the tokens of `logs[i]` are separated by a **single**  space.
- `logs[i]` is guaranteed to have an identifier and at least one word after the identifier.

## Hints/Notes

- 2025/04/19 Q1
- string
- [Leetcode solution](https://leetcode.com/problems/reorder-data-in-log-files/editorial)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digits;
        map<string, set<string>> m;
        for (auto& log : logs) {
            int start = 0, end = log.find(' ');
            string identifier = log.substr(0, end);
            end++;
            if (isalpha(log[end])) {
                m[log.substr(end)].insert(identifier);
            } else {
                digits.push_back(log);
            }
        }
        vector<string> res;
        for (auto& [content, ids] : m) {
            for (auto& id : ids) {
                res.push_back(id + " " + content);
            }
        }
        res.insert(res.end(), digits.begin(), digits.end());
        return res;
    }
};
```
