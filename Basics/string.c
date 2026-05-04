#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // this is how you create a string in C
    char str[] = {"Hello"};
    // you can modify the string
    str[0] = 'h';
    printf("%s\n", str);

    // 2D array of strings
    char *str2[] = {
        "John",
        "Mike",
        "Sam"};
    // get the number of strings in the array
    int str2_size = sizeof(str2) / sizeof(str2[0]);

    // print each string in the array
    for (int i = 0; i < str2_size; i++)
    {
        printf("%s\n", str2[i]);
    }

    // ---------------------------------------------------------------------------------------------------
    char *ch_ptr = {"taco"};
    // this is undefined behavior in C
    // the reason is because the string literal "taco" is stored in read only memory
    // ch_ptr[0] = 'T';
    printf("%s\n", ch_ptr);

    // it's best practice to mark a char* as const, since you can only read from it
    const char *ch_ptr2 = {"train"};
    // Now this will not compile, since you marked it as const
    // ch_ptr2[0] = 'T';
    printf("%s\n", ch_ptr2);
    // ---------------------------------------------------------------------------------------------------

    // if you allocate memory on the heap, you can modify it
    char *ch_ptr3 = malloc(20);
    char str3[] = "this is a test";

    // copy str3 into ch_ptr3
    strcpy(ch_ptr3, str3);
    // modifying the char* is allowed, since it points to memory on the heap
    ch_ptr3[0] = 'T';

    printf("%s\n", ch_ptr3);

    free(ch_ptr3);

    return 0;
}