---
title: 359. Logger Rate Limiter
categories: Leetcode
date: 2025-03-14 12:13:41
tags:
    - Hash Table
    - Design
    - Data Stream
---

[359. Logger Rate Limiter](https://leetcode.com/problems/logger-rate-limiter/description/)

## Description

Design a logger system that receives a stream of messages along with their timestamps. Each **unique**  message should only be printed **at most every 10 seconds**  (i.e. a message printed at timestamp `t` will prevent other identical messages from being printed until timestamp `t + 10`).

All messages will come in chronological order. Several messages may arrive at the same timestamp.

Implement the `Logger` class:

- `Logger()` Initializes the `logger` object.
- `bool shouldPrintMessage(int timestamp, string message)` Returns `true` if the `message` should be printed in the given `timestamp`, otherwise returns `false`.

**Example 1:**

```bash
Input

["Logger", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage"]
[[], [1, "foo"], [2, "bar"], [3, "foo"], [8, "bar"], [10, "foo"], [11, "foo"]]
Output

[null, true, true, false, false, false, true]

Explanation

Logger logger = new Logger();
logger.shouldPrintMessage(1, "foo");  // return true, next allowed timestamp for "foo" is 1 + 10 = 11
logger.shouldPrintMessage(2, "bar");  // return true, next allowed timestamp for "bar" is 2 + 10 = 12
logger.shouldPrintMessage(3, "foo");  // 3 < 11, return false
logger.shouldPrintMessage(8, "bar");  // 8 < 12, return false
logger.shouldPrintMessage(10, "foo"); // 10 < 11, return false
logger.shouldPrintMessage(11, "foo"); // 11 >= 11, return true, next allowed timestamp for "foo" is 11 + 10 = 21
```

**Constraints:**

- `0 <= timestamp <= 10^9`
- Every `timestamp` will be passed in non-decreasing order (chronological order).
- `1 <= message.length <= 30`
- At most `10^4` calls will be made to `shouldPrintMessage`.

## Hints/Notes

- 2025/03/11 Q3
- design
- [Leetcode solution](https://leetcode.com/problems/logger-rate-limiter/editorial/)

Step by step improvement:

1. Use a queue of pairs + set, when there's a new request coming in, we
    remove items from the queue first(also remove item from set), then push
    the item to the end of the queue. The problem: worst case time complexity
    is bad due to inline cleanup
2. Use a unordered_map, so we can just check if the item is in the map. The
    problem: need a separate job cleaning items
3. If size requirement comes in, then implement a LRU
4. If the timestamp is un-ordered, then use a sorted data structure

## Solution

Language: **C++**

```C++
class Logger {
public:
    unordered_map<string, int> nextAvailable;

    Logger() {

    }

    bool shouldPrintMessage(int timestamp, string message) {
        if (!nextAvailable.contains(message)) {
            nextAvailable[message] = timestamp + 10;
            return true;
        } else {
            int prev = nextAvailable[message];
            if (timestamp < prev) {
                return false;
            } else {
                nextAvailable[message] = timestamp + 10;
                return true;
            }
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
```
