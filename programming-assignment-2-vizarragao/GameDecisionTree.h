#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Node.h"
#include "Story.h"

using namespace std;

template <typename T>
class GameDecisionTree {
private:
    int length = 0;     //Counts the amount of nodes in the tree
    Node<T>* root;      //Creates a root for the binary tree


public:
    // TODO: Constructor
    GameDecisionTree() : root(nullptr) {

    }

    //This method will add and create a node from the Story object
    //Then it will place it into the binary tree at the correct position
    //Hard coded to work up to 16 nodes
    void addStoryNode(T value) {
        Node<T> *newNode = new Node<T>(value);
        Node<T> *temp = root;
        if (root == nullptr) {
            root = newNode;
        }

        else {

            if (newNode->data.eventNumber == 2) {
                temp->left = newNode;
            }

            if (newNode->data.eventNumber == 3) {
                temp->right = newNode;
            }
            if (newNode->data.eventNumber == 4) {
                temp->left->left = newNode;
            }
            if (newNode->data.eventNumber == 5) {
                temp->left->right = newNode;
            }
            if (newNode->data.eventNumber == 6) {
                temp->right->left = newNode;
            }
            if (newNode->data.eventNumber == 7) {
                temp->right->right = newNode;
            }
            if (newNode->data.eventNumber == 8) {
                temp->left->left->left = newNode;
            }
            if (newNode->data.eventNumber == 9) {
                temp->left->left->right = newNode;
            }
            if (newNode->data.eventNumber == 10) {
                temp->left->right->left = newNode;
            }
            if (newNode->data.eventNumber == 11) {
                temp->left->right->right = newNode;
            }
            if (newNode->data.eventNumber == 12) {
                temp->right->left->left = newNode;
            }
            if (newNode->data.eventNumber == 13) {
                temp->right->left->right = newNode;
            }
            if (newNode->data.eventNumber == 14) {
                temp->right->right->left = newNode;
            }
            if (newNode->data.eventNumber == 15) {
                temp->right->right->right = newNode;
            }
            if (newNode->data.eventNumber == 16) {
                temp->left->left->left->left = newNode;
            }

        }

        length++;

    }

    //This method prints the eventDescription associated with the number of the node
    void printSelectedEvent(int i) {
        Node<T> *temp = root;
        if (i == 1) {
            cout << temp->data.description << endl;
        }
        if (i ==2) {
            cout << temp->left->data.description << endl;
        }
        if (i == 3) {
            cout << temp->right->data.description << endl;
        }
        if (i == 4) {
            cout << temp->left->left->data.description << endl;
        }
        if (i == 5) {
            cout << temp->left->right->data.description << endl;
        }
        if (i == 6) {
            cout << temp->right->left->data.description << endl;
        }
        if (i == 7) {
            cout << temp->right->right->data.description << endl;
        }
        if (i == 8) {
            cout << temp->left->left->left->data.description << endl;
        }
        if (i == 9) {
            cout << temp->left->left->right->data.description << endl;
        }
        if (i == 10) {
            cout << temp->left->right->left->data.description << endl;
        }
        if (i == 11) {
            cout << temp->left->right->right->data.description << endl;
        }
        if (i == 12) {
            cout << temp->right->left->left->data.description << endl;
        }
        if (i == 13) {
            cout << temp->right->left->right->data.description << endl;
        }
        if (i == 14) {
            cout << temp->right->right->left->data.description << endl;
        }
        if (i == 15) {
            cout << temp->right->right->right->data.description << endl;
        }
        if (i == 16) {
            cout << temp->left->left->left->left->data.description << endl;
        }

    }

    //This method prints the event number associated with the node
    void printSelectedEventNumber(int j) {
        Node<T> *temp = root;
        if (j == 1) {
            cout << temp->data.eventNumber << " ";
        }
        if (j ==2) {
            cout << temp->left->data.eventNumber << " ";
        }
        if (j == 3) {
            cout << temp->right->data.eventNumber << " ";
        }
        if (j == 4) {
            cout << temp->left->left->data.eventNumber << " ";
        }
        if (j == 5) {
            cout << temp->left->right->data.eventNumber << " ";
        }
        if (j == 6) {
            cout << temp->right->left->data.eventNumber << " ";
        }
        if (j == 7) {
            cout << temp->right->right->data.eventNumber << " ";
        }
        if (j == 8) {
            cout << temp->left->left->left->data.eventNumber << " ";
        }
        if (j == 9) {
            cout << temp->left->left->right->data.eventNumber << " ";
        }
        if (j == 10) {
            cout << temp->left->right->left->data.eventNumber << " ";
        }
        if (j == 11) {
            cout << temp->left->right->right->data.eventNumber << " ";
        }
        if (j == 12) {
            cout << temp->right->left->left->data.eventNumber << " ";
        }
        if (j == 13) {
            cout << temp->right->left->right->data.eventNumber << " ";
        }
        if (j == 14) {
            cout << temp->right->right->left->data.eventNumber << " ";
        }
        if (j == 15) {
            cout << temp->right->right->right->data.eventNumber << " ";
        }
        if (j == 16) {
            cout << temp->left->left->left->left->data.eventNumber << " ";
        }

    }

    //Method that asks user if they'd like to play again
    void playAgain() {
        string answer;
        cout << "Do you want to play again?(y/n) " << endl;
        cin >> answer;

        //What to do if they put "y"
        if (answer == "y") {
            cout << "Awesome! Try another path if you'd like!\n" << endl;
            playGame();
        }
        //What to do if they put "n"
        if (answer == "n") {
            cout << "Until next Time" << endl;
        }

        //What to do if they put something else
        else if (answer != "y" || answer != "n") {
            cout << "try again" << endl;
            cout << "Enter a y or n " << endl;
            playAgain();
        }

    }

    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const std::string& filename, char delimiter) {

        //creating the file stream and the string that will store the data
        //in the current line as the file is being read
        ifstream file(filename);
        string someString;

        //If the file fails to open it will give the player a message
        if (!file.is_open()) {
            cout << "Couldn't open the file " << endl;
        }

        //If the file is open then it will read it while it contains a line with
        //data to be parsed
        if (file.is_open()) {
            while (getline(file, someString)) {

                //creating a stringstream from the current line we got from the file
                stringstream ss(someString);
                //naming the string that will be used as the string stream string is parsed
                string theSSString;

                //Creating variables that will be initialized from values in the string that is being parsed
                string description;
                int eventNumber;
                int leftEventNumber;
                int rightEventNumber;

                //getting the first portion of the string from the current line up to the delimiter point
                getline(ss, theSSString,delimiter);
                eventNumber = stoi(theSSString);

                //getting the second portion of the string from the current line up to the delimiter point
                getline(ss, theSSString, delimiter);
                description = theSSString;

                //getting the third portion of the string from the current line up to the delimiter point
                getline(ss, theSSString, delimiter);
                leftEventNumber = stoi(theSSString);

                //getting the first portion of the string from the current line up to the delimiter point
                getline(ss, theSSString, delimiter);
                rightEventNumber = stoi(theSSString);

                //Creating a story object from the initialized variables that were taken from the string being parsed
                Story storyNode(description, eventNumber, leftEventNumber, rightEventNumber);

                //Adding the story object into the binary tree
                addStoryNode(storyNode);

            }

        }

        file.close();

    }

    // TODO: Function to start the game and traverse the tree based on user input
    void playGame() {

        //Introducing the game to the player
        cout<< "Welcome to my adventure fellow programmer!" << endl << endl;

        //Presenting player their current event
        printSelectedEventNumber(1);
        printSelectedEvent(1);

        //Asking player what they want to do
        cout<< "What do you do?" << endl;

        //Presenting the player with their two options
        printSelectedEventNumber(2);
        printSelectedEvent(2);
        cout<< "Or" << endl;
        printSelectedEventNumber(3);
        printSelectedEvent(3);

        //Player will input which option they want
        int input;
        cin >> input;

        //If the input they choose in not one of the two they could choose from, then
        //an invalid input text will be outputted and will ask the player to try again
        if (input != 2 && input != 3) {
            while ( input!=2 && input!=3) {
                cout<<"Invalid input! Please try again!" << endl;
                cin >> input;
            }
        }

        //If the player chooses path 2
        if (input == 2) {
            if (length>=4) {
                cout<< "What do you do?" << endl;
                printSelectedEventNumber(4);
                printSelectedEvent(4);
            }

            if (length>=5) {
                cout<< "Or" << endl;
                printSelectedEventNumber(5);
                printSelectedEvent(5);

            }

            //Player will input which option they want
            cin >> input;

            //If the input they choose in not one of the two they could choose from, then
            //an invalid input text will be outputted and will ask the player to try again
            if (input != 4 && input != 5) {
                while ( input!=4 && input!=5) {
                    cout<<"Invalid input! Please try again!" << endl;
                    cin >> input;
                }
            }

            //If the player chooses 4
            if (input == 4) {
                if (length>=4) {
                    cout<< "What do you do?" << endl;
                    printSelectedEventNumber(8);
                    printSelectedEvent(8);
                }

                if (length>=5) {
                    cout<< "Or" << endl;
                    printSelectedEventNumber(9);
                    printSelectedEvent(9);

                }
                //Player will input which option they want
                cin >> input;

                //If the input they choose in not one of the two they could choose from, then
                //an invalid input text will be outputted and will ask the player to try again
                if (input != 8 && input != 9) {
                    while ( input!=9 && input!=9) {
                        cout<<"Invalid input! Please try again!" << endl;
                        cin >> input;
                    }
                }

                //If the player chooses 8
                if (input==8) {

                    printSelectedEventNumber(16);
                    printSelectedEvent(16);
                }

                //If the player chooses 9
                if (input==9) {
                    printSelectedEventNumber(9);
                    printSelectedEvent(9);
                }
            }

            //If the player chooses 5
            if (input == 5) {
                printSelectedEventNumber(5);
                printSelectedEvent(5);
            }

        }

        //If the player chooses path 3
        if (input == 3) {
                cout<< "What do you do?" << endl;
                printSelectedEventNumber(6);
                printSelectedEvent(6);

                cout<< "Or" << endl;
                printSelectedEventNumber(7);
                printSelectedEvent(7);

            //Player will input which option they want
            cin >> input;

            //If the input they choose in not one of the two they could choose from, then
            //an invalid input text will be outputted and will ask the player to try again
            if (input != 6 && input != 7) {
                while ( input!=6 && input!=7) {
                    cout<<"Invalid input! Please try again!" << endl;
                    cin >> input;
                }
            }

            //If the player chooses 6
            if (input == 6) {
                printSelectedEventNumber(6);
                printSelectedEvent(6);
            }

            //If the player chooses 7
            if (input == 7) {
                printSelectedEventNumber(7);
                printSelectedEvent(7);
            }

        }

        //Farewell message
        cout<<"\nYou have determined your ending! Good Job!"<< endl;

        //Asking user if they'd like to play again using a method
        playAgain();

    };

};

#endif // GAMEDECISIONTREE_H
