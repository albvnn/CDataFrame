#ifndef CDATAFRAME_MAIN_H
#define CDATAFRAME_MAIN_H
#include "double-linked-list.h"
#include "cdataframe.h"

void MenuSection(CDATAFRAME* cdf, list* cdfs, int nb_cdf);
void MenuFilling(CDATAFRAME* cdf, list* cdfs, int nb_cdf);
void MenuDisplaying(CDATAFRAME* cdf, list* cdfs, int nb_cdf);
void MenuUsualOperations(CDATAFRAME* cdf, list* cdfs, int nb_cdf);
void MenuAnalysisStatistics(CDATAFRAME* cdf, list* cdfs, int nb_cdf);
void MenuOperationColumn(CDATAFRAME* cdf, list* cdfs, int nb_cdf);
void MenuSearching(CDATAFRAME* cdf, list* cdfs, int nb_cdf);

#endif //CDATAFRAME_MAIN_H
