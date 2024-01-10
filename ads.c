#include <stdio.h>
#include <stdlib.h>

#define MAX_WAGONS 100

struct wagon {
    int minute;
    int wagon_number;
    char type[10];
    int weight;
    int time;
};

int main() {
    FILE *fp;
    char filename[] = "input.txt";
    char line[100];
    struct wagon wagons[MAX_WAGONS];
    int i = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Nie udało się otworzyć pliku %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%*d %d %s %d %d", &wagons[i].wagon_number, wagons[i].type, &wagons[i].weight, &wagons[i].time);
        wagons[i].minute = atoi(strtok(line, " "));
        i++;
    }

    fclose(fp);

    printf("Wczytane dane:\n");
    for (int j = 0; j < i; j++) {
        printf("%d %d %s %d %d\n", wagons[j].minute, wagons[j].wagon_number, wagons[j].type, wagons[j].weight, wagons[j].time);
    }

    return 0;
}
