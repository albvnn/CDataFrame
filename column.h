#ifndef CDATAFRAME_COLUMN_H
#define CDATAFRAME_COLUMN_H

typedef struct Column COLUMN;
COLUMN *create_column(char* title);
int insert_value(COLUMN* col, int value);
void delete_column(COLUMN **col);
void print_col(COLUMN* col);
#endif //CDATAFRAME_COLUMN_H

