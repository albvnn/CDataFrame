#ifndef CDATAFRAME_COLUMN_H
#define CDATAFRAME_COLUMN_H

typedef struct Column {
    char title[100];
    int TP;
    int TL;
    int *data;
}COLUMN;

COLUMN *create_column(char* title);

int insert_value(COLUMN* col, int value);

int insert_value_at_position(COLUMN* col, int value, int position); //-1 for position take the last position

int delete_value_at_position(COLUMN* col, int position); //-1 for position take the last position

void delete_column(COLUMN **col);

void print_col(COLUMN* col);

int count_occ(COLUMN *col, int x);

int positionval(COLUMN *col, int x);

int valuegreater(COLUMN *col, int x);

int valueless(COLUMN *col, int x);

int valuequal(COLUMN *col, int x);

#endif //CDATAFRAME_COLUMN_H

