#include <stdio.h>
#include <math.h>

// Struct to hold coordinate pairs
typedef struct {
    double x;
    double y;
} Point;

// Trilateration solver function
int solve_trilateration(Point A, double ar, Point B, double br, Point C, double cr, Point *result) {
    // Matrix equation: M * [x, y]^T = K
    // M = [M11, M12]
    //     [M21, M22]
    
    double M11 = 2 * (A.x - B.x);
    double M12 = 2 * (A.y - B.y);
    double M21 = 2 * (A.x - C.x);
    double M22 = 2 * (A.y - C.y);

    double K1 = (br*br) - (ar*ar) - (B.x*B.x) - (B.y*B.y) + (A.x*A.x) + (A.y*A.y);
    double K2 = (cr*cr) - (ar*ar) - (C.x*C.x) - (C.y*C.y) + (A.x*A.x) + (A.y*A.y);

    // Solve using Cramer's Rule for a 2x2 matrix
    double determinant = (M11 * M22) - (M12 * M21);

    // If determinant is 0, the anchor points are collinear (in a straight line) and cannot resolve a 2D position
    if (fabs(determinant) < 1e-9) {
        return 0; // Failure
    }

    result->x = ((K1 * M22) - (M12 * K2)) / determinant;
    result->y = ((M11 * K2) - (K1 * M21)) / determinant;

    return 1; // Success
}

int main() {
    // Inputs from your SymPy script
    Point A = {0.0, 6.0};   double ar = 5.0;
    Point B = {8.0, 14.0};  double br = 13.0;
    Point C = {9.0, -6.0};  double cr = 10.0;
    
    Point solution;

    if (solve_trilateration(A, ar, B, br, C, cr, &solution)) {
        printf("Solution found!\n");
        printf("x = %.2f\n", solution.x);
        printf("y = %.2f\n", solution.y);
    } else {
        printf("Error: Matrix determinant is zero. Cannot solve location.\n");
    }

    return 0;
}
