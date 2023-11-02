#pragma once

#include <iostream>
#include <fstream>

class Base {
private:
    char* breed;
    char* color;

public:
    Base();
    Base(const char* breed, const char* color);
    Base(const Base& other);
    virtual ~Base();

    const char* getBreed() const;
    const char* getColor() const;

    void setBreed(const char* breed);
    void setColor(const char* color);

    virtual void printInfo() const = 0; // Виртуальный чистый метод
    virtual void saveToFile(std::ofstream& file) const = 0;
    virtual void loadFromFile(std::ifstream& file) = 0;
};
