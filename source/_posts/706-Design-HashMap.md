---
title: 706. Design HashMap
categories: Leetcode
date: 2025-03-29 11:32:51
tags:
    - Array
    - Hash Table
    - Linked List
    - Design
    - Hash Function
---

[706. Design HashMap](https://leetcode.com/problems/design-hashmap/description/?envType=company&envId=apple&favoriteSlug=apple-six-months)

## Description

Design a HashMap without using any built-in hash table libraries.

Implement the `MyHashMap` class:

- `MyHashMap()` initializes the object with an empty map.
- `void put(int key, int value)` inserts a `(key, value)` pair into the HashMap. If the `key` already exists in the map, update the corresponding `value`.
- `int get(int key)` returns the `value` to which the specified `key` is mapped, or `-1` if this map contains no mapping for the `key`.
- `void remove(key)` removes the `key` and its corresponding `value` if the map contains the mapping for the `key`.

**Example 1:**

```bash
Input

["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
[[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
Output

[null, null, null, 1, -1, null, 1, null, -1]

Explanation

MyHashMap myHashMap = new MyHashMap();
myHashMap.put(1, 1); // The map is now [[1,1]]
myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
myHashMap.get(1);    // return 1, The map is now [[1,1], [2,2]]
myHashMap.get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
myHashMap.get(2);    // return 1, The map is now [[1,1], [2,1]]
myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
myHashMap.get(2);    // return -1 (i.e., not found), The map is now [[1,1]]
```

**Constraints:**

- `0 <= key, value <= 10^6`
- At most `10^4` calls will be made to `put`, `get`, and `remove`.

## Hints/Notes

- 2025/03/20 Q3
- hash and vector
- [Leetcode solution](https://leetcode.cn/problems/design-hashmap/solutions/654139/she-ji-ha-xi-ying-she-by-leetcode-soluti-klu9/?envType=company&envId=apple&favoriteSlug=apple-six-months)

## Solution

Language: **C++**

```C++
class MyHashMap {
private:
    static const int size = 997;
    vector<list<pair<int, int>>> v;
    static int hash(int key) {
        return key % size;
    }

public:
    MyHashMap() : v(size) {

    }

    void put(int key, int value) {
        int h = hash(key);
        for (auto it = v[h].begin(); it != v[h].end(); ++it) {
            if (it->first == key) {
                it->second = value;
                return;
            }
        }
        v[h].push_back({key, value});
    }

    int get(int key) {
        int h = hash(key);
        for (auto it = v[h].begin(); it != v[h].end(); ++it) {
            if (it->first == key) {
                return it->second;
            }
        }
        return -1;
    }

    void remove(int key) {
        int h = hash(key);
        for (auto it = v[h].begin(); it != v[h].end(); ++it) {
            if (it->first == key) {
                v[h].erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
```
