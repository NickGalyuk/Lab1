#include <iostream>
#include "Keeper.h"
#include "Fish.h"
#include "Bird.h"
#include "Cat.h"

int main() {
    setlocale(LC_ALL, "Russian");

    Keeper keeper;

    while (true) {
        std::cout << "\n���� (���� �������������� �� ��������� �����):\n"
            "1. �������� ����\n"
            "2. �������� �����\n"
            "3. �������� ����\n"
            "4. ������� ��������\n"
            "5. ���������� ���� ��������\n"
            "6. ��������� � ����\n"
            "7. �������� �� �����\n"
            "8. �����\n";

        int choice;
        std::cout << "������� ���� �����: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            char breed[100], color[100], diet[100];
            std::cout << "������� ������ � ����:\n";
            std::cout << "������: ";
            std::cin >> breed;
            std::cout << "����: ";
            std::cin >> color;
            std::cout << "��� �������: ";
            std::cin >> diet;
            keeper.addAnimal(new Fish(breed, color, diet));
            break;
        }
        case 2: {
            char breed[100], color[100], diet[100], habitat[100];
            std::cout << "������� ������ � �����:\n";
            std::cout << "������: ";
            std::cin >> breed;
            std::cout << "����: ";
            std::cin >> color;
            std::cout << "��� �������: ";
            std::cin >> diet;
            std::cout << "����� ��������: ";
            std::cin >> habitat;
            keeper.addAnimal(new Bird(breed, color, diet, habitat));
            break;
        }
        case 3: {
            char breed[100], color[100], ownerName[100], petName[100];
            std::cout << "������� ������ � �����:\n";
            std::cout << "������: ";
            std::cin >> breed;
            std::cout << "����: ";
            std::cin >> color;
            std::cout << "��� ���������: ";
            std::cin >> ownerName;
            std::cout << "������: ";
            std::cin >> petName;
            keeper.addAnimal(new Cat(breed, color, ownerName, petName));
            break;
        }
        case 4: {
            int index;
            std::cout << "������� ������ ���������, ������� ��������� �������: ";
            std::cin >> index;
            keeper.removeAnimal(index);
            break;
        }
        case 5:
            std::cout << "��� ��������:\n";
            keeper.printAllAnimals();
            break;
        case 6: {
            char filename[100];
            std::cout << "������� ��� ����� ��� ����������: ";
            std::cin >> filename;
            keeper.saveToFile(filename);
            break;
        }
        case 7: {
            char filename[100];
            std::cout << "������� ��� ����� ��� ��������: ";
            std::cin >> filename;
            keeper.loadFromFile(filename);
            break;
        }
        case 8:
            std::cout << "����� �� ���������.\n";
            return 0;
        default:
            std::cout << "�������� �����. ����������, ������� ����� �� 1 �� 8.\n";
        }
    }

    return 0;
}
