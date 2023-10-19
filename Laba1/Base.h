#pragma once
#include <iostream>
#include <fstream>

class Base
{
private :
	char* color;
	char* breed;

public:
	Base();
	Base(const char* color, const char* breed);
	Base(const Base& other);
	virtual ~Base();

	const char* getBreed() const;
	const char* getColor() const;

	void setBreed(const char* breed);
	void setColor(const char* color);

	
	virtual void saveToFile(std::ofstream& file) const = 0;
	virtual void loadFromFile(std::ifstream& file) = 0;
};

