#ifndef CPPNUM_H
#define CPPNUM_H

#include "array.hpp"
#include "dtypes.hpp"
#include "shape.hpp"
#include "operations.hpp"
#include "broadcasting.hpp"
#include "linalg.hpp"

namespace cppnum {

// Version info
static constexpr const char* VERSION = "1.0.0";
static constexpr int MAJOR_VERSION = 1;
static constexpr int MINOR_VERSION = 0;
static constexpr int PATCH_VERSION = 0;

// Core initialization function
void initialize() {
    // Initialize library resources if needed
}

// Cleanup function
void finalize() {
    // Cleanup library resources if needed
}

// Convenience typedef for common array types
template<typename T, std::size_t N>
using NDArray = Array<T, N>;

} // namespace cppnum

#endif // CPPNUM_H