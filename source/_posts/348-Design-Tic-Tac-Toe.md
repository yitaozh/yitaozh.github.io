---
title: 348. Design Tic-Tac-Toe
categories: Leetcode
date: 2025-01-21 02:34:30
tags:
    - Array
    - Hash Table
    - Design
    - Matrix
    - Simulation
---

[348. Design Tic-Tac-Toe](https://leetcode.com/problems/design-tic-tac-toe/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

Assume the following rules are for the tic-tac-toe game on an `n x n` board between two players:

- A move is guaranteed to be valid and is placed on an empty block.
- Once a winning condition is reached, no more moves are allowed.
- A player who succeeds in placing `n` of their marks in a horizontal, vertical, or diagonal row wins the game.

Implement the `TicTacToe` class:

- `TicTacToe(int n)` Initializes the object the size of the board `n`.
- `int move(int row, int col, int player)` Indicates that the player with id `player` plays at the cell `(row, col)` of the board. The move is guaranteed to be a valid move, and the two players alternate in making moves. Return

- `0` if there is **no winner**  after the move,
- `1` if **player 1**  is the winner after the move, or
- `2` if **player 2**  is the winner after the move.

**Example 1:**

```bash
Input

["TicTacToe", "move", "move", "move", "move", "move", "move", "move"]
[[3], [0, 0, 1], [0, 2, 2], [2, 2, 1], [1, 1, 2], [2, 0, 1], [1, 0, 2], [2, 1, 1]]
Output

[null, 0, 0, 0, 0, 0, 0, 1]

Explanation

TicTacToe ticTacToe = new TicTacToe(3);
Assume that player 1 is "X" and player 2 is "O" in the board.
ticTacToe.move(0, 0, 1); // return 0 (no one wins)
|X| | |
| | | |    // Player 1 makes a move at (0, 0).
| | | |

ticTacToe.move(0, 2, 2); // return 0 (no one wins)
|X| |O|
| | | |    // Player 2 makes a move at (0, 2).
| | | |

ticTacToe.move(2, 2, 1); // return 0 (no one wins)
|X| |O|
| | | |    // Player 1 makes a move at (2, 2).
| | |X|

ticTacToe.move(1, 1, 2); // return 0 (no one wins)
|X| |O|
| |O| |    // Player 2 makes a move at (1, 1).
| | |X|

ticTacToe.move(2, 0, 1); // return 0 (no one wins)
|X| |O|
| |O| |    // Player 1 makes a move at (2, 0).
|X| |X|

ticTacToe.move(1, 0, 2); // return 0 (no one wins)
|X| |O|
|O|O| |    // Player 2 makes a move at (1, 0).
|X| |X|

ticTacToe.move(2, 1, 1); // return 1(player 1 wins)
|X| |O|
|O|O| |    // Player 1 makes a move at (2, 1).
|X|X|X|
```

**Constraints:**

- `2 <= n <= 100`
- player is `1` or `2`.
- `0 <= row, col < n`
- `(row, col)` are **unique**  for each different call to `move`.
- At most `n^2` calls will be made to `move`.

**Follow-up:**  Could you do better than `O(n^2)` per `move()` operation?

## Hints/Notes

- 2025/01/20
- set
- premium

## Solution

Language: **C++**

```C++
class TicTacToe {
public:
    int diag1, diag2, n;
    vector<int> cols;
    vector<int> rows;
    TicTacToe(int n) {
        diag1 = diag2 = 0;
        this->n = n;
        cols.resize(n, 0);
        rows.resize(n, 0);
    }

    int move(int row, int col, int player) {
        int curPlayer = (player == 1) ? 1 : -1;
        if (row == col) {
            diag1 += curPlayer;
        }
        if (row + col == n - 1) {
            diag2 += curPlayer;
        }
        cols[col] += curPlayer;
        rows[row] += curPlayer;
        if (abs(diag1) == n || abs(diag2) == n ||
            abs(cols[col]) == n || abs(rows[row]) == n) {
            return player;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
```
