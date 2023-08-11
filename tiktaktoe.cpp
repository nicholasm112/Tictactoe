#include <iostream>
#include <vector>


//create default start 
//alternate between asking players what spot they want to pick and update it accordingly 
//do this while available spots and no one has won 
//if someone won cout they won, if no one won and no spots available cout << tie 
std::string space[3][3];


void createPlayers() {
    std::string p1;
    std::string p2;
    std::cout << "Enter the name of the first player:  ";
    std::cin >> p1;
    std::cout << "Enter the name of the second player:  ";
    std::cin >> p2;
    std::cout << p1 << " is player1 so he/she will be X and play first!" << "\n";
    std::cout << p2 << " is player2 so he/she will be O and play second!" << "\n";
}

 void createGame() {
    std::string space[3][3];
    int j = 1;
    std::string s;
    for (int i = 0; i < 9; i++) {
        s = std::to_string(j);
        space[i/3][i%3] = s;
        j++;
    }
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
    //have to make sure it is a number passed here ca
    std::string s = std::to_string(n);
    // if(!(n>=1 and n<=9)) {
    //     return false;
    // }
    for(int i = 0; i < 9; i++) {
        if(space[i/3][i%3] == s) {
            return true;
        }
    }
    return false;    
}

std::string playerMove() {//request player move
    //while(p1)
    std::cout<< "please enter move(available integer):  ";
    

}


int main() {
    createPlayers();
    createGame();
    

}

