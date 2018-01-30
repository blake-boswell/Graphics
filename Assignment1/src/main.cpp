#include <iostream>
#include <fstream>
#include <stdlib.h>
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
    file.open("points.txt");
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

    bool loop = true;
    char input;
    float xSize;
    float ySize;
    float originalWidth;
    float originalHeight;
    float x;
    float y;
    while(loop) {
        // prompt user for what letter they want to generate
        std::cout << "Enter \"q\" at any time to quit the program." << std::endl;
        std::cout << "What letter do you want to generate? (L, N, T, E, F)" << std::endl;
        input;
        std::cin >> input;
        input = toupper(input);
        // prompt user for size of model in the X & Y dimensions
        if(input != 'Q') {
            std::cout << "Enter X size" << std::endl;
            std::cin >> xSize;
            std::cout << "Enter Y size" << std::endl;
            std::cin >> ySize;
        }
        switch(input) {
            case 'L':
                // numVertices = 7
                originalWidth = 3;
                originalHeight = 5;
                for(int i = startL; i < endL + 1; i++) {
                    if(i == 0)
                        std::cout << "From" << std::endl;
                    x = points[i].getX() * (xSize/originalWidth);
                    y = points[i].getY() * (ySize/originalHeight);
                    std::cout << "(" << x << ", " << y << ")" << std::endl;
                    if(i != endL)
                        std::cout << "To" << std::endl;
                }
                break;
            case 'N':
                // numVertices = 11
                originalWidth = 5;
                originalHeight = 5;
                for(int i = startN; i < endN + 1; i++) {
                    if(i == 0)
                        std::cout << "From" << std::endl;
                    x = points[i].getX() * (xSize/originalWidth);
                    y = points[i].getY() * (ySize/originalHeight);
                    std::cout << "(" << x << ", " << y << ")" << std::endl;
                    if(i != endN)
                        std::cout << "To" << std::endl;
                }
                break;
            case 'T':
                // numVertices = 9
                originalWidth = 5;
                originalHeight = 5;
                for(int i = startT; i < endT + 1; i++) {
                    if(i == 0)
                        std::cout << "From" << std::endl;
                    x = points[i].getX() * (xSize/originalWidth);
                    y = points[i].getY() * (ySize/originalHeight);
                    std::cout << "(" << x << ", " << y << ")" << std::endl;
                    if(i != endT)
                        std::cout << "To" << std::endl;
                }
                break;
            case 'E':
                // numVertices = 13
                originalWidth = 3;
                originalHeight = 5;
                for(int i = startE; i < endE + 1; i++) {
                    if(i == 0)
                        std::cout << "From" << std::endl;
                    x = points[i].getX() * (xSize/originalWidth);
                    y = points[i].getY() * (ySize/originalHeight);
                    std::cout << "(" << x << ", " << y << ")" << std::endl;
                    if(i != endE)
                        std::cout << "To" << std::endl;
                }
                break;
            case 'F':
                // numVertices = 11
                originalWidth = 3;
                originalHeight = 5;
                for(int i = startF; i < endF + 1; i++) {
                    if(i == 0)
                        std::cout << "From" << std::endl;
                    x = points[i].getX() * (xSize/originalWidth);
                    y = points[i].getY() * (ySize/originalHeight);
                    std::cout << "(" << x << ", " << y << ")" << std::endl;
                    if(i != endF)
                        std::cout << "To" << std::endl;
                }
                break;
            case 'Q':
                std::cout << "Terminating the program..." << std::endl;
                loop = false;
                break;
            default:
                std::string trash;
                std::cout << "Invalid input: please enter one of the available letters(L, N, T, E, F)" << std::endl;
                std::cin >> trash;
                break;
        }
    }

    return 0;
}