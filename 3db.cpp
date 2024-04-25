#include <iostream>
#include <cmath>

struct Point {
    double x, y, z;
};

// Function to apply rotation around x-axis
Point rotateX(Point p) {
    Point rotated;
    rotated.x = p.x;
    rotated.y = p.y * cos(M_PI/2) - p.z * sin(M_PI/2);
    rotated.z = p.y * sin(M_PI/2) + p.z * cos(M_PI/2);
    return rotated;
}

// Function to apply rotation around y-axis
Point rotateY(Point p) {
    Point rotated;
    rotated.x = p.x * cos(M_PI/2) + p.z * sin(M_PI/2);
    rotated.y = p.y;
    rotated.z = -p.x * sin(M_PI/2) + p.z * cos(M_PI/2);
    return rotated;
}

// Function to apply rotation around z-axis
Point rotateZ(Point p) {
    Point rotated;
    rotated.x = p.x * cos(M_PI/2) - p.y * sin(M_PI/2);
    rotated.y = p.x * sin(M_PI/2) + p.y * cos(M_PI/2);
    rotated.z = p.z;
    return rotated;
}

int main() {
    // Define the point
    Point P = {1, 2, 3};

    // Apply rotation around x-axis
    Point rotatedX = rotateX(P);
    // Apply rotation around y-axis
    Point rotatedY = rotateY(P);
    // Apply rotation around z-axis
    Point rotatedZ = rotateZ(P);

    // Output new coordinates after rotation
    std::cout << "New Coordinates after rotation around x-axis: (" << rotatedX.x << ", " << rotatedX.y << ", " << rotatedX.z << ")" << std::endl;
    std::cout << "New Coordinates after rotation around y-axis: (" << rotatedY.x << ", " << rotatedY.y << ", " << rotatedY.z << ")" << std::endl;
    std::cout << "New Coordinates after rotation around z-axis: (" << rotatedZ.x << ", " << rotatedZ.y << ", " << rotatedZ.z << ")" << std::endl;

    return 0;
}
