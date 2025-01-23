---
title: 346. Moving Average from Data Stream
categories: Leetcode
date: 2023-12-14 20:11:20
tags:
    - Array
    - Design
    - Queue
    - Data Stream
---

[346\. Moving Average from Data Stream](https://leetcode.com/problems/moving-average-from-data-stream/)

## Description

Difficulty: **Easy**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Design](https://leetcode.com/tag/https://leetcode.com/tag/design//), [Queue](https://leetcode.com/tag/https://leetcode.com/tag/queue//), [Data Stream](https://leetcode.com/tag/https://leetcode.com/tag/data-stream//)

Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

Implement the `MovingAverage` class:

* `MovingAverage(int size)` Initializes the object with the size of the window `size`.
* `double next(int val)` Returns the moving average of the last `size` values of the stream.

**Example 1:**

```bash
Input
["MovingAverage", "next", "next", "next", "next"]
[[3], [1], [10], [3], [5]]
Output
[null, 1.0, 5.5, 4.66667, 6.0]

Explanation
MovingAverage movingAverage = new MovingAverage(3);
movingAverage.next(1); // return 1.0 = 1 / 1
movingAverage.next(10); // return 5.5 = (1 + 10) / 2
movingAverage.next(3); // return 4.66667 = (1 + 10 + 3) / 3
movingAverage.next(5); // return 6.0 = (10 + 3 + 5) / 3
```

**Constraints:**

* `1 <= size <= 1000`
* -10<sup>5</sup> <= val <= 10<sup>5</sup>
* At most 10<sup>4</sup> calls will be made to `next`.

## Hints/Notes

* 2023/12/05
* queue
* [Leetcode solution](https://leetcode.com/problems/moving-average-from-data-stream/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)(checked)

## Solution

Language: **C++**

```C++
class MovingAverage {
public:
    int size_;
    double sum_;
    queue<int> q;

    MovingAverage(int size) {
        size_ = size;
        sum_ = 0;
    }
    
    double next(int val) {
        sum_ += val;
        q.push(val);
        if (q.size() > size_) {
            sum_ -= q.front();
            q.pop();
        }
        return sum_ / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
```
