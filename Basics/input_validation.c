#include <stdio.h>
#include <ctype.h> // toupper
#include <string.h> // strcspn

int main()
{
    char name[40];

    printf("Enter your name: ");
    // Only allow 39 characters to be read (leave room for NULL)
    // scanf reads until whitespace is encountered
    scanf("%39s", name);
    // fgets reads an entire line including whitespace
    fgets(name, sizeof(name), stdin);
    // Since fgets read the \n into name, replace it with NULL
    name[strcspn(name, '\n')] = '\0';
    printf("Name entered: %s", name);
    puts("");

    // Integer input validation
    int age = 0;
    char extra[64]; // Capture the extra characters after the valid input
    
    while (age <= 0)
    {
        printf("Enter your age: ");
        if(!scanf("%d", &age))
        {
            printf("Error: age must be a number\n");
            // When scanf fails (say the user entered "abc"), the invalid input is left in the buffer.
            // This line clears the buffer, so scanf can read new input, and not what was left in the buffer.
            scanf("%*s");
            // This is what you would have to do in C++
            // cin.clear();  // clear the error flag
            // cin.ignore(numeric_limits<streamsize>::max(), '\n');  // discard the bad input
        }
        // Don't allow input like "34x"
        else if (scanf("%[^\n]", extra) == 1)
        {
            printf("Error: unexpected input '%s' after age\n", extra);
            age = 0;
        }
        else if (age <= 0 || age >= 130)
            printf("Error: age must be between 1 and 130\n");
    }
    printf("Age entered: %d", age);
    puts("");

    char gender = ' ';

    while (gender != 'M' && gender != 'F')
    {
        printf("Enter your gender (M/F): ");
        // Leaving a space before the '%', skips the the whitespace left in the buffer
        // which include the \n from the previous scanf
        scanf(" %c", &gender);
        gender = toupper(gender);

        if (gender != 'M' && gender != 'F')
            printf("Error: gender must be \'M\' or \'F\'\n");
        else if (scanf("%[^\n]", extra) == 1)
        {
            printf("Error: unexpected input '%s' after gender\n", extra);
            gender = ' ';
        }

    }
    printf("Gender entered: %c", gender);
    puts("");


    return 0;
}