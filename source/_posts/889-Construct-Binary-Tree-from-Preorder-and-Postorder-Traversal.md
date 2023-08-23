---
title: 889. Construct Binary Tree from Preorder and Postorder Traversal
categories: Leetcode
date: 2023-08-22 00:56:54
tags:
---

# [889\. Construct Binary Tree from Preorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Hash Table](https://leetcode.com/tag/https://leetcode.com/tag/hash-table//), [Divide and Conquer](https://leetcode.com/tag/https://leetcode.com/tag/divide-and-conquer//), [Tree](https://leetcode.com/tag/https://leetcode.com/tag/tree//), [Binary Tree](https://leetcode.com/tag/https://leetcode.com/tag/binary-tree//)

Given two integer arrays, `preorder` and `postorder` where `preorder` is the preorder traversal of a binary tree of **distinct** values and `postorder` is the postorder traversal of the same tree, reconstruct and return _the binary tree_.

If there exist multiple answers, you can **return any** of them.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/07/24/lc-prepost.jpg)

```bash
Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]
```

**Example 2:**

```bash
Input: preorder = [1], postorder = [1]
Output: [1]
```

**Constraints:**

* `1 <= preorder.length <= 30`
* `1 <= preorder[i] <= preorder.length`
* All the values of `preorder` are **unique**.
* `postorder.length == preorder.length`
* `1 <= postorder[i] <= postorder.length`
* All the values of `postorder` are **unique**.
* It is guaranteed that `preorder` and `postorder` are the preorder traversal and postorder traversal of the same binary tree.

## Hints/Notes

* It's possible to have multiple solution from preorder + postorder
* Draw the tree to find the pattern of root's left child

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

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int size = preorder.size();
        for (int i = 0; i < size; i++) {
            valToIndex[postorder[i]] = i;
        }
        return build(preorder, 0, size - 1, postorder, 0, size - 1);
    }

    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                    vector<int>& postorder, int postStart, int postEnd) {
        if (preStart > preEnd) {
            return nullptr;
        }

        int rootVal = preorder[preStart];

        TreeNode* root = new TreeNode(rootVal);

        if (preStart == preEnd) {
            return root;
        }

        int leftVal = preorder[preStart + 1];
        int leftIndex = valToIndex[leftVal];
        int leftSize = leftIndex - postStart + 1;

        root->left = build(preorder, preStart + 1, preStart + leftSize,
                           postorder, postStart, leftIndex);
        root->right = build(preorder, preStart + leftSize + 1, preEnd,
                            postorder, leftIndex + 1, postEnd);
        return root;
    }
};
```
