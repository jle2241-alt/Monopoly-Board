# Developer Log (DEVLOG.md)
## Monopoly Board Simulator (Spring 2026)

Minimum **6 entries** required.

Each entry must document learning and reasoning. Fabricated bugs are not expected.

---

## Allowed Entry Types
Each entry may be one of the following:

1) **Bug Fix Entry**
- The issue encountered.
- Error messages or symptoms.
- Attempts made.
- Final resolution.

2) **Edge Case / Testing Entry**
- A failure discovered through testing.
- The specific input/state that caused it.
- The change you made to handle it correctly.

3) **Engineering Decision Entry (up to 2 allowed)**
- A design decision you made.
- An alternative approach you considered.
- Why you chose one approach over another (tradeoffs).

---

### Entry 1
**Date:** 2026-3-6
**Entry Type:**  Engineering Decision  
**Task worked on:** CORE A 
**Issue or decision:**  I made the decision to test CORE A addSpace after finishing it to avoid
problems moving forward.
**Error message / symptom (if applicable):**  
**What I tried:**  I ran the code and fixed brace structure.
**Fix / resolution (or final decision):**  
**Commit(s):** Core A completion and Test run


---

### Entry 2
**Date:** 2026/03/7  
**Entry Type:** Bug Fix
**Task worked on:CORE B's addMany 
**Issue or decision: The function was not allowed before '{'
**Error message / symptom (if applicable):**  The compiler indicated that movePlayer was being defined inside addMany.
**What I tried:**  I looked over the indentation and the logic, Looking over the code again in addMany.
**Fix / resolution (or final decision):**  I ended up discovering that I was missing a closing brace, which
caused functions to be nested incorrectly.
**Commit(s):**

---

### Entry 3
**Date:** 2026-03-7 
**Entry Type:** Edge Case  
**Task worked on:**  Core C- movePlayer
**Issue or decision:**  Determining when to increment passGoCount.
**Error message / symptom (if applicable):** passGoCount increased incorrectly when checking after movement.  
**What I tried:** Initially checked for GO when done updating the player position. 
**Fix / resolution (or final decision):** Moved the condition check to occur before updating playerNode.
Correctly detecting passing GO when the playerNode == tailNode, before ofcourse getting to headNode.
**Commit(s):**

---

### Entry 4
**Date:** 2026-03-08  
**Entry Type:** Bug Fix 
**Task worked on:** Core D - printFromPlayer 
**Issue or decision:**  Compiler error cause by defining a function inside another function.
**Error message / symptom (if applicable):** Red underline and compliation failure when I tried defining printCurrentSpace() inside printFromPlayer()
**What I tried:** Looked at syntax and indentation, at first was unsure why function did not work. 
**Fix / resolution (or final decision):**  C++ does not allow function definitions in nested. So I had to move CurrentSpace() outside of printFRomPlayer() but still inside class.
**Commit(s):**

---

### Entry 5
**Date:** 2026-3-8  
**Entry Type:** Engineering Decision  
**Task worked on:**  Constructing the Board
**Issue or decision:**  Choosing to max the board's 40 space capacity
**Error message / symptom (if applicable):**  
**What I tried:**  I generated 39 spaces with them being themed from by friend's interests, since, GO already exists
**Fix / resolution (or final decision):**  Decided to create a custom themed board using a combination of manual insertion and structured ordering, while ensuring exactly 40 spaces were added via addMany.
**Commit(s):**

---

### Entry 6
**Date:**  2026-08-03
**Entry Type:** Edge Case 
**Task worked on:** clear() and memory  
**Issue or decision:**  Taking care of delition in the circular linked list and having it not cause infinite loops
**Error message / symptom (if applicable):**  Did not want it to loop infinitly
**What I tried:**  Considered using a standard while loop without modifying the circular structure.
**Fix / resolution (or final decision):**  I added a deletion process which separates the link (tailNode->nextNode = nullptr), then deleting the nodes
like a normal linked list. Than to reset all pointers and counters.
**Commit(s):**  
