# Question 2: Detect and Remove a Cycle in a Linked List

Write a complete program that:

**1)** Defines a singly linked list node (struct Node).

**2)** Implements a function insertEnd to add new nodes to the list.

**3)** Implements a function createCycle that artificially creates a cycle in the list (e.g., last node points back to a middle node).

**4)** Implements a function detectCycle using Floyd’s cycle detection algorithm (tortoise & hare).

**5)** Implements a function removeCycle that, if a cycle exists, breaks it and restores the list to a proper linear structure.

**6)** In main, build a list with the numbers 1 → 2 → 3 → 4 → 5, create a cycle (5 points back to 3), detect the cycle, remove it, and finally print the corrected list.

---
