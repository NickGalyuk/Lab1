#include "Keeper.h"
#include "Keeper.h"

Keeper::Keeper() : animals(nullptr), capacity(0), size(0) {
    std::cout << "Вызывается конструктор Keeper по умолчанию." << std::endl;
}

Keeper::~Keeper() {
    for (int i = 0; i < size; ++i) {
        delete animals[i];
    }
    delete[] animals;
    std::cout << "Вызван деструктор Keeper." << std::endl;
}

void Keeper::addAnimal(Base* animal) {
    if (size == capacity) {
        resize();
    }
    animals[size++] = animal;
}

void Keeper::removeAnimal(int index) {
    if (index >= 0 && index < size) {
        delete animals[index];
        for (int i = index; i < size - 1; ++i) {
            animals[i] = animals[i + 1];
        }
        size--;
    }
    else {
        std::cerr << "Недопустимый индекс для удаления." << std::endl;
    }
}

void Keeper::printAllAnimals() const {
    for (int i = 0; i < size; ++i) {
        animals[i]->printInfo();
    }
}

void Keeper::saveToFile(const char* filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << size << std::endl;
        for (int i = 0; i < size; ++i) {
            animals[i]->saveToFile(file);
        }
        file.close();
        std::cout << "Данные, сохраненные в файл: " << filename << std::endl;
    }
    else {
        std::cerr << "Не удается открыть файл: " << filename << std::endl;
    }
}

void Keeper::loadFromFile(const char* filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        int loadedSize;
        file >> loadedSize;

        // Clear existing data
        for (int i = 0; i < size; ++i) {
            delete animals[i];
        }
        delete[] animals;

        // Allocate new space
        capacity = loadedSize;
        size = 0;
        animals = new Base * [capacity];

        // Load data
        for (int i = 0; i < loadedSize; ++i) {
            int type;
            file >> type;
            Base* animal = nullptr;
            switch (type) {
            case 1: // Fish
                animal = new Fish();
                break;
            case 2: // Bird
                animal = new Bird();
                break;
            case 3: // Cat
                animal = new Cat();
                break;
            default:
                std::cerr << "Неизвестный тип животного в файле." << std::endl;
                delete animal;
                continue;
            }
            animal->loadFromFile(file);
            addAnimal(animal);
        }

        file.close();
        std::cout << "Данные, загруженные из файла: " << filename << std::endl;
    }
    else {
        std::cerr << "Не удается открыть файл: " << filename << std::endl;
    }
}

void Keeper::resize() {
    int newCapacity = (capacity == 0) ? 1 : capacity * 2;
    Base** newArray = new Base * [newCapacity];
    for (int i = 0; i < size; ++i) {
        newArray[i] = animals[i];
    }
    delete[] animals;
    animals = newArray;
    capacity = newCapacity;
}