#include <clocale>
#include <iostream>


void task1() {
    unsigned int rows;
    std::cout << "\tЗадание №1\n";
    std::cout << "Введите количество строк: ";
    std::cin >> rows;
    for (int i = 0; i <= rows; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << j;
        }
        std::cout << "\n";
    }
    std::cout << "\n\n";
}

void task2() {
    unsigned int c = 1, k = 1, n = 1;
    std::cout << "\tЗадание №2\n";
    std::cout << "Введите значения переменных: ";
    std::cin >> n >> k;
    for (int i = n - k + 1; i <= n; i++)
        c *= i;
    for (int i = 2; i <= k; i++)
        c /= i;
    std::cout << "Последовательность биномиальных коэффициентов: " << c << std::endl;
    std::cout << "\n\n";
}
void task3() {
    bool stop = false;
    int num = 0, num_1 = 0, amount = 0;
    std::cout << "\tЗадание №3\n";
    while (!stop) {
        std::cout << "Введите число(где 0 - выход из цикла): ";
        std::cin >> num;
        num_1 += num;
        if (num != 0)
            amount++;
        if (num == 0) {
            std::cout << "Сумма всех введенных чисел = " << num_1 << std::endl;
            std::cout << "Количество введеных чисел = " << amount << std::endl;
            stop = true;
        }
    }
    std::cout << "Среднее арифметическое =" << num_1 / amount;
    std::cout << "\n\n";
}



int main()
{
    setlocale(LC_ALL, "Russian");
    unsigned short choice;
    std::cout << "Введите номер задания(1/2/3/0, 0 это выход): ";
    std::cin >> choice;
    while (choice != 0) {
        switch (choice)
        {
        case 1:
            task1();
            std::cout << "Введите номер задания(1/2/3, 0 это выход): ";
            std::cin >> choice;
            break;
        case 2:
            task2();
            std::cout << "Введите номер задания(1/2/3, 0 это выход): ";
            std::cin >> choice;
            break;
        case 3:
            task3();
            std::cout << "Введите номер задания(1/2/3, 0 это выход): ";
            std::cin >> choice;
            break;
        case 0:
            break;
        default:
            std::cout << "Неверное число(\n";
            std::cout << "Введите номер задания(1/2/3, 0 это выход): ";
            std::cin >> choice;
            break;
        }
    }
    return 0;
}
