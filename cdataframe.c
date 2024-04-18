#include "cdataframe.h"
#include "column.h"
#include "sort.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//DONT TOUCH
typedef struct CDataFrame {
    int TP;
    int TL;
    int *columns[100];
}CDATAFRAME;

CDATAFRAME *create_cdataframe(int size){
    CDATAFRAME* cdf = (CDATAFRAME*)malloc(sizeof(CDATAFRAME));
    cdf->TP = size;
    cdf->TL = 0;
    cdf->columns = NULL;
};

int add_columns(CDATAFRAME* cdf, COLUMN* col){
    if(cdf->columns == NULL){
        cdf->columns = (int *)malloc(sizeof(COLUMN*));
    }
    if(cdf->TL >= cdf->TP){
        cdf->columns = (int *)realloc(cdf->columns, sizeof(COLUMN*));
        if(cdf->columns == NULL){
            return 0;
        }
    }
    cdf->columns[cdf->TL] = (int *) col;
    cdf->TL++;
    return 1;
};

void delete_cdf(CDATAFRAME **cdf){
    free((*cdf)->columns);
    free(*cdf);
};

void print_cdf(CDATAFRAME * cdf){
    for (int i = 0; i < cdf->TL; i++) {
        print_col((COLUMN *) cdf->columns[i]);
    }
};