## **Question 1: Binary Tree Traversals, Insertion, and Removal**

Write a complete C program that:

1. **Defines** a binary tree node (`struct Node`) with integer data and left/right pointers.

2. **Implements** the following functions:
   - `createNode(int data)` — Allocates and returns a new node.  
   - `insertLeft(struct Node* parent, int data)` — Inserts a new node as the **left child** of the given parent.  
   - `insertRight(struct Node* parent, int data)` — Inserts a new node as the **right child** of the given parent.  
   - `deleteTree(struct Node* root)` — Recursively frees all nodes in the tree.  

3. **Manually builds** the following binary tree in `main` using the insertion functions:

       1
      / \
     2   3
    / \   \
   4   5   6


4. **Implements the following traversal functions:**
- `preorderTraversal()` — Root → Left → Right  
- `inorderTraversal()` — Left → Root → Right  
- `postorderTraversal()` — Left → Right → Root  
5. **Prints** the output of each traversal, clearly labeled.

6. **Demonstrates** tree removal by calling `deleteTree(root)` at the end and confirming memory cleanup (e.g., printing a message).

---

### **Expected Output**
Preorder: 1 2 4 5 3 6
Inorder: 4 2 5 1 3 6
Postorder: 4 5 2 6 3 1
Tree deleted successfully.