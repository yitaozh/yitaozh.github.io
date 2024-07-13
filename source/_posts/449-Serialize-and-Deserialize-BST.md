---
title: 449. Serialize and Deserialize BST
categories: Leetcode
date: 2024-07-13 01:46:34
tags:
    -String
    -Tree
    -Depth-First Search
    -Breadth-First Search
    -Design
    -Binary Search Tree
    -Binary Tree
---

[449. Serialize and Deserialize BST](https://leetcode.com/problems/serialize-and-deserialize-bst/description/)

## Description

Serialization is converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a <b>binary search tree</b>. There is no restriction on how your serialization/deserialization algorithm should work. You need to ensure that a binary search tree can be serialized to a string, and this string can be deserialized to the original tree structure.

<b>The encoded string should be as compact as possible.</b>

**Example 1:**

```bash
Input: root = [2,1,3]
Output: [2,1,3]
```

**Example 2:**

```bash
Input: root = []
Output: []
```

**Constraints:**

- The number of nodes in the tree is in the range `[0, 10^4]`.
- `0 <= Node.val <= 10^4`
- The input tree is **guaranteed**  to be a binary search tree.

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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "";
        }
        string res = to_string(root->val);
        if (root->left) {
            res += "," + serialize(root->left);
        }
        if (root->right) {
            res += "," + serialize(root->right);
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }
        vector<int> nums;
        int pos = 0;
        while ((pos = data.find(",")) != string::npos) {
            nums.push_back(stoi(data.substr(0, pos)));
            data.erase(0, pos + 1);
        }
        nums.push_back(stoi(data));
        for (int num : nums) {
            cout << num << " ";
        }
        return build(nums, 0, nums.size() - 1);
    }

    TreeNode* build(vector<int>& nums, int start, int end) {
        TreeNode* root = new TreeNode(nums[start]);
        if (start == end) {
            return root;
        }
        int i;
        for (i = start; i <= end && nums[i] <= root->val; i++) {
        }
        if (i > start + 1) {
            root->left = build(nums, start + 1, i - 1);
        }
        if (i <= end) {
            root->right = build(nums, i, end);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
```
