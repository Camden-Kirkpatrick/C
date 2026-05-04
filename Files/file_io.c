#include <stdio.h>
#include <string.h>

int main()
{
    FILE *f = fopen("seek.txt", "r");
    if (f == NULL)
    {
        perror("Failed to open file");
        return 1;
    }

    // get the first character in the file and print it
    int ch2 = fgetc(f);
    putchar(ch2);

    // SEEK_SET is used to move the file pointer from the start of the file
    // ->ab->c
    fseek(f, 2, SEEK_SET);
    ch2 = fgetc(f);
    putchar(ch2);

    // after reading 'c', the file pointer now points to 'd' in the next position

    putchar('\n');

    // ftell is used to get the position of the file pointer
    long pos = ftell(f);
    printf("Pos: %ld\n", pos);

    // SEEK_CUR is used to move the file pointer from the current position
    fseek(f, 1, SEEK_CUR);
    ch2 = fgetc(f);
    putchar(ch2);

    // SEEK_END is used to move the file pointer from the end of the file.
    fseek(f, -1, SEEK_END);
    ch2 = fgetc(f);
    putchar(ch2);

    // you can use negative numbers to go backwards instead
    fseek(f, -5, SEEK_CUR);
    ch2 = fgetc(f);
    putchar(ch2);

    putchar('\n');

    // ftell gives you the position of the file pointer
    fseek(f, 0, SEEK_END);
    printf("Size of file in bytes: %d", ftell(f));

    fclose(f);

    return 0;
}