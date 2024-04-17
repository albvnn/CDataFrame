#include "column.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define REALOC_SIZE 256

typedef struct Column {
    char title[100];
    int TP;
    int TL;
    int *data;
}COLUMN;

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
        col->TL = 0;
        free(col->data);
        col->data = (int *)realloc(col->data, sizeof(int)*REALOC_SIZE);
        if (col->data == NULL) {
            return 0;
        }
    }
    if(col->data == NULL) {
        col->data = (int *)malloc(sizeof(int)*REALOC_SIZE);
        if (col->data == NULL) {
            return 0;
        }
    }
    col->data[col->TL] = value;
    col->TL++;
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