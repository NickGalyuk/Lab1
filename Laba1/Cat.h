#pragma once
#include "Base.h"

class Cat : public Base 
{
private:
    char* ownerName;
    char* petName;

public:
    Cat();
    Cat(const char* breed, const char* color, const char* ownerName, const char* petName);
    Cat(const Cat& other);
    ~Cat();

    const char* getOwnerName() const;
    const char* getPetName() const;

    void setOwnerName(const char* ownerName);
    void setPetName(const char* petName);

    void printInfo() const;

    void saveToFile(std::ofstream& file) const override;
    void loadFromFile(std::ifstream& file) override;
};

