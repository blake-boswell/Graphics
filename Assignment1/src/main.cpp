#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Point.h"

int main() {
    int numPoints = 51;

    int startL = 0;
    int endL = startL + 5;
    int startN = endL + 1;
    int endN = startN + 9;
    int startT = endN + 1;
    int endT = startT + 7;
    int startE = endT + 1;
    int endE = startE + 11;
    int startF = endE + 1;
    int endF = startF + 9;

    Point points[numPoints];
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
    int numVertices;
    char input;
    float xSize;
    float ySize;
    float originalWidth;
    float originalHeight;
    float x;
    float y;
    while(loop) {
        // prompt user for what letter they want to generate
        std::cout << "What letter do you want to generate? (L, N, T, E, F)" << std::endl <<
                  "Or enter  \"q\" to quit the program" << std::endl;
        std::cin >> input;
        if(isalpha(input)) {
            input = toupper(input);
            // prompt user for size of model in the X & Y dimensions
            switch(input) {
                case 'L':
                    numVertices = 6;
                    std::cout << "Enter X size" << std::endl;
                    std::cin >> xSize;
                    std::cout << "Enter Y size" << std::endl;
                    std::cin >> ySize;
                    originalWidth = 3;
                    originalHeight = 5;
                    std::cout << "poly2d" << numVertices << std::endl;
                    for(int i = startL; i < endL + 1; i++) {
                        x = points[i].getX() * (xSize/originalWidth);
                        y = points[i].getY() * (ySize/originalHeight);
                        std::cout << x << " " << y << std::endl;
                    }
                    break;
                case 'N':
                    numVertices = 10;
                    std::cout << "Enter X size" << std::endl;
                    std::cin >> xSize;
                    std::cout << "Enter Y size" << std::endl;
                    std::cin >> ySize;
                    originalWidth = 5;
                    originalHeight = 5;
                    std::cout << "poly2d" << numVertices << std::endl;
                    for(int i = startN; i < endN + 1; i++) {
                        x = points[i].getX() * (xSize/originalWidth);
                        y = points[i].getY() * (ySize/originalHeight);
                        std::cout << x << " " << y << std::endl;
                    }
                    break;
                case 'T':
                    numVertices = 8;
                    std::cout << "Enter X size" << std::endl;
                    std::cin >> xSize;
                    std::cout << "Enter Y size" << std::endl;
                    std::cin >> ySize;
                    originalWidth = 5;
                    originalHeight = 5;
                    std::cout << "poly2d" << numVertices << std::endl;
                    for(int i = startT; i < endT + 1; i++) {
                        x = points[i].getX() * (xSize/originalWidth);
                        y = points[i].getY() * (ySize/originalHeight);
                        std::cout << x << " " << y << std::endl;
                    }
                    break;
                case 'E':
                    numVertices = 12;
                    std::cout << "Enter X size" << std::endl;
                    std::cin >> xSize;
                    std::cout << "Enter Y size" << std::endl;
                    std::cin >> ySize;
                    originalWidth = 3;
                    originalHeight = 5;
                    std::cout << "poly2d" << numVertices << std::endl;
                    for(int i = startE; i < endE + 1; i++) {
                        x = points[i].getX() * (xSize/originalWidth);
                        y = points[i].getY() * (ySize/originalHeight);
                        std::cout << x << " " << y << std::endl;
                    }
                    break;
                case 'F':
                    numVertices = 10;
                    std::cout << "Enter X size" << std::endl;
                    std::cin >> xSize;
                    std::cout << "Enter Y size" << std::endl;
                    std::cin >> ySize;
                    originalWidth = 3;
                    originalHeight = 5;
                    std::cout << "poly2d" << numVertices << std::endl;
                    for(int i = startF; i < endF + 1; i++) {
                        x = points[i].getX() * (xSize/originalWidth);
                        y = points[i].getY() * (ySize/originalHeight);
                        std::cout << x << " " << y << std::endl;
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
        } else {
            std::cout << "Invalid input: please enter a letter" << std::endl;
        }

    }

    return 0;
}