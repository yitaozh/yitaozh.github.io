---
title: 341. Flatten Nested List Iterator
categories: Leetcode
date: 2023-08-28 23:22:29
tags:
---

# [341\. Flatten Nested List Iterator](https://leetcode.com/problems/flatten-nested-list-iterator/)

## Description

Difficulty: **Medium**

Related Topics: [Stack](https://leetcode.com/tag/https://leetcode.com/tag/stack//), [Tree](https://leetcode.com/tag/https://leetcode.com/tag/tree//), [Depth-First Search](https://leetcode.com/tag/https://leetcode.com/tag/depth-first-search//), [Design](https://leetcode.com/tag/https://leetcode.com/tag/design//), [Queue](https://leetcode.com/tag/https://leetcode.com/tag/queue//), [Iterator](https://leetcode.com/tag/https://leetcode.com/tag/iterator//)

You are given a nested list of integers `nestedList`. Each element is either an integer or a list whose elements may also be integers or other lists. Implement an iterator to flatten it.

Implement the `NestedIterator` class:

* `NestedIterator(List<NestedInteger> nestedList)` Initializes the iterator with the nested list `nestedList`.
* `int next()` Returns the next integer in the nested list.
* `boolean hasNext()` Returns `true` if there are still some integers in the nested list and `false` otherwise.

Your code will be tested with the following pseudocode:

```bash
initialize iterator with nestedList
res = []
while iterator.hasNext()
    append iterator.next() to the end of res
return res
```

If `res` matches the expected flattened list, then your code will be judged as correct.

**Example 1:**

```bash
Input: nestedList = [[1,1],2,[1,1]]
Output: [1,1,2,1,1]
Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].
```

**Example 2:**

```bash
Input: nestedList = [1,[4,[6]]]
Output: [1,4,6]
Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].
```

**Constraints:**

* `1 <= nestedList.length <= 500`
* The values of the integers in the nested list is in the range [-10<sup>6</sup>, 10<sup>6</sup>].

## Solution

Language: **C++**

```C++
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<NestedInteger> res;

    NestedIterator(vector<NestedInteger> &nestedList) {
        // res = new vector<NestedInteger>(nestedList);
        res = nestedList;
    }

    int next() {
        int val = res.front().getInteger();
        res.erase(res.begin());
        return val;
    }

    bool hasNext() {
        while (!res.empty() && res.front().isInteger() == false) {
            vector<NestedInteger> frontList = res.front().getList();
            res.erase(res.begin());
            for (int i = frontList.size() - 1; i >= 0; i--) {
                res.insert(res.begin(), frontList[i]);
            }
        }
        return !res.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
```
