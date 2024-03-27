---
title: 251. Flatten 2D Vector
categories: Leetcode
date: 2024-03-27 17:33:20
tags:
    -
---

# [251. Flatten 2D Vector](https://leetcode.com/problems/flatten-2d-vector/description/)

## Description

Design an iterator to flatten a 2D vector. It should support the `next` and `hasNext` operations.

Implement the `Vector2D` class:

- `Vector2D(int[][] vec)` initializes the object with the 2D vector `vec`.
- `next()` returns the next element from the 2D vector and moves the pointer one step forward. You may assume that all the calls to `next` are valid.
- `hasNext()` returns `true` if there are still some elements in the vector, and `false` otherwise.

**Example 1:**

```bash
Input

["Vector2D", "next", "next", "next", "hasNext", "hasNext", "next", "hasNext"]
[[[[1, 2], [3], [4]]], [], [], [], [], [], [], []]
Output

[null, 1, 2, 3, true, true, 4, false]

Explanation

Vector2D vector2D = new Vector2D([[1, 2], [3], [4]]);
vector2D.next();    // return 1
vector2D.next();    // return 2
vector2D.next();    // return 3
vector2D.hasNext(); // return True
vector2D.hasNext(); // return True
vector2D.next();    // return 4
vector2D.hasNext(); // return False
```

**Constraints:**

- `0 <= vec.length <= 200`
- `0 <= vec[i].length <= 500`
- `-500 <= vec[i][j] <= 500`
- At most `10^5` calls will be made to `next` and `hasNext`.

**Follow up:**  As an added challenge, try to code it using only <a href="http://www.cplusplus.com/reference/iterator/iterator/" target="_blank">iterators in C++</a> or <a href="http://docs.oracle.com/javase/7/docs/api/java/util/Iterator.html" target="_blank">iterators in Java</a>.

## Hints/Notes

- update i, j correctly

## Solution

Language: **C++**

```C++
class Vector2D {
public:
    vector<vector<int>> vec_;
    int i, j;
    Vector2D(vector<vector<int>>& vec) {
        vec_ = vec;
        i = 0;
        j = 0;
    }

    int next() {
        if (!hasNext()) {
            return -1;
        }
        return vec_[i][j++];
    }

    bool hasNext() {
        while (i != vec_.size() && j == vec_[i].size()) {
            i++;
            j = 0;
        }
        if (i == vec_.size()) {
            return false;
        }
        return true;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
```
