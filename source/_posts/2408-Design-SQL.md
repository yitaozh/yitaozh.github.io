---
title: 2408. Design SQL
categories: Leetcode
date: 2025-05-13 01:08:53
tags:
    - Array
    - Hash Table
    - String
    - Design
---

[2408. Design SQL](https://leetcode.com/problems/design-sql/description/?envType=company&envId=openai&favoriteSlug=openai-all)

## Description

You are given two string arrays, <code>names</code> and <code>columns</code>, both of size <code>n</code>. The <code>i^th</code> table is represented by the name <code>names[i]</code> and contains <code>columns[i]</code> number of columns.

You need to implement a class that supports the following **operations** :

- **Insert**  a row in a specific table with an id assigned using an auto-increment method, where the id of the first inserted row is 1, and the id of each new row inserted into the same table is **one greater**  than the id of the **last inserted**  row, even if the last row was removed.
- **Remove**  a row from a specific table. Removing a row **does not**  affect the id of the next inserted row.
- **Select**  a specific cell from any table and return its value.
- **Export**  all rows from any table in csv format.

Implement the <code>SQL</code> class:

- <code>SQL(String[] names, int[] columns)</code>

- Creates the <code>n</code> tables.

- <code>bool ins(String name, String[] row)</code>

- Inserts <code>row</code> into the table <code>name</code> and returns <code>true</code>.
- If <code>row.length</code> **does not**  match the expected number of columns, or <code>name</code> is **not**  a valid table, returns <code>false</code> without any insertion.

- <code>void rmv(String name, int rowId)</code>

- Removes the row <code>rowId</code> from the table <code>name</code>.
- If <code>name</code> is **not**  a valid table or there is no row with id <code>rowId</code>, no removal is performed.

- <code>String sel(String name, int rowId, int columnId)</code>

- Returns the value of the cell at the specified <code>rowId</code> and <code>columnId</code> in the table <code>name</code>.
- If <code>name</code> is **not**  a valid table, or the cell <code>(rowId, columnId)</code> is **invalid** , returns <code>"<null>"</code>.

- <code>String[] exp(String name)</code>

- Returns the rows present in the table <code>name</code>.
- If name is **not**  a valid table, returns an empty array. Each row is represented as a string, with each cell value (**including**  the row's id) separated by a <code>","</code>.

**Example 1:**

```bash
Input:

["SQL","ins","sel","ins","exp","rmv","sel","exp"]
[[["one","two","three"],[2,3,1]],["two",["first","second","third"]],["two",1,3],["two",["fourth","fifth","sixth"]],["two"],["two",1],["two",2,2],["two"]]

Output:

[null,true,"third",true,["1,first,second,third","2,fourth,fifth,sixth"],null,"fifth",["2,fourth,fifth,sixth"]]
```

Explanation:

// Creates three tables.
SQL sql = new SQL(["one", "two", "three"], [2, 3, 1]);

// Adds a row to the table "two" with id 1. Returns True.
sql.ins("two", ["first", "second", "third"]);

// Returns the value "third" from the third column
// in the row with id 1 of the table "two".
sql.sel("two", 1, 3);

// Adds another row to the table "two" with id 2. Returns True.
sql.ins("two", ["fourth", "fifth", "sixth"]);

// Exports the rows of the table "two".
// Currently, the table has 2 rows with ids 1 and 2.
sql.exp("two");

// Removes the first row of the table "two". Note that the second row
// will still have the id 2.
sql.rmv("two", 1);

// Returns the value "fifth" from the second column
// in the row with id 2 of the table "two".
sql.sel("two", 2, 2);

// Exports the rows of the table "two".
// Currently, the table has 1 row with id 2.
sql.exp("two");

**Example 2:**

```bash
Input:

["SQL","ins","sel","rmv","sel","ins","ins"]
[[["one","two","three"],[2,3,1]],["two",["first","second","third"]],["two",1,3],["two",1],["two",1,2],["two",["fourth","fifth"]],["two",["fourth","fifth","sixth"]]]

Output:

[null,true,"third",null,"<null>",false,true]
```

Explanation:

// Creates three tables.
SQL sQL = new SQL(["one", "two", "three"], [2, 3, 1]);

// Adds a row to the table "two" with id 1. Returns True.
sQL.ins("two", ["first", "second", "third"]);

// Returns the value "third" from the third column
// in the row with id 1 of the table "two".
sQL.sel("two", 1, 3);

// Removes the first row of the table "two".
sQL.rmv("two", 1);

// Returns "<null>" as the cell with id 1
// has been removed from table "two".
sQL.sel("two", 1, 2);

// Returns False as number of columns are not correct.
sQL.ins("two", ["fourth", "fifth"]);

// Adds a row to the table "two" with id 2. Returns True.
sQL.ins("two", ["fourth", "fifth", "sixth"]);

**Constraints:**

- <code>n == names.length == columns.length</code>
- <code>1 <= n <= 10^4</code>
- <code>1 <= names[i].length, row[i].length, name.length <= 10</code>
- <code>names[i]</code>, <code>row[i]</code>, and <code>name</code> consist only of lowercase English letters.
- <code>1 <= columns[i] <= 10</code>
- <code>1 <= row.length <= 10</code>
- All <code>names[i]</code> are **distinct** .
- At most <code>2000</code> calls will be made to <code>ins</code> and <code>rmv</code>.
- At most <code>10^4</code> calls will be made to <code>sel</code>.
- At most <code>500</code> calls will be made to <code>exp</code>.

**Follow-up:**  Which approach would you choose if the table might become sparse due to many deletions, and why? Consider the impact on memory usage and performance.

## Hints/Notes

- 2025/05/07 Q1
- Design
- No solution from 0x3F or Leetcode

## Solution

Language: **C++**

```C++
class SQL {
public:
    unordered_map<string, int> table2Cols;
    unordered_map<string, int> table2CurIdx;
    unordered_map<string, map<int, vector<string>>> table;

    SQL(vector<string>& names, vector<int>& columns) {
        int n = names.size();
        for (int i = 0; i < n; i++) {
            string& name = names[i];
            int& column = columns[i];
            table2Cols[name] = column;
        }
    }

    bool ins(string name, vector<string> row) {
        if (!table2Cols.contains(name) || table2Cols[name] != row.size()) {
            return false;
        }
        int rowId = ++table2CurIdx[name];
        table[name][rowId] = row;
        return true;
    }

    void rmv(string name, int rowId) {
        if (table2Cols.contains(name)) {
            table[name].erase(rowId);
        }
    }

    string sel(string name, int rowId, int columnId) {
        if (!table2Cols.contains(name) || table2Cols[name] < columnId || !table[name].contains(rowId)) {
            return "<null>";
        }
        return table[name][rowId][columnId - 1];
    }

    // unordered_map<string, map<int, vector<string>>> table;
    vector<string> exp(string name) {
        vector<string> res;
        for (auto [idx, v] : table[name]) {
            string cur = to_string(idx);
            for (string item : v) {
                cur.push_back(',');
                cur += item;
            }
            res.push_back(cur);
        }
        return res;
    }
};

/**
 * Your SQL object will be instantiated and called as such:
 * SQL* obj = new SQL(names, columns);
 * bool param_1 = obj->ins(name,row);
 * obj->rmv(name,rowId);
 * string param_3 = obj->sel(name,rowId,columnId);
 * vector<string> param_4 = obj->exp(name);
 */
```
