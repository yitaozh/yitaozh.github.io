---
title: 127. Word Ladder
categories: Leetcode
date: 2024-12-28 17:05:43
tags:
    - Hash Table
    - String
    - Breadth-First Search
---

[127. Word Ladder](https://leetcode.com/problems/word-ladder/description/?envType=problem-list-v2&envId=plakya4j)

## Description

A **transformation sequence**  from word `beginWord` to word `endWord` using a dictionary `wordList` is a sequence of words beginWord -> s<sub>1</sub> -> s<sub>2</sub> -> ... -> s<sub>k</sub> such that:

- Every adjacent pair of words differs by a single letter.
- Every s<sub>i</sub> for `1 <= i <= k` is in `wordList`. Note that `beginWord` does not need to be in `wordList`.
- s<sub>k</sub> == endWord

Given two words, `beginWord` and `endWord`, and a dictionary `wordList`, return the **number of words**  in the **shortest transformation sequence**  from `beginWord` to `endWord`, or `0` if no such sequence exists.

**Example 1:**

```bash
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
```

**Example 2:**

```bash
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
```

**Constraints:**

- `1 <= beginWord.length <= 10`
- `endWord.length == beginWord.length`
- `1 <= wordList.length <= 5000`
- `wordList[i].length == beginWord.length`
- `beginWord`, `endWord`, and `wordList[i]` consist of lowercase English letters.
- `beginWord != endWord`
- All the words in `wordList` are **unique** .

## Hints/Notes

- 2024/12/28
- BFS
- No solution from 0x3F

## Solution

Language: **C++**

```C++
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (!words.contains(endWord)) {
            return 0;
        }
        queue<string> q;
        unordered_set<string> visited;
        q.push(beginWord);
        int step = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string cur = q.front();
                q.pop();
                for (int j = 0; j < cur.size(); j++) {
                    char tmp = cur[j];
                    for (int k = 0; k < 26; k++) {
                        char tmp = cur[j];
                        cur[j] = 'a' + k;
                        if (endWord == cur) {
                            return step + 1;
                        }
                        if (words.contains(cur) && !visited.contains(cur)) {
                            visited.insert(cur);
                            q.push(cur);
                        }
                    }
                    cur[j] = tmp;
                }
            }
            step++;
        }
        return 0;

    }
};
```
