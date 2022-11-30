#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include "Human.h"
#include "Tile.h"

using namespace std;

// Constructor
Human::Human(string colour) : Player{colour} {}

// Destructor
Human::~Human() {}

// Creates player move based on input
vector<int> Human::moveCreate() {
    vector<vector<Tile *>> curBoard = getBoard()->getBoardRef();
    string input; // reads user provided input

    while (getline(cin, input)) { // for each line,
        istringstream iss(input); // converts string input into input stringstream
        string cmd;
        iss >> cmd; // reads iss into cmd
        
        if (cmd == "resign") { // if cmd is simply resign, just set resign in player to true
            setResign(true);
            return vector<int>{-1};
        } else if (cmd == "move") { // if move,
            string initialPos; // this string holds initial position provided
            string destinationPos; // this string holds destination position provided
            stringstream conversionTool; // used to convert strings to integers
            int tempInt; // used to temporarily hold the integers that have been converted from strings

            iss >> initialPos; // reads second iss input into initalPos
            iss >> destinationPos; // reads third iss input into initalPos

            conversionTool << intialPos[1]; // read integer string into conversionTool
            conversionTool >> tempInt; // read conversionTool into tempInt, converting the string into integer value
            int initialRow = 8 - tempInt; // gets row value
            int initialCol = intialPos[0] - 97; // converts col value into integer
    

            conversionTool << destinationPos[1]; // same as above but just with destinationPos
            conversionTool >> tempInt;
            int destinationRow = 8 - tempInt;
            int destinationCol = destinationPos[0] - 97;

            // Exception Handling
            try {
                // Destination tile is the same as initial tile?
                if (initialRow == destinationRow && initialCol == destinationCol) { throw out_of_range("Reason: Destination tile is same as initial tile"); }

                Piece *testInitial = curBoard.at(initialRow).at(initialCol)->getPiece();
                Piece *testDestination = curBoard.at(initialRow).at(initialCol)->getPiece();
                // No piece in initial tile?
                if (testInitial == nullptr) { throw out_of_range("Reason: No piece located within initial tile"); } 
                // check if user even owns the piece
                if (own(testDestination) == false) { throw out_of_range("Reason: You do not own that piece"); }


            } catch (out_of_range r) {
                cerr << "Invalid Move. " << r.what() << endl;
            }
        } else {
            // if no valid move is provided
            cerr << "Invalid Move. Please use one of the following formats: 'resign', 'move [row][col] [row][col]'" << endl;
        }
    }
    return vector<int>();
}

