---
title: 380. Insert Delete GetRandom O(1)
categories: Leetcode
date: 2023-01-31 13:33:24
tags:
    - Array
    - Hash Table
    - Math
    - Design
    - Randomized
---

# [380\. Insert Delete GetRandom O(1)](https://leetcode.com/problems/insert-delete-getrandom-o1/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Math](https://leetcode.com/tag/math/), [Design](https://leetcode.com/tag/design/), [Randomized](https://leetcode.com/tag/randomized/)

Implement the `RandomizedSet` class:

* `RandomizedSet()` Initializes the `RandomizedSet` object.
* `bool insert(int val)` Inserts an item `val` into the set if not present. Returns `true` if the item was not present, `false` otherwise.
* `bool remove(int val)` Removes an item `val` from the set if present. Returns `true` if the item was present, `false` otherwise.
* `int getRandom()` Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the **same probability** of being returned.

You must implement the functions of the class such that each function works in **average** `O(1)` time complexity.

**Example 1:**

```text
Input
["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
[[], [1], [2], [2], [], [1], [2], []]
Output
[null, true, false, true, 2, true, false, 2]

Explanation
RandomizedSet randomizedSet = new RandomizedSet();
randomizedSet.insert(1); // Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomizedSet.remove(2); // Returns false as 2 does not exist in the set.
randomizedSet.insert(2); // Inserts 2 to the set, returns true. Set now contains [1,2].
randomizedSet.getRandom(); // getRandom() should return either 1 or 2 randomly.
randomizedSet.remove(1); // Removes 1 from the set, returns true. Set now contains [2].
randomizedSet.insert(2); // 2 was already in the set, so return false.
randomizedSet.getRandom(); // Since 2 is the only number in the set, getRandom() will always return 2.
```

**Constraints:**

* -2<sup>31</sup> <= val <= 2<sup>31</sup> - 1
* At most `2 *` 10<sup>5</sup> calls will be made to `insert`, `remove`, and `getRandom`.
* There will be **at least one** element in the data structure when `getRandom` is called.

## Hints/Notes

* Use array for O(1) random access, map doesn't have O(1) random access, it needs to advance n slots
* Use a map from val to index to ensure O(1) addition/removal

## Solution

Language: **C++**

```C++
class RandomizedSet {
public:
    vector<int> vals;
    unordered_map<int, int> valToIndex;

    RandomizedSet() {

    }

    bool insert(int val) {
        if (valToIndex.count(val)) {
            return false;
        }
        vals.push_back(val);
        valToIndex[val] = vals.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (!valToIndex.count(val)) {
            return false;
        }
        int idx = valToIndex[val];
        int last = vals.back();
        // it's to remove the value from array in O(1)
        vals[idx] = last;
        valToIndex[last] = idx;
        vals.pop_back();
        valToIndex.erase(val);
        return true;
    }

    int getRandom() {
        return vals[rand() % vals.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
```
