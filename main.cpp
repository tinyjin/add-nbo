#include<stdio.h>
#include<stdint.h>
#include <netinet/in.h>

int main(int argc, char* argv[]) {

    FILE* f1;
    FILE* f2;

    uint32_t n1;
    uint32_t n2;
    uint32_t result;


    if (argc < 3) {
        return 0;
    }

    f1 = fopen(argv[1], "r");
    f2 = fopen(argv[2], "r");

    if (f1) {
        fread(&n1, sizeof(n1), 1, f1);
    }

    if (f2) {
        fread(&n2, sizeof(n2), 1, f2);
    }

    n1 = ntohl(n1);
    n2 = ntohl(n2);
    result = n1 + n2;

    printf("%d(0x%x) + ", n1, n1);
    printf("%d(0x%x) = ", n2, n2);
    printf("%d(0x%x)", result, result); 

    fclose(f1);
    fclose(f2);

    return 0;
}
