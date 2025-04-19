---
title: 588. Design In-Memory File System
categories: Leetcode
date: 2025-04-18 22:42:55
tags:
    - Hash Table
    - String
    - Design
    - Trie
    - Sorting
---

[588. Design In-Memory File System](https://leetcode.com/problems/design-in-memory-file-system/description/?source=submission-noac)

## Description

Design a data structure that simulates an in-memory file system.

Implement the FileSystem class:

- `FileSystem()` Initializes the object of the system.
- `List<String> ls(String path)`

- If `path` is a file path, returns a list that only contains this file's name.
- If `path` is a directory path, returns the list of file and directory names **in this directory** .

The answer should in **lexicographic order** .

- `void mkdir(String path)` Makes a new directory according to the given `path`. The given directory path does not exist. If the middle directories in the path do not exist, you should create them as well.
- `void addContentToFile(String filePath, String content)`

- If `filePath` does not exist, creates that file containing given `content`.
- If `filePath` already exists, appends the given `content` to original content.

- `String readContentFromFile(String filePath)` Returns the content in the file at `filePath`.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/04/28/filesystem.png" style="width: 650px; height: 315px;">

```bash
Input

["FileSystem", "ls", "mkdir", "addContentToFile", "ls", "readContentFromFile"]
[[], ["/"], ["/a/b/c"], ["/a/b/c/d", "hello"], ["/"], ["/a/b/c/d"]]
Output

[null, [], null, null, ["a"], "hello"]

Explanation

FileSystem fileSystem = new FileSystem();
fileSystem.ls("/");                         // return []
fileSystem.mkdir("/a/b/c");
fileSystem.addContentToFile("/a/b/c/d", "hello");
fileSystem.ls("/");                         // return ["a"]
fileSystem.readContentFromFile("/a/b/c/d"); // return "hello"
```

**Constraints:**

- `1 <= path.length,filePath.length <= 100`
- `path` and `filePath`are absolute paths which begin with `'/'`and do not end with `'/'`except that the path is just`"/"`.
- You can assume that all directory names and file names only contain lowercase letters, and the same names will not exist in the same directory.
- You can assume that all operations will be passed valid parameters, and users will not attempt to retrieve file content or list a directory or file that does not exist.
- You can assume that the parent directory for the file in `addContentToFile` will exist.
- `1 <= content.length <= 50`
- At most `300` calls will be made to `ls`, `mkdir`,`addContentToFile`, and`readContentFromFile`.

## Hints/Notes

- 2025/04/13 Q3
- Trie
- [Leetcode solution](https://leetcode.com/problems/design-in-memory-file-system/editorial/?source=submission-noac)

## Solution

Language: **C++**

```C++
class FileSystem {
public:
    struct Object {
        Object(string name) {
            this->name = name;
            isFile = false;
        }
        unordered_map<string, Object*> children;
        bool isFile = false;
        string name;
        string fileContent;
    };

    Object* root;

    FileSystem() {
        root = new Object("root");
    }

    vector<string> ls(string path) {
        vector<string> names = parsePath(path);
        Object* curNode = root;
        for (auto& name : names) {
            curNode = curNode->children[name];
        }
        set<string> res;
        if (curNode->isFile) {
            res.insert(curNode->name);
        } else {
            for (auto [k, _] : curNode->children) {
                res.insert(k);
            }
        }
        return vector<string>(res.begin(), res.end());
    }

    void mkdir(string path) {
        vector<string> names = parsePath(path);
        Object* curNode = root;
        for (auto& name : names) {
            if (!curNode->children.contains(name)) {
                curNode->children[name] = new Object(name);
            }
            curNode = curNode->children[name];
        }
    }

    void addContentToFile(string filePath, string content) {
        vector<string> names = parsePath(filePath);
        Object* curNode = root;
        for (auto& name : names) {
            if (!curNode->children.contains(name)) {
                curNode->children[name] = new Object(name);
            }
            curNode = curNode->children[name];
        }
        curNode->isFile = true;
        curNode->fileContent += content;
    }

    string readContentFromFile(string filePath) {
        vector<string> names = parsePath(filePath);
        Object* curNode = root;
        for (auto& name : names) {
            if (!curNode->children.contains(name)) {
                curNode->children[name] = new Object("name");
            }
            curNode = curNode->children[name];
        }
        return curNode->fileContent;
    }

    vector<string> parsePath(string& filePath) {
        vector<string> names;
        int start = 1, end;
        while ((end = filePath.find('/', start)) != string::npos) {
            names.push_back(filePath.substr(start, end - start));
            start = end + 1;
        }
        if (start < filePath.size()) {
            names.push_back(filePath.substr(start));
        }
        return names;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
```
