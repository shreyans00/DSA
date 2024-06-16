// Program to convert decimal to fraction

#include <iostream>
#include <valarray>

using namespace std;

void as_fraction(double number, int cycles = 10, double precision = 5e-4)
{
    int sign = number > 0 ? 1 : -1;
    number = number * sign; //abs(number);
    double new_number, whole_part;
    double decimal_part = number - (int)number;
    int counter = 0;

    valarray<double> vec_1{double((int)number), 1}, vec_2{1, 0}, temporary;

    while (decimal_part > precision & counter < cycles)
    {
        new_number = 1 / decimal_part;
        whole_part = (int)new_number;

        temporary = vec_1;
        vec_1 = whole_part * vec_1 + vec_2;
        vec_2 = temporary;

        decimal_part = new_number - whole_part;
        counter += 1;
    }
    cout << "x: " << number << "\tFraction: " << sign * vec_1[0] << '/' << vec_1[1] << endl;
}

int main()
{
    as_fraction(3.142857);
    as_fraction(0.2);
    as_fraction(0.333333);
    as_fraction(514.0 / 37.0);
    as_fraction(1.17171717);
    as_fraction(-1.17);
}