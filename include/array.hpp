#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>
#include <stdexcept>

template<typename T, std::size_t N>
class Array {
private:
    T* data;
    std::size_t sizes[N];

    std::size_t calculateIndex(const std::size_t* indices) const {
        std::size_t index = 0;
        std::size_t factor = 1;
        for (size_t i = 0; i < N; ++i) {
            if (indices[i] >= sizes[i]) {
                throw std::out_of_range("Index out of bounds");
            }
            index += indices[i] * factor;
            factor *= sizes[i];
        }
        return index;
    }

public:
    Array(const std::size_t (&sizes)[N]) {
        std::size_t totalSize = 1;
        for (size_t i = 0; i < N; ++i) {
            this->sizes[i] = sizes[i];
            totalSize *= sizes[i];
        }
        data = new T[totalSize]();
    }

    ~Array() {
        delete[] data;
    }

    T& operator[](const std::size_t* indices) {
        return data[calculateIndex(indices)];
    }

    const T& operator[](const std::size_t* indices) const {
        return data[calculateIndex(indices)];
    }
};

#endif // ARRAY_HPP
