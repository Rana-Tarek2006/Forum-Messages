#pragma once
#include <iostream>
using namespace std;

template<typename type>
class vector {
private:
    type* array;
    int Size;
    int Capacity;

public:
    vector();
    vector(int capacity);
    ~vector();
    void push( const type& item);
    void pop();
    void resize(int n);
    int size() const;
    int capacity() const;
    bool empty() const;
    type& operator[](int index);
    const type& operator[](int index) const;


};






template<typename type>
vector<type>::vector() : Capacity(10), Size(0) {
    array = new type[Capacity];
}

template<typename type>
vector<type>::vector(int capacity) : Capacity(capacity), Size(0) {
    array = new type[Capacity];
}

template<typename type>
vector<type>::~vector() {
    delete[] array;
}

template<typename type>
void vector<type>::push(const type& item) {
    std::cout << "DEBUG: Pushing item at index " << Size << ", Capacity: " << Capacity << "\n";

    if (Size == Capacity) {
        resize(2 * Capacity); // Double the capacity if needed
        std::cout << "DEBUG: Resized vector. New Capacity: " << Capacity << "\n";
    }

    array[Size++] = item; // Assign item
    std::cout << "DEBUG: Item pushed successfully.\n";
}




template<typename type>
void vector<type>::pop() {
    if (Size > 0) Size--;
}

template<typename type>
void vector<type>::resize(int newCapacity) {
    std::cout << "DEBUG: Resizing vector to capacity " << newCapacity << "\n";

    type* newArray = new type[newCapacity];
    for (int i = 0; i < Size; i++) {
        newArray[i] = array[i]; // Copy elements
    }

    delete[] array; // Free old array
    array = newArray;
    Capacity = newCapacity;

    std::cout << "DEBUG: Resize complete.\n";
}




template<typename type>
int vector<type>::size() const {
    return Size;
}

template<typename type>
int vector<type>::capacity() const {
    return Capacity;
}

template<typename type>
bool vector<type>::empty() const {
    return Size == 0;
}

template<typename type>
type& vector<type>::operator[](int index) {
    return array[index];
}

template<typename type>
const type& vector<type>::operator[](int index) const {
    if (index < 0 || index >= Size) {
        throw std::out_of_range("Index out of bounds");
    }
    return array[index];
}




template class vector<int>;
template class vector<std::string>;
