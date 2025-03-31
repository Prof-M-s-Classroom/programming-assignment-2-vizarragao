[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/jIKk4bke)
# CS210 Data Structures SP25
## Programming Assignment 2: Text-Based RPG Using Decision Trees

### **Student Name:** `[Omar Vizarraga]`  
### **Student ID:** `[820622433]`  

---

## **1. Project Overview**
(Provide a brief summary of your RPG game. Describe how it uses a decision tree and how the player interacts with it.)

Example:
> This project implements a text-based RPG using a **binary decision tree**. Each game event is represented as a node, and the player progresses by choosing between two paths at each stage. The storyline is loaded from an external text file (`story.txt`), which is parsed to construct the decision tree. The game ends when a leaf node (with `-1` as left and right children) is reached.
> 
    This program will run a text based RPG game. The program takes a filename from the user and uses it to read and store
>   The contents of each line into a Story object that will then be stored as a node and added into a binary tree.
>   The player will then be presented with the first event which will be followed by two other events that the player can choose from.
>   The player must choose one of the two event numbers presented or the program will output an invalid input text and prompt
>   the user to try again until they input a valid input. The program will run until there are no more possible outcomes for the path chosen.
>   The path chosen is dependent on the input values that the player chooses.
---

## **2. Folder & File Structure**
(Explain the role of each file in your project.)

- **`main.cpp`** → `[Describe its function]`  
  - The main cpp file will instantiate a GameDecision object. It will then call the loadStoryFromFile method which will
  - take two parameter inputs one will be the filename variable and the second will be the delimiter used in the file.
  - This will then load the contents of the file and build a binary decision tree out of it.
  - The file will then call a method that initiates the game and will begin outputting the story text
  - and the two choices for possible paths to take. Player will then input an event number associated
  - with one of the two paths to get to the next choices.
  - 
- **`GameDecisionTree.h`** → `[Explain what this file contains]`  
  - This file contains all the methods needed to construct the text based RPG.
  - There are the two main methods that are directly called in the main file and then there are other methods
  - that are used by these two main methods to help construct and execute the decision binary tree.
  - 
- **`Node.h`** → `[Explain what this file contains]`  
- This file contains the template and constructor for creating a node.
- 
- **`Story.h`** → `[Explain what this file contains]`  
- This file contains the variables associated with a Story object and creates the class. It
- also contains the types of constructors that the story class can have.
- 
- **`story.txt`** → `[Explain how the game loads story events from this file]`  
- The game loads story events into a binary tree from this file by reading it and storing its content into Story
- objects line by line. Each line is parsed using a string stream and each section of the string
- is seperated by a delimiter and after that section is parsed it's put it is assigned to a variable. Once
- all the variables are set, a Story object is created using those variables. The Story object is
- then created into a node and added to the binary tree. This is repeated for all of the
- story.txt's file lines.

---

## **3. Decision Tree Construction**
(Explain how the decision tree is built from the `story.txt` file.)

- How are `Story` objects created from the text file?  
    Story objects are created by opening the story.txt file and reading in the file 
    line by line. The lines are parsed using a string stream. Each line has delimiters seperating
    the content of the line. Each time the getline() command is called it will take that content up
    to the delimiter point and store it into a variable that will be needed to create the Story object.

- How are nodes linked based on left and right event numbers?  
    Nodes are linked depending on what the left or event number is. Each node in the binary decision
    tree has a 

- What happens if an event has `-1` as left or right children?  
    This means that there is not further option or choice to go from that eventNumber side.
    For example if a node has a leftEventNumber of -1, then there won't be an option to choose an event
    in that direction. However, the rightEventNumber could still have a path option.

---

## **4. Game Traversal**
(Describe how the game moves through the decision tree.)

- How does user input determine the path taken?  
    The user will be given two path choices from the beginning of the game. The user will be able
    to input a evenNumber associated with the text that they would like to follow. The program will
    output an invalid input text if the input is neither of the two choices shown previously. The user
    will then have the opportunity to choose a path again.
- What happens when the player reaches a leaf node?  
    When a player chooses a leaf node they will receive an exit text telling them that the game has ended.
- Explain the special case where multiple events lead to the same outcome.  
    I wasn't able to implement this into my text based RPG program.

---

## **5. File Parsing & Data Loading**
(Explain the process of reading `story.txt` and constructing the decision tree.)

- How is the file read and parsed using a delimiter?
    The file is read line by line. The lines are parsed using a string stream after getting the line 
    that will be parsed. Each line has delimiters separating the content of the line. Each time the 
    getline() command is called it will take that content up to the delimiter point and store it into 
    a variable that will be needed to create the Story object. Once the Story object is created, an
    addStoryNode() function will be called where the parameter will be the Story object. It will then 
    become a node and be added to the binary decision tree.

- How do you ensure nodes are properly linked?  
    I hard coded the way the decision tree should be built. So I had a case for each possible eventNumber
    up to 16. There is a flaw to this though. In the case that there is an eventNumber that has a preceding node
    that doesn't exist, it will likely make the program fail. However, I figured if the story text file needs to be
    formatted in a certain way in order to work, then the possible story events should be formated in a way where 
    they have the correct preceding nodes and don't jump over any binary tree levels.
    
- Any challenges faced while handling file input?  
    I struggled with inputting the file quite a bit. I wasn't aware of using a string stream to parse each line 
    for a while. I was trying to parse the file lines into separate values but wasn't having any luck. After
    learning about string steams though, I was able to use the getline() command to store that line into a string.
    Then converting that string into a string stream that would be parsed and seperated and stored into variables
    to create the story object for that line.
---

## **6. Debugging Process (Errors & Fixes)**
(Describe one or more debugging challenges you faced and how you fixed them.)

Example: (accidentally deleted example)
    
    Initially, my program was crashing when trying to access an uninitialized node. I realized it was because I was not properly checking for `nullptr` before accessing child nodes, so I added a check to prevent accessing uninitialized memory.
    I was getting a Sigsegv error when I was creating the playGame() method because it was trying to access a node
    that hadn't been created. I realized that in my addStoryNode method I hadn't handled a case where the event number
    would be greater than 6. I fixed it by adding an if statement that handled an input of 7 as the new eventNumber
    and it ended up working.

    Like I had said previously in one of the question answers, I struggled with inputting the file for a while. After
    learning about string streams and how I could use them to parse a line it made it a lot easier to sepearte the different
    sections of each line into seperate values to store them into variables that would be used to create Story objects.

    I also struggled with how to create the binary tree without hard coding it. I ended up just hardcoding it because
    it worked but I feel like there is a easier way to do it.

---

## **7. Sample Output & Walkthrough**
(Provide an example of how the game runs, including player input.)

Sample Output (inputs were 2, 4, 8, and n)

    /Users/vizarraga/Desktop/programming-assignment-2-vizarragao/cmake-build-debug/CS210PA2
    Welcome to my adventure fellow programmer!

    1  You're on the Titanic as it's sinking
    What do you do?
    2  Jump off the ship
    Or
    3  Stay on the ship
    2
    What do you do?
    4  Swim towards a floating door
    Or
    5  Take your chances and just keep swimming
    4
    What do you do?
    8  Get on the door
    Or
    9  Admire the craftsmanship of the door -=but stay in the water and keep swimming
    8
    16  You are on the door and wait for help

    You have determined your ending! Good Job!
    Do you want to play again?(y/n)
    n
    Until next Time

    Process finished with exit code 0

---

## **8. Big-O Analysis of Core Methods**
(Analyze the complexity of key methods.)

- **Loading the tree from the file** → `O(?)`  
    O(n). The while loop that reads each line of the file will run n times
    depending on the amount of lines that are inserted into the file.

  - **Searching for an event in the tree** → `O(?)`
    O(logn). Depending on the event when searching the tree will travered in one of two ways
    on every level of the bianry tree making its search time O(log n). 
    
- **Game traversal efficiency** → `O(?)`  
    O(logn). Just like searching, the amount of nodes that will be traversed is split into two
    on each level so it doesn't have to go through every node. This makes the traversal 
    efficiemcy O(logn).

---

## **9. Edge Cases & Testing**
(Describe at least one edge case you tested and its outcome.)

Example:
> I tested a scenario where the player reaches a dead-end (leaf node) and ensured the program correctly ends the game.
    I tested the 5 possible paths for my binary tree. Since I hard coded my binary tree traversal method to 
    play the game, I tried all five possible paths: 
    1->2->4->8->16
    1->2->4->9
    1->2->5
    1->3->6
    1->3->7
    I made sure each path ended with the last eventDescription of the eventNumber that they chose or could choose. If there was
    only one eventDescription after their choice, the program would return that single node eventDescription.
---

## **10. Justification of Additional Features (If Any)**
(If you added extra features, describe them and explain why.)

Example:
> I added a **save/load feature** so players can resume the game later. This was done by writing the current node’s event number to a file and reading it when restarting.
    I added a playAgain() method that is called at the end of the playGame() method. This method
    asks the player if they'd like to play the game again and can input a "y" or "n." If the input is
    something else, then the playagain() method is called again recursively with an additional message telling the
    player to try again. If the input is a "y" then game will restart and a message to encourage the user to try out a
    different path is presented and the game restarts. I added this method so the player can see what other
    possible outcomes he could have had if he chose a different path.
---

## **Final Notes**
- **README is mandatory** → `(-10 points deduction if missing).`  
- **Code must compile and run** → `(Code that does not run will receive a 0).`  
- **Do not modify provided skeleton code** → `(You may only add to it).`  

---
