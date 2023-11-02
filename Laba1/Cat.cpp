#include "Cat.h"
#include "Cat.h"

Cat::Cat() : ownerName(nullptr), petName(nullptr) {
    std::cout << "Вызывается конструктор Cat по умолчанию." << std::endl;
}

Cat::Cat(const char* breed, const char* color, const char* ownerName, const char* petName) : Base(breed, color), ownerName(nullptr), petName(nullptr) {
    setOwnerName(ownerName);
    setPetName(petName);
    std::cout << "Вызывается параметризованный конструктор Cat." << std::endl;
}

Cat::Cat(const Cat& other) : Base(other), ownerName(nullptr), petName(nullptr) {
    setOwnerName(other.ownerName);
    setPetName(other.petName);
    std::cout << "Вызывается конструктор копирования Cat." << std::endl;
}

Cat::~Cat() {
    delete[] ownerName;
    delete[] petName;
    std::cout << "Вызван деструктор Cat." << std::endl;
}

const char* Cat::getOwnerName() const {
    return ownerName;
}

const char* Cat::getPetName() const {
    return petName;
}

void Cat::setOwnerName(const char* ownerName) {
    if (ownerName == nullptr) {
        throw std::invalid_argument("Имя владельца не может быть пустым");
    }

    delete[] this->ownerName;
    this->ownerName = _strdup(ownerName);
}

void Cat::setPetName(const char* petName) {
    if (petName == nullptr) {
        throw std::invalid_argument("Кличка не может быть пустой");
    }

    delete[] this->petName;
    this->petName = _strdup(petName);
}

void Cat::printInfo() const {
    std::cout << "Кот - Порода: " << getBreed() << ", Цвет: " << getColor() << ", Имя владельца: " << ownerName << ", Кличка: " << petName << std::endl;
}


void Cat::loadFromFile(std::ifstream& file) {
    char buffer[100];
    file >> buffer; // Считываем породу
    setBreed(buffer);
    file >> buffer; // Считываем цвет
    setColor(buffer);
    file >> buffer; // Считываем имя владельца
    setOwnerName(buffer);
    file >> buffer; // Считываем кличку
    setPetName(buffer);
}
void Cat::saveToFile(std::ofstream& file) const {
    file << "3 "; // Метка, что сохраняем объект класса Cat
    file << getBreed() << " " << getColor() << " " << ownerName << " " << petName << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) { // Проверка на самоприсваивание
        Base::operator=(other); // Вызываем оператор присваивания базового класса

        setOwnerName(other.ownerName);
        setPetName(other.petName);
    }
    return *this;
}