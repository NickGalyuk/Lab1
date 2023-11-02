#pragma once
#ifndef KEEPER_H
#define KEEPER_H

#include "Base.h"
#include "Fish.h"
#include "Bird.h"
#include "Cat.h"

class Keeper {
public:
    Keeper();
    ~Keeper();

    void addAnimal(Base* animal);
    void removeAnimal(int index);
    void printAllAnimals() const;
    void saveToFile(const char* filename) const;
    void loadFromFile(const char* filename);

private:
    Base** animals;
    int capacity;
    int size;

    void resize();
};

#endif