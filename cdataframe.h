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

void fill_user(CDATAFRAME *cdf);

void fill_hard(CDATAFRAME *cdf, int size, char *title, int *values);

int add_column_cdf(CDATAFRAME *cdf, COLUMN *col);

void delete_column_cdf(CDATAFRAME *cdf, char *col_name);

int add_row_cdf(CDATAFRAME *cdf, int row[cdf->TL], int position);

int delete_row_cdf(CDATAFRAME *cdf, int position);

void rename_column_cdf(CDATAFRAME *cdf, int col_num, char new_title[]);

void delete_cdf(CDATAFRAME **cdf);

int get_cols_number_cdf(CDATAFRAME *cdf);

int get_rows_number_cdf(CDATAFRAME *cdf);

void search_value_cdf(CDATAFRAME *cdf, int value);

int access_and_replace_value_by_pos(CDATAFRAME *cdf, int new_value, int row, int column);

void print_cdf(CDATAFRAME * cdf);

void print_rows_cdf(CDATAFRAME *cdf, int start, int end);

void print_cols_cdf(CDATAFRAME *cdf, int start, int end);

void print_columns_title(CDATAFRAME *cdf);

CDATAFRAME* load_from_csv(const char *file_name, int size_col);

void save_into_csv(CDATAFRAME *cdf, char *file_name);

#endif //CDATAFRAME_CDATAFRAME_H
