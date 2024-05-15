#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <column.h>
#include <main.h>
#include <cdataframe.h>
#include <double-linked-list.h>
#include <utils.h>

void MenuFilling(CDATAFRAME* cdf, list* cdfs, int nb_cdf) {
    int choice;
    do {
        printf(
                "     #########################################################################\n"
                "     #                              Filling Menu                             #\n"
                "     #  CDataFrame selected : CDataFrame %d                                  #\n"
                "     #                                                                       #\n"
                "     #  1- Create an empty CDataFrame                                        #\n"
                "     #  2- Fill the CDataframe with input (new column)                       #\n"
                "     #  3- Hard fill the CDataframe with an array (new column)               #\n"
                "     #  4- Load from CSV                                                     #\n"
                "     #  5- Save into CSV                                                     #\n"
                "     #  6- Back                                                              #\n"
                "     #########################################################################\n", nb_cdf
        );
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the size of the CDataFrame :");
                int new_cdf_size;
                scanf("%d", &new_cdf_size);
                CDATAFRAME* new_cdf = create_cdataframe(new_cdf_size);
                lnode* cdf_create = lst_create_lnode(new_cdf);

                if (get_first_node(cdfs) == NULL){
                    lst_insert_head(cdfs, cdf_create);
                }else{
                    lst_insert_tail(cdfs, cdf_create);
                }

                printf("A new empty CDataFrame has been created.\n");
                MenuFilling(cdf, cdfs, nb_cdf);
                break;
            case 2:
                fill_user(cdf);
                printf("\n");
                MenuFilling(cdf, cdfs, nb_cdf);
                break;
            case 3:
                printf("Enter the array wanted (123456) then the size (6) :");
                char array_str[100];
                int size;
                scanf("%99s", array_str);
                scanf("%d", &size);
                int* array = string_to_int_array(array_str, &size);
                fill_hard(cdf, size, array);
                MenuFilling(cdf, cdfs, nb_cdf);
                break;
            case 4:
                printf("Enter the path to the csv file :");
                char file_name[200];
                scanf("%199s", file_name);
                printf("Enter the number of column of your csv file :");
                int nb_col = 0;
                scanf("%d", &nb_col);
                CDATAFRAME* cdf_csv = load_from_csv(file_name, nb_col);
                lst_insert_tail(cdfs, lst_create_lnode(cdf_csv));
                MenuFilling(cdf, cdfs, nb_cdf);
                break;
            case 5:
                printf("Enter name of the csv file :");
                char file_name2[200];
                scanf("%199s", file_name2);
                save_into_csv(cdf, file_name2);
                MenuFilling(cdf, cdfs, nb_cdf);
            case 6:
                printf("Going back...\n");
                MenuSection(cdf, cdfs, nb_cdf);
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    } while (choice < 1 || choice > 6);
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
                print_cdf(cdf);
                MenuDisplaying(cdf, cdfs, nb_cdf);
                break;
            case 2:
                // Print Rows
                printf("You chose to print Rows.\n");
                MenuDisplaying(cdf, cdfs, nb_cdf);
                break;
            case 3:
                // Print Columns
                printf("You chose to print Columns.\n");
                MenuDisplaying(cdf, cdfs, nb_cdf);
                break;
            case 4:
                // Print Column Titles
                printf("You chose to print Column Titles.\n");
                MenuDisplaying(cdf, cdfs, nb_cdf);
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
                MenuUsualOperations(cdf, cdfs, nb_cdf);
                break;
            case 2:
                // Delete Column
                printf("You chose to delete a column.\n");
                MenuUsualOperations(cdf, cdfs, nb_cdf);
                break;
            case 3:
                // Access and Replace Value
                printf("You chose to access and replace a value.\n");
                MenuUsualOperations(cdf, cdfs, nb_cdf);
                break;
            case 4:
                // Search Value
                printf("You chose to search a value.\n");
                MenuUsualOperations(cdf, cdfs, nb_cdf);
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
                if (cdfs->head == NULL){
                    printf("There is no CDataFrame created, please go to the Section 1 - Creation and Filling\n");
                    MenuSection(cdf, cdfs, nb_cdf);
                } else {
                    lnode* cdf_choice = get_first_node(cdfs);
                    int number_cdf = -1;
                    int i = 1;
                    printf("List of CDataFrame\n");
                    printf("%d - CDataFrame %d\n", 1, 1);
                    while (cdf_choice != cdfs->tail){
                        i++;
                        printf("%d - CDataFrame %d\n", i, i);
                        cdf_choice = get_next_node(cdfs, cdf_choice);
                    }
                    do{
                        printf("Enter the number of the CDataFrame :");
                        scanf("%d", &number_cdf);
                        if (number_cdf < 1 || number_cdf > i){
                            printf("Invalid choice! Please enter a number between 1 and %d.\n", i);
                        }
                    }while (number_cdf < 1 || number_cdf > i);
                    cdf_choice = get_first_node(cdfs);
                    for (int k = 0; k < number_cdf - 1; k++){
                        cdf_choice = get_next_node(cdfs, cdf_choice);
                    }
                    cdf = cdf_choice->data;
                    nb_cdf = number_cdf;
                    MenuSection(cdf, cdfs, nb_cdf);
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