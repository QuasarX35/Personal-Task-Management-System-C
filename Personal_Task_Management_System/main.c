// Standard Libraries
#include <stdio.h>
#include <stdlib.h>

// Custom function files
/* ifndef and endif are used to protect against multiple inclusion of headers and redefinition errors */
#ifndef _MY_HEADER_H_

#include "PTMS_functions.h"

#endif /* _MY_HEADER_H_ */

#define _MY_HEADER_H_
#define ERROR_MESSAGE "\n*** ERROR, please try again. ***\n"
#define FILE_ERROR_MESSAGE "\n***ERROR, file could not be opened. ***\n"



// TODO: Add Task Priority
// TODO: go back to the ranged_input page and try to understand clean_stdin()
// TODO: add an option for the user to add new task categories
// TODO: add an option for the user to remove all completed tasks (within update task) 
// TODO: return an error OR exit if user does not type anything
// TODO: add a boxed output for each task to make it look nice lol
// TODO: put all the functions related to each other in one .h file
// TODO: compare task_remove with task_add and change the while loop
// // TODO: remove completed status from task_add
// TODO: press Esc to cancel
// TODO: rename all files and functions
// TODO: add a config file to save the current categories (name: categories.config i guess)
// TODO: try to understand the changing of string elements in a list



int main() {
    int choice;
    char view_exit;

    do {
        system("cls");  // clears the terminal screen
        printf(
            "\n"
            "\t+---------------------------------+\n"
            "\t| Personal Task Management System |\n"
            "\t+---------------------------------+\n"
            "\t| 1) Add New Task                 |\n"
            "\t| 2) View All Tasks               |\n"
            "\t| 3) Update Task                  |\n"
            "\t| 4) Delete Task                  |\n"
            "\t| 5) Exit Program                 |\n"
            "\t+---------------------------------+\n"
            );

        choice = ranged_input(1, 5, "Please enter your choice");
        system("cls");

        switch (choice) {
            case 1:
                printf(
                    "-----------------------------\n"
                    "\tCurrent Tasks\n"
                    "-----------------------------\n"
                );
                task_view();
                task_add();
                break;

            case 2:
                printf(
                    "-----------------------------\n"
                    "\tCurrent Tasks\n"
                    "-----------------------------\n"
                );
                task_view();
                printf("Enter any key to return: ");
                scanf("%c", &view_exit);
                fflush(stdin);
                break;

            case 3:
                printf(
                    "-----------------------------\n"
                    "\tCurrent Tasks\n"
                    "-----------------------------\n"
                );
                task_view();
                task_modify();
                printf("3. Update Task\n");
                break;

            case 4:
                printf(
                    "-----------------------------\n"
                    "\tCurrent Tasks\n"
                    "-----------------------------\n"
                );
                task_view();
                task_remove();
                break;

            case 5:
                printf("\nProgram will be exited shortly...\n");
                exit(0);
                break;

            default:
                printf("%s", ERROR_MESSAGE);
        }
    } while (choice < 5);

    return 0;
}