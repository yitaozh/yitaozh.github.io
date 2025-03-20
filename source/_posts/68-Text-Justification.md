---
title: 68. Text Justification
categories: Leetcode
date: 2025-03-19 21:51:20
tags:
    - Array
    - String
    - Simulation
---

[68. Text Justification](https://leetcode.com/problems/text-justification/description/)

## Description

Given an array of strings `words` and a width `maxWidth`, format the text such that each line has exactly `maxWidth` characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces `' '` when necessary so that each line has exactly `maxWidth` characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left-justified, and no extra space is inserted between words.

**Note:**

- A word is defined as a character sequence consisting of non-space characters only.
- Each word's length is guaranteed to be greater than `0` and not exceed `maxWidth`.
- The input array `words` contains at least one word.

**Example 1:**

```bash
Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
Output:
[
 "This  is  an",
 "example of text",
 "justification. "
]
```

**Example 2:**

```bash
Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
Output:
[
 "What  must  be",
 "acknowledgment ",
 "shall be    "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
Note that the second line is also left-justified because it contains only one word.
```

**Example 3:**

```bash
Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
Output:
[
 "Science is what we",
  "understand   well",
 "enough to explain to",
 "a computer. Art is",
 "everything else we",
 "do         "
]
```

**Constraints:**

- `1 <= words.length <= 300`
- `1 <= words[i].length <= 20`
- `words[i]` consists of only English letters and symbols.
- `1 <= maxWidth <= 100`
- `words[i].length <= maxWidth`

## Hints/Notes

- 2025/02/22 Q3
- simulation
- [Leetcode solution](https://leetcode.com/problems/text-justification/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        vector<string> wordsInCurLine;
        int curWordsLen = 0;
        for (auto& word : words) {
            if (wordsInCurLine.size() + curWordsLen + word.size() > maxWidth) {
                // this is the case we need to construct one line
                if (wordsInCurLine.size() == 1) {
                    string line = wordsInCurLine[0] + string(maxWidth - curWordsLen, ' ');
                    res.push_back(line);
                } else {
                    int numOfSpace = maxWidth - curWordsLen;
                    int avgLen = numOfSpace / (wordsInCurLine.size() - 1);
                    int remain = numOfSpace % (wordsInCurLine.size() - 1);
                    string line;
                    for (int i = 0; i < wordsInCurLine.size() - 1; i++) {
                        line += wordsInCurLine[i];
                        line += string(avgLen + (remain-- > 0), ' ');
                    }
                    line += wordsInCurLine.back();
                    res.push_back(line);
                }
                curWordsLen = 0;
                wordsInCurLine.clear();
            }
            curWordsLen += word.size();
            wordsInCurLine.push_back(word);
        }
        if (wordsInCurLine.size()) {
            string line;
            for (int i = 0; i < wordsInCurLine.size() - 1; i++) {
                line += wordsInCurLine[i];
                line += " ";
            }
            line += wordsInCurLine.back();
            line += string(maxWidth - line.size(), ' ');
            res.push_back(line);
        }
        return res;
    }
};
```
