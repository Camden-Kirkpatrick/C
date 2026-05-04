#include <stdio.h>

int main()
{
    // printf is used to print to stdout
    printf("Hello, World!\n");

    // fprintf is used to print to a specific output stream
    fprintf(stdout, "Printing to stdout\n");
    fprintf(stderr, "Printing to stderr\n");

    // puts is simpler than printf, it only prints a string followed by a newline
    puts("This is a simple version of printf");

    // putchar is used to print a single character
    char ch;

    for (ch = 'A'; ch <= 'Z'; ch++)
    {
        putchar(ch);
    }

    // fputc is similar to putchar, but it allows output to other streams
    fputc('B', stderr);
    fputc('E', stderr);

    // fputs is similar to puts, but it allows output to other streams, and doesn't add a newline automatically
    fputs("This is similar to puts\n", stdout);

    // snprintf writes formatted output to a string buffer instead of printing, and has bounds checking
    char buffer[100];
    snprintf(buffer, sizeof(buffer), "Score: %d", 100);
    printf("%s", buffer);

    return 0;
}