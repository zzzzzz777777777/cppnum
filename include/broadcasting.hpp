// broadcasting.hpp
// Broadcasting Mechanism for Arrays in C++23

#ifndef BROADCASTING_HPP
#define BROADCASTING_HPP

#include <vector>
#include <stdexcept>

// A function to perform broadcasting of two arrays of different shapes.
template<typename T>
std::vector<T> broadcast(const std::vector<T>& a, const std::vector<T>& b) {
    // Logic for broadcasting arrays 'a' and 'b'
    // This is a simple example and might need to handle various edge cases.

    size_t a_size = a.size();
    size_t b_size = b.size();

    if (a_size == b_size || b_size == 1) {
        return a;
    } else if (a_size == 1) {
        return std::vector<T>(b.begin(), b.end());
    }

    throw std::invalid_argument("Arrays not compatible for broadcasting.");
}

#endif // BROADCASTING_HPP
