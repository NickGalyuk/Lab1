#pragma once


#include "Base.h"

class Fish : public Base {
private:
    char* feedingType;

public:
    Fish();
    Fish(const char* breed, const char* color, const char* feedingType);
    Fish(const Fish& other);
    ~Fish();

    const char* getFeedingType() const;

    void printInfo() const override;
    void saveToFile(std::ofstream& file) const override;
    void loadFromFile(std::ifstream& file) override;

    Fish& operator=(const Fish& other);
    void setFeedingType(const char* feedingType);
};