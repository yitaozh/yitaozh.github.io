---
title: 1048. Longest String Chain
categories: Leetcode
date: 2025-04-19 23:09:58
tags:
    - Array
    - Hash Table
    - Two Pointers
    - String
    - Dynamic Programming
    - Sorting
---

[1048. Longest String Chain](https://leetcode.com/problems/longest-string-chain/description/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Description

You are given an array of `words` where each word consists of lowercase English letters.

`word<sub>A</sub>` is a **predecessor**  of `word<sub>B</sub>` if and only if we can insert **exactly one**  letter anywhere in `word<sub>A</sub>` **without changing the order of the other characters**  to make it equal to `word<sub>B</sub>`.

- For example, `"abc"` is a **predecessor**  of `"abac"`, while `"cba"` is not a **predecessor**  of `"bcad"`.

A **word chain**  is a sequence of words [word<sub>1</sub>, word<sub>2</sub>, ..., word<sub>k</sub>] with `k >= 1`, where word<sub>1</sub> is a **predecessor**  of word<sub>2</sub>, word<sub>2</sub> is a **predecessor**  of word<sub>3</sub>, and so on. A single word is trivially a **word chain**  with `k == 1`.

Return the **length**  of the **longest possible word chain**  with words chosen from the given list of `words`.

**Example 1:**

```bash
Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation
: One of the longest word chains is ["a","ba","bda","bdca"].
```

**Example 2:**

```bash
Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
```

**Example 3:**

```bash
Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.
```

**Constraints:**

- `1 <= words.length <= 1000`
- `1 <= words[i].length <= 16`
- `words[i]` only consists of lowercase English letters.

## Hints/Notes

- 2025/04/19 Q2
- dp
- [0x3F's solution](https://leetcode.cn/problems/longest-string-chain/solutions/2247269/jiao-ni-yi-bu-bu-si-kao-dong-tai-gui-hua-wdkm/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    map<int, vector<string>> lenToWords;
    unordered_map<string, int> chainLen;

    int longestStrChain(vector<string>& words) {
        for (auto& word : words) {
            lenToWords[word.size()].push_back(word);
        }
        int res = 0;
        for (auto& [len, words] : lenToWords) {
            for (auto& word : words) {
                res = max(res, dfs(word));
            }
        }
        return res;
    }

    int dfs(string word) {
        if (chainLen.contains(word)) {
            return chainLen[word];
        }
        int res = 1, len = word.size();
        if (!lenToWords.contains(len + 1)) {
            chainLen[word] = res;
            return res;
        }
        for (auto& nxtWord : lenToWords[len + 1]) {
            if (nxtWord.find(word) != string::npos) {
                res = max(res, 1 + dfs(nxtWord));
            } else {
                for (int i = 1; i <= len - 1; i++) {
                    if (nxtWord.find(word.substr(0, i)) == 0 && nxtWord.find(word.substr(i), i) == i + 1) {
                        res = max(res, 1 + dfs(nxtWord));
                    }
                }
            }
        }
        chainLen[word] = res;
        return res;
    }
};
```
