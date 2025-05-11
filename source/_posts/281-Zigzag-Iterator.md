---
title: 281. Zigzag Iterator
categories: Leetcode
date: 2025-05-11 17:27:30
tags:
    - Array
    - Design
    - Queue
    - Iterator
---

[281. Zigzag Iterator](https://leetcode.com/problems/zigzag-iterator/description/)

## Description

Given two vectors of integers <code>v1</code> and <code>v2</code>, implement an iterator to return their elements alternately.

Implement the <code>ZigzagIterator</code> class:

- <code>ZigzagIterator(List<int> v1, List<int> v2)</code> initializes the object with the two vectors <code>v1</code> and <code>v2</code>.
- <code>boolean hasNext()</code> returns <code>true</code> if the iterator still has elements, and <code>false</code> otherwise.
- <code>int next()</code> returns the current element of the iterator and moves the iterator to the next element.

**Example 1:**

```bash
Input: v1 = [1,2], v2 = [3,4,5,6]
Output: [1,3,2,4,5,6]
Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,3,2,4,5,6].
```

**Example 2:**

```bash
Input: v1 = [1], v2 = []
Output: [1]
```

**Example 3:**

```bash
Input: v1 = [], v2 = [1]
Output: [1]
```

**Constraints:**

- <code>0 <= v1.length, v2.length <= 1000</code>
- <code>1 <= v1.length + v2.length <= 2000</code>
- <code>-2^31 <= v1[i], v2[i] <= 2^31 - 1</code>

**Follow up:**  What if you are given <code>k</code> vectors? How well can your code be extended to such cases?

**Clarification for the follow-up question:**

The "Zigzag" order is not clearly defined and is ambiguous for <code>k > 2</code> cases. If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic".

**Follow-up Example:**

```bash
Input: v1 = [1,2,3], v2 = [4,5,6,7], v3 = [8,9]
Output: [1,4,8,2,5,9,3,6,7]
```

## Hints/Notes

- 2025/05/04 Q1
- queue
- [Leetcode solution](https://leetcode.com/problems/zigzag-iterator/editorial/)

## Solution

Language: **C++**

```C++
class ZigzagIterator {
public:
    queue<pair<int, int>> q;
    vector<vector<int>> v;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        v.push_back(v1);
        v.push_back(v2);
        for (int i = 0; i < v.size(); i++) {
            if (v[i].size()) {
                q.push({i, 0});
            }
        }
    }

    int next() {
        auto [vIdx, idx] = q.front();
        q.pop();
        int res = v[vIdx][idx];
        idx++;
        if (v[vIdx].size() > idx) {
            q.emplace(vIdx, idx);
        }
        return res;
    }

    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
```
