#ifndef CDATAFRAME_CDATAFRAME_H
#define CDATAFRAME_CDATAFRAME_H

typedef struct Column COLUMN;
typedef struct CDataFrame CDATAFRAME;

CDATAFRAME *create_cdataframe(int size);
int add_columns(CDATAFRAME* cdf, COLUMN* col);
void delete_cdf(CDATAFRAME **cdf);
void print_cdf(CDATAFRAME * cdf);
#endif //CDATAFRAME_CDATAFRAME_H
