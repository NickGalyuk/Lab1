#include "Bird.h"
#include "Bird.h"

Bird::Bird() : diet(nullptr), habitat(nullptr) {
    std::cout << "Вызывается конструктор Bird по умолчанию." << std::endl;
}

Bird::Bird(const char* breed, const char* color, const char* diet, const char* habitat) : Base(breed, color), diet(nullptr), habitat(nullptr) {
    setDiet(diet);
    setHabitat(habitat);
    std::cout << "Вызывается параметризованный конструктор Bird." << std::endl;
}

Bird::Bird(const Bird& other) : Base(other), diet(nullptr), habitat(nullptr) {
    setDiet(other.diet);
    setHabitat(other.habitat);
    std::cout << "Вызывается конструктор копирования Bird." << std::endl;
}

Bird::~Bird() {
    delete[] diet;
    delete[] habitat;
    std::cout << "Вызывается птичий деструктор." << std::endl;
}

const char* Bird::getDiet() const {
    return diet;
}

const char* Bird::getHabitat() const {
    return habitat;
}

void Bird::setDiet(const char* diet) {
    if (diet == nullptr) {
        throw std::invalid_argument("Тип питания не может быть пустым");
    }

    delete[] this->diet;
    this->diet = _strdup(diet);
}

void Bird::setHabitat(const char* habitat) {
    if (habitat == nullptr) {
        throw std::invalid_argument("Среда обитания не может быть пустой");
    }

    delete[] this->habitat;
    this->habitat = _strdup(habitat);
}

void Bird::printInfo() const {
    std::cout << "Птица - Порода: " << getBreed() << ", Цвет: " << getColor() << ", Тип питания: " << diet << ", Среда обитания: " << habitat << std::endl;
}

void Bird::saveToFile(std::ofstream& file) const {
    file << "2 "; // Метка, что сохраняем объект класса Bird
    file << getBreed() << " " << getColor() << " " << diet << " " << habitat << std::endl;
}

void Bird::loadFromFile(std::ifstream& file) {
    char buffer[100];
    file >> buffer; // Считываем породу
    setBreed(buffer);
    file >> buffer; // Считываем цвет
    setColor(buffer);
    file >> buffer; // Считываем тип питания
    setDiet(buffer);
    file >> buffer; // Считываем место обитания
    setHabitat(buffer);
}

Bird& Bird::operator=(const Bird& other) {
    if (this != &other) { // Проверка на самоприсваивание
        Base::operator=(other); // Вызываем оператор присваивания базового класса

        setDiet(other.diet);
        setHabitat(other.habitat);
    }
    return *this;
}