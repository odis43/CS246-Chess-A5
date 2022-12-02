#include <string>
#include <sstream>
#include <iostream>
#include "Level1.h"
#include "Tile.h"
#include "Piece.h"

using namespace std;

// Constructor
Level1::Level1(string colour) : AI{colour} {}

// Destructor
Level1::~Level1() {}

// Creates move info to place into a Move object
std::vector<int> Level1::moveCreate() {
    vector<vector<Tile *>> curBoard = getBoard()->getBoardRef(); // holds a reference to the board
    string input; // will store input provided
    while (getline(cin, input)) {
        istringstream iss(input); // converts string input into input stringstream
        string cmd;
        iss >> cmd; // reads iss into cmd

        if (cmd == "move") { // command provided is called "move"
            vector<Piece *> myPieces; // holds the pieces that belong to this computer, computer will choose a random piece to make a move

            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    Piece *myPiece = curBoard.at(i).at(j)->getPiece(); // get each piece in the board
                    
                    if (!myPiece && myPiece->getColour() == colour) { // if belonging to my colour and existent
                        myPieces.emplace_back(myPiece); // add to my list of available pieces to move
                    }
                }
            }

            int randomVal;
            do { // used to select a random piece from myPieces
                randomVal = rand() % myPieces.size(); // generate a random value within the number of pieces in myPieces
                Piece *chosenPiece = myPieces.at(randomVal); // select the random piece with the given index from randomVal
            } while (chosenPiece->validMoves.size() == 0); // repeat if no valid moves belong to the piece

            Tile *initialTile = chosenPiece->getTile(); // this is the tile where the chosen piece is on
            int rowInitialTile = intialTile->getRow(); // get row of this chosen piece's tile
            int colInitialTile = intialTile->getCol(); // get col of this chosen piece's tile
        }
    }
}

