#include <stdio.h>
#include <stdlib.h>
#include <column.h>
#include <main.h>
#include <cdataframe.h>
#include <double-linked-list.h>

#define REALOC_SIZE 256
// need to comment the code
// Create a menu with corresponding sub-menu

void MenuFilling(CDATAFRAME* cdf, list* cdfs, int nb_cdf) {
    int choice;
    do {
        printf(
                "     #########################################################################\n"
                "     #                              Filling Menu                             #\n"
                "     #  CDataFrame selected : CDataFrame %d                                  #\n"
                "     #                                                                       #\n"
                "     #  1- Add Column                                                        #\n"
                "     #  2- Add Row                                                           #\n"
                "     #  3- Load from CSV                                                     #\n"
                "     #  4- Save into CSV                                                     #\n"
                "     #  5- Back                                                              #\n"
                "     #########################################################################\n", nb_cdf
        );
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                // Add Column
                printf("You chose to add a column.\n");
                // Implement Add Column functionality
                break;
            case 2:
                // Add Row
                printf("You chose to add a row.\n");
                // Implement Add Row functionality
                break;
            case 3:
                // Load from CSV
                printf("You chose to load from CSV.\n");
                // Implement Load from CSV functionality
                break;
            case 4:
                // Save into CSV
                printf("You chose to save into CSV.\n");
                // Implement Save into CSV functionality
                break;
            case 5:
                printf("Going back...\n");
                MenuSection(cdf, cdfs, nb_cdf);
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice < 1 || choice > 5);
}

void MenuDisplaying(CDATAFRAME* cdf, list* cdfs, int nb_cdf) {
    int choice;
    do {
        printf(
                "     #########################################################################\n"
                "     #                           Displaying Menu                             #\n"
                "     #  CDataFrame selected : CDataFrame %d                                  #\n"
                "     #                                                                       #\n"
                "     #  1- Print DataFrame                                                   #\n"
                "     #  2- Print Rows                                                        #\n"
                "     #  3- Print Columns                                                     #\n"
                "     #  4- Print Column Titles                                               #\n"
                "     #  5- Back                                                              #\n"
                "     #########################################################################\n", nb_cdf
        );
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                // Print DataFrame
                printf("You chose to print DataFrame.\n");
                // Implement Print DataFrame functionality
                break;
            case 2:
                // Print Rows
                printf("You chose to print Rows.\n");
                // Implement Print Rows functionality
                break;
            case 3:
                // Print Columns
                printf("You chose to print Columns.\n");
                // Implement Print Columns functionality
                break;
            case 4:
                // Print Column Titles
                printf("You chose to print Column Titles.\n");
                // Implement Print Column Titles functionality
                break;
            case 5:
                printf("Going back...\n");
                MenuSection(cdf, cdfs, nb_cdf);
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice < 1 || choice > 5);
}

void MenuUsualOperations(CDATAFRAME* cdf, list* cdfs, int nb_cdf) {
    int choice;
    do {
        printf(
                "     #########################################################################\n"
                "     #                      Usual Operations Menu                            #\n"
                "     #  CDataFrame selected : CDataFrame %d                                  #\n"
                "     #                                                                       #\n"
                "     #  1- Delete Row                                                        #\n"
                "     #  2- Delete Column                                                     #\n"
                "     #  3- Access and Replace Value                                          #\n"
                "     #  4- Search Value                                                      #\n"
                "     #  5- Back                                                              #\n"
                "     #########################################################################\n", nb_cdf
        );
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                // Delete Row
                printf("You chose to delete a row.\n");
                // Implement Delete Row functionality
                break;
            case 2:
                // Delete Column
                printf("You chose to delete a column.\n");
                // Implement Delete Column functionality
                break;
            case 3:
                // Access and Replace Value
                printf("You chose to access and replace a value.\n");
                // Implement Access and Replace Value functionality
                break;
            case 4:
                // Search Value
                printf("You chose to search a value.\n");
                // Implement Search Value functionality
                break;
            case 5:
                printf("Going back...\n");
                MenuSection(cdf, cdfs, nb_cdf);
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice < 1 || choice > 5);
}

void MenuAnalysisStatistics(CDATAFRAME* cdf, list* cdfs, int nb_cdf) {
    int choice;
    do {
        printf(
                "     #########################################################################\n"
                "     #                   Analysis and Statistics Menu                         #\n"
                "     #  CDataFrame selected : CDataFrame %d                                  #\n"
                "     #                                                                       #\n"
                "     #  1- Count Occurrences                                                 #\n"
                "     #  2- Find Position of Value                                            #\n"
                "     #  3- Find Values Greater Than                                          #\n"
                "     #  4- Find Values Less Than                                             #\n"
                "     #  5- Find Values Equal To                                              #\n"
                "     #  6- Sort Column                                                       #\n"
                "     #  7- Back                                                               #\n"
                "     #########################################################################\n", nb_cdf
        );
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                // Count Occurrences
                printf("You chose to count occurrences.\n");
                // Implement Count Occurrences functionality
                break;
            case 2:
                // Find Position of Value
                printf("You chose to find the position of a value.\n");
                // Implement Find Position of Value functionality
                break;
            case 3:
                // Find Values Greater Than
                printf("You chose to find values greater than.\n");
                // Implement Find Values Greater Than functionality
                break;
            case 4:
                // Find Values Less Than
                printf("You chose to find values less than.\n");
                // Implement Find Values Less Than functionality
                break;
            case 5:
                // Find Values Equal To
                printf("You chose to find values equal to.\n");
                // Implement Find Values Equal To functionality
                break;
            case 6:
                // Sort Column
                printf("You chose to sort a column.\n");
                // Implement Sort Column functionality
                break;
            case 7:
                printf("Going back...\n");
                MenuSection(cdf, cdfs, nb_cdf);
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 7.\n");
        }
    } while (choice < 1 || choice > 7);
}

void MenuOperationColumn(CDATAFRAME* cdf, list* cdfs, int nb_cdf){

}

void MenuSearching(CDATAFRAME* cdf, list* cdfs, int nb_cdf){

}

void MenuSection(CDATAFRAME* cdf, list* cdfs, int nb_cdf) {
    int choice;
    do {
        printf(
                "     #########################################################################\n"
                "     #                               Sections                                #\n"
                "     #  CDataFrame selected : CDataFrame %d                                  #\n"
                "     #                                                                       #\n"
                "     #  1- Creation and Filling:                                             #\n"
                "     #  Functions for creating and filling CdataFrame.                       #\n"
                "     #                                                                       #\n"
                "     #  2- Displaying:                                                       #\n"
                "     #  Functions to display data from the CdataFrame.                       #\n"
                "     #                                                                       #\n"
                "     #  3- Usual Operations:                                                 #\n"
                "     #  Operations like adding or deleting rows or columns but also          #\n"
                "     #  looking for values, and accessing cells.                             #\n"
                "     #                                                                       #\n"
                "     #  4- Analysis and statistics:                                          #\n"
                "     #  Functions for analyzing data.                                        #\n"
                "     #                                                                       #\n"
                "     #  5- Operations on column:                                             #\n"
                "     #  Functions for work with columns                                      #\n"
                "     #                                                                       #\n"
                "     #  6- Searching:                                                        #\n"
                "     #  Functions for searching data in our dataframe.                       #\n"
                "     #                                                                       #\n"
                "     #  7- Change CDataframe                                                 #\n"
                "     #                                                                       #\n"
                "     #  8- Exit                                                              #\n"
                "     #                                                                       #\n"
                "     #########################################################################\n", nb_cdf
        );
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                MenuFilling(cdf, cdfs, nb_cdf);
                break;
            case 2:
                MenuDisplaying(cdf, cdfs, nb_cdf);
                break;
            case 3:
                MenuUsualOperations(cdf, cdfs, nb_cdf);
                break;
            case 4:
                MenuAnalysisStatistics(cdf, cdfs, nb_cdf);
                break;
            case 5:
                MenuOperationColumn(cdf, cdfs, nb_cdf);
                break;
            case 6:
                MenuSearching(cdf, cdfs, nb_cdf);
                break;
            case 7:
                if (cdf == NULL){
                    printf("There is no CDataFrame created, please go to the Section 1 - Creation and Filling");
                    MenuSection(cdf, cdfs, nb_cdf);
                } else {
                    lnode* cdf_choice = get_first_node(cdfs);
                    int number_cdf = -1;
                    int i = 1;
                    printf("List of CDataFrame\n");
                    while (cdf_choice->next != NULL){
                        printf("%d - CDataFrame %d", i, i);
                        i++;
                    }
                    do{
                        printf("Enter the number of the CDataFrame :");
                        scanf("%d", &number_cdf);
                        if (number_cdf < 1 || number_cdf > i){
                            printf("Invalid choice! Please enter a number between 1 and %d.\n", i);
                        }
                    }while (number_cdf < 1 || number_cdf > i);
                    cdf_choice = get_first_node(cdfs);
                    for (int k = 0; k <= i; k++){
                        cdf_choice = get_next_node(cdfs, cdf_choice);
                    }
                    cdf = cdf_choice->data;
                    nb_cdf = i;
                }
                break;
            case 8:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    } while (choice < 1 || choice > 7);
}

int main(){
    list* cdfs = lst_create_list();
    CDATAFRAME* cdf = get_first_node(cdfs);
    int nb_cdf = -1;
    MenuSection(cdf, cdfs, nb_cdf);
    /*
    COLUMN *mycol = create_column("Column 0");
    insert_value(mycol, 52);
    insert_value(mycol, 44);
    insert_value(mycol, 15);
    insert_value(mycol, 12);
    COLUMN *mycol2 = create_column("Column 1");
    insert_value(mycol2, 1);
    insert_value(mycol2, 2);
    insert_value(mycol2, 3);
    insert_value(mycol2, 15);
    COLUMN *mycol3 = create_column("Column 2");
    insert_value(mycol3, 0);
    insert_value(mycol3, 0);
    insert_value(mycol3, 1);
    insert_value(mycol3, 15);
    COLUMN *mycol4 = create_column("Column 3");
    insert_value(mycol4, 6);
    insert_value(mycol4, 6);
    insert_value(mycol4, 6);
    insert_value(mycol4, 15);
    COLUMN *mycol5 = create_column("Column 4");
    insert_value(mycol5, 7);
    insert_value(mycol5, 5);
    insert_value(mycol5, 42);
    insert_value(mycol5, 15);




    printf("Occurrences of 44: %d\n", count_occ(mycol, 44));
    printf("Value at position 1: %d\n", positionval(mycol, 1));
    printf("Values greater than 20: %d\n", valuegreater(mycol, 20));
    printf("Values less than 30: %d\n", valueless(mycol, 30));
    printf("Values equal to 44: %d\n", valuequal(mycol, 44));


    CDATAFRAME *cdf = create_cdataframe(5);
    printf("%d", add_column_cdf(cdf, mycol));
    printf("%d", add_column_cdf(cdf, mycol2));
    printf("%d", add_column_cdf(cdf, mycol3));
    printf("%d", add_column_cdf(cdf, mycol4));
    printf("%d", add_column_cdf(cdf, mycol5));
    printf("\n");


    print_rows_cdf(cdf, 2, 2);
    print_cols_cdf(cdf, 1, 2);
    print_cdf(cdf);
    print_columns_title(cdf);
    rename_column_cdf(cdf, 2, "Testtt");
    print_columns_title(cdf);


    print_cdf(cdf);
    int tab[5] = {1,2,3,4,5};
    add_row_cdf(cdf, tab, 2);
    print_cdf(cdf);
    delete_row_cdf(cdf, 2);
    print_cdf(cdf);


    print_cdf(cdf);
    search_value_cdf(cdf, 1000);


    print_cdf(cdf);
    access_and_replace_value_by_pos(cdf, 20, 1, 3);
    print_cdf(cdf);


    CDATAFRAME *cdff = load_from_csv("C:\\Users\\alban\\CLionProjects\\CDataFrame\\test_file_csv.csv",6);
    print_cdf(cdff);


    print_cdf(cdf);
    save_into_csv(cdf, "Test.csv");


    print_col(mycol);
    sort(mycol, 0);
    print_col_by_index(mycol);

    sort(mycol, 0);
    search_value_in_column(mycol, 44);


    */
    return 0;
}