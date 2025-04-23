---
title: 2115. Find All Possible Recipes from Given Supplies
categories: Leetcode
date: 2025-04-23 01:20:02
tags:
    - Array
    - Hash Table
    - String
    - Graph
    - Topological Sort
---

[2115. Find All Possible Recipes from Given Supplies](https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/description/)

## Description

You have information about `n` different recipes. You are given a string array `recipes` and a 2D string array `ingredients`. The `i^th` recipe has the name `recipes[i]`, and you can **create**  it if you have **all**  the needed ingredients from `ingredients[i]`. A recipe can also be an ingredient for **other** recipes, i.e., `ingredients[i]` may contain a string that is in `recipes`.

You are also given a string array `supplies` containing all the ingredients that you initially have, and you have an infinite supply of all of them.

Return a list of all the recipes that you can create. You may return the answer in **any order** .

Note that two recipes may contain each other in their ingredients.

**Example 1:**

```bash
Input: recipes = ["bread"], ingredients = [["yeast","flour"]], supplies = ["yeast","flour","corn"]
Output: ["bread"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
```

**Example 2:**

```bash
Input: recipes = ["bread","sandwich"], ingredients = [["yeast","flour"],["bread","meat"]], supplies = ["yeast","flour","meat"]
Output: ["bread","sandwich"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".
```

**Example 3:**

```bash
Input: recipes = ["bread","sandwich","burger"], ingredients = [["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]], supplies = ["yeast","flour","meat"]
Output: ["bread","sandwich","burger"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".
We can create "burger" since we have the ingredient "meat" and can create the ingredients "bread" and "sandwich".
```

**Constraints:**

- `n == recipes.length == ingredients.length`
- `1 <= n <= 100`
- `1 <= ingredients[i].length, supplies.length <= 100`
- `1 <= recipes[i].length, ingredients[i][j].length, supplies[k].length <= 10`
- `recipes[i], ingredients[i][j]`, and `supplies[k]` consist only of lowercase English letters.
- All the values of `recipes` and `supplies`combined are unique.
- Each `ingredients[i]` does not contain any duplicate values.

## Hints/Notes

- 2025/04/21 Q2
- topological sort
- [Leetcode solution](https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    unordered_map<string, unordered_set<string>> graph;
    unordered_map<string, int> inDegree;
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        for (int i = 0; i < n; i++) {
            for (auto& ingredient : ingredients[i]) {
                inDegree[ingredient];
                inDegree[recipes[i]]++;
                graph[ingredient].insert(recipes[i]);
            }
        }
        unordered_set<string> canMake(supplies.begin(), supplies.end());
        queue<string> q;
        for (auto& [k, v] : inDegree) {
            if (canMake.contains(k)) {
                q.push(k);
            }
        }
        while (!q.empty()) {
            string ingredient = q.front();
            q.pop();
            for (auto recipe : graph[ingredient]) {
                if (!canMake.contains(recipe)) {
                    inDegree[recipe]--;
                    if (inDegree[recipe] == 0) {
                        canMake.insert(recipe);
                        q.push(recipe);
                    }
                }
            }
        }
        vector<string> res;
        for (auto& r : recipes) {
            if (canMake.contains(r)) {
                res.push_back(r);
            }
        }
        return res;
    }
};
```
