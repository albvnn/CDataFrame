#ifndef CDATAFRAME_CDATAFRAME_H
#define CDATAFRAME_CDATAFRAME_H

#include "double-linked-list.h"

typedef struct Column COLUMN;
typedef struct CDataFrame {
    list *list_cdf;
    int TL;
    int TP;
}CDATAFRAME;

CDATAFRAME *create_cdataframe(int size);

int add_column_cdf(CDATAFRAME *cdf, COLUMN *col);

void delete_cdf(CDATAFRAME **cdf);

void print_cdf(CDATAFRAME * cdf);

#endif //CDATAFRAME_CDATAFRAME_H
