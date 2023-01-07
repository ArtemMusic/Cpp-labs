#include <iostream>
#include <cmath>

using namespace std;

template <typename F, typename P>

class Complex
{
private:
    F real[2], im[2];

public:
    // Конструктор по умолчанию
    Complex()
    {

        cout << "Введите действительную часть комплексного числа: ";
        cin >> real[0];
        cout << "Введите мнимую часть комплексного числа: ";
        cin >> im[0];
        if (im[0] >= 0)
            cout << "Введенное число: " << real[0] << "+" << im[0] << "i" << endl;
        else
        {
            cout << "Введенное число: " << real[0] << im[0] << "i" << endl;
        }
        cout << "Модуль комплексного числа = |" << (sqrt((pow(real[0], 2)) + (pow(im[0], 2)))) << "|" << endl;

        cout << endl
             << "\t [Введите 2-ое комплексное число для проведения арифметических операций]:" << endl;
        cout << "\nДействительная часть: ";
        cin >> real[1];
        cout << "Мнимая часть: ";
        cin >> im[1];
        if (im[1] >= 0)
            cout << "Введенное число: " << real[1] << "+" << im[1] << "i" << endl;
        else
        {
            cout << "Введенное число: " << real[1] << im[1] << "i" << endl;
        }
        cout << "Модуль комплексного числа = |" << (sqrt((pow(real[1], 2)) + (pow(im[1], 2)))) << "|" << endl;

        cout << endl
             << "\t [Результаты]" << endl
             << endl;
        summ(real, im);
        dif(real, im);
        mult(real, im);
        div(real, im);
        cout << endl;
    };
    // Метод "+"
    P summ(F *real, F *im)
    {
        cout << "Сумма введенных чисел = " << real[0] + real[1] << "+(" << (im[0] + im[1]) << ")i" << endl;
        return (0);
    }
    // Метод "-"
    P dif(F *real, F *im)
    {
        cout << "Разность введенных чисел = " << real[0] - real[1] << "+(" << (im[0] - im[1]) << ")i" << endl;
        return (0);
    }
    // Метод "*"
    P mult(F *real, F *im)
    {
        cout << "Произведение введенных чисел = " << (real[0] * real[1] - im[0] * im[1]) << "+(" << im[0] * real[1] + real[0] * im[1] << ")i" << endl;
        return (0);
    }
    // Метод "/"
    P div(F *real, F *im)
    {
        cout << "Частное введенных чисел = " << (real[0] * real[1] + im[0] * im[1]) / (real[1] * real[1] + im[1] * im[1]) << "+(" << (im[0] * real[1] - real[0] * im[1]) / (real[1] * real[1] + im[1] * im[1]) << ")i" << endl;
        return (0);
    }
    ~Complex(){};
};

int main()
{
    int ans = 1, ch = 0;
    while (ans != 0)
    {
        // Задача 16 (Комплексные числа) :
        cout << "\t |КОМПЛЕКСНЫЕ ЧИСЛА|" << endl;
        Complex<float, int> first; // создание объекта класса
        break;
    }
    return 0;
}