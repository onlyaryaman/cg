#include <iostream>

struct Point {
    double x, y, z;
};

// Function to apply scaling to a point
Point scale(Point p, double sx, double sy, double sz) {
    p.x *= sx;
    p.y *= sy;
    p.z *= sz;
    return p;
}

int main() {
    // Define the points of the object
    Point A = {0, 3, 3};
    Point B = {3, 3, 6};
    Point C = {3, 0, 1};
    Point D = {0, 0, 0};

    // Define scaling factors
    double sx = 2;
    double sy = 3;
    double sz = 3;

    // Apply scaling
    A = scale(A, sx, sy, sz);
    B = scale(B, sx, sy, sz);
    C = scale(C, sx, sy, sz);
    D = scale(D, sx, sy, sz);

    // Output new coordinates
    std::cout << "New Coordinates after scaling:" << std::endl;
    std::cout << "A(" << A.x << ", " << A.y << ", " << A.z << ")" << std::endl;
    std::cout << "B(" << B.x << ", " << B.y << ", " << B.z << ")" << std::endl;
    std::cout << "C(" << C.x << ", " << C.y << ", " << C.z << ")" << std::endl;
    std::cout << "D(" << D.x << ", " << D.y << ", " << D.z << ")" << std::endl;

    return 0;
}
