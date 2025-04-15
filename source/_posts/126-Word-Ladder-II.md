---
title: 126. Word Ladder II
categories: Leetcode
date: 2025-04-15 01:08:41
tags:
    - Hash Table
    - String
    - Backtracking
    - Breadth-First Search
---

[126. Word Ladder II](https://leetcode.com/problems/word-ladder-ii/description/?envType=company&envId=linkedin&favoriteSlug=linkedin-six-months)

## Description

A **transformation sequence**  from word `beginWord` to word `endWord` using a dictionary `wordList` is a sequence of words beginWord -> s<sub>1</sub> -> s<sub>2</sub> -> ... -> s<sub>k</sub> such that:

- Every adjacent pair of words differs by a single letter.
- Every s<sub>i</sub> for `1 <= i <= k` is in `wordList`. Note that `beginWord` does not need to be in `wordList`.
- s<sub>k</sub> == endWord

Given two words, `beginWord` and `endWord`, and a dictionary `wordList`, return all the **shortest transformation sequences**  from `beginWord` to `endWord`, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s<sub>1</sub>, s<sub>2</sub>, ..., s<sub>k</sub>].

**Example 1:**

```bash
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation:There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"
```

**Example 2:**

```bash
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
```

**Constraints:**

- `1 <= beginWord.length <= 5`
- `endWord.length == beginWord.length`
- `1 <= wordList.length <= 500`
- `wordList[i].length == beginWord.length`
- `beginWord`, `endWord`, and `wordList[i]` consist of lowercase English letters.
- `beginWord != endWord`
- All the words in `wordList` are **unique** .
- The **sum**  of all shortest transformation sequences does not exceed `10^5`.

## Hints/Notes

- 2025/04/13 Q1
- bfs + dfs
- No good solution from Leetcode or 0x3F

## Solution

Language: **C++**

```C++
class Solution {
public:
    unordered_map<string, int> shortestSteps;
    vector<vector<string>> res;
    unordered_map<string, vector<string>> graph;

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (!words.contains(endWord)) {
            return res;
        }
        queue<string> q;
        q.push(beginWord);
        int curStep = 0;
        shortestSteps[beginWord] = curStep;
        while (!q.empty()) {
            int size = q.size();
            bool finished = false;
            for (int i = 0; i < size; i++) {
                string curWord = q.front();
                q.pop();
                if (curWord == endWord) {
                    finished = true;
                    break;
                }
                int len = curWord.size();
                for (int j = 0; j < len; j++) {
                    string newWord = curWord;
                    for (char k = 'a'; k <= 'z'; k++) {
                        newWord[j] = k;
                        if (words.contains(newWord)) {
                            if (!shortestSteps.contains(newWord) || shortestSteps[newWord] == curStep + 1) {
                                graph[newWord].push_back(curWord);
                            }
                            if (!shortestSteps.contains(newWord)) {
                                shortestSteps[newWord] = curStep + 1;
                                q.push(newWord);
                            }
                        }
                    }
                }
            }
            if (finished) {
                break;
            }
            curStep++;
        }
        if (!shortestSteps.contains(endWord)) {
            return res;
        }
        vector<string> path = {endWord};
        dfs(endWord, beginWord, shortestSteps[endWord], words, path);
        return res;
    }

    void dfs(string& curWord, string& beginWord, int curStep, unordered_set<string>& words, vector<string>& path) {
        if (curWord == beginWord) {
            reverse(path.begin(), path.end());
            res.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }
        int len = curWord.size();
        for (auto newWord : graph[curWord]) {
            if (shortestSteps[newWord] == curStep - 1) {
                path.push_back(newWord);
                dfs(newWord, beginWord, curStep - 1, words, path);
                path.pop_back();
            }
        }
    }
};
```
