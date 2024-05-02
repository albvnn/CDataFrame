#include "column.h"
#include "cdataframe.h"
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
    column->index = NULL;
    column->valid_index = 0;
    column->sort_dir = 0;
    return column;
};

int insert_value(COLUMN* col, int value){
    if (col->valid_index == 1)
        col->valid_index = -1;
    if(col->TL >= col->TP) {
        col->data = (int *)realloc(col->data, (col->TP) * sizeof(int)); // if TL > TP reallocate memory
        if (col->data == NULL) {
            return 0;
        }
    }
    if(col->data == NULL) {
        col->data = (int *)malloc((col->TP) * sizeof(int)); // allocate memory for the first value
        col->index = (long long*)malloc((col->TP) * sizeof(long long));
        if (col->data == NULL) {
            return 0;
        }
    }
    col->index[col->TL] = col->TL;
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
        col->index = (unsigned long long*)malloc(sizeof(unsigned long long));
        if (col->data == NULL) {
            return 0;
        }
    }
    if (col->valid_index == 1)
        col->valid_index = -1;
    position++;
    if (position > col->TL + 1) // for out of range
        return 0;
    col->TL++;
    for (i = col->TL - 1; i >= position; i--) { // shift element to make place for the new value
        col->data[i] = col->data[i - 1];
        col->index[i] = col->index[i - 1];
    };
    col->data[i] = value;
    col->data[col->TL] = value; // insert value
    col->index[col->TL] = col->TL;
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
        col->index[i] = col->index[i + 1];
    };
    if (col->valid_index == 1)
        col->valid_index = -1;
    col->TL--; // since remove TL is minus one
    return 1;
};

void delete_column(COLUMN **col){ // understand
    free((*col)->data);
    erase_index(*col);
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

void erase_index(COLUMN *col){
    free(col->index);
    col->index = NULL;
    col->valid_index = 0;
}

int check_index(COLUMN *col){
    return col->valid_index;
}

void update_index(COLUMN *col){
    sort(col, col->sort_dir);
}

void sort(COLUMN* col, int sort_dir){
    if (col->valid_index == 1) {
        printf("Column already sorted");
        return;
    };

    int data_array[col->TL];

    for (int i = 0; i < col->TL; i++){
        data_array[i] = col->data[col->index[i]];
    };


    if (col->valid_index == 0) {
        quickSort(data_array, col->index, 0, col->TL - 1);
        col->valid_index = 1;
        return;
    }
    if (col->valid_index == -1) {
        insertionSort(data_array, col->index, col->TL);
        col->valid_index = 1;
        return;
    } else {
        printf("Unvalid index (%d)", col->valid_index);
        return;
    }
}

void print_col_by_index(COLUMN *col){
    for (int i = 0; i < col->TL; i++) {
        printf("[%d] %d | %lld", i, col->data[col->index[i]], col->index[i]); // print every elem in a for loop
        printf("\n");
    }
}



int search_value_in_column(COLUMN *col, void *val){
    //dichotomous search
}