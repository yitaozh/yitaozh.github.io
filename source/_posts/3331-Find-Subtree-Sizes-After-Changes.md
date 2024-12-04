---
title: 3331. Find Subtree Sizes After Changes
categories: Leetcode
date: 2024-11-20 14:35:13
tags:
    - Array
    - Hash Table
    - String
    - Tree
    - Depth-First Search
---

[3331. Find Subtree Sizes After Changes](https://leetcode.com/problems/find-subtree-sizes-after-changes/description/)

## Description

You are given a tree rooted at node 0 that consists of `n` nodes numbered from `0` to `n - 1`. The tree is represented by an array `parent` of size `n`, where `parent[i]` is the parent of node `i`. Since node 0 is the root, `parent[0] == -1`.

You are also given a string `s` of length `n`, where `s[i]` is the character assigned to node `i`.

We make the following changes on the tree **one**  time **simultaneously**  for all nodes `x` from `1` to `n - 1`:

- Find the **closest**  node `y` to node `x` such that `y` is an ancestor of `x`, and `s[x] == s[y]`.
- If node `y` does not exist, do nothing.
- Otherwise, **remove**  the edge between `x` and its current parent and make node `y` the new parent of `x` by adding an edge between them.

Return an array `answer` of size `n` where `answer[i]` is the **size**  of the subtree rooted at node `i` in the **final**  tree.

**Example 1:**

```bash
Input: parent = [-1,0,0,1,1,1], s = "abaabc"

Output: [6,3,1,1,1,1]
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/08/15/graphex1drawio.png" style="width: 230px; height: 277px;">

The parent of node 3 will change from node 1 to node 0.

**Example 2:**

```bash
Input: parent = [-1,0,4,0,1], s = "abbba"

Output: [5,2,1,1,1]
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/08/20/exgraph2drawio.png" style="width: 160px; height: 308px;">

The following changes will happen at the same time:

- The parent of node 4 will change from node 1 to node 0.
- The parent of node 2 will change from node 4 to node 1.

**Constraints:**

- `n == parent.length == s.length`
- `1 <= n <= 10^5`
- `0 <= parent[i] <= n - 1` for all `i >= 1`.
- `parent[0] == -1`
- `parent` represents a valid tree.
- `s` consists only of lowercase English letters.

## Hints/Notes

- 2024/10/31
- Use array as map is faster
- [0x3F's solution](https://leetcode.cn/problems/find-subtree-sizes-after-changes/solution/liang-ci-dfszi-ding-xiang-xia-zi-di-xian-k4zj/)(checked)
- Biweekly Contest 142

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<unordered_set<int>> tree;
    array<int, 26> m;
    vector<int> res;

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = s.size();
        fill(m.begin(), m.end(), -1);
        tree.resize(n);
        res.resize(n, 0);
        for (int i = 1; i < n; i++) {
            int p = parent[i];
            tree[p].insert(i);
        }
        dfs(0, parent, s);
        return res;
    }

    void dfs(int idx, vector<int>& parent, string& s) {
        int c = s[idx] - 'a', prev = m[c];
        m[c] = idx;
        res[idx] += 1;
        for (int child : tree[idx]) {
            dfs(child, parent, s);
            int anc = m[s[child] - 'a'];
            res[anc < 0 ? idx : anc] += res[child];
        }
        m[c] = prev;
    }
};
```

Two DFS:

```C++
class Solution {
public:
    vector<vector<int>> children;
    array<int, 26> m;
    string s_;
    vector<int> res;

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = s.size(); s_ = s;
        for (int i = 0; i < 26; i++) {
            m[i] = -1;
        }
        children.resize(n, vector<int>());
        res.resize(n);
        buildTree(parent);
        dfs(0, parent);
        children.clear();
        children.resize(n, vector<int>());
        buildTree(parent);
        dfsCount(0, parent);
        return res;
    }

    int dfsCount(int idx, vector<int>& parent) {
        int ans = 0;
        for (int child : children[idx]) {
            ans += dfsCount(child, parent);
        }
        res[idx] = ans + 1;
        return ans + 1;
    }

    void dfs(int idx, vector<int>& parent) {
        int c = s_[idx] - 'a', prev = -1;
        if (m[c] != -1) {
            parent[idx] = m[c];
            prev = m[c];
        }
        m[c] = idx;
        for (int child : children[idx]) {
            dfs(child, parent);
        }
        m[c] = prev;
    }

    void buildTree(vector<int>& parent) {
        int n = parent.size();
        for (int i = 0; i < parent.size(); i++) {
            if (parent[i] != -1)  {
                int p = parent[i];
                children[p].push_back(i);
            }
        }
    }
};
```
