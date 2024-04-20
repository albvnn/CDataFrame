#include <stdio.h>
#include <stdlib.h>
#include <column.h>
#include <cdataframe.h>

#define REALOC_SIZE 256
// need to comment the code

int main() {
    COLUMN *mycol = create_column("My column");
    insert_value(mycol, 52);
    insert_value(mycol, 44);
    insert_value(mycol, 15);
    COLUMN *mycol2 = create_column("My column");
    insert_value(mycol2, 1);
    insert_value(mycol2, 2);
    insert_value(mycol2, 3);
    COLUMN *mycol3 = create_column("My column");
    insert_value(mycol3, 0);
    insert_value(mycol3, 0);
    insert_value(mycol3, 1);

    printf("Occurrences of 44: %d\n", count_occ(mycol, 44));
    printf("Value at position 1: %d\n", positionval(mycol, 1));
    printf("Values greater than 20: %d\n", valuegreater(mycol, 20));
    printf("Values less than 30: %d\n", valueless(mycol, 30));
    printf("Values equal to 44: %d\n", valuequal(mycol, 44));

    CDATAFRAME *cdf = create_cdataframe(3);
    printf("%d", add_column_cdf(cdf, mycol));
    printf("%d", add_column_cdf(cdf, mycol2));
    printf("%d", add_column_cdf(cdf, mycol3));
    printf("\n");
    print_cdf(cdf);

    return 0;
}
