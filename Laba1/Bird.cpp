#include "Bird.h"
#include "Bird.h"

Bird::Bird() : diet(nullptr), habitat(nullptr) {
    std::cout << "���������� ����������� Bird �� ���������." << std::endl;
}

Bird::Bird(const char* breed, const char* color, const char* diet, const char* habitat) : Base(breed, color), diet(nullptr), habitat(nullptr) {
    setDiet(diet);
    setHabitat(habitat);
    std::cout << "���������� ����������������� ����������� Bird." << std::endl;
}

Bird::Bird(const Bird& other) : Base(other), diet(nullptr), habitat(nullptr) {
    setDiet(other.diet);
    setHabitat(other.habitat);
    std::cout << "���������� ����������� ����������� Bird." << std::endl;
}

Bird::~Bird() {
    delete[] diet;
    delete[] habitat;
    std::cout << "���������� ������ ����������." << std::endl;
}

const char* Bird::getDiet() const {
    return diet;
}

const char* Bird::getHabitat() const {
    return habitat;
}

void Bird::setDiet(const char* diet) {
    if (diet == nullptr) {
        throw std::invalid_argument("��� ������� �� ����� ���� ������");
    }

    delete[] this->diet;
    this->diet = _strdup(diet);
}

void Bird::setHabitat(const char* habitat) {
    if (habitat == nullptr) {
        throw std::invalid_argument("����� �������� �� ����� ���� ������");
    }

    delete[] this->habitat;
    this->habitat = _strdup(habitat);
}

void Bird::printInfo() const {
    std::cout << "����� - ������: " << getBreed() << ", ����: " << getColor() << ", ��� �������: " << diet << ", ����� ��������: " << habitat << std::endl;
}

void Bird::saveToFile(std::ofstream& file) const {
    file << "2 "; // �����, ��� ��������� ������ ������ Bird
    file << getBreed() << " " << getColor() << " " << diet << " " << habitat << std::endl;
}

void Bird::loadFromFile(std::ifstream& file) {
    char buffer[100];
    file >> buffer; // ��������� ������
    setBreed(buffer);
    file >> buffer; // ��������� ����
    setColor(buffer);
    file >> buffer; // ��������� ��� �������
    setDiet(buffer);
    file >> buffer; // ��������� ����� ��������
    setHabitat(buffer);
}

Bird& Bird::operator=(const Bird& other) {
    if (this != &other) { // �������� �� ����������������
        Base::operator=(other); // �������� �������� ������������ �������� ������

        setDiet(other.diet);
        setHabitat(other.habitat);
    }
    return *this;
}