#include "Base.h"
#define _CRT_SECURE_NO_WARNINGS
#include "Base.h"
#include <cstring>

Base::Base() : breed(nullptr), color(nullptr) {
    std::cout << "���������� ������� ����������� �� ���������." << std::endl;
}

Base::Base(const char* breed, const char* color) : breed(nullptr), color(nullptr) {
    setBreed(breed);
    setColor(color);
    std::cout << "���������� ������� ����������������� �����������." << std::endl;
}

Base::Base(const Base& other) : breed(nullptr), color(nullptr) {
    setBreed(other.breed);
    setColor(other.color);
    std::cout << "���������� ����������� �������� �����������." << std::endl;
}

Base::~Base() {
    delete[] breed;
    delete[] color;
    std::cout << "���������� ������� ����������." << std::endl;
}

const char* Base::getBreed() const {
    return breed;
}

const char* Base::getColor() const {
    return color;
}

void Base::setBreed(const char* breed) {
    delete[] this->breed;
    this->breed = _strdup(breed);
}

void Base::setColor(const char* color) {
    delete[] this->color;
    this->color = _strdup(color);
}

void Base::printInfo() const {
    std::cout << "���� - ������: " << breed << ", ����: " << color << std::endl;
}

void Base::saveToFile(std::ofstream& file) const {
    file << "1 "; // �����, ��� ��������� ������ ������ Base
    file << breed << " " << color << std::endl;
}

void Base::loadFromFile(std::ifstream& file) {
    char buffer[100];
    file >> buffer; // ��������� ������
    setBreed(buffer);
    file >> buffer; // ��������� ����
    setColor(buffer);
}