---
title: 245. Shortest Word Distance III
categories: Leetcode
date: 2025-03-14 12:07:26
tags:
    - Array
    - String
---

[245. Shortest Word Distance III](https://leetcode.com/problems/shortest-word-distance-iii/description/)

## Description

Given an array of strings `wordsDict` and two strings that already exist in the array `word1` and `word2`, return the shortest distance between the occurrence of these two words in the list.

**Note**  that `word1` and `word2` may be the same. It is guaranteed that they represent **two individual words**  in the list.

**Example 1:**

```bash
Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 = "makes", word2 = "coding"
Output: 1
```

**Example 2:**

```bash
Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 = "makes", word2 = "makes"
Output: 3
```

**Constraints:**

- `1 <= wordsDict.length <= 10^5`
- `1 <= wordsDict[i].length <= 10`
- `wordsDict[i]` consists of lowercase English letters.
- `word1` and `word2` are in `wordsDict`.

## Hints/Notes

- 2025/03/11 Q1
- Array
- [0x3F's solution](https://leetcode.com/problems/shortest-word-distance-iii/editorial/)

## Solution

Language: **C++**

Better solution:

```C++
class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        int prev = -1, n = wordsDict.size(), res = INT_MAX;
        for (int i = 0; i < n; i++) {
            auto& word = wordsDict[i];
            if (word == word1 || word == word2) {
                if (prev != -1 && (wordsDict[prev] != word || word1 == word2)) {
                    res = min(res, i - prev);
                }
                prev = i;
            }
        }
        return res;
    }
};
```

```C++
class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        vector<pair<int, int>> indices;
        // Store the indices of word1 or word2 and an extra integer in the pair
        // as 0 if the string is word1 or 1 if the string is word2.
        for (int i = 0; i < wordsDict.size(); i++) {
            if (wordsDict[i] == word1) {
                indices.push_back({i, 0});
            }
            if (wordsDict[i] == word2) {
                indices.push_back({i, 1});
            }
        }

        // Initialize it to maximum integer as it will store the minimum distance.
        int shortestDistance = INT_MAX;
        for (int i = 0; i < indices.size() - 1; i++) {
            // If the two consecutive pairs have both different values
            if (indices[i].second != indices[i + 1].second && indices[i].first != indices[i + 1].first) {
                // Find the difference between indices and update shortestDistance
                shortestDistance = min(shortestDistance, indices[i + 1].first - indices[i].first);
            }
        }
        return shortestDistance;
    }
};
```
