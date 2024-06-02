---
title: 987. Vertical Order Traversal of a Binary Tree
categories: Leetcode
date: 2024-05-24 17:44:29
tags:
    - Hash Table
    - Tree
    - Depth-First Search
    - Breadth-First Search
    - Sorting
    - Binary Tree
---

[987. Vertical Order Traversal of a Binary Tree](https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/)

## Description

Given the `root` of a binary tree, calculate the **vertical order traversal**  of the binary tree.

For each node at position `(row, col)`, its left and right children will be at positions `(row + 1, col - 1)` and `(row + 1, col + 1)` respectively. The root of the tree is at `(0, 0)`.

The **vertical order traversal**  of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the **vertical order traversal**  of the binary tree.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/01/29/vtree1.jpg" style="width: 431px; height: 304px;">

```bash
Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation:
Column -1: Only node 9 is in this column.
Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
Column 1: Only node 20 is in this column.
Column 2: Only node 7 is in this column.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/01/29/vtree2.jpg" style="width: 512px; height: 304px;">

```bash
Input: root = [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
Column -2: Only node 4 is in this column.
Column -1: Only node 2 is in this column.
Column 0: Nodes 1, 5, and 6 are in this column.
          1 is at the top, so it comes first.
          5 and 6 are at the same position (2, 0), so we order them by their value, 5 before 6.
Column 1: Only node 3 is in this column.
Column 2: Only node 7 is in this column.
```

**Example 3:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/01/29/vtree3.jpg" style="width: 512px; height: 304px;">

```bash
Input: root = [1,2,3,4,6,5,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
This case is the exact same as example 2, but with nodes 5 and 6 swapped.
Note that the solution remains the same since 5 and 6 are in the same location and should be ordered by their values.
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 1000]`.
- `0 <= Node.val <= 1000`

## Hints/Notes

- priority queue

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
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
        vector<vector<int>> res;
        traverse(root, 0, 0, pq);
        int prev = INT_MIN;
        while (!pq.empty()) {
            auto tri = pq.top();
            pq.pop();
            int index = tri[0];
            int level = tri[1];
            int val = tri[2];
            if (prev != index) {
                res.push_back({val});
                prev = index;
            } else {
                res[res.size() - 1].push_back(val);
            }
        }
        return res;
    }

    void traverse(TreeNode* root, int index, int level,
                  priority_queue<vector<int>, vector<vector<int>>,
                                 greater<vector<int>>>& pq) {
        if (!root) {
            return;
        }
        pq.push({index, level, root->val});
        traverse(root->left, index - 1, level + 1, pq);
        traverse(root->right, index + 1, level + 1, pq);
    }
};
```
