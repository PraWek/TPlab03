#include "solver.h"
#include <cmath>
#include <stdexcept>

void solve(float a, float b, float c, float& x1, float& x2)
{
    if (a == 0.0f) {
        throw std::invalid_argument("Coefficient 'a' cannot be zero");
    }

    const float discriminant = b * b - 4 * a * c;
    
    if (discriminant < 0.0f) {
        throw std::domain_error("Discriminant is negative, no real roots exist");
    }

    const float sqrt_d = std::sqrt(discriminant);
    const float denominator = 1.0f / (2 * a);  // Используем умножение вместо деления
    
    x1 = (-b - sqrt_d) * denominator;
    x2 = (-b + sqrt_d) * denominator;
}
