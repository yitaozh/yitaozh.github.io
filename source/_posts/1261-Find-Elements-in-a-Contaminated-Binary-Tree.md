---
title: 1261. Find Elements in a Contaminated Binary Tree
categories: Leetcode
date: 2024-06-03 01:09:51
tags:
    - Hash Table
    - Tree
    - Depth-First Search
    - Breadth-First Search
    - Design
    - Binary Tree
---

[1261. Find Elements in a Contaminated Binary Tree](https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/description/)

## Description

Given a binary tree with the following rules:

- `root.val == 0`
- If `treeNode.val == x` and `treeNode.left != null`, then `treeNode.left.val == 2 * x + 1`
- If `treeNode.val == x` and `treeNode.right != null`, then `treeNode.right.val == 2 * x + 2`

Now the binary tree is contaminated, which means all `treeNode.val` have been changed to `-1`.

Implement the `FindElements` class:

- `FindElements(TreeNode* root)` Initializes the object with a contaminated binary tree and recovers it.
- `bool find(int target)` Returns `true` if the `target` value exists in the recovered binary tree.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2019/11/06/untitled-diagram-4-1.jpg" style="width: 320px; height: 119px;">

```bash
Input:
["FindElements","find","find"]
[[[-1,null,-1]],[1],[2]]

Output:
[null,false,true]

Explanation:
FindElements findElements = new FindElements([-1,null,-1]);
findElements.find(1); // return False
findElements.find(2); // return True
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2019/11/06/untitled-diagram-4.jpg" style="width: 400px; height: 198px;">

```bash
Input:
["FindElements","find","find","find"]
[[[-1,-1,-1,-1,-1]],[1],[3],[5]]

Output:
[null,true,true,false]

Explanation:
FindElements findElements = new FindElements([-1,-1,-1,-1,-1]);
findElements.find(1); // return True
findElements.find(3); // return True
findElements.find(5); // return False
```

**Example 3:**

<img alt="" src="https://assets.leetcode.com/uploads/2019/11/07/untitled-diagram-4-1-1.jpg" style="width: 306px; height: 274px;">

```bash
Input:
["FindElements","find","find","find","find"]
[[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]

Output:
[null,true,false,false,true]

Explanation:
FindElements findElements = new FindElements([-1,null,-1,-1,null,-1]);
findElements.find(2); // return True
findElements.find(3); // return False
findElements.find(4); // return False
findElements.find(5); // return True
```

**Constraints:**

- `TreeNode.val == -1`
- The height of the binary tree is less than or equal to `20`
- The total number of nodes is between `[1, 10^4]`
- Total calls of `find()` is between `[1, 10^4]`
- `0 <= target <= 10^6`

## Hints/Notes

- N/A

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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class FindElements {
public:
    TreeNode* root_;
    set<int> nodes;

    FindElements(TreeNode* root) {
        if (!root) {
            root_ = nullptr;
        }
        root_ = root;
        traverse(root_, 0);
    }

    void traverse(TreeNode* node, int curVal) {
        if (!node) {
            return;
        }
        node->val = curVal;
        nodes.insert(curVal);
        traverse(node->left, curVal * 2 + 1);
        traverse(node->right, curVal * 2 + 2);
    }

    bool find(int target) { return nodes.contains(target); }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
```
