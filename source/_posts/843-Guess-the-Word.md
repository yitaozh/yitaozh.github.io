---
title: 843. Guess the Word
categories: Leetcode
date: 2025-03-31 13:11:34
tags:
    - Array
    - Math
    - String
    - Interactive
    - Game Theory
---

[843. Guess the Word](https://leetcode.com/problems/guess-the-word/description/)

## Description

You are given an array of unique strings `words` where `words[i]` is six letters long. One word of `words` was chosen as a secret word.

You are also given the helper object `Master`. You may call `Master.guess(word)` where `word` is a six-letter-long string, and it must be from `words`. `Master.guess(word)` returns:

- `-1` if `word` is not from `words`, or
- an integer representing the number of exact matches (value and position) of your guess to the secret word.

There is a parameter `allowedGuesses` for each test case where `allowedGuesses` is the maximum number of times you can call `Master.guess(word)`.

For each test case, you should call `Master.guess` with the secret word without exceeding the maximum number of allowed guesses. You will get:

- **`"Either you took too many guesses, or you did not find the secret word."`**  if you called `Master.guess` more than `allowedGuesses` times or if you did not call `Master.guess` with the secret word, or
- **`"You guessed the secret word correctly."`**  if you called `Master.guess` with the secret word with the number of calls to `Master.guess` less than or equal to `allowedGuesses`.

The test cases are generated such that you can guess the secret word with a reasonable strategy (other than using the bruteforce method).

**Example 1:**

```bash
Input: secret = "acckzz", words = ["acckzz","ccbazz","eiowzz","abcczz"], allowedGuesses = 10
Output: You guessed the secret word correctly.
Explanation:
master.guess("aaaaaa") returns -1, because "aaaaaa" is not in wordlist.
master.guess("acckzz") returns 6, because "acckzz" is secret and has all 6 matches.
master.guess("ccbazz") returns 3, because "ccbazz" has 3 matches.
master.guess("eiowzz") returns 2, because "eiowzz" has 2 matches.
master.guess("abcczz") returns 4, because "abcczz" has 4 matches.
We made 5 calls to master.guess, and one of them was the secret, so we pass the test case.
```

**Example 2:**

```bash
Input: secret = "hamada", words = ["hamada","khaled"], allowedGuesses = 10
Output: You guessed the secret word correctly.
Explanation: Since there are two words, you can guess both.
```

**Constraints:**

- `1 <= words.length <= 100`
- `words[i].length == 6`
- `words[i]` consist of lowercase English letters.
- All the strings of `wordlist` are **unique** .
- `secret` exists in `words`.
- `10 <= allowedGuesses <= 30`

## Hints/Notes

- 2025/03/27 Q2
- string
- [Good solution](https://leetcode.com/problems/guess-the-word/solutions/556075/how-to-explain-to-interviewer-843-guess-the-word/)

## Solution

Language: **C++**

```C++
/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& words, Master& master) {
        int matches = 0;
        while (matches != 6) {
            int n = words.size();
            unordered_map<string, int> count;
            for (string w1 : words) {
                for (string w2 : words) {
                    if (getMatches(w1, w2) == 0) {
                        count[w1]++;
                    }
                }
            }
            int minZero = 1000; string guess = words[0];
            for (string w : words) {
                if (count[w] <= minZero) {
                    minZero = count[w];
                    guess = w;
                }
            }
            matches = master.guess(guess);
            vector<string> candidates;
            for (auto& word : words) {
                if (matches == getMatches(guess, word)) {
                    candidates.push_back(word);
                }
            }
            words = candidates;
        }
    }

    int getMatches(string w1, string w2) {
        int matches = 0;
        for (int i = 0; i < 6; i++) {
            if (w1[i] == w2[i]) {
                matches++;
            }
        }
        return matches;
    }
};
```
