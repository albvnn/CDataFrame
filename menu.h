#ifndef CDATAFRAME_MENU_H
#define CDATAFRAME_MENU_H
#include "double-linked-list.h"
#include "cdataframe.h"

void MenuSection(CDATAFRAME *cdf, list *cdfs, int nb_cdf, COLUMN *col, list *cols, int nb_col);
void MenuFilling(CDATAFRAME *cdf, list *cdfs, int nb_cdf, COLUMN *col, list *cols, int nb_col);
void MenuDisplaying(CDATAFRAME *cdf, list *cdfs, int nb_cdf, COLUMN *col, list *cols, int nb_col);
void MenuUsualOperations(CDATAFRAME *cdf, list *cdfs, int nb_cdf, COLUMN *col, list *cols, int nb_col);
void MenuAnalysisStatistics(CDATAFRAME *cdf, list *cdfs, int nb_cdf, COLUMN *col, list *cols, int nb_col);
void MenuOperationColumn(CDATAFRAME* cdf, list* cdfs, int nb_cdf, COLUMN *col, list *cols, int nb_col);
void MenuSearching(CDATAFRAME* cdf, list* cdfs, int nb_cdf, COLUMN *col, list *cols, int nb_col);

#endif //CDATAFRAME_MENU_H
