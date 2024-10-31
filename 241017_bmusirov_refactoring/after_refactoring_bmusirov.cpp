#include <iostream>

int main()
{
    int day;
    std::cout << "Введите дату дня: " << std::endl;
    std::cin >> day;

    int month;
    std::cout << "Введите число месяца: " << std::endl;
    std::cin >> month;

    int year;
    std::cout << "Введите год: " << std::endl;
    std::cin >> year;

    int first_digits, last_digits;
    last_digits = year % 100;
    first_digits = year / 100;

    int weekday;
    weekday = (day 
            + ((13 * month - 1) / 5) 
            + last_digits 
            + (last_digits / 4) 
            + (first_digits / 4) 
            - (2 * first_digits))
            % 7;
    
    std::cout << "День недели: ";

    switch (weekday)
    {   
        case 0:
            std::cout << "Вторник" << std::endl;
            break;
        case 1:
            std::cout << "Среда" << std::endl;
            break;
        case 2:
            std::cout << "Четверг" << std::endl;
            break;
        case 3:
            std::cout << "Пятница" << std::endl;
            break;
        case 4:
            std::cout << "Суббота" << std::endl;
            break;
        case 5:
            std::cout << "Воскресенье" << std::endl;
            break;
        case 6:
            std::cout << "Понедельник" << std::endl;
            break;
    }
    return 0;
}