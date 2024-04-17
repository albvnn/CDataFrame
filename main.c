#include "main.h"
#include "column.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    COLUMN *mycol = create_column("My column");
    insert_value(mycol, 52);
    insert_value(mycol, 44);
    insert_value(mycol, 15);
    print_col(mycol);
}