#pragma once
#include <iostream>
#include <fstream>
class Keeper
{
private:
    static const int maxObjects = 50;
    Base* objects[maxObjects];
    int objectCount;

public:
    Keeper();
    ~Keeper();

    void addObject(Base* obj);
    void removeObject(int index);
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

