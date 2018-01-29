//
// Created by Blake on 1/26/2018.
//
#include "Point.h"

Point::Point(int x, int y) {
    Point::x = x;
    Point::y = y;
}

Point::Point() {
    Point::x = 0;
    Point::y = 0;
}

float Point::getX() {
    return x;
}

void Point::setX(int x) {
    Point::x = x;
}

float Point::getY() {
    return y;
}

void Point::setY(int y) {
    Point::y = y;
}
