---
title: 2265. Count Nodes Equal to Average of Subtree
categories: Leetcode
date: 2025-03-14 13:32:59
tags:
    - Tree
    - Depth-First Search
    - Binary Tree
---

[2265. Count Nodes Equal to Average of Subtree](https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/description/)

## Description

Given the `root` of a binary tree, return the number of nodes where the value of the node is equal to the **average**  of the values in its **subtree** .

**Note:**

- The **average**  of `n` elements is the **sum**  of the `n` elements divided by `n` and **rounded down**  to the nearest integer.
- A **subtree**  of `root` is a tree consisting of `root` and all of its descendants.

**Example 1:**

<img src="https://assets.leetcode.com/uploads/2022/03/15/image-20220315203925-1.png" style="width: 300px; height: 212px;">

```bash
Input: root = [4,8,5,0,1,null,6]
Output: 5
Explanation:
For the node with value 4: The average of its subtree is (4 + 8 + 5 + 0 + 1 + 6) / 6 = 24 / 6 = 4.
For the node with value 5: The average of its subtree is (5 + 6) / 2 = 11 / 2 = 5.
For the node with value 0: The average of its subtree is 0 / 1 = 0.
For the node with value 1: The average of its subtree is 1 / 1 = 1.
For the node with value 6: The average of its subtree is 6 / 1 = 6.
```

**Example 2:**

<img src="https://assets.leetcode.com/uploads/2022/03/26/image-20220326133920-1.png" style="width: 80px; height: 76px;">

```bash
Input: root = [1]
Output: 1
Explanation: For the node with value 1: The average of its subtree is 1 / 1 = 1.
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 1000]`.
- `0 <= Node.val <= 1000`

## Hints/Notes

- 2025/03/14 Q3
- tree
- [0x3F's solution](https://leetcode.cn/problems/count-nodes-equal-to-average-of-subtree/solutions/1477315/tong-ji-zi-shu-de-jie-dian-he-ji-jie-dia-va8t/)

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
    int res = 0;

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return res;
    }

    pair<int, int> dfs(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        int totalSum = left.first + right.first + root->val;
        int totalNode = left.second + right.second + 1;
        if (totalSum / totalNode == root->val) {
            res++;
        }
        return {totalSum, totalNode};
    }
};
```
