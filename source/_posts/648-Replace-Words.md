---
title: 648. Replace Words
categories: Leetcode
date: 2023-10-08 23:31:50
tags:
    - Array
    - Hash Table
    - String
    - Trie
---

[648\. Replace Words](https://leetcode.com/problems/replace-words/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Hash Table](https://leetcode.com/tag/https://leetcode.com/tag/hash-table//), [String](https://leetcode.com/tag/https://leetcode.com/tag/string//), [Trie](https://leetcode.com/tag/https://leetcode.com/tag/trie//)

In English, we have a concept called **root**, which can be followed by some other word to form another longer word - let's call this word **successor**. For example, when the **root** `"an"` is followed by the **successor** word `"other"`, we can form a new word `"another"`.

Given a `dictionary` consisting of many **roots** and a `sentence` consisting of words separated by spaces, replace all the **successors** in the sentence with the **root** forming it. If a **successor** can be replaced by more than one **root**, replace it with the **root** that has **the shortest length**.

Return _the `sentence`_ after the replacement.

**Example 1:**

```bash
Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
```

**Example 2:**

```bash
Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
Output: "a a b c"
```

**Constraints:**

* `1 <= dictionary.length <= 1000`
* `1 <= dictionary[i].length <= 100`
* `dictionary[i]` consists of only lower-case letters.
* 1 <= sentence.length <= 10<sup>6</sup>
* `sentence` consists of only lower-case letters and spaces.
* The number of words in `sentence` is in the range `[1, 1000]`
* The length of each word in `sentence` is in the range `[1, 1000]`
* Every two consecutive words in `sentence` will be separated by exactly one space.
* `sentence` does not have leading or trailing spaces.

## Hints/Notes

* Trie

## Solution

Language: **C++**

```C++
class Solution {
public:
    struct TrieNode{
        bool end;
        vector<TrieNode*> children;
        TrieNode() {
            end = false;
            children = vector<TrieNode*>(26, nullptr);
        }
    };

    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode* root = new TrieNode();
        for (string word : dictionary) {
            TrieNode* head = root;
            for (char c : word) {
                if (!head->children[c - 'a']) {
                    head->children[c - 'a'] = new TrieNode();
                }
                head = head->children[c - 'a'];
            }
            head->end = true;
        }
        size_t pos = 0;
        string word;
        istringstream iss(sentence);
        string res;
        while (iss >> word) {
            TrieNode* head = root;
            string newWord;
            for (char c : word) {
                if (!head) {
                    newWord = word;
                    break;
                } else {
                    if (head->end) {
                        break;
                    } else {
                        head = head->children[c - 'a'];
                        newWord += c;
                    }
                }
            }
            res = res == "" ? newWord : res + " " + newWord;
        };
        return res;
    }
};
```
