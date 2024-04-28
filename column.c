#include "column.h"
#include "sort.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define REALOC_SIZE 256

COLUMN *create_column(char* title) {
    COLUMN* column = (COLUMN *)malloc(sizeof(COLUMN));
    strcpy(column->title, title); // copy title
    column->TP = REALOC_SIZE;
    column->TL = 0;
    column->data = NULL; // initialize members of the structure
    return column;
};

int insert_value(COLUMN* col, int value){
    if(col->TL >= col->TP) {
        col->data = (int *)realloc(col->data, sizeof(int)); // if TL > TP reallocate memory
        if (col->data == NULL) {
            return 0;
        }
    }
    if(col->data == NULL) {
        col->data = (int *)malloc(sizeof(int)); // allocate memory for the first value
        if (col->data == NULL) {
            return 0;
        }
    }
    col->data[col->TL] = value; //assign the value to the next available position
    col->TL++; // increase the TL by 1 since +1 value
    return 1;
};

int insert_value_at_position(COLUMN* col, int value, int position){
    int i;
    if (position == -1)
        position = col->TL;//  will insert the value at the last index
    if(col->TL >= col->TP) {
        col->data = (int *)realloc(col->data, sizeof(int)); // reallocate memory
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
    if (position > col->TL + 1) // for out of range
        return 0;
    col->TL++;
    for (i = col->TL - 1; i >= position; i--) { // shift element to make place for the new value
        col->data[i] = col->data[i - 1];
    };
    col->data[i] = value;
    col->data[col->TL] = value; // insert value
    return 1;
};

int delete_value_at_position(COLUMN* col, int position){
    int i;
    if (position == -1)
        position = col->TL;
    if (position > col->TL + 1) // if bigger than LS then false
        return 0;
    for (i = position; i < col->TL; i++) { // travel trough the data until find position
        col->data[i] = col->data[i + 1]; //remove it by changing it to the next one
    };
    col->TL--; // since remove TL is minus one
    return 1;
};

void delete_column(COLUMN **col){ // understand
    free((*col)->data);
    free(*col);
};

void print_col(COLUMN* col){ // understand 
    for (int i = 0; i < col->TL; i++) {
        printf("[%d] %d", i, col->data[i]); // print every elem in a for loop
        printf("\n");
    }
};

int count_occ(COLUMN *col, int x) {
    if (!col)
        return 0;

    int count = 0;
    for (int i = 0; i < col->TL; i++) {
        if (col->data[i] == x) // if i == x then +1
            count++;
    }
    return count; // return occ
}

int positionval(COLUMN *col, int x) {
    if (!col || x < 0 || x >= col->TL)
        return -1; // meaning a error

    return col->data[x];
}

int valuegreater(COLUMN *col, int x) { // no need to explain
    if (!col)
        return 0;

    int count = 0;
    for (int i = 0; i < col->TL; i++) {
        if (col->data[i] > x)
            count++;
    }
    return count;
}

int valueless(COLUMN *col, int x) { // same as value greater
    if (!col)
        return 0;

    int count = 0;
    for (int i = 0; i < col->TL; i++) {
        if (col->data[i] < x)
            count++;
    }
    return count;
}

int valuequal(COLUMN *col, int x) { // same as the two previous one just sign = changing
    if (!col)
        return 0;

    int count = 0;
    for (int i = 0; i < col->TL; i++) {
        if (col->data[i] == x)
            count++;
    }
    return count;
}
