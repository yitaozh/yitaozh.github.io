---
title: 146. LRU Cache
categories: Leetcode
date: 2023-10-03 23:44:46
tags:
    - Hash Table
    - Linked List
    - Design
    - Doubly-Linked List
---

[146\. LRU Cache](https://leetcode.com/problems/lru-cache/)

## Description

Difficulty: **Medium**

Related Topics: [Hash Table](https://leetcode.com/tag/https://leetcode.com/tag/hash-table//), [Linked List](https://leetcode.com/tag/https://leetcode.com/tag/linked-list//), [Design](https://leetcode.com/tag/https://leetcode.com/tag/design//), [Doubly-Linked List](https://leetcode.com/tag/https://leetcode.com/tag/doubly-linked-list//)

Design a data structure that follows the constraints of a **[Least Recently Used (LRU) cache](https://en.wikipedia.org/wiki/Cache_replacement_policies#LRU)**.

Implement the `LRUCache` class:

* `LRUCache(int capacity)` Initialize the LRU cache with **positive** size `capacity`.
* `int get(int key)` Return the value of the `key` if the key exists, otherwise return `-1`.
* `void put(int key, int value)` Update the value of the `key` if the `key` exists. Otherwise, add the `key-value` pair to the cache. If the number of keys exceeds the `capacity` from this operation, **evict** the least recently used key.

The functions `get` and `put` must each run in `O(1)` average time complexity.

**Example 1:**

```bash
Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
```

**Constraints:**

* `1 <= capacity <= 3000`
* 0 <= key <= 10<sup>4</sup>
* 0 <= value <= 10<sup>5</sup>
* At most 2 * 10<sup>5</sup> calls will be made to `get` and `put`.

## Hints/Notes

* Use list + map to mimic the behavior of linkedHashMap

## Solution

Language: **C++**

```C++
class LRUCache {
public:
    int size;
    list<pair<int, int>> l;
    map<int, list<pair<int, int>>::iterator> m;


    LRUCache(int capacity) {
        size = capacity;
    }

    void add_to_end(int key, int value) {
        l.push_back({key, value});
        m[key] = next(l.end(), -1);
    }

    int get(int key) {
        if (!m.count(key)) {
            return -1;
        } else {
            list<pair<int,int>>::iterator i = m[key];
            int value = (*i).second;
            l.erase(i);
            add_to_end(key, value);
            return value;
        }
    }

    void put(int key, int value) {
        if (!m.count(key)) {
            if (l.size() == size) {
                int k = l.front().first;
                m.erase(k);
                l.pop_front();
            }
            add_to_end(key, value);
        } else {
            auto i = m[key];
            l.erase(i);
            add_to_end(key, value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```
