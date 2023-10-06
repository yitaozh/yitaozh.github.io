---
title: 208. Implement Trie (Prefix Tree)
categories: Leetcode
date: 2023-10-06 00:11:04
tags:
    - Hash Table
    - String
    - Design
    - Trie
---

# [208\. Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/)

## Description

Difficulty: **Medium**

Related Topics: [Hash Table](https://leetcode.com/tag/https://leetcode.com/tag/hash-table//), [String](https://leetcode.com/tag/https://leetcode.com/tag/string//), [Design](https://leetcode.com/tag/https://leetcode.com/tag/design//), [Trie](https://leetcode.com/tag/https://leetcode.com/tag/trie//)

A [**trie**](https://en.wikipedia.org/wiki/Trie) (pronounced as "try") or **prefix tree** is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

* `Trie()` Initializes the trie object.
* `void insert(String word)` Inserts the string `word` into the trie.
* `boolean search(String word)` Returns `true` if the string `word` is in the trie (i.e., was inserted before), and `false` otherwise.
* `boolean startsWith(String prefix)` Returns `true` if there is a previously inserted string `word` that has the prefix `prefix`, and `false` otherwise.

**Example 1:**

```bash
Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
```

**Constraints:**

* `1 <= word.length, prefix.length <= 2000`
* `word` and `prefix` consist only of lowercase English letters.
* At most 3 * 10<sup>4</sup> calls **in total** will be made to `insert`, `search`, and `startsWith`.

## Hints/Notes

* Use a bool value to indicate if it's the end of one word
* If one node has been initialized then we should recreate the node

## Solution

Language: **C++**

```C++
class Trie {
public:
    struct TrieNode {
        bool end;
        vector<TrieNode*> children;
        TrieNode() {
            end = false;
            children = vector<TrieNode*>(26, nullptr);
        };
    };
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* head = root;
        for (char c : word) {
            if (!head->children[c - 'a']) {
                head->children[c - 'a'] = new TrieNode();
            }
            head = head->children[c - 'a'];
        }
        head->end = true;
    }

    bool search(string word) {
        TrieNode* head = root;
        for (char c : word) {
            head = head->children[c - 'a'];
            if (!head) return false;
        }
        return head->end;;
    }

    bool startsWith(string prefix) {
        TrieNode* head = root;
        for (char c : prefix) {
            head = head->children[c - 'a'];
            if (!head) return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
```
