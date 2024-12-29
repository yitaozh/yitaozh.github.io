---
title: 133. Clone Graph
categories: Leetcode
date: 2024-12-29 16:54:52
tags:
---

[133. Clone Graph](https://leetcode.com/problems/clone-graph/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Given a reference of a node in a **<a href="https://en.wikipedia.org/wiki/Connectivity_(graph_theory)#Connected_graph" target="_blank">connected</a>**  undirected graph.

Return a <a href="https://en.wikipedia.org/wiki/Object_copying#Deep_copy" target="_blank">**deep copy** </a> (clone) of the graph.

Each node in the graph contains a value (`int`) and a list (`List[Node]`) of its neighbors.

```C++
class Node {
    public int val;
    public List<Node> neighbors;
}
```

**Test case format:**

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with `val == 1`, the second node with `val == 2`, and so on. The graph is represented in the test case using an adjacency list.

<b>An adjacency list</b> is a collection of unordered <b>lists</b> used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with `val = 1`. You must return the **copy of the given node**  as a reference to the cloned graph.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2019/11/04/133_clone_graph_question.png" style="width: 454px; height: 500px;">

```bash
Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/01/07/graph.png" style="width: 163px; height: 148px;">

```bash
Input: adjList = [[]]
Output: [[]]
Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.
```

**Example 3:**

```bash
Input: adjList = []
Output: []
Explanation: This an empty graph, it does not have any nodes.
```

**Constraints:**

- The number of nodes in the graph is in the range `[0, 100]`.
- `1 <= Node.val <= 100`
- `Node.val` is unique for each node.
- There are no repeated edges and no self-loops in the graph.
- The Graph is connected and all nodes can be visited starting from the given node.

## Hints/Notes

- 2024/12/29
- dfs
- No solution from 0x3F

## Solution

Language: **C++**

```C++
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int, Node*> m;

    Node* cloneGraph(Node* node) {
        if (!node) {
            return node;
        }
        if (m.contains(node->val)) return m[node->val];
        Node* head = new Node(node->val);
        m[node->val] = head;
        for (auto n : node->neighbors) {
            head->neighbors.push_back(cloneGraph(n));
        }
        return head;
    }
};
```
