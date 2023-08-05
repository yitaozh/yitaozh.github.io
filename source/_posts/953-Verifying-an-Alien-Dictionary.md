---
title: 953. Verifying an Alien Dictionary
categories: Leetcode
date: 2023-02-03 13:17:50
tags:
  - Array
  - Hash Table
  - String
---

# [953\. Verifying an Alien Dictionary](https://leetcode.com/problems/verifying-an-alien-dictionary/)

## Description

Difficulty: **Easy**

Related Topics: [Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/)

In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different `order`. The `order` of the alphabet is some permutation of lowercase letters.

Given a sequence of `words` written in the alien language, and the `order` of the alphabet, return `true` if and only if the given `words` are sorted lexicographically in this alien language.

**Example 1:**

```bash
Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
```

**Example 2:**

```bash
Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
```

**Example 3:**

```bash
Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).
```

**Constraints:**

* `1 <= words.length <= 100`
* `1 <= words[i].length <= 20`
* `order.length == 26`
* All characters in `words[i]` and `order` are English lowercase letters.

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<int, int> mapping;
        for (int i = 0; i < order.size(); i++) {
            char c = order[i];
            mapping[c - 'a'] = i;
        }
        for (int i = 0; i < words.size() - 1; i++) {
            for (int j = 0; j < words[i].size(); j++) {
                if (j >= words[i + 1].size()) {
                    return false;
                }
                if (words[i][j] != words[i + 1][j]) {
                    int w1 = mapping[words[i][j] - 'a'];
                    int w2 = mapping[words[i + 1][j] - 'a'];
                    if (w1 > w2) {
                        return false;
                    } else {
                        break;
                    }
                }
            }
        }
        return true;
    }
};
```
