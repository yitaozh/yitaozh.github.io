---
title: 379. Design Phone Directory
categories: Leetcode
date: 2024-01-03 18:02:19
tags:
    - Array
    - Hash Table
    - Linked List
    - Design
    - Queue
---

[379\. Design Phone Directory](https://leetcode.com/problems/design-phone-directory/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Hash Table](https://leetcode.com/tag/https://leetcode.com/tag/hash-table//), [Linked List](https://leetcode.com/tag/https://leetcode.com/tag/linked-list//), [Design](https://leetcode.com/tag/https://leetcode.com/tag/design//), [Queue](https://leetcode.com/tag/https://leetcode.com/tag/queue//)

Design a phone directory that initially has `maxNumbers` empty slots that can store numbers. The directory should store numbers, check if a certain slot is empty or not, and empty a given slot.

Implement the `PhoneDirectory` class:

* `PhoneDirectory(int maxNumbers)` Initializes the phone directory with the number of available slots `maxNumbers`.
* `int get()` Provides a number that is not assigned to anyone. Returns `-1` if no number is available.
* `bool check(int number)` Returns `true` if the slot `number` is available and `false` otherwise.
* `void release(int number)` Recycles or releases the slot `number`.

**Example 1:**

```bash
Input
["PhoneDirectory", "get", "get", "check", "get", "check", "release", "check"]
[[3], [], [], [2], [], [2], [2], [2]]
Output
[null, 0, 1, true, 2, false, null, true]

Explanation
PhoneDirectory phoneDirectory = new PhoneDirectory(3);
phoneDirectory.get();      // It can return any available phone number. Here we assume it returns 0.
phoneDirectory.get();      // Assume it returns 1.
phoneDirectory.check(2);   // The number 2 is available, so return true.
phoneDirectory.get();      // It returns 2, the only number that is left.
phoneDirectory.check(2);   // The number 2 is no longer available, so return false.
phoneDirectory.release(2); // Release number 2 back to the pool.
phoneDirectory.check(2);   // Number 2 is available again, return true.
```

**Constraints:**

* 1 <= maxNumbers <= 10<sup>4</sup>
* `0 <= number < maxNumbers`
* At most 2 * 10<sup>4</sup> calls will be made to `get`, `check`, and `release`.

## Hints/Notes

* use set + queue

## Solution

Language: **C++**

```C++
class PhoneDirectory {
public:
    queue<int> available;
    set<int> used;

    PhoneDirectory(int maxNumbers) {
        for (int i = 0; i < maxNumbers; i++) {
            available.push(i);
        }
    }
    
    int get() {
        if (!available.empty()) {
            int number = available.front();
            used.insert(number);
            available.pop();
            return number;
        } else {
            return -1;
        }
    }
    
    bool check(int number) {
        return !used.count(number);
    }
    
    void release(int number) {
        if (used.count(number)) {
            available.push(number);
            used.erase(number);
        }
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
```
