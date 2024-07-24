#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

void write_uint32_to_file(const char *filename, uint32_t value) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    value = htonl(value); // Convert to network byte order
    fwrite(&value, sizeof(uint32_t), 1, file);
    fclose(file);
}

int main() {
    write_uint32_to_file("thousand.bin", 1000);
    write_uint32_to_file("five-hundred.bin", 500);
    return 0;
}
