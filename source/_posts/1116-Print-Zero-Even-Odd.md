---
title: 1116. Print Zero Even Odd
categories: Leetcode
date: 2025-03-30 18:16:28
tags:
    - Concurrency
---

[1116. Print Zero Even Odd](https://leetcode.com/problems/print-zero-even-odd/description/?envType=problem-list-v2&envId=concurrency)

## Description

You have a function `printNumber` that can be called with an integer parameter and prints it to the console.

- For example, calling `printNumber(7)` prints `7` to the console.

You are given an instance of the class `ZeroEvenOdd` that has three functions: `zero`, `even`, and `odd`. The same instance of `ZeroEvenOdd` will be passed to three different threads:

- **Thread A:**  calls `zero()` that should only output `0`'s.
- **Thread B:**  calls `even()` that should only output even numbers.
- **Thread C:**  calls `odd()` that should only output odd numbers.

Modify the given class to output the series `"010203040506..."` where the length of the series must be `2n`.

Implement the `ZeroEvenOdd` class:

- `ZeroEvenOdd(int n)` Initializes the object with the number `n` that represents the numbers that should be printed.
- `void zero(printNumber)` Calls `printNumber` to output one zero.
- `void even(printNumber)` Calls `printNumber` to output one even number.
- `void odd(printNumber)` Calls `printNumber` to output one odd number.

**Example 1:**

```bash
Input: n = 2
Output: "0102"
Explanation: There are three threads being fired asynchronously.
One of them calls zero(), the other calls even(), and the last one calls odd().
"0102" is the correct output.
```

**Example 2:**

```bash
Input: n = 5
Output: "0102030405"
```

**Constraints:**

- `1 <= n <= 1000`

## Hints/Notes

- 2025/03/24 Q3
- concurrency
- No solution from 0x3F or Leetcode

## Solution

Language: **C++**

```C++
class ZeroEvenOdd {
private:
    mutex m;
    condition_variable cv;
    int cur, printZero;
    int n;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->cur = 1;
        this->printZero = 0;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&]{
                return !printZero || cur > n;
            });
            if (cur > n) {
                return;
            }
            printNumber(0);
            printZero ^= 1;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&]{
                return (printZero && cur % 2 == 0) || cur > n;
            });
            if (cur > n) {
                return;
            }
            printNumber(cur);
            cur++;
            printZero ^= 1;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&]{
                return (printZero && cur % 2) || cur > n;
            });
            if (cur > n) {
                return;
            }
            printNumber(cur);
            cur++;
            printZero ^= 1;
            cv.notify_all();
        }
    }
};
```
