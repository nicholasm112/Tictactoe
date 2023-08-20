#include <iostream>
#include <vector>
#include <string>
#include <sstream>


//create default start 
//alternate between asking players what spot they want to pick and update it accordingly 
//do this while available spots and no one has won 
//if someone won cout they won, if no one won and no spots available cout << tie 
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

 void createGame() {
    int j = 1;
    std::string s;
    for (int i = 0; i < 9; i++) {
        s = std::to_string(j);
        space[i/3][i%3] = s;
        j++;
    }
}
void printGame() {
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

bool isAvailable(int n) { 
    std::string s = std::to_string(n);
    for(int i = 0; i < 9; i++) {
        if(space[i/3][i%3] == s) {
            return true;
        }
    }
    return false;    
}

bool win() {//2 diaganols 3 down 3 across
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


int main() {
    createPlayers();
    createGame();
    printGame();
    int i = 0;
    while(i<9) { 
        player1Move();
        if(win()) {
            printGame();
            std::cout << "Winner is " << p1 << '\n' << "CONGRATULATIONS!!!!!!";
            return 0;
        }
        printGame();
        i++;
        if(i>=9) {
            std::cout << "TIE";
            return 0;
        }
        player2Move();
        if(win()) {
            printGame();
            std::cout << "Winner is " << p2 << '\n' << "CONGRATULATIONS!!!!!!";
            return 0; 
        }
        printGame();
        i++;
    }
    std::cout << "TIE";
    return 0;
    

}

