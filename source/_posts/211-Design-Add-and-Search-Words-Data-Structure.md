---
title: 211. Design Add and Search Words Data Structure
categories: Leetcode
date: 2023-10-09 23:48:00
tags:
    - String
    - Depth-First Search
    - Design
    - Trie
---

[211\. Design Add and Search Words Data Structure](https://leetcode.com/problems/design-add-and-search-words-data-structure/)

## Description

Difficulty: **Medium**

Related Topics: [String](https://leetcode.com/tag/https://leetcode.com/tag/string//), [Depth-First Search](https://leetcode.com/tag/https://leetcode.com/tag/depth-first-search//), [Design](https://leetcode.com/tag/https://leetcode.com/tag/design//), [Trie](https://leetcode.com/tag/https://leetcode.com/tag/trie//)

Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the `WordDictionary` class:

* `WordDictionary()` Initializes the object.
* `void addWord(word)` Adds `word` to the data structure, it can be matched later.
* `bool search(word)` Returns `true` if there is any string in the data structure that matches `word` or `false` otherwise. `word` may contain dots `'.'` where dots can be matched with any letter.

**Example:**

```bash
Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
```

**Constraints:**

* `1 <= word.length <= 25`
* `word` in `addWord` consists of lowercase English letters.
* `word` in `search` consist of `'.'` or lowercase English letters.
* There will be at most `2` dots in `word` for `search` queries.
* At most 10<sup>4</sup> calls will be made to `addWord` and `search`.

## Hints/Notes

* Trie
* Need a for loop for wildcard matching, also need a helper function tracking the index

## Solution

Language: **C++**

```C++
class WordDictionary {
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

    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* head = root;
        for (char c : word) {
            if (head->children[c - 'a'] == nullptr) {
                head->children[c - 'a'] = new TrieNode();
            }
            head = head->children[c - 'a'];
        }
        head->end = true;
    }

    bool search(string word) {
        return searchWithPatern(root, 0, word);
    }

    bool searchWithPatern(TrieNode* head, int index, string& word) {
        if (!head) {
            return false;
        }
        if (index == word.size()) {
            return head->end;
        }
        char c = word[index];
        if (c != '.') {
            return searchWithPatern(head->children[c - 'a'], index + 1, word);
        } else {
            for (TrieNode* node : head->children) {
                if (node) {
                    bool branchMatch = searchWithPatern(node, index + 1, word);
                    if (branchMatch) {
                        return true;
                    }
                }
            }
            return false;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
```
