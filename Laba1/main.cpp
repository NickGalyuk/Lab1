#include <iostream>
#include "Keeper.h"
#include "Fish.h"
#include "Bird.h"
#include "Cat.h"

int main() {
    setlocale(LC_ALL, "Russian");

    Keeper keeper;

    while (true) {
        std::cout << "\nМеню (Ввод осуществляется на анлийском языке):\n"
            "1. Добавьте рыбу\n"
            "2. Добавьте птицу\n"
            "3. Добавьте кота\n"
            "4. Удалить животное\n"
            "5. Напечатать всех животных\n"
            "6. Сохранить в файл\n"
            "7. Загрузка из файла\n"
            "8. Выход\n";

        int choice;
        std::cout << "Введите свой выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            char breed[100], color[100], diet[100];
            std::cout << "Введите данные о рыбе:\n";
            std::cout << "Порода: ";
            std::cin >> breed;
            std::cout << "Цвет: ";
            std::cin >> color;
            std::cout << "Тип питания: ";
            std::cin >> diet;
            keeper.addAnimal(new Fish(breed, color, diet));
            break;
        }
        case 2: {
            char breed[100], color[100], diet[100], habitat[100];
            std::cout << "Введите данные о птице:\n";
            std::cout << "Порода: ";
            std::cin >> breed;
            std::cout << "Цвет: ";
            std::cin >> color;
            std::cout << "Тип питания: ";
            std::cin >> diet;
            std::cout << "Среда обитания: ";
            std::cin >> habitat;
            keeper.addAnimal(new Bird(breed, color, diet, habitat));
            break;
        }
        case 3: {
            char breed[100], color[100], ownerName[100], petName[100];
            std::cout << "Введите данные о кошке:\n";
            std::cout << "Порода: ";
            std::cin >> breed;
            std::cout << "Цвет: ";
            std::cin >> color;
            std::cout << "Имя владельца: ";
            std::cin >> ownerName;
            std::cout << "Кличка: ";
            std::cin >> petName;
            keeper.addAnimal(new Cat(breed, color, ownerName, petName));
            break;
        }
        case 4: {
            int index;
            std::cout << "Введите индекс животного, которое требуется удалить: ";
            std::cin >> index;
            keeper.removeAnimal(index);
            break;
        }
        case 5:
            std::cout << "Все животные:\n";
            keeper.printAllAnimals();
            break;
        case 6: {
            char filename[100];
            std::cout << "Введите имя файла для сохранения: ";
            std::cin >> filename;
            keeper.saveToFile(filename);
            break;
        }
        case 7: {
            char filename[100];
            std::cout << "Введите имя файла для загрузки: ";
            std::cin >> filename;
            keeper.loadFromFile(filename);
            break;
        }
        case 8:
            std::cout << "Выход из программы.\n";
            return 0;
        default:
            std::cout << "Неверный выбор. Пожалуйста, введите число от 1 до 8.\n";
        }
    }

    return 0;
}
