#include <iostream>
#include <vector>

class Shape {
public:
    Shape(std::vector<int> dimensions) : dimensions(dimensions) {}
    std::vector<int> getDimensions() const { return dimensions; }
    int getDimension(int index) const { return dimensions.at(index); }
private:
    std::vector<int> dimensions;
};

class Strides {
public:
    Strides(const Shape& shape) {
        calculateStrides(shape);
    }
    std::vector<int> getStrides() const { return strides; }
private:
    void calculateStrides(const Shape& shape) {
        int totalSize = 1;
        const auto& dimensions = shape.getDimensions();
        strides.resize(dimensions.size());
        for (int i = dimensions.size() - 1; i >= 0; --i) {
            strides[i] = totalSize;
            totalSize *= dimensions[i];
        }
    }
    std::vector<int> strides;
};