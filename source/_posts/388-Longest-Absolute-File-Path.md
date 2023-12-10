---
title: 388. Longest Absolute File Path
categories: Leetcode
date: 2023-12-09 21:46:02
tags:
    - String
    - Stack
    - Depth-First Search
---

# [388\. Longest Absolute File Path](https://leetcode.com/problems/longest-absolute-file-path/)

## Description

Difficulty: **Medium**

Related Topics: [String](https://leetcode.com/tag/https://leetcode.com/tag/string//), [Stack](https://leetcode.com/tag/https://leetcode.com/tag/stack//), [Depth-First Search](https://leetcode.com/tag/https://leetcode.com/tag/depth-first-search//)

Suppose we have a file system that stores both files and directories. An example of one system is represented in the following picture:

![](https://assets.leetcode.com/uploads/2020/08/28/mdir.jpg)

Here, we have `dir` as the only directory in the root. `dir` contains two subdirectories, `subdir1` and `subdir2`. `subdir1` contains a file `file1.ext` and subdirectory `subsubdir1`. `subdir2` contains a subdirectory `subsubdir2`, which contains a file `file2.ext`.

In text form, it looks like this (with ⟶ representing the tab character):

```bash
dir
⟶ subdir1
⟶ ⟶ file1.ext
⟶ ⟶ subsubdir1
⟶ subdir2
⟶ ⟶ subsubdir2
⟶ ⟶ ⟶ file2.ext
```

If we were to write this representation in code, it will look like this: `"dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"`. Note that the `'\n'` and `'\t'` are the new-line and tab characters.

Every file and directory has a unique **absolute path** in the file system, which is the order of directories that must be opened to reach the file/directory itself, all concatenated by `'/'s`. Using the above example, the **absolute path** to `file2.ext` is `"dir/subdir2/subsubdir2/file2.ext"`. Each directory name consists of letters, digits, and/or spaces. Each file name is of the form `name.extension`, where `name` and `extension` consist of letters, digits, and/or spaces.

Given a string `input` representing the file system in the explained format, return _the length of the **longest absolute path** to a **file** in the abstracted file system_. If there is no file in the system, return `0`.

**Note** that the testcases are generated such that the file system is valid and no file or directory name has length 0.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/08/28/dir1.jpg)

```bash
Input: input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"
Output: 20
Explanation: We have only one file, and the absolute path is "dir/subdir2/file.ext" of length 20.
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2020/08/28/dir2.jpg)

```bash
Input: input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
Output: 32
Explanation: We have two files:
"dir/subdir1/file1.ext" of length 21
"dir/subdir2/subsubdir2/file2.ext" of length 32.
We return 32 since it is the longest absolute path to a file.
```

**Example 3:**

```bash
Input: input = "a"
Output: 0
Explanation: We do not have any files, just a single directory named "a".
```

**Constraints:**

* 1 <= input.length <= 10<sup>4</sup>
* `input` may contain lowercase or uppercase English letters, a new line character `'\n'`, a tab character `'\t'`, a dot `'.'`, a space `' '`, and digits.
* All file and directory names have **positive** length.

## Hints/Notes

* stack
* '\n' and '\t' are char in cpp
* try to write with getline next time

## Solution

Language: **C++**

```bash
class Solution {
public:
    int lengthLongestPath(string input) {
        vector<string> lines;
        vector<string> vec;
        int pos = 0;
        while ((pos = input.find('\n')) != string::npos) {
            string item = input.substr(0, pos);
            lines.push_back(item);
            input.erase(0, pos + 1);
        }
        lines.push_back(input);
        int res = 0;
        for (string line: lines) {
            cout << line << endl;
            int level = line.find_last_of('\t');
            if (level != string::npos) {
                line = line.substr(level + 1);
            } else {
                level = -1;
            }
            while (vec.size() > level + 1) {
                vec.pop_back();
            }
            vec.push_back(line);
            if (line.find('.') != string::npos) {
                int sum = 0;
                for (string s : vec) {
                    sum += s.size();
                }
                sum = sum + vec.size() - 1;
                res = max(res, sum);
            }
        }
        return res;
    }
};
```
