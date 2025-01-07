---
title: 269. Alien Dictionary
categories: Leetcode
date: 2025-01-07 16:38:18
tags:
    - Array
    - String
    - Depth-First Search
    - Breadth-First Search
    - Graph
    - Topological Sort
---

[269. Alien Dictionary](https://leetcode.com/problems/alien-dictionary/description/?envType=problem-list-v2&envId=plakya4j)

## Description

There is a new alien language that uses the English alphabet. However, the order of the letters is unknown to you.

You are given a list of strings `words` from the alien language's dictionary. Now it is claimed that the strings in `words` are **sorted lexicographically** by the rules of this new language.

If this claim is incorrect, and the given arrangement of string in`words`cannot correspond to any order of letters,return`"".`

Otherwise, return a string of the unique letters in the new alien language sorted in **lexicographically increasing order**  by the new language's rules. If there are multiple solutions, return **any of them** .

**Example 1:**

```bash
Input: words = ["wrt","wrf","er","ett","rftt"]
Output: "wertf"
```

**Example 2:**

```bash
Input: words = ["z","x"]
Output: "zx"
```

**Example 3:**

```bash
Input: words = ["z","x","z"]
Output: ""
Explanation: The order is invalid, so return `""`.
```

**Constraints:**

- `1 <= words.length <= 100`
- `1 <= words[i].length <= 100`
- `words[i]` consists of only lowercase English letters.

## Hints/Notes

- 2025/01/04
- Topological Sort
- premium

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool visited[26]{};
    bool onPath[26]{};
    string res;
    bool can = true;
    unordered_map<char, vector<char>> graph;

    string alienOrder(vector<string>& words) {
        if (words.size() == 1) {
            unordered_set<char> s;
            for (auto& c : words[0]) {
                s.insert(c);
            }
            return string(s.begin(), s.end());
        }
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i], w2 = words[i + 1];
            int m = w1.size(), n = w2.size();
            for (auto& c : w1) graph[c];
            for (auto& c : w2) graph[c];
            int j = 0;
            for (; j < min(m, n); j++) {
                char c1 = w1[j], c2 = w2[j];
                if (c1 != c2) {
                    graph[c2].push_back(c1);
                    break;
                }
            }
            if (j == min(m, n) && m > n) {
                return "";
            }
        }
        for (char c = 'a'; c <= 'z'; c++) {
            if(graph.contains(c)) {
                dfs(c);
            }
        }
        return can ? res : "";
    }

    void dfs(char c) {
        int index = c - 'a';
        if (onPath[index]) {
            can = false;
        }
        if (!can || visited[index]) {
            return;
        }
        onPath[index] = true;
        visited[index] = true;
        for (auto to : graph[c]) {
            dfs(to);
        }
        onPath[index] = false;
        res.push_back(c);
    }
};
```
