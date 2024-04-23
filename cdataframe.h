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

void delete_column_cdf(CDATAFRAME *cdf, char *col_name);

void rename_column_cdf(CDATAFRAME *cdf, int col_num, char new_title[]);

void delete_cdf(CDATAFRAME **cdf);

int get_cols_number_cdf(CDATAFRAME *cdf);

int get_rows_number_cdf(CDATAFRAME *cdf);

void print_cdf(CDATAFRAME * cdf);

void print_rows_cdf(CDATAFRAME *cdf, int start, int end);

void print_cols_cdf(CDATAFRAME *cdf, int start, int end);

void print_columns_title(CDATAFRAME *cdf);

#endif //CDATAFRAME_CDATAFRAME_H
