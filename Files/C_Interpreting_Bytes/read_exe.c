// Read the .exe for the current file 

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fpr = fopen("read_cur_file.exe", "rb");
    if (fpr == NULL)
    {
        perror("Failed to open file");
        return 1;
    }

    int ch;
    int i = 0;

    while ((ch = fgetc(fpr)) != EOF)
    {
        printf("%02X ", (unsigned char)ch); // 02X -> pad with two zeros, print in hex
        if ((i + 1) % 32 == 0) // print 32 bytes per line
            printf("\n");
        i++;
    }

    printf("\nNumber of bytes read: %d\n", i);
    printf("File size in kilobytes %.2f:", i / 1024.0f);

    fclose(fpr);
    return 0;
}