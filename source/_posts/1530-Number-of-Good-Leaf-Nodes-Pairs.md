---
title: 1530. Number of Good Leaf Nodes Pairs
categories: Leetcode
date: 2025-04-05 13:53:17
tags:
    - Tree
    - Depth-First Search
    - Binary Tree
---

[1530. Number of Good Leaf Nodes Pairs](https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/?envType=company&envId=tiktok&favoriteSlug=tiktok-six-months)

## Description

You are given the `root` of a binary tree and an integer `distance`. A pair of two different **leaf**  nodes of a binary tree is said to be good if the length of **the shortest path**  between them is less than or equal to `distance`.

Return the number of good leaf node pairs in the tree.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/07/09/e1.jpg" style="width: 250px; height: 250px;">

```bash
Input: root = [1,2,3,null,4], distance = 3
Output: 1
Explanation: The leaf nodes of the tree are 3 and 4 and the length of the shortest path between them is 3. This is the only good pair.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/07/09/e2.jpg" style="width: 250px; height: 182px;">

```bash
Input: root = [1,2,3,4,5,6,7], distance = 3
Output: 2
Explanation: The good pairs are [4,5] and [6,7] with shortest path = 2. The pair [4,6] is not good because the length of ther shortest path between them is 4.
```

**Example 3:**

```bash
Input: root = [7,1,4,6,null,5,3,null,null,null,null,null,2], distance = 3
Output: 1
Explanation: The only good pair is [2,5].
```

**Constraints:**

- The number of nodes in the `tree` is in the range `[1, 2^10].`
- `1 <= Node.val <= 100`
- `1 <= distance <= 10`

## Hints/Notes

- 2025/04/01 Q3
- bfs
- [Leetcode solution](https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/editorial)

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

    int countPairs(TreeNode* root, int distance) {
        if (!root) {
            return 0;
        }
        count(root, distance);
        return res;
    }

    map<int, int> count(TreeNode* root, const int distance) {
        if (!root->left && !root->right) {
            return {{1, 1}};
        }
        map<int, int> left, right;
        if (root->left) left = count(root->left, distance);
        if (root->right) right = count(root->right, distance);
        if (!left.empty() && !right.empty()) {
            for (auto& [dis1, num1] : left) {
                for (auto& [dis2, num2] : right) {
                    if (dis1 + dis2 > distance) {
                        break;
                    }
                    res += num1 * num2;
                }
            }
        }
        map<int, int> m;
        for (auto& [dis, num] : left) {
            int new_dis = dis + 1;
            if (new_dis > distance - 1) {
                break;
            }
            m[new_dis] += num;
        }
        for (auto& [dis, num] : right) {
            int new_dis = dis + 1;
            if (new_dis > distance - 1) {
                break;
            }
            m[new_dis] += num;
        }
        return m;
    }
};
```
