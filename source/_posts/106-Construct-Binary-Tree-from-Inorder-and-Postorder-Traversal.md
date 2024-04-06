---
title: 106. Construct Binary Tree from Inorder and Postorder Traversal
categories: Leetcode
date: 2023-08-22 00:28:08
tags:
    - Array
    - Hash Table
    - Divide and Conquer
    - Tree
    - Binary Tree
---

[106\. Construct Binary Tree from Inorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Hash Table](https://leetcode.com/tag/https://leetcode.com/tag/hash-table//), [Divide and Conquer](https://leetcode.com/tag/https://leetcode.com/tag/divide-and-conquer//), [Tree](https://leetcode.com/tag/https://leetcode.com/tag/tree//), [Binary Tree](https://leetcode.com/tag/https://leetcode.com/tag/binary-tree//)

Given two integer arrays `inorder` and `postorder` where `inorder` is the inorder traversal of a binary tree and `postorder` is the postorder traversal of the same tree, construct and return _the binary tree_.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/02/19/tree.jpg)

```bash
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
```

**Example 2:**

```bash
Input: inorder = [-1], postorder = [-1]
Output: [-1]
```

**Constraints:**

* `1 <= inorder.length <= 3000`
* `postorder.length == inorder.length`
* `-3000 <= inorder[i], postorder[i] <= 3000`
* `inorder` and `postorder` consist of **unique** values.
* Each value of `postorder` also appears in `inorder`.
* `inorder` is **guaranteed** to be the inorder traversal of the tree.
* `postorder` is **guaranteed** to be the postorder traversal of the tree.

## Hints/Notes

* Draw the tree and find the pattern of root's location

## Solution

Language: **C++**

```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int, int> valToIndex;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        for (int i = 0; i < size; i++) {
            valToIndex[inorder[i]] = i;
        }
        return build(inorder, 0, size - 1, postorder, 0, size - 1);
    }

    TreeNode* build(vector<int>& inorder, int inStart, int inEnd,
                    vector<int>& postorder, int postStart, int postEnd) {
        if (inStart > inEnd) {
            return nullptr;
        }

        int rootVal = postorder[postEnd];
        int rootIndex = valToIndex[rootVal];

        TreeNode* root = new TreeNode(rootVal);

        int leftSize = rootIndex - inStart;
        root->left = build(inorder, inStart, rootIndex - 1,
                           postorder, postStart, postStart + leftSize - 1);
        root->right = build(inorder, rootIndex + 1, inEnd,
                            postorder, postStart + leftSize, postEnd - 1);
        return root;
    }
};
```
