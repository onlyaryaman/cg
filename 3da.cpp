#include <iostream>

struct Point {
    double x, y, z;
};

// Function to apply translation to a point
Point translate(Point p, double tx, double ty, double tz) {
    p.x += tx;
    p.y += ty;
    p.z += tz;
    return p;
}

int main() {
    // Define the points of the object
    Point A = {0, 3, 1};
    Point B = {3, 3, 2};
    Point C = {3, 0, 0};
    Point D = {0, 0, 0};

    // Apply translation
    double tx = 1; // towards x-axis
    double ty = 1; // towards y-axis
    double tz = 2; // towards z-axis

    A = translate(A, tx, ty, tz);
    B = translate(B, tx, ty, tz);
    C = translate(C, tx, ty, tz);
    D = translate(D, tx, ty, tz);

    // Output new coordinates
    std::cout << "New Coordinates after translation:" << std::endl;
    std::cout << "A(" << A.x << ", " << A.y << ", " << A.z << ")" << std::endl;
    std::cout << "B(" << B.x << ", " << B.y << ", " << B.z << ")" << std::endl;
    std::cout << "C(" << C.x << ", " << C.y << ", " << C.z << ")" << std::endl;
    std::cout << "D(" << D.x << ", " << D.y << ", " << D.z << ")" << std::endl;

    return 0;
}
