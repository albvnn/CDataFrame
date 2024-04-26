#include "column.h"
#include "sort.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define REALOC_SIZE 256

COLUMN *create_column(char* title) {
    COLUMN* column = (COLUMN *)malloc(sizeof(COLUMN));
    strcpy(column->title, title);
    column->TP = REALOC_SIZE;
    column->TL = 0;
    column->data = NULL;
    return column;
};

int insert_value(COLUMN* col, int value){
    if(col->TL >= col->TP) {
        col->data = (int *)realloc(col->data, sizeof(int));
        if (col->data == NULL) {
            return 0;
        }
    }
    if(col->data == NULL) {
        col->data = (int *)malloc(sizeof(int));
        if (col->data == NULL) {
            return 0;
        }
    }
    col->data[col->TL] = value;
    col->TL++;
    return 1;
};

int insert_value_at_position(COLUMN* col, int value, int position){
    int i;
    if (position == -1)
        position = col->TL;
    if(col->TL >= col->TP) {
        col->data = (int *)realloc(col->data, sizeof(int));
        if (col->data == NULL) {
            return 0;
        }
    }
    if(col->data == NULL) {
        col->data = (int *)malloc(sizeof(int));
        if (col->data == NULL) {
            return 0;
        }
    }
    position++;
    if (position > col->TL + 1)
        return 0;
    col->TL++;
    for (i = col->TL - 1; i >= position; i--) {
        col->data[i] = col->data[i - 1];
    };
    col->data[i] = value;
    col->data[col->TL] = value;
    return 1;
};

int delete_value_at_position(COLUMN* col, int position){
    int i;
    if (position == -1)
        position = col->TL;
    if (position > col->TL + 1)
        return 0;
    for (i = position; i < col->TL; i++) {
        col->data[i] = col->data[i + 1];
    };
    col->TL--;
    return 1;
};

void delete_column(COLUMN **col){
    free((*col)->data);
    free(*col);
};

void print_col(COLUMN* col){
    for (int i = 0; i < col->TL; i++) {
        printf("[%d] %d", i, col->data[i]);
        printf("\n");
    }
};

int count_occ(COLUMN *col, int x) {
    if (!col)
        return 0;

    int count = 0;
    for (int i = 0; i < col->TL; i++) {
        if (col->data[i] == x)
            count++;
    }
    return count;
}

int positionval(COLUMN *col, int x) {
    if (!col || x < 0 || x >= col->TL)
        return -1; // meaning a error

    return col->data[x];
}

int valuegreater(COLUMN *col, int x) {
    if (!col)
        return 0;

    int count = 0;
    for (int i = 0; i < col->TL; i++) {
        if (col->data[i] > x)
            count++;
    }
    return count;
}

int valueless(COLUMN *col, int x) {
    if (!col)
        return 0;

    int count = 0;
    for (int i = 0; i < col->TL; i++) {
        if (col->data[i] < x)
            count++;
    }
    return count;
}

int valuequal(COLUMN *col, int x) {
    if (!col)
        return 0;

    int count = 0;
    for (int i = 0; i < col->TL; i++) {
        if (col->data[i] == x)
            count++;
    }
    return count;
}
