---
title: 71. Simplify Path
categories: Leetcode
date: 2025-01-19 14:35:46
tags:
    - String
    - Stack
---

[71. Simplify Path](https://leetcode.com/problems/simplify-path/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

You are given an absolute path for a Unix-style file system, which always begins with a slash `'/'`. Your task is to transform this absolute path into its **simplified canonical path** .

The rules of a Unix-style file system are as follows:

- A single period `'.'` represents the current directory.
- A double period `'..'` represents the previous/parent directory.
- Multiple consecutive slashes such as `'//'` and `'///'` are treated as a single slash `'/'`.
- Any sequence of periods that does **not match**  the rules above should be treated as a **valid directory or file name**. For example, `'...'` and `'....'` are valid directory or file names.

The simplified canonical path should follow these rules:

- The path must start with a single slash `'/'`.
- Directories within the path must be separated by exactly one slash `'/'`.
- The path must not end with a slash `'/'`, unless it is the root directory.
- The path must not have any single or double periods (`'.'` and `'..'`) used to denote current or parent directories.

Return the **simplified canonical path** .

**Example 1:**

```bash
Input: path = "/home/"

Output: "/home"
```

Explanation:

The trailing slash should be removed.

**Example 2:**

```bash
Input: path = "/home//foo/"

Output: "/home/foo"
```

Explanation:

Multiple consecutive slashes are replaced by a single one.

**Example 3:**

```bash
Input: path = "/home/user/Documents/../Pictures"

Output: "/home/user/Pictures"
```

Explanation:

A double period `".."` refers to the directory up a level (the parent directory).

**Example 4:**

```bash
Input: path = "/../"

Output: "/"
```

Explanation:

Going one level up from the root directory is not possible.

**Example 5:**

```bash
Input: path = "/.../a/../b/c/../d/./"

Output: "/.../b/d"
```

Explanation:

`"..."` is a valid name for a directory in this problem.

**Constraints:**

- `1 <= path.length <= 3000`
- `path` consists of English letters, digits, period `'.'`, slash `'/'` or `'_'`.
- `path` is a valid absolute Unix path.

## Hints/Notes

- 2025/01/18
- stack
- [0x3F's solution](https://leetcode.cn/problems/simplify-path/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> dirs;
        istringstream ss(path);
        string s;
        while (getline(ss, s, '/')) {
            if (s.empty() || s == ".") {
                continue;
            }
            if (s != "..") {
                dirs.push(s);
            } else if (!dirs.empty()) {
                dirs.pop();
            }
        }
        string res;
        while (!dirs.empty()) {
            res = '/' + dirs.top() + res;
            dirs.pop();
        }
        return res.empty() ? "/" : res;

    }
};
```
