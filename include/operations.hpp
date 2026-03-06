# operations.hpp

#ifndef OPERATIONS_HPP
#define OPERATIONS_HPP

#include <vector>
#include <numeric>
#include <cmath>

namespace ArrayOperations {

    // Element-wise Addition
    std::vector<double> add(const std::vector<double>& a, const std::vector<double>& b) {
        std::vector<double> result(a.size());
        for (size_t i = 0; i < a.size(); ++i) {
            result[i] = a[i] + b[i];
        }
        return result;
    }

    // Element-wise Subtraction
    std::vector<double> subtract(const std::vector<double>& a, const std::vector<double>& b) {
        std::vector<double> result(a.size());
        for (size_t i = 0; i < a.size(); ++i) {
            result[i] = a[i] - b[i];
        }
        return result;
    }

    // Scalar Multiplication
    std::vector<double> scalarMultiply(const std::vector<double>& a, double scalar) {
        std::vector<double> result(a.size());
        for (size_t i = 0; i < a.size(); ++i) {
            result[i] = a[i] * scalar;
        }
        return result;
    }

    // Mean of Array
    double mean(const std::vector<double>& a) {
        return std::accumulate(a.begin(), a.end(), 0.0) / a.size();
    }

    // Standard Deviation
    double standardDeviation(const std::vector<double>& a) {
        double avg = mean(a);
        double sum = 0.0;
        for (double value : a) {
            sum += (value - avg) * (value - avg);
        }
        return std::sqrt(sum / a.size());
    }

}

#endif // OPERATIONS_HPP