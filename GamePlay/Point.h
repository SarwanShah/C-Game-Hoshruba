#pragma once

class Point
{
private:
    int x,y;
public:
    Point()
    {
        x=y=0;
    }
    Point(int x,int y)
    {
        this->x=x;
        this->y=y;
    }
    Point(const Point& pt)
    {
        x = pt.x;
        y = pt.y;
    }
    void SetX(int x)
    {
        this->x = x;
    }
    void SetY(int y)
    {
        this->y = y;
    }
    int GetX()
    {
        return x;
    }
    int GetY()
    {
        return y;
    }

};
