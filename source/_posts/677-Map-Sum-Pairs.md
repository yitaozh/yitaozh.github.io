---
title: 677. Map Sum Pairs
categories: Leetcode
date: 2023-10-10 00:14:22
tags:
    - Hash Table
    - String
    - Design
    - Trie
---

[677\. Map Sum Pairs](https://leetcode.com/problems/map-sum-pairs/)

## Description

Difficulty: **Medium**

Related Topics: [Hash Table](https://leetcode.com/tag/https://leetcode.com/tag/hash-table//), [String](https://leetcode.com/tag/https://leetcode.com/tag/string//), [Design](https://leetcode.com/tag/https://leetcode.com/tag/design//), [Trie](https://leetcode.com/tag/https://leetcode.com/tag/trie//)

Design a map that allows you to do the following:

* Maps a string key to a given value.
* Returns the sum of the values that have a key with a prefix equal to a given string.

Implement the `MapSum` class:

* `MapSum()` Initializes the `MapSum` object.
* `void insert(String key, int val)` Inserts the `key-val` pair into the map. If the `key` already existed, the original `key-value` pair will be overridden to the new one.
* `int sum(string prefix)` Returns the sum of all the pairs' value whose `key` starts with the `prefix`.

**Example 1:**

```bash
Input
["MapSum", "insert", "sum", "insert", "sum"]
[[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
Output
[null, null, 3, null, 5]

Explanation
MapSum mapSum = new MapSum();
mapSum.insert("apple", 3);
mapSum.sum("ap");           // return 3 (apple = 3)
mapSum.insert("app", 2);
mapSum.sum("ap");           // return 5 (apple + app = 3 + 2 = 5)
```

**Constraints:**

* `1 <= key.length, prefix.length <= 50`
* `key` and `prefix` consist of only lowercase English letters.
* `1 <= val <= 1000`
* At most `50` calls will be made to `insert` and `sum`.

## Hints/Notes

* Trie

## Solution

Language: **C++**

```C++
class MapSum {
public:
    struct TrieNode {
        int value;
        vector<TrieNode*> children;
        TrieNode() {
            value = 0;
            children = vector<TrieNode*>(26, nullptr);
        }
    };

    TrieNode* root;

    MapSum() {
        root = new TrieNode();
    }

    void insert(string key, int val) {
        TrieNode* head = root;
        for (char c : key) {
            if (head->children[c - 'a'] == nullptr) {
                head->children[c - 'a'] = new TrieNode();
            }
            head = head->children[c - 'a'];
        }
        head->value = val;
    }

    int sum(string prefix) {
        TrieNode* head = root;
        for (char c : prefix) {
            if (head->children[c - 'a'] == nullptr) {
                return 0;
            }
            head = head->children[c - 'a'];
        }
        return traverse(head);
    }

    int traverse(TrieNode* head) {
        if (head == nullptr) {
            return 0;
        }
        int sum = 0;
        for (TrieNode* child : head->children) {
            sum += traverse(child);
        }
        return sum + head->value;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
```
