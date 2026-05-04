#include <stdio.h>
#include <stdlib.h>

#define ALPHABET_LEN 26

typedef struct
{
    int x;
    int y;
} vec2_t;

char *string_calloc(size_t size);
char *string_realloc(char *original, size_t new_len);
vec2_t *vec2_malloc();

int main()
{
    {
        // string to store the alphabet (+1 needed for '\0')
        char *str = string_calloc(ALPHABET_LEN + 1);

        // fill the string with the alphabet
        for (size_t i = 0; i < ALPHABET_LEN; i++)
        {
            str[i] = 'a' + i;
        }

        printf("Alphabet: %s\n", str);

        printf("Reallocating string...\n");

        // make enough room for the alphabet to be listed twice
        str = string_realloc(str, (2 * ALPHABET_LEN) + 1);

        // fill the string with a second alphabet
        for (size_t i = 0; i < ALPHABET_LEN; i++)
        {
            str[ALPHABET_LEN + i] = 'a' + i;
        }

        printf("Alphabet x2: %s\n", str);

        free(str);
    }

    {
        // struct that represents a 2D point
        vec2_t *point = vec2_malloc();

        // set the values of the struct
        point->x = 28;
        point->y = 829;

        printf("Point: (%d, %d)\n", point->x, point->y);

        free(point);
    }

    return 0;
}

// Use calloc when: You need a new block of memory for a string or array,
// and you want all bytes initialized to zero (e.g., for null-terminated strings).
// This is useful when you're dealing with character data and need automatic '\0' padding.
char *string_calloc(size_t size)
{
    char *str = calloc(size, sizeof(*str));
    if (!str)
    {
        perror("calloc failed!");
        exit(EXIT_FAILURE);
    }

    return str;
}

// Use malloc when: You need to allocate a new block of memory for a single object or struct,
// but you do not need it to be zero-initialized. Faster than calloc, but contents are undefined.
// Ideal for general-purpose object creation where you'll manually set fields.
vec2_t *vec2_malloc()
{
    vec2_t *point = malloc(sizeof(*point));
    if (!point)
    {
        perror("malloc failed!");
        exit(EXIT_FAILURE);
    }

    return point;
}

// Use realloc when: You already have an allocated memory block and need to resize it,
// either to make it larger (e.g., growing a dynamic array) or smaller.
// This preserves existing data, but may move the block to a new location.
char *string_realloc(char *original, size_t new_len)
{
    original = realloc(original, new_len);
    if (!original)
    {
        perror("realloc failed!");
        exit(EXIT_FAILURE);
    }

    return original;
}