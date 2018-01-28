//
// Created by Blake on 1/26/2018.
//

#ifndef GRAPHICS_POINT_H
#define GRAPHICS_POINT_H
class Point {
    private:
        int x;
        int y;
    public:
        Point(int x, int y);
        Point();
        int getX();
        void setX(int x);
        int getY();
        int setY(int y);
};
#endif //GRAPHICS_POINT_H