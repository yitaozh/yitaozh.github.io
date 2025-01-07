---
title: 230. Kth Smallest Element in a BST
categories: Leetcode
date: 2023-08-26 01:40:02
tags:
    - Tree
    - Depth-First Search
    - Binary Search Tree
    - Binary Tree
---

[230\. Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)

## Description

Difficulty: **Medium**

Related Topics: [Tree](https://leetcode.com/tag/https://leetcode.com/tag/tree//), [Depth-First Search](https://leetcode.com/tag/https://leetcode.com/tag/depth-first-search//), [Binary Search Tree](https://leetcode.com/tag/https://leetcode.com/tag/binary-search-tree//), [Binary Tree](https://leetcode.com/tag/https://leetcode.com/tag/binary-tree//)

Given the `root` of a binary search tree, and an integer `k`, return _the_ k<sup>th</sup> _smallest value (**1-indexed**) of all the values of the nodes in the tree_.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/01/28/kthtree1.jpg)

```bash
Input: root = [3,1,4,null,2], k = 1
Output: 1
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/01/28/kthtree2.jpg)

```bash
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
```

**Constraints:**

* The number of nodes in the tree is `n`.
* 1 <= k <= n <= 10<sup>4</sup>
* 0 <= Node.val <= 10<sup>4</sup>

**Follow up:** If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?

## Hints/Notes

* 2023/08/24
* traverse the tree
* [0x3F's solution](https://leetcode.cn/problems/kth-smallest-element-in-a-bst/solutions/2952810/zhong-xu-bian-li-pythonjavaccgojsrust-by-wc02/)(checked)

## Solution

Language: **C++**

Another recursive solution

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
    int kthSmallest(TreeNode* root, int& k) {
        if (!root) {
            return -1;
        }
        int left = kthSmallest(root->left, k);
        if (left != -1) {
            return left;
        }
        if (--k == 0) {
            return root->val;
        }
        return kthSmallest(root->right, k);
    }
};
```

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
class Solution {
public:
    int index = 1, res = -1;
    int kthSmallest(TreeNode* root, int k) {
        traverse(root, k);
        return res;
    }

    void traverse(TreeNode* root, int k) {
        if (!root || res != -1) return;
        traverse(root->left, k);
        if (index++ == k) {
            res = root->val;
            return;
        }
        traverse(root->right, k);
    }
};
```
