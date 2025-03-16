---
title: 2385. Amount of Time for Binary Tree to Be Infected
categories: Leetcode
date: 2025-03-16 17:35:27
tags:
    - Hash Table
    - Tree
    - Depth-First Search
    - Breadth-First Search
    - Binary Tree
---

[2385. Amount of Time for Binary Tree to Be Infected](https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Description

You are given the `root` of a binary tree with **unique**  values, and an integer `start`. At minute `0`, an **infection**  starts from the node with value `start`.

Each minute, a node becomes infected if:

- The node is currently uninfected.
- The node is adjacent to an infected node.

Return the number of minutes needed for the entire tree to be infected.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2022/06/25/image-20220625231744-1.png" style="width: 400px; height: 306px;">

```bash
Input: root = [1,5,3,null,4,10,6,9,2], start = 3
Output: 4
Explanation: The following nodes are infected during:
- Minute 0: Node 3
- Minute 1: Nodes 1, 10 and 6
- Minute 2: Node 5
- Minute 3: Node 4
- Minute 4: Nodes 9 and 2
It takes 4 minutes for the whole tree to be infected so we return 4.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2022/06/25/image-20220625231812-2.png" style="width: 75px; height: 66px;">

```bash
Input: root = [1], start = 1
Output: 0
Explanation: At minute 0, the only node in the tree is infected so we return 0.
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 10^5]`.
- `1 <= Node.val <= 10^5`
- Each node has a **unique**  value.
- A node with a value of `start` exists in the tree.

## Hints/Notes

- 2025/02/09 Q2
- tree
- [0x3F's solution](https://leetcode.cn/problems/amount-of-time-for-binary-tree-to-be-infected/solutions/2753470/cong-liang-ci-bian-li-dao-yi-ci-bian-li-tmt0x/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

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
    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_set<int> visited;
    TreeNode* node;

    int amountOfTime(TreeNode* root, int start) {
        traverse(root, start);
        queue<TreeNode*> q;
        q.push(node);
        visited.insert(start);
        int time = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* curNode = q.front();
                q.pop();
                if (curNode->left && !visited.contains(curNode->left->val)) {
                    visited.insert(curNode->left->val);
                    q.push(curNode->left);
                }
                if (curNode->right && !visited.contains(curNode->right->val)) {
                    visited.insert(curNode->right->val);
                    q.push(curNode->right);
                }
                if (parent.contains(curNode) && !visited.contains(parent[curNode]->val)) {
                    visited.insert(parent[curNode]->val);
                    q.push(parent[curNode]);
                }
            }
            if (q.empty()) return time;
            time++;
        }
        return time;
    }

    void traverse(TreeNode* root, int start) {
        if (!root) {
            return;
        }
        if (root->val == start) {
            node = root;
        }
        if (root->left) {
            parent[root->left] = root;
        }
        if (root->right) {
            parent[root->right] = root;
        }
        traverse(root->left, start);
        traverse(root->right, start);
    }
};
```
