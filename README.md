# DSA-Final-Project

Overview of the Project:
This C++ program implements a Binary Tree, Binary Search Tree (BST)
along with Max Heap and Min Heap data structures. The program
allows users to interact with these structures through a simple menu
interface, where they can perform common operations such as insertion,
search, traversal, and deletion.


How to run the code:


Initialization:

• The program first prompts the user to enter the number of elements they want to insert into the BST and heaps.

• It then takes input for these elements and inserts them into both them BST and the heaps.


Displaying Initial Heaps:

• After inserting the elements, it displays the current state of the Max Heap and Min Heap.
Menu Operations:

• The user is presented with a menu to perform operations. Formexample, they can select to perform an inorder traversal of the BST:


Search and Delete Operations:

• The user can search for a key or delete a key from the BST. Aftermdeletion, the program updates the BST and displays the relevant traversal.

• The user can also delete a key and observe the changes in the tree or heap.

Exit:

• The user selects option "9" to exit the program, and the program terminates.


Description of each functionality:


1. Binary Search Tree (BST)

• Structure: The BST is a tree where each node has a key, a pointer to the left child, and a pointer to the right child. It follows the property that:

o Left child values are smaller than the parent node.

o Right child values are greater than the parent node.


• Operations:

o Insert: Inserts a new value in the appropriate position in the tree, maintaining the BST property.

o Search: Searches for a specific value in the tree. It returns whether the value exists in the tree or not.

o Delete: Deletes a node from the tree. It handles three cases:

1. Node has no children (leaf node).

2. Node has one child.

3. Node has two children (replaces node with the smallest value in the right subtree).


o Traversal: The program supports three types of traversal:

▪ Inorder: Left subtree → Node → Right subtree (used to display the tree in sorted order).

▪ Preorder: Node → Left subtree → Right subtree.

▪ Postorder: Left subtree → Right subtree → Node.

2. Heaps (Max Heap and Min Heap)

• Max Heap: The value of each parent node is greater than or equal to its children. This is used when we need quick access to themlargest element.

• Min Heap: The value of each parent node is less than or equal to its children. This is used when we need quick access to thesmallest element.


• Heap Operations:

o Insert: Inserts a new element while maintaining the heap property (Max Heap or Min Heap). This is done by "heapifying" the tree starting from the newly inserted node to ensure that the heap property is satisfied.


o Heapify: A helper function that moves a node upwards in the heap until the heap property is maintained.

• Heap Display: The program provides the ability to print both Max Heap and Min Heap.


3. Program Flow

  • Input and Initialization:
    
  o First, the program asks the user for a number of elements to insert into the Binary Search Tree (BST).
   
  o The user enters the elements, which are then inserted into the BST.
    
  o Afterward, the program inserts the same elements into both the Max Heap and Min Heap.
  
  • Operations Menu: After the initial setup, the program enters a loop where the user enters the desired number of elements and the size of each element
