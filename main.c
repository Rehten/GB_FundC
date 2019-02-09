#include <stdio.h>

enum Elems {
    U0 = 1,
    Ui = 2,
    R1 = 3,
    R2 = 4
};

void select_elem(enum Elems *index) {
    printf("Выберите, какой элемент из списка вы хотите найти?\n");
    printf("1 - Uo\n");
    printf("2 - Ui\n");
    printf("3 - R1\n");
    printf("4 - R2\n\n");
    printf("Введите число: ");

    scanf("%d", index);

    printf("\n\n");
    printf("Вы выбрали число %d\n\n", *index);
}

void calculate(enum Elems index, double *u0, double *ui, double *r1, double *r2) {
    switch (index) {
        case U0:
            printf("\nВведите Ui: ");
            scanf("%lf", ui);
            printf("Введите R1: ");
            scanf("%lf", r1);
            printf("Введите R2: ");
            scanf("%lf", r2);
            *u0 = *ui * (*r1/(*r1 + *r2));
            printf("\nUo равно %7.2lf\n\n", *u0);
            return;
        case Ui:
            printf("\nВведите Uo: ");
            scanf("%lf", u0);
            printf("Введите R1: ");
            scanf("%lf", r1);
            printf("Введите R2: ");
            scanf("%lf", r2);
            *ui = *u0 / (*r1/(*r1 + *r2));
            printf("\nUi равно %7.2lf\n\n", *u0);
            return;
        case R1:
            printf("\nВведите Uo: ");
            scanf("%lf", u0);
            printf("\nВведите Ui: ");
            scanf("%lf", ui);
            printf("Введите R2: ");
            scanf("%lf", r2);
            *r1 = (*u0 * *r2) / (*ui - *u0);
            printf("\nR1 равно %7.2lf\n\n", *u0);
            return;
        case R2:
            printf("\nВведите Uo: ");
            scanf("%lf", u0);
            printf("\nВведите Ui: ");
            scanf("%lf", ui);
            printf("Введите R1: ");
            scanf("%lf", r1);
            *r2 = (*ui - *u0) * *r1 / *u0;
            printf("\nR2 равно %7.2lf\n\n", *u0);
            return;
        default:
            printf("Выбранный Вами вариант отсутствует\n");
    }
}

int main() {
    // при формуле Uo = Ui * (R1 / (R2 + R1))
    double u0;
    double ui;
    double r1;
    double r2;
    enum Elems index; // По умолчанию программа вычисляет ищет Uo

    printf("Добро пожаловать в мою программу-калькулятор сопротивления на языке C:\n\n");

    select_elem(&index);

    calculate(index, &u0, &ui, &r1, &r2);


    printf("При Ui = %7.2f, R1 = %7.2f, R2 = %7.2f, Uo: %7.2f\n", ui, r1, r2, u0);
    return 0;
}
