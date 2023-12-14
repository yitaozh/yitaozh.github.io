---
title: 362. Design Hit Counter
categories: Leetcode
date: 2023-12-14 17:49:08
tags:
    - Array
    - Hash Table
    - Binary Search
    - Design
    - Queue
---

# [362\. Design Hit Counter](https://leetcode.com/problems/design-hit-counter/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Hash Table](https://leetcode.com/tag/https://leetcode.com/tag/hash-table//), [Binary Search](https://leetcode.com/tag/https://leetcode.com/tag/binary-search//), [Design](https://leetcode.com/tag/https://leetcode.com/tag/design//), [Queue](https://leetcode.com/tag/https://leetcode.com/tag/queue//)

Design a hit counter which counts the number of hits received in the past `5` minutes (i.e., the past `300` seconds).

Your system should accept a `timestamp` parameter (**in seconds** granularity), and you may assume that calls are being made to the system in chronological order (i.e., `timestamp` is monotonically increasing). Several hits may arrive roughly at the same time.

Implement the `HitCounter` class:

* `HitCounter()` Initializes the object of the hit counter system.
* `void hit(int timestamp)` Records a hit that happened at `timestamp` (**in seconds**). Several hits may happen at the same `timestamp`.
* `int getHits(int timestamp)` Returns the number of hits in the past 5 minutes from `timestamp` (i.e., the past `300` seconds).

**Example 1:**

```bash
Input
["HitCounter", "hit", "hit", "hit", "getHits", "hit", "getHits", "getHits"]
[[], [1], [2], [3], [4], [300], [300], [301]]
Output
[null, null, null, null, 3, null, 4, 3]

Explanation
HitCounter hitCounter = new HitCounter();
hitCounter.hit(1);       // hit at timestamp 1.
hitCounter.hit(2);       // hit at timestamp 2.
hitCounter.hit(3);       // hit at timestamp 3.
hitCounter.getHits(4);   // get hits at timestamp 4, return 3.
hitCounter.hit(300);     // hit at timestamp 300.
hitCounter.getHits(300); // get hits at timestamp 300, return 4.
hitCounter.getHits(301); // get hits at timestamp 301, return 3.
```

**Constraints:**

* 1 <= timestamp <= 2 * 10<sup>9</sup>
* All the calls are being made to the system in chronological order (i.e., `timestamp` is monotonically increasing).
* At most `300` calls will be made to `hit` and `getHits`.

**Follow up:** What if the number of hits per second could be huge? Does your design scale?

## Hints/Notes

* queue

## Solution

Language: **C++**

```C++
class HitCounter {
public:
    queue<int> q;

    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        q.push(timestamp);
    }
    
    int getHits(int timestamp) {
        while (!q.empty() && q.front() <= timestamp - 300) {
            q.pop();
        }
        return q.size();
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
```
