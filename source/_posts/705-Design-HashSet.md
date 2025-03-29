---
title: 705. Design HashSet
categories: Leetcode
date: 2025-03-29 11:28:37
tags:
    - Array
    - Hash Table
    - Linked List
    - Design
    - Hash Function
---

[705. Design HashSet](https://leetcode.com/problems/design-hashset/description/)

## Description

Design a HashSet without using any built-in hash table libraries.

Implement `MyHashSet` class:

- `void add(key)` Inserts the value `key` into the HashSet.
- `bool contains(key)` Returns whether the value `key` exists in the HashSet or not.
- `void remove(key)` Removes the value `key` in the HashSet. If `key` does not exist in the HashSet, do nothing.

**Example 1:**

```bash
Input

["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
[[], [1], [2], [1], [3], [2], [2], [2], [2]]
Output

[null, null, null, true, false, null, true, null, false]

Explanation

MyHashSet myHashSet = new MyHashSet();
myHashSet.add(1);      // set = [1]
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(1); // return True
myHashSet.contains(3); // return False, (not found)
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(2); // return True
myHashSet.remove(2);   // set = [1]
myHashSet.contains(2); // return False, (already removed)
```

**Constraints:**

- `0 <= key <= 10^6`
- At most `10^4` calls will be made to `add`, `remove`, and `contains`.

## Hints/Notes

- 2025/03/20 Q2
- hash
- [Leetcode solution](https://leetcode.com/problems/design-hashset/editorial/)

## Solution

Language: **C++**

```C++
class MyHashSet {
private:
    static const int size = 997;
    vector<list<int>> v;
    static int hash(int key) {
        return key % size;
    }

public:

    MyHashSet() :v(size) {

    }

    void add(int key) {
        int h = hash(key);
        for (auto it = v[h].begin(); it != v[h].end(); ++it) {
            if (*it == key) {
                return;
            }
        }
        v[h].push_back(key);
    }

    void remove(int key) {
        int h = hash(key);
        for (auto it = v[h].begin(); it != v[h].end(); ++it) {
            if (*it == key) {
                v[h].erase(it);
                return;
            }
        }
    }

    bool contains(int key) {
        int h = hash(key);
        for (auto it = v[h].begin(); it != v[h].end(); ++it) {
            if (*it == key) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
```
