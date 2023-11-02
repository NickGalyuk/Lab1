#include "Fish.h"
#include "Fish.h"

Fish::Fish() : feedingType(nullptr) {
    std::cout << "���������� ����������� Fish �� ���������." << std::endl;
}

Fish::Fish(const char* breed, const char* color, const char* feedingType) : Base(breed, color), feedingType(nullptr) {
    setFeedingType(feedingType);
    std::cout << "���������� ����������������� ����������� Fish." << std::endl;
}

Fish::Fish(const Fish& other) : Base(other), feedingType(nullptr) {
    setFeedingType(other.feedingType);
    std::cout << "���������� ����������� ����������� Fish." << std::endl;
}

Fish::~Fish() {
    delete[] feedingType;
    std::cout << "��������� ���������� ����." << std::endl;
}

const char* Fish::getFeedingType() const {
    return feedingType;
}

void Fish::printInfo() const {
    std::cout << "���� - ������: " << getBreed() << ", ����: " << getColor() << ", ��� �������: " << feedingType << std::endl;
}

void Fish::saveToFile(std::ofstream& file) const {
    file << "1 "; // �����, ��� ��������� ������ ������ Fish
    file << getBreed() << " " << getColor() << " " << feedingType << std::endl;
}

void Fish::loadFromFile(std::ifstream& file) {
    char buffer[100];
    file >> buffer; // ��������� ������
    setBreed(buffer);
    file >> buffer; // ��������� ����
    setColor(buffer);
    file >> buffer; // ��������� ��� �������
    setFeedingType(buffer);
}

Fish& Fish::operator=(const Fish& other) {
    if (this != &other) { // �������� �� ����������������
        Base::operator=(other); // �������� �������� ������������ �������� ������

        setFeedingType(other.feedingType);
    }
    return *this;
}

void Fish::setFeedingType(const char* feedingType) {
    if (feedingType == nullptr) {
        throw std::invalid_argument("��� ������� �� ����� ���� ������");
    }

    delete[] this->feedingType;
    size_t len = strlen(feedingType) + 1;
    this->feedingType = new char[len];
    strcpy_s(this->feedingType, len, feedingType);
}