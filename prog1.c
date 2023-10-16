#define QUEUE_SIZE 100
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct QueueItem {
    int priority, value;
};

void enterData(struct QueueItem* queue, int currentID) {
    int tempValue = 0, tempPriority = 0;
    printf("\n--------\nValue: ");
    scanf("%d", &tempValue);
    printf("Priority of value: ");
    scanf("%d", &tempPriority);

    queue[currentID].priority = tempPriority;
    queue[currentID].value = tempValue;
}

void showQueue(struct QueueItem* queue, int currentID) {
    system("cls");
    printf("Queue:\n");
    if (!currentID) printf("no elements");
    else
        for (int i = 0; i < currentID; i++) {
            printf("|%d| %d\t", queue[i].priority, queue[i].value);
        }
    printf("\n--------");
}

void bubbleSort(struct QueueItem* queue, int size) {
    int gap = size;
    int swapped = 1;

    while (gap > 1 || swapped) {
        gap = (gap * 1000) / 1247; // Уменьшаем шаг на 1000/1247

        if (gap < 1) {
            gap = 1;
        }

        swapped = 0;

        for (int i = 0; i < size - gap; i++) {
            if (queue[i].priority > queue[i + gap].priority) {
                struct QueueItem temp = queue[i];
                queue[i] = queue[i + gap];
                queue[i + gap] = temp;
                swapped = 1;
            }
        }
    }
}

int main() {
    struct QueueItem queue[QUEUE_SIZE] = { 0 };
    int currentID = 0;

    while (1) {
        showQueue(queue, currentID);
        printf("\nactions:\n\t1)add\n\t2)delete\n\t3)quit");
        switch (_getch()) {
        case '1':
            if (currentID > QUEUE_SIZE) break;
            enterData(queue, currentID++);
            bubbleSort(queue, currentID);
            showQueue(queue, currentID);
            break;
        case '2':
            if (currentID) {
                queue[currentID].value = 0;
                queue[currentID--].priority = 0;
            }
            showQueue(queue, currentID);
            break;
        case '3':
            showQueue(queue, currentID++);
            return 0;
        }
    }
}
