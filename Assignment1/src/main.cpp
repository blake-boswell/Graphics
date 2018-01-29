#include <iostream>
#include <fstream>
#include "Point.h"

int main() {
    int numVertices = 51;

    int startL = 0;
    int endL = startL + 6;
    int startN = endL + 1;
    int endN = startN + 10;
    int startT = endN + 1;
    int endT = startT + 8;
    int startE = endT + 1;
    int endE = startE + 12;
    int startF = endE + 1;
    int endF = startF + 10;

    Point points[numVertices];
    std::string pair;
    // Read points file
    std::ifstream file;
    file.open("../Assignment1/src/points.txt");
    if(file.is_open()) {
        std::cout << "Opened file" << std::endl;
        int index = 0;
        while(file >> pair) {
            points[index].setX(pair[1] - '0');
            points[index].setY(pair[3] - '0');
            index++;
        }
        file.close();
        std::cout << "Closed the file" << std::endl;
    } else {
        std::cout << "File wasn't opened!" << std::endl;
    }

    // prompt user for what letter they want to generate
    bool loop = true;
    while(loop) {
        std::cout << "Enter \"q\" at any time to quit the program." << std::endl;
        std::cout << "What letter do you want to generate? (L, N, T, E, F)" << std::endl;
        char input;
        std::cin >> input;
        input = toupper(input);
        switch(input) {
            case 'L':
                // numVertices = 7
                for(int i = startL; i < endL + 1; i++) {
                    if(i == 0)
                        std::cout << "From" << std::endl;
                    std::cout << "(" << points[i].getX() << ", " << points[i].getY() << ")" << std::endl;
                    if(i != endL)
                        std::cout << "To" << std::endl;
                }
                break;
            case 'N':
                // numVertices = 11
                for(int i = startN; i < endN + 1; i++) {
                    if(i == 0)
                        std::cout << "From" << std::endl;
                    std::cout << "(" << points[i].getX() << ", " << points[i].getY() << ")" << std::endl;
                    if(i != endN)
                        std::cout << "To" << std::endl;
                }
                break;
            case 'T':
                // numVertices = 9
                for(int i = startT; i < endT + 1; i++) {
                    if(i == 0)
                        std::cout << "From" << std::endl;
                    std::cout << "(" << points[i].getX() << ", " << points[i].getY() << ")" << std::endl;
                    if(i != endT)
                        std::cout << "To" << std::endl;
                }
                break;
            case 'E':
                // numVertices = 13
                for(int i = startE; i < endE + 1; i++) {
                    if(i == 0)
                        std::cout << "From" << std::endl;
                    std::cout << "(" << points[i].getX() << ", " << points[i].getY() << ")" << std::endl;
                    if(i != endE)
                        std::cout << "To" << std::endl;
                }
                break;
            case 'F':
                // numVertices = 11
                for(int i = startF; i < endF + 1; i++) {
                    if(i == 0)
                        std::cout << "From" << std::endl;
                    std::cout << "(" << points[i].getX() << ", " << points[i].getY() << ")" << std::endl;
                    if(i != endF)
                        std::cout << "To" << std::endl;
                }
                break;
            case 'Q':
                std::cout << "Terminating the program..." << std::endl;
                loop = false;
                break;
            default:
                std::cout << "Invalid input: please enter one of the available letters(L, N, T, E, F)" << std::endl;
                break;
        }
    }

    // prompt user for size of model in the X & Y dimensions


    return 0;
}