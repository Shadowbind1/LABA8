#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <windows.h>

void print_symbols(int n, char ch);
int sum_range(int m, int n);
void powers_of_two(int n);
void tabulate_function(double start, double end, double step);
double series_sum(int n, double x);   


int main(void)
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, ".UTF-8");

    int choice;

    printf("=== Работа 8. Цикл с параметрами ===\n");
    printf("0 - Печать символов\n");
    printf("1 - Сумма чисел от m до n\n");
    printf("1A - Степени двойки\n");
    printf("2 - Табулирование функции\n");
    printf("3 - Сумма ряда (индивидуальный)\n");
    printf("Выберите задание: ");
    scanf("%d", &choice);


    if (choice == 0)
    {
        int n;
        char ch;
        printf("Введите количество символов и сам символ: ");
        scanf("%d %c", &n, &ch);
        print_symbols(n, ch);
    }

    else if (choice == 1)
    {
        int m, n;
        printf("Введите m и n: ");
        scanf("%d %d", &m, &n);
        printf("Сумма = %d\n", sum_range(m, n));
    }


    else if (choice == 11)  
    {
        int n;
        printf("Введите максимальную степень n: ");
        scanf("%d", &n);
        powers_of_two(n);
    }


    else if (choice == 2)
    {
        double a, b, h;
        printf("Функция: f(x) = x*x - 3*x + 2\n");
        printf("Введите начало, конец и шаг: ");
        scanf("%lf %lf %lf", &a, &b, &h);
        tabulate_function(a, b, h);
    }


    else if (choice == 3)
    {
        int n;
        double x;
        printf("Сумма ряда S = 1 + x + x^2/2! + ... + x^n/n!\n");
        printf("Введите n и x: ");
        scanf("%d %lf", &n, &x);
        printf("S = %.6f\n", series_sum(n, x));
    }

    else
    {
        printf("Неверный номер задания!\n");
    }

    return 0;
}


void print_symbols(int n, char ch)
{
    int i;
    printf("+");
    for (i = 1; i <= n; i++)
    {
        putchar(ch);
        putchar('!');
    }
    printf("+\n");
}


int sum_range(int m, int n)
{
    int i, s = 0;
    if (m > n) { int t = m; m = n; n = t; }

    for (i = m; i <= n; i++)
        s += i;

    return s;
}

void powers_of_two(int n)
{
    int i;
    long long p = 1;

    for (i = 0; i <= n; i++)
    {
        printf("2^%d = %10lld", i, p);

        if (p >= 1024)
            printf("  (%.1fK)\n", p / 1024.0);
        else
            printf("\n");

        p *= 2;
    }
}

void tabulate_function(double start, double end, double step)
{
    double x;

    printf("-------------------\n");
    printf("|   x   |   f(x)  |\n");
    printf("-------------------\n");

    for (x = start; x <= end + 1e-9; x += step)
    {
        double fx = x * x - 3 * x + 2;
        printf("| %5.2f | %7.3f |\n", x, fx);
    }
    printf("-------------------\n");
}

double series_sum(int n, double x)
{
    int k;
    double sum = 1.0;
    double term = 1.0;

    for (k = 1; k <= n; k++)
    {
        term *= x / k;
        sum += term;
    }
    return sum;
}