---
title: 1268. Search Suggestions System
categories: Leetcode
date: 2025-03-22 15:43:47
tags:
    - Array
    - String
    - Binary Search
    - Trie
    - Sorting
    - Heap (Priority Queue)
---

[1268. Search Suggestions System](https://leetcode.com/problems/search-suggestions-system/description/?envType=company&envId=doordash&favoriteSlug=doordash-six-months)

## Description

You are given an array of strings `products` and a string `searchWord`.

Design a system that suggests at most three product names from `products` after each character of `searchWord` is typed. Suggested products should have common prefix with `searchWord`. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return a list of lists of the suggested products after each character of `searchWord` is typed.

**Example 1:**

```bash
Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [["mobile","moneypot","monitor"],["mobile","moneypot","monitor"],["mouse","mousepad"],["mouse","mousepad"],["mouse","mousepad"]]
Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"].
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"].
After typing mou, mous and mouse the system suggests ["mouse","mousepad"].
```

**Example 2:**

```bash
Input: products = ["havana"], searchWord = "havana"
Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
Explanation: The only word "havana" will be always suggested while typing the search word.
```

**Constraints:**

- `1 <= products.length <= 1000`
- `1 <= products[i].length <= 3000`
- `1 <= sum(products[i].length) <= 2 * 10^4`
- All the strings of `products` are **unique** .
- `products[i]` consists of lowercase English letters.
- `1 <= searchWord.length <= 1000`
- `searchWord` consists of lowercase English letters.

## Hints/Notes

- 2025/02/28 Q2
- Trie
- [Leetcode solution](https://leetcode.com/problems/search-suggestions-system/editorial/?envType=company&envId=doordash&favoriteSlug=doordash-six-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    struct TrieNode {
        TrieNode() {
            children.resize(26, nullptr);
        }
        bool end = false;
        vector<TrieNode*> children;
    };

    TrieNode* root;

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        root = new TrieNode();
        for (auto& product : products) {
            TrieNode* cur = root;
            for (auto& c : product) {
                if (!cur->children[c - 'a']) {
                    cur->children[c - 'a'] = new TrieNode();
                }
                cur = cur->children[c - 'a'];
            }
            cur->end = true;
        }
        vector<vector<string>> res;
        TrieNode* cur = root;
        string curWordStr;
        for (char& c : searchWord) {
            if (!cur) {
                res.push_back({});
                continue;
            }
            curWordStr.push_back(c);
            cur = cur->children[c - 'a'];
            vector<string> words;
            dfs(cur, words, curWordStr);
            res.push_back(words);
        }
        return res;
    }

    void dfs(TrieNode* cur, vector<string>& words, string& curWordStr) {
        if (!cur) {
            return;
        }
        if (words.size() == 3) {
            return;
        }
        if (cur->end) {
            words.push_back(curWordStr);
        }
        for (int i = 0; i < 26; i++) {
            if (cur->children[i]) {
                curWordStr.push_back('a' + i);
                dfs(cur->children[i], words, curWordStr);
                curWordStr.pop_back();
            }
        }
    }
};
```
