---
title: 1195. Fizz Buzz Multithreaded
categories: Leetcode
date: 2025-03-30 18:27:23
tags:
    - Concurrency
---

[1195. Fizz Buzz Multithreaded](https://leetcode.com/problems/fizz-buzz-multithreaded/description/?envType=problem-list-v2&envId=concurrency)

## Description

You have the four functions:

- `printFizz` that prints the word `"fizz"` to the console,
- `printBuzz` that prints the word `"buzz"` to the console,
- `printFizzBuzz` that prints the word `"fizzbuzz"` to the console, and
- `printNumber` that prints a given integer to the console.

You are given an instance of the class `FizzBuzz` that has four functions: `fizz`, `buzz`, `fizzbuzz` and `number`. The same instance of `FizzBuzz` will be passed to four different threads:

- **Thread A:**  calls `fizz()` that should output the word `"fizz"`.
- **Thread B:**  calls `buzz()` that should output the word `"buzz"`.
- **Thread C:**  calls `fizzbuzz()` that should output the word `"fizzbuzz"`.
- **Thread D:**  calls `number()` that should only output the integers.

Modify the given class to output the series `[1, 2, "fizz", 4, "buzz", ...]` where the `i^th` token (**1-indexed** ) of the series is:

- `"fizzbuzz"` if `i` is divisible by `3` and `5`,
- `"fizz"` if `i` is divisible by `3` and not `5`,
- `"buzz"` if `i` is divisible by `5` and not `3`, or
- `i` if `i` is not divisible by `3` or `5`.

Implement the `FizzBuzz` class:

- `FizzBuzz(int n)` Initializes the object with the number `n` that represents the length of the sequence that should be printed.
- `void fizz(printFizz)` Calls `printFizz` to output `"fizz"`.
- `void buzz(printBuzz)` Calls `printBuzz` to output `"buzz"`.
- `void fizzbuzz(printFizzBuzz)` Calls `printFizzBuzz` to output `"fizzbuzz"`.
- `void number(printNumber)` Calls `printnumber` to output the numbers.

**Example 1:**

```bash
Input: n = 15
Output: [1,2,"fizz",4,"buzz","fizz",7,8,"fizz","buzz",11,"fizz",13,14,"fizzbuzz"]
```

**Example 2:**

```bash
Input: n = 5
Output: [1,2,"fizz",4,"buzz"]
```

**Constraints:**

- `1 <= n <= 50`

## Hints/Notes

- 2025/03/25 Q2
- concurrency
- No solution from 0x3F or Leetcode

## Solution

Language: **C++**

```C++
class FizzBuzz {
private:
    mutex m;
    condition_variable cv;
    int curIdx;
    int n;

public:
    FizzBuzz(int n) {
        this->n = n;
        this->curIdx = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (true) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&]{
                return (curIdx % 3 == 0 && curIdx % 5 != 0) || curIdx > n;
            });
            if (curIdx > n) {
                return;
            }
            printFizz();
            curIdx++;
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (true) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&]{
                return (curIdx % 3 != 0 && curIdx % 5 == 0) || curIdx > n;
            });
            if (curIdx > n) {
                return;
            }
            printBuzz();
            curIdx++;
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
         while (true) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&]{
                return (curIdx % 3 == 0 && curIdx % 5 == 0) || curIdx > n;
            });
            if (curIdx > n) {
                return;
            }
            printFizzBuzz();
            curIdx++;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
         while (true) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&]{
                return (curIdx % 3 && curIdx % 5) || curIdx > n;
            });
            if (curIdx > n) {
                return;
            }
            printNumber(curIdx);
            curIdx++;
            cv.notify_all();
        }
    }
};
```
