# Autocomplete Engine in C++

##  Overview
This project implements a simple Autocomplete Engine using a Trie data structure.  
It allows insertion of words into a dictionary and provides suggestions based on a given prefix.

---

##  Features
- Efficient word storage using a Trie.
- Fast prefix-based search.
- Depth-first search (DFS) to collect all possible completions.
- Example dictionary included with words like `apple`, `application`, `banana`, `car`, etc.

---

##  How It Works
1. Insert words into the Trie using insert().
2. Search for suggestions with getSuggestions(prefix).
3. The engine traverses the Trie to the prefix node and performs DFS to collect all words starting with that prefix.

---

## 📊 Example Run

o/p: Enter prefix: 
i/p: app

Suggestions:
app
apple
application
apply
