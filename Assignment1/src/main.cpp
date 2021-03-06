#include <iostream>
#include <fstream>
#include "Point.h"
#include "Letter.h"

bool isFloatOrInt(std::string input) {
    std::string delimeter = ".";
    int splitIndex = input.find(delimeter);
    // No decimal, its an int
    if(splitIndex == -1 && (input[0] == '-' || isdigit(input[0]))) {
        for(int i = 1; i < input.size(); i++) {
            if(!isdigit(input[i])) {
                return false;
            }
        }
        return true;
    } else if(input[0] == '-' || isdigit(input[0])) {
        for(int i = 1; i < splitIndex; i++) {
            if(!isdigit(input[i])) {
                return false;
            }
        }
        for(int i = splitIndex + 1; i < input.size(); i++) {
            if(!isdigit(input[i])) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }

}

void resizePrompt(char letter, Letter letters[]) {
    for(int i = 0; i < Letter::numLetters; i++) {
        if(letters[i].getLetter() == letter) {
            std::cout << "You chose " << letter << std::endl;
            std::string xSize;
            std::string ySize;
            std::cout << "Enter X size" << std::endl;
            std::cin >> xSize;
            // Error handling
            while(!isFloatOrInt(xSize)) {
                std::cout << "Please enter only numbers." << std::endl;
                std::cout << "Enter X size" << std::endl;
                std::cin >> xSize;
            }
            float x = std::stof(xSize);
            std::cout << "Enter Y size" << std::endl;
            std::cin >> ySize;
            // Error handling
            while(!isFloatOrInt(ySize)) {
                std::cout << "Please enter only numbers." << std::endl;
                std::cout << "Enter Y size" << std::endl;
                std::cin >> ySize;
            }
            float y = std::stof(ySize);
            Point* newPoints = letters[i].transform(x, y);
            std::cout << "poly2d" << letters[i].getNumVertices() << std::endl;
            for(int j = 0; j < letters[i].getNumVertices(); j++) {
                std::cout << (newPoints + j)->getX() << " " << (newPoints + j)->getY() << std::endl;
            }
            delete newPoints;
        }
    }
}

void letterTransformationMenu(Letter letters[]) {
    bool loop = true;
    std::string response;
    char input;
    while(loop) {
        // prompt user for what letter they want to generate
        std::cout << "What letter do you want to generate? (L, N, T, E, F)" << std::endl <<
                  "Or enter  \"q\" to quit the program" << std::endl;
        std::cin >> response;
        if(response.size() == 1) {
            input = response[0];
            if(isalpha(input)) {
                input = toupper(input);
                // prompt user for size of model in the X & Y dimensions
                switch(input) {
                    case 'L':
                        resizePrompt('L', letters);
                        break;
                    case 'N':
                        resizePrompt('N', letters);
                        break;
                    case 'T':
                        resizePrompt('T', letters);
                        break;
                    case 'E':
                        resizePrompt('E', letters);
                        break;
                    case 'F':
                        resizePrompt('F', letters);
                        break;
                    case 'Q':
                        loop = false;
                        break;
                    default:
                        std::cout << "Invalid input: please enter one of the available letters(L, N, T, E, F)" << std::endl;
                        break;
                }
            }
        } else {
            std::cout << "Invalid input: please enter a letter" << std::endl;
        }

    }

}

int readFile(std::string fileName) {
    std::ifstream file;
    file.open(fileName);
    if(file.is_open()) {
        std::cout << "Reading file..." << std::endl;
        std::string pair;
        std::string line;
        char letter;
        int numVertices;
        int index;
        int splitIndex;
        int x;
        int y;

        // Read numLetter line
        std::getline(file, line, '\n');
        int numLetters = std::stoi(line);
        Letter letters[numLetters];
        // Read blank line
        std::getline(file, line, '\n');
        // Read in letters and vertices
        for(int i = 0; i < numLetters; i++) {
            // Read letter line
            std::getline(file, line, '\n');
            letter = line[0];
            letters[i].setLetter(letter);
            // Read numVertices line
            std::getline(file, line, '\n');
            numVertices = std::stoi(line);
            letters[i].setNumVertices(numVertices);
            Point points[numVertices];
            // Read original points
            std::getline(file, line);
            index = 0;
            while(line != "") {
                pair = line;
                // Extract the x and y
                std::string delimeter = ",";
                splitIndex = line.find(delimeter);
                x = std::stoi(line.substr(0, splitIndex));
                y = std::stoi(line.substr(splitIndex+1, line.length()));
                // create a point object for each point
                points[index].setX(x);
                points[index].setY(y);
                index++;
                // Protection from seg. fault
                // Won't try to read in another line if we are at the end of file
                if(file.eof()) {
                    line = "";
                }
                std::getline(file, line);
            }
            // Set the letter's points to the points array we just made
            letters[i].setOriginalPoints(points, numVertices);
            delete points;
        }
        file.close();
        std::cout << "File read complete." << std::endl;
        // Letter transformation menu
        letterTransformationMenu(letters);
        return 1;
    } else {
        std::cout << "File wasn't opened! Please make sure you entered the correct file name" << std::endl;
        return 0;
    }
}

std::string getFileName() {
    // default file
    std::string fileName = "letters.txt";
    // Prompt user for a file to read from
    std::string response;
    char input;
    std::cout << "Welcome!" << std::endl;
    std::cout << "Read data from default file? (y or n)" << std::endl;
    std::cin >> response;
    input = response[0];
    // Error handling
    while(input != 'y' && input != 'Y' && input != 'n' && input != 'N') {
        std::cout << "Please respond with y or n" << std::endl;
        // re-prompt
        std::cout << "Read data from default file? (y or n)" << std::endl;
        std::cin >> input;
    }
    if(input == 'n' || input == 'N') {
        std::cout << "Please enter the name of the file you wish to read from:" << std::endl;
        std::cin >> fileName;
    }
    return fileName;
}

int main() {
    bool loop = true;
    while(loop) {
        std::string fileName = getFileName();
        // Read file
        if(readFile(fileName)) {
            // Success
            loop = false;
        } else {
            // Failed reading
            std::cout << "Would you like to retry? (y or n)" << std::endl;
            char response;
            std::cin >> response;
            while(response != 'Y' && response != 'y' && response != 'N' && response != 'n') {
                std::cout << "Would you like to retry? (y or n)" << std::endl;
                std::cin >> response;
            }
            if(response == 'n' || response == 'N') {
                loop = false;
            }
        }
    }
    std::cout << "Terminating program..." << std::endl;
    return 0;
}