#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <arpa/inet.h> // for ntohl

uint32_t read_uint32_from_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    uint32_t number;
    size_t result = fread(&number, sizeof(uint32_t), 1, file);
    if (result != 1) {
        fprintf(stderr, "Error reading from file %s\n", filename);
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fclose(file);

    // Convert from network byte order to host byte order
    number = ntohl(number);

    return number;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
        return EXIT_FAILURE;
    }

    uint32_t num1 = read_uint32_from_file(argv[1]);
    uint32_t num2 = read_uint32_from_file(argv[2]);

    uint32_t sum = num1 + num2;

    printf("%u (0x%x) + %u (0x%x) = %u (0x%x)\n", num1, num1, num2, num2, sum, sum);

    return EXIT_SUCCESS;
}
