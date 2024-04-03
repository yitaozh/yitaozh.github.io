---
title: 460. LFU Cache
categories: Leetcode
date: 2023-10-05 23:41:26
tags:
    - Hash Table
    - Linked List
    - Design
    - Doubly-Linked List
---

# [460\. LFU Cache](https://leetcode.com/problems/lfu-cache/)

## Description

Difficulty: **Hard**

Related Topics: [Hash Table](https://leetcode.com/tag/https://leetcode.com/tag/hash-table//), [Linked List](https://leetcode.com/tag/https://leetcode.com/tag/linked-list//), [Design](https://leetcode.com/tag/https://leetcode.com/tag/design//), [Doubly-Linked List](https://leetcode.com/tag/https://leetcode.com/tag/doubly-linked-list//)

Design and implement a data structure for a [Least Frequently Used (LFU)](https://en.wikipedia.org/wiki/Least_frequently_used) cache.

Implement the `LFUCache` class:

* `LFUCache(int capacity)` Initializes the object with the `capacity` of the data structure.
* `int get(int key)` Gets the value of the `key` if the `key` exists in the cache. Otherwise, returns `-1`.
* `void put(int key, int value)` Update the value of the `key` if present, or inserts the `key` if not already present. When the cache reaches its `capacity`, it should invalidate and remove the **least frequently used** key before inserting a new item. For this problem, when there is a **tie** (i.e., two or more keys with the same frequency), the **least recently used** `key` would be invalidated.

To determine the least frequently used key, a **use counter** is maintained for each key in the cache. The key with the smallest **use counter** is the least frequently used key.

When a key is first inserted into the cache, its **use counter** is set to `1` (due to the `put` operation). The **use counter** for a key in the cache is incremented either a `get` or `put` operation is called on it.

The functions `get` and `put` must each run in `O(1)` average time complexity.

**Example 1:**

```bash
Input
["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, 3, null, -1, 3, 4]

Explanation
// cnt(x) = the use counter for key x
// cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
LFUCache lfu = new LFUCache(2);
lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
lfu.get(1);      // return 1
                 // cache=[1,2], cnt(2)=1, cnt(1)=2
lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
                 // cache=[3,1], cnt(3)=1, cnt(1)=2
lfu.get(2);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,1], cnt(3)=2, cnt(1)=2
lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                 // cache=[4,3], cnt(4)=1, cnt(3)=2
lfu.get(1);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,4], cnt(4)=1, cnt(3)=3
lfu.get(4);      // return 4
                 // cache=[4,3], cnt(4)=2, cnt(3)=3
```

**Constraints:**

* 1 <= capacity <= 10<sup>4</sup>
* 0 <= key <= 10<sup>5</sup>
* 0 <= value <= 10<sup>9</sup>
* At most 2 * 10<sup>5</sup> calls will be made to `get` and `put`.

## Hints/Notes

* need a map to record all elements with same freq, i.e. a freqToKeys map
* need a map to record one element's position in the above map's value
* need rewrite next time

## Solution

Language: **C++**

```C++
class LFUCache {
public:
    int size;
    int minFreq = INT_MAX;
    map<int, int> keyToValue;
    map<int, list<int>> freqToKeys;
    map<int, int> keyToFreq;
    map<int, list<int>::iterator> keyListIter;
    LFUCache(int capacity) {
        size = capacity;
    }

    void updateFreq(int key, int freq) {
        if (!freqToKeys.count(freq)) {
            freqToKeys[freq] = {key};
        } else {
            freqToKeys[freq].push_back(key);
        }
        keyListIter[key] = prev(freqToKeys[freq].end());
        keyToFreq[key] = freq;
    }

    void updateExistingFreq(int key) {
        int freq = keyToFreq[key];
        freqToKeys[freq].erase(keyListIter[key]);
        int newFreq = freq + 1;
        if (freq == minFreq && freqToKeys[freq].empty()) {
            freqToKeys.erase(freq);
            minFreq = freq + 1;
        }
        updateFreq(key, newFreq);
    }

    int get(int key) {
        // cout << "now handling get for " << key << endl;
        if (keyToValue.count(key)) {
            updateExistingFreq(key);
            return keyToValue[key];
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        // cout << "now handling put for " << key << " value:" << value << endl;
        if (keyToValue.count(key)) {
            updateExistingFreq(key);
        } else {
            if (keyToValue.size() < size) {
                int freq = 1;
                updateFreq(key, freq);
                minFreq = 1;
            } else {
                int leastFreqKey = freqToKeys[minFreq].front();
                freqToKeys[minFreq].pop_front();
                if (freqToKeys[minFreq].empty()) {
                    freqToKeys.erase(minFreq);
                }
                keyToValue.erase(leastFreqKey);
                keyToFreq.erase(leastFreqKey);
                keyListIter.erase(leastFreqKey);
                int freq = 1;
                updateFreq(key, freq);
                minFreq = 1;
            }
        }
        keyToValue[key] = value;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```
