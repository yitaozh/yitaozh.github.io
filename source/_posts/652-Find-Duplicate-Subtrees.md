---
title: 652. Find Duplicate Subtrees
categories: Leetcode
date: 2023-08-22 01:22:00
tags:
    - Hash Table
    - Tree
    - Depth-First Search
    - Binary Tree
---

# [652\. Find Duplicate Subtrees](https://leetcode.com/problems/find-duplicate-subtrees/)

## Description

Difficulty: **Medium**

Related Topics: [Hash Table](https://leetcode.com/tag/https://leetcode.com/tag/hash-table//), [Tree](https://leetcode.com/tag/https://leetcode.com/tag/tree//), [Depth-First Search](https://leetcode.com/tag/https://leetcode.com/tag/depth-first-search//), [Binary Tree](https://leetcode.com/tag/https://leetcode.com/tag/binary-tree//)

Given the `root` of a binary tree, return all **duplicate subtrees**.

For each kind of duplicate subtrees, you only need to return the root node of any **one** of them.

Two trees are **duplicate** if they have the **same structure** with the **same node values**.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/08/16/e1.jpg)

```bash
Input: root = [1,2,3,4,null,2,4,null,null,4]
Output: [[2,4],[4]]
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2020/08/16/e2.jpg)

```bash
Input: root = [2,1,1]
Output: [[1]]
```

**Example 3:**

![](https://assets.leetcode.com/uploads/2020/08/16/e33.jpg)

```bash
Input: root = [2,2,2,3,null,3,null]
Output: [[2,3],[3]]
```

**Constraints:**

* The number of the nodes in the tree will be in the range `[1, 5000]`
* `-200 <= Node.val <= 200`

## Hints/Notes

* Serialize the (sub)tree to check if there's duplicate
* Use map the avoid the duplicate in return, only push to res when freq[seri] == 1

## Solution

Language: **C++**

```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> res;
    map<string, int> freq;

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serialize(root);
        return res;
    }

    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "#";
        }
        string seri = serialize(root->left)
              + ',' + serialize(root->right)
              + "," + to_string(root->val);

        if (freq[seri] == 1) {
            res.push_back(root);
        }
        freq[seri]++;

        return seri;
    }
};
```
