#include <stdio.h>
#include <math.h>
#include <locale.h>
void task1()
{
    int m, n, s = 0, k = 0;

    printf("Введите m и n: ");
    scanf("%d %d", &m, &n);

    for (int i = m; i <= n; i++)
    {
        s += i;
        k++;
        printf("выполнено %d раз\n", k);
    }
    printf("результат %d\n", s);
}
int digits(unsigned long long x)
{
    int d = 1;
    while (x >= 10)
    {
        x /= 10;
        d++;
    }
    return d;
}

void task1A()
{
    int n, m;
    printf("Введите степень n (0..62): ");
    scanf("%d", &n);
    if (n < 0 || n > 62)
    {
        printf("Недопустимое значение\n");
        return;
    }

    unsigned long long last = 1ULL << n;
    int w = digits(last);

    for (int i = 0; i <= n; i++)
        printf("2^%-2d = %*llu\n", i, w, 1ULL << i);

    printf("Результат: %gK\n", (double)last / 1024);
    printf("\nВведите целое число m: ");
    scanf("%d", &m);
    if (m < 0 || m > 62)
    {
        printf("Недопустимое значение\n");
        return;
    }

    for (int i = 0; i <= m; i++)
    {
        unsigned long long p = 1ULL << i;
        if (p >= 1024)
            printf("2^%-2d = %8.1fK\n", i, (double)p / 1024);
        else
            printf("2^%-2d = %8llu\n", i, p);
    }
}
void task2()
{
    double a = 0.1, b = 2.1, h, x;

    printf("Вычисляемая функция: y = x^2 + sin(5x), x принадлежит [0.1; 2.1]\n");
    printf("Введите шаг табуляции: ");
    scanf("%lf", &h);

    if (h <= 0)
    {
        printf("Шаг должен быть положительным\n");
        return;
    }

    printf("______________\n");
    printf("|   x  |  f(x)  |\n");
    printf("--------------\n");

    for (int i = 0; (x = a + i * h) <= b + 1e-9; i++)
        printf("| %4.2f | %7.4f |\n", x, x * x + sin(5 * x));

    printf("--------------\n");
}
int main()
{
    setlocale(LC_CTYPE, "RUS");
    int choice;

    do
    {
        printf("1.Сумма чисел от m до n\n");
        printf("2.Степени двойки\n");
        printf("3.Табулирование функции\n");
        printf("Выберите задание: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            task1();
            break;
        case 2:
            task1A();
            break;
        case 3:
            task2();
            break;
        case 0:
            printf("Выход\n");
            break;
        default:
            printf("Нет такого пункта\n");
        }
    } while (choice != 0);

    return 0;
}