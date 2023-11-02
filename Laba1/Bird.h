#pragma once

#ifndef BIRD_H
#define BIRD_H

#include "Base.h"

class Bird : public Base {
public:
    Bird();
    Bird(const char* breed, const char* color, const char* diet, const char* habitat);
    Bird(const Bird& other);
    ~Bird();

    const char* getDiet() const;
    const char* getHabitat() const;

    void printInfo() const override;
    void saveToFile(std::ofstream& file) const override;
    void loadFromFile(std::ifstream& file) override;

    Bird& operator=(const Bird& other);
    void setDiet(const char* diet);
    void setHabitat(const char* habitat);

private:
    char* diet;
    char* habitat;
};

#endif