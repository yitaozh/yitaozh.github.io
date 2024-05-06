---
title: 353. Design Snake Game
categories: Leetcode
date: 2023-12-27 21:40:46
tags:
    - Array
    - Hash Table
    - Design
    - Queue
    - Simulation
---

[353\. Design Snake Game](https://leetcode.com/problems/design-snake-game/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Hash Table](https://leetcode.com/tag/https://leetcode.com/tag/hash-table//), [Design](https://leetcode.com/tag/https://leetcode.com/tag/design//), [Queue](https://leetcode.com/tag/https://leetcode.com/tag/queue//), [Simulation](https://leetcode.com/tag/https://leetcode.com/tag/simulation//)

Design a [Snake game](https://en.wikipedia.org/wiki/Snake_(video_game)) that is played on a device with screen size `height x width`. [Play the game online](http://patorjk.com/games/snake/) if you are not familiar with the game.

The snake is initially positioned at the top left corner `(0, 0)` with a length of `1` unit.

You are given an array `food` where food[i] = (r<sub>i</sub>, c<sub>i</sub>) is the row and column position of a piece of food that the snake can eat. When a snake eats a piece of food, its length and the game's score both increase by `1`.

Each piece of food appears one by one on the screen, meaning the second piece of food will not appear until the snake eats the first piece of food.

When a piece of food appears on the screen, it is **guaranteed** that it will not appear on a block occupied by the snake.

The game is over if the snake goes out of bounds (hits a wall) or if its head occupies a space that its body occupies **after** moving (i.e. a snake of length 4 cannot run into itself).

Implement the `SnakeGame` class:

* `SnakeGame(int width, int height, int[][] food)` Initializes the object with a screen of size `height x width` and the positions of the `food`.
* `int move(String direction)` Returns the score of the game after applying one `direction` move by the snake. If the game is over, return `-1`.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/01/13/snake.jpg)

```bash
Input
["SnakeGame", "move", "move", "move", "move", "move", "move"]
[[3, 2, [[1, 2], [0, 1]]], ["R"], ["D"], ["R"], ["U"], ["L"], ["U"]]
Output
[null, 0, 0, 1, 1, 2, -1]

Explanation
SnakeGame snakeGame = new SnakeGame(3, 2, [[1, 2], [0, 1]]);
snakeGame.move("R"); // return 0
snakeGame.move("D"); // return 0
snakeGame.move("R"); // return 1, snake eats the first piece of food. The second piece of food appears at (0, 1).
snakeGame.move("U"); // return 1
snakeGame.move("L"); // return 2, snake eats the second food. No more food appears.
snakeGame.move("U"); // return -1, game over because snake collides with border
```

**Constraints:**

* 1 <= width, height <= 10<sup>4</sup>
* `1 <= food.length <= 50`
* `food[i].length == 2`
* 0 <= r<sub>i</sub> < height
* 0 <= c<sub>i</sub> < width
* `direction.length == 1`
* `direction` is `'U'`, `'D'`, `'L'`, or `'R'`.
* At most 10<sup>4</sup> calls will be made to `move`.

## Hints/Notes

* use a queue + set to record where the head/tail is and if one node is in the snake
* remove the previous tail first before checking if the snake is hitting itself

## Solution

Language: **C++**

```C++
class SnakeGame {
public:
    int width_;
    int height_;
    queue<int> foods;
    queue<int> body;
    set<int> s;
    bool finished;

    SnakeGame(int width, int height, vector<vector<int>>& food) {
        width_ = width;
        height_ = height;
        for (auto f : food) {
            int row = f[0];
            int col = f[1];
            foods.push(encode(row, col));
        }
        body.push(encode(0, 0));
        s.insert(encode(0, 0));
        finished = false;
    }

    int move(string direction) {
        if (finished) {
            return -1;
        }
        int r = body.back() / width_;
        int c = body.back() % width_;
        char d = direction[0];
        switch (d) {
            case 'D':
                r++;
                break;
            case 'U':
                r--;
                break;
            case 'L':
                c--;
                break;
            case 'R':
                c++;
                break;
        }
        int val = encode(r, c);
        if (!foods.empty() && val == foods.front()) {
            foods.pop();
        } else {
            int tail = body.front();
            body.pop();
            s.erase(tail);
        }
        if (r < 0 || r >= height_ || c < 0 || c >= width_ || s.count(val)) {
            cout << r << " " << c << " " << val << endl;
            finished = true;
            return -1;
        }
        cout << "val: " << val << endl;
        s.insert(val);
        body.push(val);
        return s.size() - 1;
    }

    int encode(int row, int col) {
        return row * width_ + col;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
```
