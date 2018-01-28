#include <iostream>
#include <fstream>
#include "Point.h"

int main() {
    int numVertices = 51;
    Point points[numVertices];
    std::string pair;
    // Read points file
    std::ifstream file("../src/points.txt");
    if(file.is_open()) {
        std::cout << "Opened file" << std::endl;
        int index = 0;
        while(file >> pair) {
            std::cout << pair << std::endl;
//            std::cout << "x " << pair[1] << std::endl;
//            std::cout << "y " << pair[3] << std::endl;
//            std::cout << "x[int] " << pair[1] - '0' << std::endl;
//            std::cout << "y[int] " << pair[3] - '0' << std::endl;
            std::cout << "index " << index << std::endl;
//            points[index].setX(pair[1] - '0');
//            points[index].setY(pair[3] - '0');
            index++;
        }
        file.close();
    } else {
        std::cout << "File wasn't opened!" << std::endl;
    }

//    for(int i = 0; i < numVertices; i++) {
//        std::cout << "(" << points[i].getX() << "," << points[i].getY() << ")" << std::endl;
//    }

    // prompt user for what letter they want to generate
    std::cout << "What letter do you want to generate?" << std::endl;
    char input;
    std::cin >> input;
    input = toupper(input);
    std::cout << "You chose " << input << std::endl;
    switch(input) {
        case 'L':
            numVertices = 7;
            break;
        case 'N':
            numVertices = 11;
            break;
        case 'T':
            numVertices = 9;
            break;
        case 'E':
            numVertices = 13;
            break;
        case 'F':
            numVertices = 11;
            break;
        default:
            std::cout << "Please enter one of the available letters(L, N, T, E, F)" << std::endl;
            break;
    }
    // prompt user for size of model in the X & Y dimensions


    return 0;
}