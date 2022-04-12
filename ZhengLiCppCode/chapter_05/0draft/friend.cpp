#include <cmath>
#include <iostream>
using namespace std;

class Point
{
private:
    int x, y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    friend class Dist;
    // friend float dist(Point &A, Point &B);
};

class Dist
{
private:
    float x, y;
    float dist;

public:
    Dist(Point &A, Point &B);
    float getDistance() { return dist; }
};

Dist::Dist(Point &A, Point &B)
{
    x = (float)A.x - B.x;
    y = (float)A.y - B.x;
    dist = sqrt(x * x + y * y);
}

int main()
{
    Point A(3, 7);
    Point B(9, 6);
    Dist dist(A, B);
    cout << dist.getDistance() << endl
         << endl;

    return 0;
}