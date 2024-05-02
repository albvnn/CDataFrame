#ifndef CDATAFRAME_COLUMN_H
#define CDATAFRAME_COLUMN_H

typedef struct Column {
    char title[100];
    int TP;
    int TL;
    int *data;
    long long *index;
// index valid
// 0 : no index
// -1 : invalid index
// 1 : valid index
    int valid_index;
// direction de tri Ascendant ou Déscendant
// 0 : ASC
// 1 : DESC
    int sort_dir;
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

void erase_index(COLUMN *col);

int check_index(COLUMN *col);

void update_index(COLUMN *col);

#endif //CDATAFRAME_COLUMN_H

