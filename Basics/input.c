#include <stdio.h>

int main()
{
    // -------------------------------------------------------------------
    // SCANF
    char buffer[50];

    // scanf read until whitespace is encountered
    printf("Enter a word: ");
    // The 49 ensures that you don't overflow the buffer
    scanf("%49s", buffer);

    printf("buffer: %s\n", buffer);


    printf("Enter an integer: ");

    // When entering a number, you need to make sure that the input went through
    int x;
    if (scanf("%d", &x) == 1)
    {
        printf("Integer: %d\n", x);
    }
    else
        puts("Invalid input!");


    printf("Enter a floating point number: ");

    // When entering a double, be sure to use %lf, not just %f
    double num;
    if (scanf("%lf", &num) == 1)
    {
        printf("Double: %lf\n", num);
    }
    else
        puts("Invalid input!");

    // -------------------------------------------------------------------
    // FLUSH THE INPUT BUFFER

    // When you use scanf, it leaves a '\n' in the input buffer
    // If you use fgets directly after using scanf, then it will immediately read the '\n'
    // that was left in the input buffer. The code below consumes the '\n' that was left.
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
    // -------------------------------------------------------------------
    // FGETS

    char line[256];

    // fgets is used to read an entire line of text, including whitespace
    printf("Enter a line of text: ");
    fgets(line, sizeof(line), stdin);

    printf("line: %s", line);
    // -------------------------------------------------------------------



    // GETCHAR

    // getchar is used to read a single character
    // the ASCII value of the entered character is stored
    printf("Press any key: ");
    char ch = getchar();
    printf("You typed: %c\n", ch);
    // -------------------------------------------------------------------
    // PARSING A STRING WITH SSCANF

    char buff[] = "Name: Camden Age: 21";
    char name[20];
    int userAge;

    // Return the number of items successfully read from buff
    int itemsRead = sscanf(buff, "Name: %s Age: %d", name, &userAge);

    if (itemsRead == 2)
    {
        printf("Name: %s\n", name);
        printf("Age: %d\n", userAge);
    }
    else
        puts("Failed to parse the string");

    return 0;
}