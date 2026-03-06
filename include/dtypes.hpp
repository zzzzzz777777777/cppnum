// dtypes.hpp

#ifndef DTYPES_HPP
#define DTYPES_HPP

#include <complex>
#include <type_traits>
#include <array>

template <typename T>
struct MultiArray {
    using ValueType = T;
    using ComplexType = std::complex<T>;

    // Example: 3D Array
    std::array<std::array<std::array<ValueType, N>, M>, L> data;

    // Type Traits
    static_assert(std::is_arithmetic<ValueType>::value || std::is_same<ValueType, ComplexType>::value,
                  "ValueType must be an arithmetic type or complex type");
};

#endif // DTYPES_HPP