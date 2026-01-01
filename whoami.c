#include <stdio.h>
#include <stdlib.h>

int main() {
    char *user = getenv("USERNAME");
    if (user)
        printf("%s\n", user);
    else
        printf("Unknown user\n");
    return 0;
}
