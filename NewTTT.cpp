#include <iostream>
#include <vector>
#include <string>
#include <sstream>
//because class is being implemented in the same class that it is being instantiated in I dont need Game:: but is could make hpp file 

class Game {
public:

    std::string space[3][3];
    std::string p1;
    std::string p2;


    void createPlayers() {
        std::cout << "Enter the name of the first player:  ";
        std::cin >> p1;
        std::cout << "Enter the name of the second player:  ";
        std::cin >> p2;
        std::cout << std::endl;
        std::cout << p1 << " is player1 so he/she will be X and play first!" << std::endl;
        std::cout << p2 << " is player2 so he/she will be O and play second!" << std::endl;
        std::cout << std::endl;
    }

    void createSinglePlayer() {
        std::cout << "Enter the name of the first player:  ";
        std::cin >> p1;
        std::cout << "\n";
    }

    const void createGame() {
        int j = 1;
        std::string s;
        for (int i = 0; i < 9; i++) {
            s = std::to_string(j);
            space[i/3][i%3] = s;
            j++;
        }
    }
   const void printGame() {
        std::cout << "    |       |   \n";
        std::cout <<  " " << space[0][0] << "  |   " << space[0][1] << "   |  " << space[0][2] << "\n";
        std::cout << "____|_______|_____\n";
        std::cout << "    |       |   \n";
        std::cout <<  " " << space[1][0] << "  |   " << space[1][1] << "   |  " << space[1][2] << "\n";
        std::cout << "____|_______|_____\n";
        std::cout << "    |       |   \n";
        std::cout <<  " " << space[2][0] << "  |   " << space[2][1] << "   |  " << space[2][2] << "\n";
        std::cout << "    |       |   \n";

    }

   const bool isAvailable(int n) { 
        std::string s = std::to_string(n);
        for(int i = 0; i < 9; i++) {
            if(space[i/3][i%3] == s) {
                return true;
            }
        }
        return false;    
    }

    const bool isDraw() {
        for (int i = 0; i < 9; i++) {
            if(space[i/3][i%3] == std::to_string(i+1)) {
                return false;
            }
        }
        return true;
    }

    const bool win() {//2 diaganols 3 down 3 across
        if(space[0][0] == space[1][1] and space[0][0] == space[2][2]) {
                return true;
            }
            if(space[2][0] == space[1][1] and space[2][0] == space[0][2] ) {//this and statement above is to check diagnols 
                return true;
            }
        for(int i = 0; i < 3; i++) {
            if(space[0][i] == space[1][i] and  space[0][i] == space[2][i]) { //checking down
                return true;
            }
            if(space[i][0] == space[i][1] and space[i][0] ==  space[i][2]) {//checking across
                return true;
            }
        }
        return false;
    }

    void player1Move() {//request player move
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        int number;
        bool validInput = false;

        while (!validInput) {
            std::cout << p1 << " please enter a number: ";
            if (std::cin >> number) {
                // Input is a valid number
                if (isAvailable(number)) {
                    validInput = true;
                    number--;
                    space[number/3][number%3] = "X";
                }
                else {
                std::cout << "Invalid input. Please enter a valid number." << std::endl;
                std::cin.clear(); // Clear error state
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            } 
            else {
                // Input is not a valid number
                std::cout << "Invalid input. Please enter a valid number." << std::endl;
                std::cin.clear(); // Clear error state
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }

    void player2Move() {//request player move
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        int number;
        bool validInput = false;

        while (!validInput) {
            std::cout << p2 << " please enter a number: ";
            if (std::cin >> number) {
                // Input is a valid number
                if (isAvailable(number)) {
                    validInput = true;
                    number--;
                    space[number/3][number%3] = "O";
                }
                else {
                std::cout << "Invalid input. Please enter a valid number." << std::endl;
                std::cin.clear(); // Clear error state
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            } 
            else {
                // Input is not a valid number
                std::cout << "Invalid input. Please enter a valid number." << std::endl;
                std::cin.clear(); // Clear error state
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }      
        }
    }

    int miniMax(std::string board[3][3], std::string player) {  
        if(win()) {
            if (player == "O" ) {
                return 10;
            }
            else {
                return -10;
                }
        }
        else if (isDraw()) {
            return 0;
        }
        int bestScore;
        if (player == "O") {
            bestScore = -INT_MAX;
            for(int i = 0; i < 9; i++) {
                if (board[i/3][i%3] != "X" && board[i/3][i%3] != "O") {
                    board[i/3][i%3] = "O";
                    int score = miniMax(board, "X");
                    board[i/3][i%3] = std::to_string(i+1);
                    bestScore = std::max(score, bestScore);

                }
            }
        }
        else {
            bestScore = INT_MAX;
            for (int i = 0; i < 9; i++) {
                if (board[i/3][i%3] != "X" && board[i/3][i%3] != "O") {
                    board[i/3][i%3] = "X";
                    int score = miniMax(board,"O");
                    board[i/3][i%3] = std::to_string(i+1);
                    bestScore = std::min(score, bestScore);
                }
            }
        }
        return bestScore; 
    }

    void aiMove() {
        int bestScore = -INT_MAX;
        int bestMove = -1;
        for (int i = 0; i < 9; i++) {
            if (space[i / 3][i % 3] != "X" and space[i / 3][i % 3] != "O") {
                space[i / 3][i % 3] = "O";
                int score = miniMax(space, "X");
                space[i / 3][i % 3] = std::to_string(i+1);

                if (score > bestScore) {
                    bestScore = score;
                    bestMove = i;
                }
            }
        }

        space[bestMove / 3][bestMove % 3] = "O";
    }
};


int main() { 
    int x;
    bool valid = false;
    std::cout << "**********!!!!!TICTACTOE!!!!************\n\n" << "Enter 1 For Single Player Or 2 for Two Players: ";
    while(!valid) {
        if (std::cin >> x) {
            if (x == 1 or x == 2) {
                valid = true;
            }
            else {
                std::cout << "Invalid input. Please enter a valid number." << std::endl;
                std::cin.clear(); // Clear error state
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        else {
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
            std::cin.clear(); // Clear error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    Game S;
    if (x == 1 ) {
        S.createSinglePlayer();
    }
    else {
        S.createPlayers();
    }
    S.createGame();
    S.printGame();
    int i = 0;
    while(i<9) { 
        S.player1Move();
        if(S.win()) {
            S.printGame();
            std::cout << "Winner is " << S.p1 << '\n' << "CONGRATULATIONS!!!!!!";
            return 0;
        }
        S.printGame();
        i++;
        if(i>=9) {
            std::cout << "TIE";
            return 0;
        }
        if (x == 2) {
            S.player2Move();
        }
        else if (x ==1 ) {
            S.aiMove();
        }
        if(S.win()) {
            S.printGame();
            std::cout << "Winner is " << "Computer" << '\n' << "CONGRATULATIONS!!!!!!";
            return 0; 
        }
        S.printGame();
        i++;
    }
    
    std::cout << "TIE";
    return 0;

    }
    
