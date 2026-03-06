// Array operations implementation
#include <iostream>

class Array {
private:
    int* arr;
    int size;

public:
    Array(int s) : size(s) {
        arr = new int[size];
    }

    ~Array() {
        delete[] arr;
    }

    void set(int index, int value) {
        if (index >= 0 && index < size) {
            arr[index] = value;
        }
    }

    int get(int index) const {
        if (index >= 0 && index < size) {
            return arr[index];
        }
        return -1; // or throw an exception
    }

    int length() const {
        return size;
    }

    void print() const {
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Array myArray(5);
    myArray.set(0, 10);
    myArray.set(1, 20);
    myArray.set(2, 30);
    myArray.print(); // Output: 10 20 30
    return 0;
}