---
title: 1166. Design File System
categories: Leetcode
date: 2025-03-27 00:29:27
tags:
    - Hash Table
    - String
    - Design
    - Trie
---

[1166. Design File System](https://leetcode.com/problems/design-file-system/description/)

## Description

You are asked to design a file systemthat allows you to create new paths and associate them with different values.

The format of a path isone or more concatenated strings of the form:`/` followed by one or more lowercase English letters. For example, "`/leetcode"`and "`/leetcode/problems"`are valid paths while an emptystring `""` and `"/"`are not.

Implement the`FileSystem` class:

- `bool createPath(string path, int value)`Creates a new `path` and associates a `value` to it if possible and returns `true`.Returns `false`if the path **already exists**  or its parent path **doesn't exist** .
- `int get(string path)`Returns the value associated with `path` or returns`-1`if the path doesn't exist.

**Example 1:**

```bash
Input:
["FileSystem","createPath","get"]
[[],["/a",1],["/a"]]
Output:
[null,true,1]
Explanation:
FileSystem fileSystem = new FileSystem();

fileSystem.createPath("/a", 1); // return true
fileSystem.get("/a"); // return 1
```

**Example 2:**

```bash
Input:
["FileSystem","createPath","createPath","get","createPath","get"]
[[],["/leet",1],["/leet/code",2],["/leet/code"],["/c/d",1],["/c"]]
Output:
[null,true,true,2,false,-1]
Explanation:
FileSystem fileSystem = new FileSystem();

fileSystem.createPath("/leet", 1); // return true
fileSystem.createPath("/leet/code", 2); // return true
fileSystem.get("/leet/code"); // return 2
fileSystem.createPath("/c/d", 1); // return false because the parent path "/c" doesn't exist.
fileSystem.get("/c"); // return -1 because this path doesn't exist.
```

**Constraints:**

- `2 <= path.length <= 100`
- `1 <= value <= 10^9`
- Each `path` is **valid**  and consists of lowercase English letters and `'/'`.
- At most `10^4` calls **in total**  will be made to `createPath` and `get`.

## Hints/Notes

- 2025/03/19 Q1
- Trie
- [Leetcode solution](https://leetcode.com/problems/design-file-system/)

## Solution

Language: **C++**

```C++
class FileSystem {
public:
    struct TrieNode {
        TrieNode(string name = ""): name(name) {}

        string name;
        int val = -1;
        unordered_map<string, TrieNode*> m;
    };

    TrieNode* root;

    FileSystem() {
        root = new TrieNode();
    }

    bool createPath(string path, int value) {
        vector<string> components = getComponents(path);
        if (components.size() == 0) {
            return false;
        }
        TrieNode* cur = root;
        int n = components.size();
        for (int i = 0; i < n - 1; i++) {
            string& c = components[i];
            if (!cur->m.contains(c)) {
                return false;
            }
            cur = cur->m[c];
        }
        string new_path = components[n - 1];
        if (cur->m.contains(new_path)) {
            return false;
        } else {
            cur->m[new_path] = new TrieNode(new_path);
            cur->m[new_path]->val = value;
            return true;
        }
    }

    int get(string path) {
        vector<string> components = getComponents(path);
        int n = components.size();
        TrieNode* cur = root;
        for (int i = 0; i < n; i++) {
            string& c = components[i];
            if (!cur->m.contains(c)) {
                return -1;
            }
            cur = cur->m[c];
        }
        return cur->val;
    }

    vector<string> getComponents(string path) {
        int start = 1, end;
        vector<string> components;
        while ((end = path.find('/', start)) != string::npos) {
            components.push_back(path.substr(start, end - start));
            start = end + 1;
        }
        components.push_back(path.substr(start));
        return components;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */
```
