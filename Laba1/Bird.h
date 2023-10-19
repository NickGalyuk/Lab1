#pragma once
#include "Base.h"
#ifndef BIRD_H
#define BIRD_H
class Bird : public Base
{
private :
	char* habitat;
	char* howEat;

public:
    Bird();
    Bird(const char* breed, const char* color, const char* howEat, const char* habitat);
    Bird(const Bird& other);
    ~Bird();

    const char* gethowEat() const;
    const char* gethabitat() const;

    void sethowEat(const char* howEat);
    void sethabitat(const char* habitat);

    
    void saveToFile(std::ofstream& file) const override;
    void loadFromFile(std::ifstream& file) override;

};

#endif