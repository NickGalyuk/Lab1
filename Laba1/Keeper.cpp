#include "Keeper.h"
Keeper::Keeper() : objectCount(0) {}

Keeper::~Keeper() {
    for (int i = 0; i < objectCount; i++) {
        delete objects[i];
    }
}

void Keeper::addObject(Base* obj) {
    if (objectCount < maxObjects) {
        objects[objectCount] = obj;
        objectCount++;
    }
}

void Keeper::removeObject(int index) {
    if (index >= 0 && index < objectCount) {
        delete objects[index];
        for (int i = index; i < objectCount - 1; i++) {
            objects[i] = objects[i + 1];
        }
        objectCount--;
    }
}

void Keeper::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < objectCount; i++) {
            objects[i]->serialize(file);
            file << std::endl;
        }
    }
}

void Keeper::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        objectCount = 0;
        while (!file.eof()) {
            Base* obj = new Derived;
            obj->deserialize(file);
            addObject(obj);
        }
    }
}