#include <stdio.h>
#include <stdlib.h>

#define REALOC_SIZE 256
// need to comment the code
typedef struct {
    char *title;
    int physical_size;
    int logical_size;
    int *data;
} COLUMN;

COLUMN *create_col(char *title) {
    COLUMN *col = (COLUMN *)malloc(sizeof(COLUMN));
    if (col) {
        col->title = title;
        col->data = NULL;
        col->physical_size = 0;
        col->logical_size = 0;
    }
    return col;
}

int insert_val(COLUMN *col, int value) {
    if (!col)
        return 0;

    if (col->logical_size == col->physical_size) {
        int *temp = realloc(col->data, (col->physical_size + REALOC_SIZE) * sizeof(int));
        if (!temp)
            return 0;
        col->data = temp;
        col->physical_size += REALOC_SIZE;
    }

    col->data[col->logical_size++] = value;
    return 1;
}

void delete_col(COLUMN **col) {
    if (!col || !(*col))
        return;

    free((*col)->data);
    free((*col)->title);
    free(*col);
    *col = NULL;
}

void print_col(COLUMN *col) {
    if (!col)
        return;

    printf("[%s]\n", col->title);
    for (int i = 0; i < col->logical_size; i++) {
        printf("[%d] %d\n", i, col->data[i]);
    }
}

int count_occ(COLUMN *col, int x) {
    if (!col)
        return 0;

    int count = 0;
    for (int i = 0; i < col->logical_size; i++) {
        if (col->data[i] == x)
            count++;
    }
    return count;
}

int positionval(COLUMN *col, int x) {
    if (!col || x < 0 || x >= col->logical_size)
        return -1; // meaning a error

    return col->data[x];
}

int valuegreater(COLUMN *col, int x) {
    if (!col)
        return 0;

    int count = 0;
    for (int i = 0; i < col->logical_size; i++) {
        if (col->data[i] > x)
            count++;
    }
    return count;
}

int valueless(COLUMN *col, int x) {
    if (!col)
        return 0;

    int count = 0;
    for (int i = 0; i < col->logical_size; i++) {
        if (col->data[i] < x)
            count++;
    }
    return count;
}

int valuequal(COLUMN *col, int x) {
    if (!col)
        return 0;

    int count = 0;
    for (int i = 0; i < col->logical_size; i++) {
        if (col->data[i] == x)
            count++;
    }
    return count;
}

int main() {
    COLUMN *mycol = create_col("My column");
    insert_val(mycol, 52);
    insert_val(mycol, 44);
    insert_val(mycol, 15);
    print_col(mycol);

    printf("Occurrences of 44: %d\n", count_occ(mycol, 44));
    printf("Value at position 1: %d\n", positionval(mycol, 1));
    printf("Values greater than 20: %d\n", valuegreater(mycol, 20));
    printf("Values less than 30: %d\n", valueless(mycol, 30));
    printf("Values equal to 44: %d\n", valuequal(mycol, 44));

    delete_col(&mycol);
    return 0;
}
