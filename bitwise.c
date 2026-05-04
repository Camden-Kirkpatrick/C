#include <stdio.h>

// Prints a 4-bit binary representation of n
// Uses a mask (1 << i) to check each bit from left to right
void print_binary(unsigned int n)
{
    for (int i = 3; i >= 0; i--)
    {
        // (1 << i) creates a mask with only the i-th bit set
        // n & mask checks if that bit is ON (non-zero) or OFF (zero)
        printf("%d", (n & (1 << i)) != 0);
    }
}

// Prints a stacked visualization of a bitwise operation
void print_operation(const char *op, unsigned int a, unsigned int b, unsigned int result)
{
    printf("  ");
    print_binary(a);
    printf("   (a = %u)\n", a);

    printf("%s ", op);
    print_binary(b);
    printf("   (b = %u)\n", b);

    printf("------\n  ");
    print_binary(result);
    printf("   (%u)\n\n", result);
}

int main()
{
    unsigned int a = 14; // 1110
    unsigned int b = 9;  // 1001

    // Original values (decimal and binary)
    printf("a = %u (", a);
    print_binary(a);
    printf(")\n");

    printf("b = %u (", b);
    print_binary(b);
    printf(")\n\n");

    // Bit Shifting
    // Left shift (<<) moves all bits to the left
    // Each shift left multiplies the number by 2 (for unsigned integers)
    // Example: 1110 << 1 -> 1100 (14 -> 28)
    printf("Left Shift:\n");
    printf("a << 1 = %u (", a << 1);
    print_binary(a << 1);
    printf(")\n\n");

    // Right shift (>>) moves all bits to the right
    // Each shift right divides the number by 2 (integer division)
    // Example: 1110 >> 1 -> 0111 (14 -> 7)
    printf("Right Shift:\n");
    printf("a >> 1 = %u (", a >> 1);
    print_binary(a >> 1);
    printf(")\n\n");

    // AND, OR, XOR, and NOT

    // Bitwise AND (&)
    // Result bit is 1 ONLY if both bits are 1
    // Example:
    //   1110
    // & 1001
    // = 1000
    printf("Bitwise AND:\n");
    print_operation("&", a, b, a & b);

    // Bitwise OR (|)
    // Result bit is 1 if EITHER bit is 1
    // Example:
    //   1110
    // | 1001
    // = 1111
    printf("Bitwise OR:\n");
    print_operation("|", a, b, a | b);

    // Bitwise XOR (^)
    // Result bit is 1 if bits are DIFFERENT, 0 if they are the same
    // Example:
    //   1110
    // ^ 1001
    // = 0111
    printf("Bitwise XOR:\n");
    print_operation("^", a, b, a ^ b);

    // Bitwise NOT (~)
    // ~ flips ALL bits (usually 32 bits), not just the 4 we display,
    // so we mask with 0xF (1111) to keep only the last 4 bits
    // Example:
    //   1110
    // ~ ----
    //   0001
    printf("Bitwise NOT (~a):\n");

    unsigned int not_a = ~a;

    printf("~ ");
    print_binary(a);
    printf("   (a = %u)\n", a);

    printf("------\n  ");
    print_binary(not_a & 0xF); // mask to keep only 4 bits
    printf("   (%u masked to 4 bits)\n\n", not_a & 0xF);

    return 0;
}