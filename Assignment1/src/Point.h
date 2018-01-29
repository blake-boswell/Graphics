//
// Created by Blake on 1/26/2018.
//

#ifndef GRAPHICS_POINT_H
#define GRAPHICS_POINT_H
class Point {
    private:
        float x;
        float y;
    public:
        Point(int x, int y);
        Point();
        float getX();
        void setX(int x);
        float getY();
        void setY(int y);
};
#endif //GRAPHICS_POINT_H