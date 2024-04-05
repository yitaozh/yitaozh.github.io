---
title: 297. Serialize and Deserialize Binary Tree
categories: Leetcode
date: 2023-08-22 20:31:34
tags:
    - String
    - Tree
    - Depth-First Search
    - Breadth-First Search
    - Design
    - Binary Tree
---

[297\. Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)

## Description

Difficulty: **Hard**

Related Topics: [String](https://leetcode.com/tag/https://leetcode.com/tag/string//), [Tree](https://leetcode.com/tag/https://leetcode.com/tag/tree//), [Depth-First Search](https://leetcode.com/tag/https://leetcode.com/tag/depth-first-search//), [Breadth-First Search](https://leetcode.com/tag/https://leetcode.com/tag/breadth-first-search//), [Design](https://leetcode.com/tag/https://leetcode.com/tag/design//), [Binary Tree](https://leetcode.com/tag/https://leetcode.com/tag/binary-tree//)

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

**Clarification:** The input/output format is the same as [how LeetCode serializes a binary tree](https://support.leetcode.com/hc/en-us/articles/360011883654-What-does-1-null-2-3-mean-in-binary-tree-representation-). You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/09/15/serdeser.jpg)

```bash
Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]
```

**Example 2:**

```bash
Input: root = []
Output: []
```

**Constraints:**

* The number of nodes in the tree is in the range [0, 10<sup>4</sup>].
* `-1000 <= Node.val <= 1000`

## Hints/Notes

* preorder done
* postorder done
* levelorder tbd

## Solution

Language: **C++**

```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "#";
        string res;
        res = to_string(root->val);
        res += "," + serialize(root->left);
        res += "," + serialize(root->right);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> dataStr;
        int start = 0, found = data.find(",", 0);
        while (found != string::npos) {
            string node = data.substr(start, found - start);
            dataStr.push(node);
            start = found + 1;
            found = data.find(",", start);
        }
        dataStr.push(data.substr(start, data.size() - start));
        return build(dataStr);
    }

    TreeNode* build(queue<string>& dataStr) {
        // if (dataStr.empty()) return nullptr;
        string rootStr = dataStr.front();
        dataStr.pop();
        if (rootStr == "#") return nullptr;

        int rootVal = stoi(rootStr);
        TreeNode* root = new TreeNode(rootVal);
        root->left = build(dataStr);
        root->right = build(dataStr);

        return root;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
```
