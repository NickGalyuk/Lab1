#include "Cat.h"
#include "Cat.h"

Cat::Cat() : ownerName(nullptr), petName(nullptr) {
    std::cout << "���������� ����������� Cat �� ���������." << std::endl;
}

Cat::Cat(const char* breed, const char* color, const char* ownerName, const char* petName) : Base(breed, color), ownerName(nullptr), petName(nullptr) {
    setOwnerName(ownerName);
    setPetName(petName);
    std::cout << "���������� ����������������� ����������� Cat." << std::endl;
}

Cat::Cat(const Cat& other) : Base(other), ownerName(nullptr), petName(nullptr) {
    setOwnerName(other.ownerName);
    setPetName(other.petName);
    std::cout << "���������� ����������� ����������� Cat." << std::endl;
}

Cat::~Cat() {
    delete[] ownerName;
    delete[] petName;
    std::cout << "������ ���������� Cat." << std::endl;
}

const char* Cat::getOwnerName() const {
    return ownerName;
}

const char* Cat::getPetName() const {
    return petName;
}

void Cat::setOwnerName(const char* ownerName) {
    if (ownerName == nullptr) {
        throw std::invalid_argument("��� ��������� �� ����� ���� ������");
    }

    delete[] this->ownerName;
    this->ownerName = _strdup(ownerName);
}

void Cat::setPetName(const char* petName) {
    if (petName == nullptr) {
        throw std::invalid_argument("������ �� ����� ���� ������");
    }

    delete[] this->petName;
    this->petName = _strdup(petName);
}

void Cat::printInfo() const {
    std::cout << "��� - ������: " << getBreed() << ", ����: " << getColor() << ", ��� ���������: " << ownerName << ", ������: " << petName << std::endl;
}


void Cat::loadFromFile(std::ifstream& file) {
    char buffer[100];
    file >> buffer; // ��������� ������
    setBreed(buffer);
    file >> buffer; // ��������� ����
    setColor(buffer);
    file >> buffer; // ��������� ��� ���������
    setOwnerName(buffer);
    file >> buffer; // ��������� ������
    setPetName(buffer);
}
void Cat::saveToFile(std::ofstream& file) const {
    file << "3 "; // �����, ��� ��������� ������ ������ Cat
    file << getBreed() << " " << getColor() << " " << ownerName << " " << petName << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) { // �������� �� ����������������
        Base::operator=(other); // �������� �������� ������������ �������� ������

        setOwnerName(other.ownerName);
        setPetName(other.petName);
    }
    return *this;
}