---
title: 295. Find Median from Data Stream
categories: Leetcode
date: 2023-10-10 23:10:45
tags:
    - Two Pointers
    - Design
    - Sorting
    - Heap (Priority Queue)
    - Data Stream
---

# [295\. Find Median from Data Stream](https://leetcode.com/problems/find-median-from-data-stream/)

## Description

Difficulty: **Hard**

Related Topics: [Two Pointers](https://leetcode.com/tag/https://leetcode.com/tag/two-pointers//), [Design](https://leetcode.com/tag/https://leetcode.com/tag/design//), [Sorting](https://leetcode.com/tag/https://leetcode.com/tag/sorting//), [Heap (Priority Queue)](https://leetcode.com/tag/https://leetcode.com/tag/heap-priority-queue//), [Data Stream](https://leetcode.com/tag/https://leetcode.com/tag/data-stream//)

The **median** is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

* For example, for `arr = [2,3,4]`, the median is `3`.
* For example, for `arr = [2,3]`, the median is `(2 + 3) / 2 = 2.5`.

Implement the MedianFinder class:

* `MedianFinder()` initializes the `MedianFinder` object.
* `void addNum(int num)` adds the integer `num` from the data stream to the data structure.
* `double findMedian()` returns the median of all elements so far. Answers within 10<sup>-5</sup> of the actual answer will be accepted.

**Example 1:**

```bash
Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
```

**Constraints:**

* -10<sup>5</sup> <= num <= 10<sup>5</sup>
* There will be at least one element in the data structure before calling `findMedian`.
* At most 5 * 10<sup>4</sup> calls will be made to `addNum` and `findMedian`.

**Follow up:**

* If all integer numbers from the stream are in the range `[0, 100]`, how would you optimize your solution?
* If `99%` of all integer numbers from the stream are in the range `[0, 100]`, how would you optimize your solution?

## Hints/Notes

* Use two priority queues

## Solution

Language: **C++**

```C++
class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> big;
    priority_queue<int, vector<int>, less<int>> small;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (small.size() >= big.size()) {
            small.push(num);
            int top = small.top();
            small.pop();
            big.push(top);
        } else {
            big.push(num);
            int top = big.top();
            big.pop();
            small.push(top);
        }
    }
    
    double findMedian() {
        if (small.size() > big.size()) {
            return small.top();
        } else if (small.size() < big.size()) {
            return big.top();
        } else {
            return (small.top() + big.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```
