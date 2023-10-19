#pragma once
#include "Base.h"

class Fish : public Base 
{
private:
    char* foodtype;

public:
    Fish();
    Fish(const char* breed, const char* color, const char* foodtype);
    Fish(const Fish& other);
    ~Fish();

    const char* getfoodtype() const;
    void setfoodtype(const char* foodtype);

    
    void saveToFile(std::ofstream& file) const override;
    void loadFromFile(std::ifstream& file) override;
};