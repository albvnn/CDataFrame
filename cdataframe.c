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

int get_cdataframe_cols_size(CDATAFRAME *cdf){
    return cdf->TL;
};

void print_cdf(CDATAFRAME *cdf){
    lnode* col_node = get_first_node(cdf->list_cdf);
    COLUMN* col = col_node->data;
    for (int i = 0; i < cdf->TL; i++) {
        print_col(col);
        printf("-----------------\n");
        col_node = get_next_node(cdf->list_cdf, col_node);
        col = col_node->data;
    }
};