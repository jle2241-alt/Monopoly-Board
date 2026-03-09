# CS210 Programming Assignment
## Monopoly Board Simulator (Spring 2026)

Author: Jackson Le
DATA STRUCTURES USED

1.) MonopolySpace Class
A single space on the Board and stores:
-propertyName
-propertyColor
-value
-rent
Each of the space also includes 
-the a default constructor
-overloaded constructor
-isEqual() for comparing the properties from name
-print() for an output that is formatted


2.) Node<T> Template Class
Represent a node in the circular linked list.
Every node has
-t data
-Node<T>* nextNode

3.) CircularLinkedList<T> Template Class  
Represents the Monopoly Board using a circular linked list.

The board keeps track of:

-headNode  
-tailNode  
-playerNode  
-nodeCount  
-passGoCount

The list is circular, meaning:

-tailNode->nextNode = headNode

This allows the player to move continuously around the board without reaching nullptr.


CORE FUNCTIONS IMPLEMENTED

1.) addSpace(T value)  
Adds a single space to the board.

-enforces the MAX_SPACES limit (40)  
-creates a new node  
-links it at the tail  
-maintains circular structure  
-returns true if successful, false if full


2.) addMany(vector<T> values)  
Adds multiple spaces at once.

-calls addSpace for each element  
-stops exactly when the board reaches 40 spaces  
-returns the number successfully added  
-does not corrupt the circular structure


3.) movePlayer(int steps)  
Moves the player around the circular board.

-moves node-by-node using nextNode  
-wraps naturally because the list is circular  
-detects when moving from tailNode to headNode  
-increments passGoCount when GO is passed


4.) printFromPlayer(int count)  
Prints a fixed number of spaces starting from the player's position.

-uses controlled traversal  
-does not modify player position  
-prints exactly count nodes  
-prevents infinite looping


ADVANCED OPTION A FEATURES

1.) removeByName(string name)  
Deletes the first matching space by name.

-handles deleting the head node  
-handles deleting the tail node  
-handles deleting the only node  
-maintains circular integrity  
-updates playerNode if necessary  
-decrements nodeCount


2.) findByColor(string color)  
Finds all spaces matching a given color.

-traverses the ring exactly once using a do-while loop  
-compares propertyColor values  
-returns a vector<string> of matching property names  
-handles empty list safely


EDGE CASE FUNCTIONS

1.) countSpaces()  
Counts the number of spaces on the board.

-traverses exactly once  
-does not rely on nodeCount  
-returns 0 if board is empty


2.) clear()  
Deletes all nodes from the board.

-breaks the circular link first  
-deletes each node safely  
-resets headNode, tailNode, playerNode  
-resets nodeCount and passGoCount


TRAVERSAL AND MOVEMENT LOGIC

The board is treated as a ring, not an array.

Player movement works by:

-playerNode = playerNode->nextNode

Each step moves forward one node.

If the player is currently on tailNode and moves forward,  
they return to headNode and pass GO.

When this occurs:

-passGoCount is incremented


40-SPACE BOARD LIMIT

The board has a strict maximum of 40 spaces.

This is enforced in addSpace() by checking:

-if nodeCount == MAX_SPACES

Once 40 spaces are reached, no additional spaces can be added.

This guarantees the board never exceeds the Monopoly limit and prevents corruption of the circular structure.

EXTRAS: Board themed based on friend's names and interests.