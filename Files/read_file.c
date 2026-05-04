#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{

    FILE *f = fopen("read.txt", "r");
    if (f == NULL)
    {
        perror("Failed to open file");
        return 1;
    }

    // Read the file line by line
    char buffer[100];
    // fgets() read up to the specified number of characters, or until '\n' or EOF
    // '\n' is included as part of what is read, and '\0' is added automatically
    while (fgets(buffer, sizeof(buffer), f))
    {
        printf("Line: %s", buffer);
    }
    puts("\n");
    rewind(f);


    // Read the files character by character
    int ch; // ch stores the ASCII value of the character we read, since fgetc returns an int
    int i = 0;
    while ((ch = fgetc(f)) != EOF)
    {
        printf("%4d: ", ++i);

        if (ch == ' ')
            printf("[SPACE]");
        else if (ch == '\t') // this may not run, since tabs are 4 spaces (depsnds on editor)
            printf("[TAB]");
        else if (ch == '\n')
            printf("[NEWLINE]");
        else if (ch == '\r')
            printf("[CR]");
        else
            printf("[%c]", ch);

        printf("  (ASCII: %d)\n", ch);
    }
    puts("\n");
    rewind(f);


    // read from a file and store the contents in a variable
    char w1[5];
    char w2[5];
    // fscanf returns a number indicating how many input items were successfully matched and assigned
    if (fscanf(f, "%4s %4s", w1, w2) == 2)
        printf("Grabbed from read.txt: %s, %s\n", w1, w2);
    else
        printf("Error reading from file\n");
    puts("\n"); 
    rewind(f);


    // Read the file all at once

    // --- Method 1: fseek + ftell + fread (load entire file into memory) ---
    fseek(f, 0, SEEK_END);          // move to end
    long size = ftell(f);           // get file size
    rewind(f);                      // go back to beginning

    char *full_buffer = malloc(size + 1); // +1 for null terminator
    if (!full_buffer)
    {
        perror("Memory allocation failed");
        fclose(f);
        return 1;
    }

    fread(full_buffer, 1, size, f); // read entire file
    full_buffer[size] = '\0';       // make it a string

    printf("Full file (method 1):\n%s\n", full_buffer);

    free(full_buffer);
    puts("\n");
    rewind(f);


    // --- Method 2: fread in chunks (streaming) ---
    char chunk[1024];
    size_t num_read;

    printf("Full file (method 2):\n");

    // fread reads up to sizeof(chunk) bytes into "chunk".
    // It returns the number of bytes actually read (may be less at EOF).
    // Loop continues until fread returns 0, and we only process num_read bytes.
    while ((num_read = fread(chunk, 1, sizeof(chunk), f)) > 0)
    {
        for (size_t i = 0; i < num_read; i++)
        {
            putchar(chunk[i]);
        }
    }

    puts("\n\n");

    fclose(f);
    return 0;
}