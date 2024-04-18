#include "main.h"
#include "column.h"
#include "cdataframe.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    COLUMN *mycol = create_column("My column");
    insert_value(mycol, 52);
    insert_value(mycol, 44);
    insert_value(mycol, 15);
    COLUMN *mycol2= create_column("My column2");
    insert_value(mycol2, 1);
    insert_value(mycol2, 2);
    insert_value(mycol2, 3);
    CDATAFRAME *mycdf = create_cdataframe(5);
    add_columns(mycdf, mycol);
    add_columns(mycdf, mycol2);
    print_cdf(mycdf);
}