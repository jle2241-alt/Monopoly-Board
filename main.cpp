#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

static const int MAX_SPACES = 40;

// -------------------------------
// Data class (NOT a struct)
// -------------------------------
class MonopolySpace {
public:
    string propertyName;
    string propertyColor;
    int value;
    int rent;

    MonopolySpace() {
        // DEFAULT CONSTRUCTOR
        propertyName = "";
        propertyColor = "";
        value = 0;
        rent = 0;
    }

    MonopolySpace(string propertyName, string propertyColor, int value, int rent) {
        // OVERLOAD CONSTRUCTOR
        this->propertyName =propertyName;
        this->propertyColor = propertyColor;
        this->rent = rent;
        this->value = value;
    }

    bool isEqual(MonopolySpace other) {
        return propertyName == other.propertyName;
    }

    void print() {
        cout << propertyName << " | " << propertyColor << " | $" << value << " | Rent " << rent;

    }
};

// -------------------------------
// Template Node class (NOT a struct)
// -------------------------------
template <typename T>
class Node {
public:
    T data;
    Node<T>* nextNode;

    Node(T value) {
        data = value;
        nextNode = nullptr;
    }
};

// -------------------------------
// Template Circular Linked List class
// Spring 2026 version: traversable board
// -------------------------------
template <typename T>
class CircularLinkedList {
private:
    Node<T>* headNode;
    Node<T>* tailNode;

    // player cursor for traversal-based gameplay
    Node<T>* playerNode;

    int nodeCount;
    int passGoCount;

public:
    CircularLinkedList() {
        headNode = nullptr;
        tailNode = nullptr;
        playerNode = nullptr;

        nodeCount = 0;
        passGoCount = 0;
    }

    // -------------------------------
    // Board Construction Policy (Reminder)
    // -------------------------------
    // Spaces are added during board construction BEFORE gameplay.
    // You choose how to construct the board:
    // - hardcode spaces, read from file, or generate programmatically
    // The only non-negotiable requirement:
    // - enforce MAX_SPACES
    // - maintain circular integrity
    // -------------------------------

    // -------------------------------
    // Core A: Add a Space with Capacity Enforcement
    // -------------------------------
    bool addSpace(T value) {
        if (nodeCount == MAX_SPACES) {
            return false;
        }
        Node<T>* newNode = new Node<T>(value);

        if (headNode == nullptr) {
            headNode =newNode;
            tailNode = newNode;
            playerNode = newNode;
            newNode->nextNode = headNode;
        }
        else {
            tailNode->nextNode = newNode;
            tailNode = newNode;
            newNode->nextNode = headNode;
        }
        nodeCount++;
        return true;

        // TODO:
        // - If nodeCount == MAX_SPACES return false (do not corrupt list)
        // - Create new node
        // - If empty list: head=tail=player=new, new->next=head
        // - Else: tail->next=new, tail=new, tail->next=head
        // - nodeCount++
        cout << "addSpace unwritten" << endl;
        return false;
    }

    // -------------------------------
    // Core B: Add Multiple Spaces at Once
    // -------------------------------
    int addMany(vector<T> values) {
        int added = 0;
        for (int i = 0; i< values.size(); i++) {
            if (addSpace(values[i])) {
                added++;
            } else {
                break;
            }
        }
        return added;
    }

        // -------------------------------
        // Core C: Traversal-Based Player Movement
        // -------------------------------
        void movePlayer(int steps) {
        if (playerNode == nullptr) {
            return;
        }

        for (int i = 0; i< steps; i++) {
            if (playerNode == tailNode) { //compares player position to tailNode to see if it is on TailN
                passGoCount++;
            }
            playerNode = playerNode->nextNode;
        }

        cout << endl;
    }

    int getPassGoCount() {
        return passGoCount;
    }

    // -------------------------------
    // Core D: Controlled Board Display
    // -------------------------------
    void printFromPlayer(int count) {
     if (playerNode == nullptr) {
         return;
     }
        Node<T>* currentNode = playerNode;

        for (int i = 0; i< count; i++) {
            currentNode->data.print();
            cout << endl;
            currentNode = currentNode->nextNode;    //move
        }

    }

    // Optional helper: print full board once (one full cycle)
    void printBoardOnce() {
        // TODO:
        // - Traverse exactly one full cycle and print each node
        cout << "printBoardOnce unwritten" << endl;
    }

    // -------------------------------
    // Advanced Option A (Level 1): removeByName
    // -------------------------------
    bool removeByName(string name) {
        // TODO:
        // - Delete FIRST matching node
        // - Must handle:
        //   - deleting head
        //   - deleting tail
        //   - deleting the only-node list
        // - Maintain circular link tail->next=head
        // - If playerNode points to deleted node, move playerNode to a safe node
        // - nodeCount--
        cout << "removeByName unwritten" << endl;
        return false;
    }

    // -------------------------------
    // Advanced Option A (Level 1): findByColor
    // -------------------------------
    vector<string> findByColor(string color) {
        vector<string> matches;

        if (headNode == nullptr) {
            return matches;
        }

        Node<T>* current =headNode;

        do {

            if (current->data.propertyColor == color) {
                matches.push_back(current->data.propertyName);
            }

            current = current->nextNode;
        } while (current!=headNode);

        return matches;
    }


    // -------------------------------
    // Advanced Option B (Level 2): Mirror the Board (Circular Reversal)
    // -------------------------------
    void mirrorBoard() {
        // TODO:
        // - Reverse the direction of the circular list by reversing next pointers
        // - Preserve circular structure
        // - Correctly handle empty list and single-node list
        // - Player cursor must remain on the same logical space after reversal
        cout << "mirrorBoard unwritten" << endl;
    }

    // -------------------------------
    // Edge-case helper: countSpaces O(n)
    // -------------------------------
    int countSpaces() {
        // TODO:
        // - Must be O(n), traverse exactly once with correct stop condition
        // - Do NOT rely on nodeCount for this method
        cout << "countSpaces unwritten" << endl;
        return 0;
    }

    // -------------------------------
    // Cleanup
    // -------------------------------
    void clear() {
        // TODO:
        // - Safely delete all nodes
        // - Tip: if tailNode exists, break the cycle first: tailNode->nextNode = nullptr
        // - Then delete like a normal singly linked list
        cout << "clear unwritten" << endl;
    }
};

// -------------------------------
// Main: playable loop demo
// -------------------------------
int rollDice2to12() {
    return (rand() % 6 + 1) + (rand() % 6 + 1);
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    CircularLinkedList<MonopolySpace> board;

    // -------------------------------
    // Board Construction Phase
    // -------------------------------
    // You decide how to build the board:
    // - hardcode spaces, load from file, or generate spaces programmatically
    // The only requirement: never exceed MAX_SPACES and keep the list circular.
    //
    // Example (hardcoded) usage:
    // vector<MonopolySpace> spaces;
    // spaces.push_back(MonopolySpace("GO","None",0,0));
    // ...
    // board.addMany(spaces);
    //
    // NOTE: This starter calls addSpace once to show the intended API,
    // but your final submission should build a meaningful board.
    vector<MonopolySpace> spaces;

    spaces.push_back(MonopolySpace("GO","None",0,0));

    spaces.push_back(MonopolySpace("Janson Gym", "Iron", 120, 12));
    spaces.push_back(MonopolySpace("Antonio Arena", "Gold", 130, 13));
    spaces.push_back(MonopolySpace("Wynn Woods", "Green", 135, 13));
    spaces.push_back(MonopolySpace("Humberto Heights", "Denim", 145, 14));
    spaces.push_back(MonopolySpace("Jackson Arena", "Royal", 350, 40));

    spaces.push_back(MonopolySpace("Bench Press Blvd", "Iron", 140, 14));
    spaces.push_back(MonopolySpace("Studio Street", "Gold", 150, 15));
    spaces.push_back(MonopolySpace("Emerald Estate", "Green", 155, 15));
    spaces.push_back(MonopolySpace("JNCO Junction", "Denim", 165, 16));
    spaces.push_back(MonopolySpace("Three Point Terrace", "Royal", 400, 45));

    spaces.push_back(MonopolySpace("Deadlift Drive", "Iron", 160, 16));
    spaces.push_back(MonopolySpace("Bassline Blvd", "Gold", 170, 17));
    spaces.push_back(MonopolySpace("Clover Court", "Green", 175, 17));
    spaces.push_back(MonopolySpace("Runway Road", "Denim", 185, 18));
    spaces.push_back(MonopolySpace("Slam Dunk Street", "Royal", 450, 50));

    spaces.push_back(MonopolySpace("Protein Shake Place", "Steel", 180, 18));
    spaces.push_back(MonopolySpace("Treble Terrace", "Silver", 190, 19));
    spaces.push_back(MonopolySpace("Pine Park", "Forest", 195, 19));
    spaces.push_back(MonopolySpace("Vintage Vogue", "Black", 205, 20));
    spaces.push_back(MonopolySpace("MVP Manor", "Royal", 500, 60));

    spaces.push_back(MonopolySpace("Leg Day Lane", "Steel", 200, 20));
    spaces.push_back(MonopolySpace("Rhythm Road", "Silver", 210, 21));
    spaces.push_back(MonopolySpace("Mint Meadows", "Forest", 215, 21));
    spaces.push_back(MonopolySpace("Designer Drive", "Black", 225, 22));
    spaces.push_back(MonopolySpace("Teddy Bear Tower", "Platinum", 550, 70));

    spaces.push_back(MonopolySpace("Cardio Court", "Steel", 220, 22));
    spaces.push_back(MonopolySpace("Melody Manor", "Silver", 230, 23));
    spaces.push_back(MonopolySpace("Olive Orchard", "Forest", 235, 23));
    spaces.push_back(MonopolySpace("Baggy Boulevard", "Black", 245, 24));
    spaces.push_back(MonopolySpace("Stuffed Animal Square", "Platinum", 600, 80));

    spaces.push_back(MonopolySpace("Dumbbell District", "Black", 240, 24));
    spaces.push_back(MonopolySpace("Encore Avenue", "Platinum", 250, 25));
    spaces.push_back(MonopolySpace("Lime Lane", "Jade", 255, 25));
    spaces.push_back(MonopolySpace("Streetwear Square", "Luxury", 265, 26));
    spaces.push_back(MonopolySpace("Championship Court", "Diamond", 700, 100));

    spaces.push_back(MonopolySpace("PR Parkway", "Black", 260, 26));
    spaces.push_back(MonopolySpace("Mixtape Mile", "Platinum", 270, 27));
    spaces.push_back(MonopolySpace("Evergreen Plaza", "Jade", 275, 27));
    spaces.push_back(MonopolySpace("High Fashion Hub", "Luxury", 285, 28));
    int added = board.addMany(spaces);
    cout<< "Added spaces:"<< added << endl;
    // -------------------------------
    // Playable Traversal Loop
    // -------------------------------
    for (int turn = 1; turn <= 10; turn++) {
        int roll = rollDice2to12();
        cout << "\nTurn " << turn << " | Rolled: " << roll << endl;

        board.movePlayer(roll);

        cout << "Board view from player (next 5 spaces):" << endl;
        board.printFromPlayer(5);

        cout << "Times passed GO so far: " << board.getPassGoCount() << endl;

        int added = board.addMany(spaces);
        cout << "Added spaces: " << added << endl;

        vector<string> blacks = board.findByColor("Black");
        cout << "\nfindByColor(\"Black\") returned " << blacks.size() << " matches:\n";
        for (string name : blacks) {
            cout << name << endl;
        }
        cout << endl;
        // -------------------------------
        // Advanced Feature Demos (students choose path)
        // -------------------------------
        // Option A examples:
        // boaaddrd.removeByName("Baltic Avenue");
        // vector<string> brownProps = board.findByColor("Brown");
    }//
}

