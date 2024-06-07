---
title: 331. Verify Preorder Serialization of a Binary Tree
categories: Leetcode
date: 2024-06-07 12:16:21
tags:
    - String
    - Stack
    - Tree
    - Binary Tree
---

[331. Verify Preorder Serialization of a Binary Tree](https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/description/)

## Description

One way to serialize a binary tree is to use **preorder traversal** . When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as `'#'`.

<img alt="" src="https://assets.leetcode.com/uploads/2021/03/12/pre-tree.jpg" style="width: 362px; height: 293px;">

For example, the above binary tree can be serialized to the string `"9,3,4,#,#,1,#,#,2,#,6,#,#"`, where `'#'` represents a null node.

Given a string of comma-separated values `preorder`, return `true` if it is a correct preorder traversal serialization of a binary tree.

It is **guaranteed**  that each comma-separated value in the string must be either an integer or a character `'#'` representing null pointer.

You may assume that the input format is always valid.

- For example, it could never contain two consecutive commas, such as `"1,,3"`.

**Note:** You are not allowed to reconstruct the tree.

**Example 1:**

```bash
Input: preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#"
Output: true
```

**Example 2:**

```bash
Input: preorder = "1,#"
Output: false
```

**Example 3:**

```bash
Input: preorder = "9,#,#,1"
Output: false
```

**Constraints:**

- `1 <= preorder.length <= 10^4`
- `preorder` consist of integers in the range `[0, 100]` and `'#'` separated by commas `','`.

## Hints/Notes

- N/A

## Solution

Language: **C++**

```C++
class Solution {
public:
    int index = 0;
    bool isValid = true;

    bool isValidSerialization(string preorder) {
        vector<int> nums;
        string delimiter = ",";
        int pos = 0;
        preorder += ",";
        while ((pos = preorder.find(delimiter)) != string::npos) {
            string numStr = preorder.substr(0, pos);
            if (numStr == "#") {
                nums.push_back(-1);
            } else {
                nums.push_back(stoi(numStr));
            }
            preorder.erase(0, pos + delimiter.size());
        }
        build(nums);
        return isValid && index == nums.size();
    }

    void build(vector<int>& nums) {
        if (index == nums.size()) {
            isValid = false;
            return;
        }
        if (nums[index] == -1) {
            index++;
            return;
        }
        index++;
        build(nums);
        build(nums);
    }
};
```
