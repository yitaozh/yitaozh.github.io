---
title: 2502. Design Memory Allocator
categories: Leetcode
date: 2025-05-13 01:36:57
tags:
    - Array
    - Hash Table
    - Design
    - Simulation
---

[2502. Design Memory Allocator](https://leetcode.com/problems/design-memory-allocator/description/?envType=company&envId=openai&favoriteSlug=openai-all)

## Description

You are given an integer <code>n</code> representing the size of a **0-indexed**  memory array. All memory units are initially free.

You have a memory allocator with the following functionalities:

- **Allocate** a block of <code>size</code> consecutive free memory units and assign it the id <code>mID</code>.
- **Free**  all memory units with the given id <code>mID</code>.

**Note**  that:

- Multiple blocks can be allocated to the same <code>mID</code>.
- You should free all the memory units with <code>mID</code>, even if they were allocated in different blocks.

Implement the <code>Allocator</code> class:

- <code>Allocator(int n)</code> Initializes an <code>Allocator</code> object with a memory array of size <code>n</code>.
- <code>int allocate(int size, int mID)</code> Find the **leftmost**  block of <code>size</code> **consecutive**  free memory units and allocate it with the id <code>mID</code>. Return the block's first index. If such a block does not exist, return <code>-1</code>.
- <code>int freeMemory(int mID)</code> Free all memory units with the id <code>mID</code>. Return the number of memory units you have freed.

**Example 1:**

```bash
Input

["Allocator", "allocate", "allocate", "allocate", "freeMemory", "allocate", "allocate", "allocate", "freeMemory", "allocate", "freeMemory"]
[[10], [1, 1], [1, 2], [1, 3], [2], [3, 4], [1, 1], [1, 1], [1], [10, 2], [7]]
Output

[null, 0, 1, 2, 1, 3, 1, 6, 3, -1, 0]

Explanation

Allocator loc = new Allocator(10); // Initialize a memory array of size 10. All memory units are initially free.
loc.allocate(1, 1); // The leftmost block's first index is 0. The memory array becomes [**1** ,_,_,_,_,_,_,_,_,_]. We return 0.
loc.allocate(1, 2); // The leftmost block's first index is 1. The memory array becomes [1,**2** ,_,_,_,_,_,_,_,_]. We return 1.
loc.allocate(1, 3); // The leftmost block's first index is 2. The memory array becomes [1,2,**3** ,_,_,_,_,_,_,_]. We return 2.
loc.freeMemory(2); // Free all memory units with mID 2. The memory array becomes [1,_, 3,_,_,_,_,_,_,_]. We return 1 since there is only 1 unit with mID 2.
loc.allocate(3, 4); // The leftmost block's first index is 3. The memory array becomes [1,_,3,**4** ,**4** ,**4** ,_,_,_,_]. We return 3.
loc.allocate(1, 1); // The leftmost block's first index is 1. The memory array becomes [1,**1** ,3,4,4,4,_,_,_,_]. We return 1.
loc.allocate(1, 1); // The leftmost block's first index is 6. The memory array becomes [1,1,3,4,4,4,**1** ,_,_,_]. We return 6.
loc.freeMemory(1); // Free all memory units with mID 1. The memory array becomes [_,_,3,4,4,4,_,_,_,_]. We return 3 since there are 3 units with mID 1.
loc.allocate(10, 2); // We can not find any free block with 10 consecutive free memory units, so we return -1.
loc.freeMemory(7); // Free all memory units with mID 7. The memory array remains the same since there is no memory unit with mID 7. We return 0.
```

**Constraints:**

- <code>1 <= n, size, mID <= 1000</code>
- At most <code>1000</code> calls will be made to <code>allocate</code> and <code>freeMemory</code>.

## Hints/Notes

- 2025/05/08 Q1
- design
- No solution from 0x3F or Leetcode

## Solution

Language: **C++**

```C++
class Allocator {
public:
    vector<int> memory;
    int n;
    Allocator(int n): n(n) {
        memory.resize(n, -1);
    }

    int allocate(int size, int mID) {
        for (int i = 0; i < n;) {
            if (memory[i] == -1) {
                int start = i;
                while (i < n && memory[i] == -1 && i - start < size) {
                    i++;
                }
                if (i - start == size) {
                    fill(memory.begin() + start, memory.begin() + i, mID);
                    return start;
                }
            } else {
                i++;
            }
        }
        return -1;
    }

    int freeMemory(int mID) {
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (memory[i] == mID) {
                int start = i;
                while (i < n && memory[i] == mID) {
                    i++;
                }
                fill(memory.begin() + start, memory.begin() + i, -1);
                res += i - start;
            }
        }
        return res;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */
```
