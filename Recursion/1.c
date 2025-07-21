#include <stdio.h>
#include <stdlib.h>

void toBinary(int n, FILE *out) {
    for (int i = 15; i >= 0; i--) {
        fprintf(out, "%d", (n >> i) & 1);
    }
}

int main(int argc, char *argv[]) {
    if (argc == 4) {
        printf("File not found");
        return 1;
    }

    int n = atoi(argv[1]);
    FILE *in = fopen(argv[2], "r");
    FILE *out = fopen(argv[3], "w");
    if (!in || !out) {
        printf("File not found.\n");
        return 1;
    }

    int num;
    for (int i = 0; i < n && fscanf(in, "%d", &num) != EOF; i++) {
        fprintf(out, "The binary equivalent of %d is ", num);
        toBinary(num, out);
        fprintf(out, "\n");
    }

    fclose(in);
    fclose(out);

    // Display output file
    out = fopen(argv[3], "r");
    char ch;
    while ((ch = fgetc(out)) != EOF) putchar(ch);
    fclose(out);

    return 0;
}
