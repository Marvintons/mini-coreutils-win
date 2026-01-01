#include <stdio.h>
#include <windows.h>

int main() {
    ULONGLONG ms = GetTickCount64(); // milliseconds since system start
    unsigned long seconds = (unsigned long)(ms / 1000);
    unsigned long minutes = seconds / 60;
    unsigned long hours = minutes / 60;
    unsigned long days = hours / 24;

    printf("Uptime: %lu days, %lu hours, %lu minutes, %lu seconds\n",
           days, hours % 24, minutes % 60, seconds % 60);

    return 0;
}
