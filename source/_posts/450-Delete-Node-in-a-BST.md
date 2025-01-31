---
title: 450. Delete Node in a BST
categories: Leetcode
date: 2025-01-30 22:53:59
tags:
    - Tree
    - Binary Search Tree
    - Binary Tree
---

[450. Delete Node in a BST](https://leetcode.com/problems/delete-node-in-a-bst/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the **root node reference**  (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

- Search for a node to remove.
- If the node is found, delete the node.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/09/04/del_node_1.jpg" style="width: 800px; height: 214px;">

```bash
Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/04/del_node_supp.jpg" style="width: 350px; height: 255px;">
```

**Example 2:**

```bash
Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.
```

**Example 3:**

```bash
Input: root = [], key = 0
Output: []
```

**Constraints:**

- The number of nodes in the tree is in the range `[0, 10^4]`.
- `-10^5 <= Node.val <= 10^5`
- Each node has a **unique**  value.
- `root` is a valid binary search tree.
- `-10^5 <= key <= 10^5`

**Follow up:**  Could you solve it with time complexity `O(height of tree)`?

## Hints/Notes

- 2025/01/30
- bst
- [Leetcode solution](https://leetcode.com/problems/delete-node-in-a-bst/editorial/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)(checked)

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return root;
        }
        if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else {
            if (!root->left && !root->right) {
                return nullptr;
            } else if (root->right) {
                root->val = successor(root);
                root->right = deleteNode(root->right, root->val);
            } else {
                root->val = predecessor(root);
                root->left = deleteNode(root->left, root->val);
            }
        }
        return root;
    }

    int successor(TreeNode* root) {
        root = root->right;
        while (root->left) {
            root = root->left;
        }
        return root->val;
    }

    int predecessor(TreeNode* root) {
        root = root->left;
        while (root->right) {
            root = root->right;
        }
        return root->val;
    }
};
```
