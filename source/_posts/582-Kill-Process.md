---
title: 582. Kill Process
categories: Leetcode
date: 2024-07-11 14:35:24
tags:
    - Array
    - Hash Table
    - Tree
    - Depth-First Search
    - Breadth-First Search
---

[582. Kill Process](https://leetcode.com/problems/kill-process/description/)

## Description

You have `n` processes forming a rooted tree structure. You are given two integer arrays `pid` and `ppid`, where `pid[i]` is the ID of the `i^th` process and `ppid[i]` is the ID of the `i^th` process's parent process.

Each process has only **one parent process** but may have multiple children processes. Only one process has `ppid[i] = 0`, which means this process has **no parent process** (the root of the tree).

When a process is **killed**, all of its children processes will also be killed.

Given an integer `kill` representing the ID of a process you want to kill, return a list of the IDs of the processes that will be killed. You may return the answer in **any order**.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/02/24/ptree.jpg" style="width: 207px; height: 302px;">

```bash
Input: pid = [1,3,10,5], ppid = [3,0,5,3], kill = 5
Output: [5,10]
Explanation:The processes colored in red are the processes that should be killed.
```

**Example 2:**

```bash
Input: pid = [1], ppid = [0], kill = 1
Output: [1]
```

**Constraints:**

- `n == pid.length`
- `n == ppid.length`
- `1 <= n <= 5 * 10^4`
- `1 <= pid[i] <= 5 * 10^4`
- `0 <= ppid[i] <= 5 * 10^4`
- Only one process has no parent.
- All the values of `pid` are **unique** .
- `kill` is **guaranteed**  to be in `pid`.

## Hints/Notes

- N/A

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool found = false;
    vector<int> res;
    map<int, vector<int>> m;

    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        int n = pid.size(), root = -1;
        for (int i = 0; i < n; i++) {
            int p = pid[i];
            int pp = ppid[i];
            if (pp == 0) {
                root = p;
            } else {
                m[pp].push_back(p);
            }
        }
        findProcess(root, kill);
        return res;
    }

    void findProcess(int root, int kill) {
        if (root == kill) {
            traverse(root);
            found = true;
            return;
        }
        if (found) {
            return;
        }
        for (int child : m[root]) {
            findProcess(child, kill);
        }
    }

    void traverse(int root) {
        res.push_back(root);
        for (int child : m[root]) {
            traverse(child);
        }
    }
};
```
