---
title: 1255. Maximum Score Words Formed by Letters
categories: Leetcode
date: 2024-05-24 15:31:55
tags:
    - Array
    - String
    - Dynamic Programming
    - Backtracking
    - Bit Manipulation
    - Bitmask
---

[1255. Maximum Score Words Formed by Letters](https://leetcode.com/problems/maximum-score-words-formed-by-letters/description/?envType=daily-question&envId=2024-05-24)

Given a list of `words`, list of single`letters` (might be repeating)and `score`of every character.

Return the maximum score of **any**  valid set of words formed by using the given letters (`words[i]` cannot be used twoor more times).

It is not necessary to use all characters in `letters` and each letter can only be used once. Score of letters`'a'`, `'b'`, `'c'`, ... ,`'z'` is given by`score[0]`, `score[1]`, ... , `score[25]` respectively.

**Example 1:**

```bash
Input: words = ["dog","cat","dad","good"], letters = ["a","a","c","d","d","d","g","o","o"], score = [1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0]
Output: 23
Explanation:
Score  a=1, c=9, d=5, g=3, o=2
Given letters, we can form the words "dad" (5+1+5) and "good" (3+2+2+5) with a score of 23.
Words "dad" and "dog" only get a score of 21.
```

**Example 2:**

```bash
Input: words = ["xxxz","ax","bx","cx"], letters = ["z","a","b","c","x","x","x"], score = [4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10]
Output: 27
Explanation:
Score  a=4, b=4, c=4, x=5, z=10
Given letters, we can form the words "ax" (4+5), "bx" (4+5) and "cx" (4+5) with a score of 27.
Word "xxxz" only get a score of 25.
```

**Example 3:**

```bash
Input: words = ["leetcode"], letters = ["l","e","t","c","o","d"], score = [0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0]
Output: 0
Explanation:
Letter "e" can only be used once.
```

**Constraints:**

- `1 <= words.length <= 14`
- `1 <= words[i].length <= 15`
- `1 <= letters.length <= 100`
- `letters[i].length == 1`
- `score.length ==26`
- `0 <= score[i] <= 10`
- `words[i]`, `letters[i]`contains only lower case English letters.

## Hints/Notes

- dfs

## Solution

Language: **C++**

```C++
class Solution {
public:
    unordered_map<char, int> m;
    int res = 0;

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        for (char letter : letters) {
            m[letter]++;
        }
        dfs(0, 0, words, score);
        return res;
    }

    void dfs(int index, int curScore, vector<string>& words, vector<int>& score) {
        if (index == words.size()) {
            res = max(res, curScore);
            return;
        }
        if (addWord(words[index])) {
            dfs(index + 1, curScore + getScore(words[index], score), words, score);
        }
        removeWord(words[index]);
        dfs(index + 1, curScore, words, score);
    }

    int getScore(string word, vector<int>& score) {
        int res = 0;
        for (char c : word) {
            res += score[c - 'a'];
        }
        return res;
    }

    bool addWord(string word) {
        bool res = true;
        for (char c : word) {
            m[c]--;
            if (m[c] < 0) {
                res = false;
            }
        }
        return res;
    }

    void removeWord(string word) {
        for (char c : word) {
            m[c]++;
        }
    }
};
```
