#include "cdataframe.h"
#include "column.h"
#include "sort.h"
#include "double-linked-list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


CDATAFRAME *create_cdataframe(int size){
    CDATAFRAME* cdf = (CDATAFRAME*)malloc(sizeof(CDATAFRAME));
    cdf->list_cdf = lst_create_list();
    cdf->TL = 0;
    cdf->TP = size;
    return cdf;
};

void delete_cdf(CDATAFRAME **cdf){
    lst_erase((*cdf)->list_cdf);
    lst_delete_list((*cdf)->list_cdf);
    free(*cdf);
};

void rename_column_cdf(CDATAFRAME *cdf, int col_num, char new_title[]) {
    lnode* col_node = get_first_node(cdf->list_cdf);
    COLUMN* col = col_node->data;
    for (int i = 0; i < col_num; i++){
        col_node = get_next_node(cdf->list_cdf, col_node);
    };
    col = col_node->data;
    col->title;
    strcpy(col->title, new_title);
};

int add_column_cdf(CDATAFRAME *cdf, COLUMN *col){
    if(cdf->TL >= cdf->TP){
        printf("The CDataFrame is full !");
        return 1;
    }
    if(cdf->TL == 0){
        lst_insert_head(cdf->list_cdf, lst_create_lnode(col));
        cdf->TL++;
    } else {
    lst_insert_after(cdf->list_cdf, lst_create_lnode(col), get_last_node(cdf->list_cdf));
    cdf->TL++;
    }
    return 1;
}

void delete_column_cdf(CDATAFRAME *cdf, char *col_name){
    lnode* col_node = get_first_node(cdf->list_cdf);
    COLUMN* col = col_node->data;
    for (int i = 0; i <= cdf->TL; i++){
        if (strcmp(col->title, col_name) == 0){
            delete_column(&col);
            cdf->TL--;
        }
    }
};


int add_row_cdf(CDATAFRAME *cdf, int row[cdf->TL], int position) {
    lnode* col_node = get_first_node(cdf->list_cdf);
    COLUMN* col;
    int i;
    for (int j = 0; j < cdf->TL; j++) {
        col = col_node->data;
        if (insert_value_at_position(col, row[j], position) == 0)
            return 0;
        col_node = get_next_node(cdf->list_cdf, col_node);
    };
    return 1;
};

int delete_row_cdf(CDATAFRAME *cdf, int position) {
    lnode* col_node = get_first_node(cdf->list_cdf);
    COLUMN* col;
    int i;
    for (int j = 0; j < cdf->TL; j++) {
        col = col_node->data;
        if (delete_value_at_position(col, position) == 0)
            return 0;
        col_node = get_next_node(cdf->list_cdf, col_node);
    };
    return 1;
};

int get_cols_number_cdf(CDATAFRAME *cdf){
    return cdf->TL;
};

int get_rows_number_cdf(CDATAFRAME *cdf){
    lnode* col_node = get_first_node(cdf->list_cdf);
    COLUMN* col = col_node->data;
    return col->TL;
};

void search_value_cdf(CDATAFRAME *cdf, int value){
    lnode* col_node = get_first_node(cdf->list_cdf);
    COLUMN* col;
    int existence = 0;
    for(int i = 0; i < cdf->TL; i++){
        col = col_node->data;
        for(int j = 0; j <= col->TL; j++){
            if (col->data[j] == value){
                existence = 1;
                printf("The value %d was founded in row %d column %d", value, j, i);
                printf("\n");
            }
        };
        col_node = get_next_node(cdf->list_cdf, col_node);
    };
    if (existence == 0) {
        printf("No value %d was founded !", value);
        printf("\n");
    };
};

int access_and_replace_value_by_pos(CDATAFRAME *cdf, int new_value, int row, int column){
    lnode* col_node = get_first_node(cdf->list_cdf);
    COLUMN* col = col_node->data;
    if (row > col->TL || column > cdf->TL)
        return 0;
    for(int i = 0; i < cdf->TL; i++) {
        col = col_node->data;
        for (int j = 0; j <= col->TL; j++) {
            if (j == row && i == column) {
                col->data[j] = new_value;
                return 1;
            };
        };
        col_node = get_next_node(cdf->list_cdf, col_node);
    };
};

void print_rows_cdf(CDATAFRAME *cdf, int start, int end){
    lnode* col_node;
    COLUMN* col;
    for (int j = start; j <= end; j++) {
        printf("[%d] ", j);
        col_node = get_first_node(cdf->list_cdf);
        for (int i = 0; i < cdf->TL; i++) {
            col = col_node->data;
            if (0 <= col->data[j] && col->data[j] <= 9) {
                printf(" %d  ", col->data[j]);
            } else {
                printf("%d  ", col->data[j]);
            };
            col_node = get_next_node(cdf->list_cdf, col_node);
        };
        printf("\n");
    };
};

void print_cols_cdf(CDATAFRAME *cdf, int start, int end) {
    COLUMN* col_list[end-start];
    lnode* col_node = get_first_node(cdf->list_cdf);
    COLUMN* col = col_node->data;
    int number_rows = get_rows_number_cdf(cdf);
    for (int k = start; k <= end; k++){
        printf("[%d] ", k);
    };
    printf("\n");
    for (int i = 0; i < start; i++){
        col_node = get_next_node(cdf->list_cdf, col_node);
    };
    col = col_node->data;
    for (int z = 0; z <= end-start; z++){
        col_list[z] = col;
        col_node = get_next_node(cdf->list_cdf, col_node);
        col = col_node->data;
    };
    for (int y = 0; y < number_rows; y++){
        for (int j = 0; j <= end-start; j++) {
            printf(" %d ", col_list[j]->data[y]);
        };
        printf("\n");
    };
};

void print_columns_title(CDATAFRAME *cdf){
    lnode* col_node = get_first_node(cdf->list_cdf);
    COLUMN* col = col_node->data;
    for (int i = 0; i < cdf->TL; i++){
        printf("[%d] %s", i, col->title);
        if (i < cdf->TL - 1) {
            col_node = get_next_node(cdf->list_cdf, col_node);
            col = col_node->data;
        };
        printf("\n");
    };
};

void print_cdf(CDATAFRAME *cdf){
    lnode* col_node = get_first_node(cdf->list_cdf);
    COLUMN* col = col_node->data;
    printf("    ");
    for (int j = 0; j < cdf->TL; j++) {
        printf("[%d] ", j);
    }
    printf("\n");
    print_rows_cdf(cdf, 0, col->TL - 1);
};