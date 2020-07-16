This was a computer science 1 assignment that had to demonstrate my capability to write and utilize a Binary Search Tree:


Problem:

In this assignment, you have to read a text file (in.txt) that contains a set of words. The first line
of the file contains 3 numbers (N, S, D). These numbers represent the sequence of input words in
your file.

N: represents the number of words to read to build binary search tree. You have to write a
recursive insert code to create and insert these words into the binary search tree. After inserting
all the items, you should show the words in Pre order, In order, and Post order. So, you need to
create three functions for this purpose.

S: represents the number of the words to search from the tree. These S words are placed after the
first N words in the input file.You need to implement a search function that will be able to search
these words in your BST. 

D: represents the number of words to be deleted from the BST. This list of words are placed after
N+S words in the input file. Write a recursive delete function for your task. After deleting all the
items, also show the tree in only in-order traversal.

Other required functions: In addition to the general functions for the above tasks, your code
should also contain the following functions.

totalCharacters(treeNode* root): This function takes the root of the tree in parameter and
returns the total number of characters in the whole Binary Search Tree. You need to call this
function after creating the tree and also at the end of deleting the requested nodes from the tree.

isBalanced(treeNode* root): We call the tree as imbalanced if the differences between the
height of left subtree and height of right subtree is more than one. This function takes the root
of the tree in parameter and returns 1 if the tree is balanced, otherwise it returns 0. In this
process, you might consider implementing a height function to get the height of a subtree. The
isBalanced function should be called after creating the tree.

All the output must be written to the out.txt file according the sample output shown bellow. You
may output in the console, however, we will mainly see the out.txt file for our given input file.
Do not hardcode your code only for the example provided below. If we see you have hard-coded
any output, you will get zero for your full assignment submission.

[SEE EXAMPLE PNGS]