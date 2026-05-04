#include <stdio.h>

int main()
{
    int age = 21;
    float price = 23.99f;
    double num = 87.3879872097;
    char ch = 'J';
    char name[] = "Camden";

    printf("age: %d\n", age);
    printf("price: %f\n", price);
    printf("num: %lf\n", num);
    printf("ch: %c\n", ch);
    printf("ASCII value of ch: %d\n", ch);
    printf("name: %s\n", name);

    // ----------------------------------------------------------

    int num1 = 1;
    int num2 = 10;
    int num3 = -100;

    // set the width to 3 (padding on left)
    printf("%3d\n", num1);
    printf("%3d\n", num2);
    printf("%3d\n\n", num3);

    // add padding on the right
    printf("%-3d\n", num1);
    printf("%-3d\n", num2);
    printf("%-3d\n\n", num3);

    // pad with zeros
    printf("%03d\n", num1);
    printf("%03d\n", num2);
    printf("%03d\n\n", num3);

    // show + sign
    printf("%+d\n", num1);
    printf("%+d\n", num2);
    printf("%+d\n\n", num3);

    // decimal precision
    float price1 = 19.99f;
    float price2 = 1.50f;
    float price3 = 150.45f;
    printf("%.2f\n", price1);
    printf("%.2f\n", price2);
    printf("%.2f\n", price3);

    return 0;
}