#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fpw = fopen("write.txt", "w");
    if (fpw == NULL)
    {
        perror("Failed to open file");
        return 1;
    }

    char buffer[] = {"this is a bunch of random text...\n"};
    // write formatted ouput to the file
    fprintf(fpw, "%s", buffer);
    // write a string to the file
    fputs("Another line\n", fpw);
    // write a character to the file
    fputc('A', fpw);

    // overwrite part of a file with fwrite
    // provide the object to write to the file, the size of each element in bytes
    // the number of elements in the object, and the file pointer
    fseek(fpw, 0, SEEK_SET); // SEEK_SET = START OF FILE, SEEK_END = END OF FILE, and SEEK_CUR = CURRENT POSITION IN FILE
    char str[] = {"abc123"};
    fwrite(str, sizeof(char), strlen(str), fpw);

    fclose(fpw);
    return 0;
}