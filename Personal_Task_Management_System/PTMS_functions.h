// Standard Libraries
#include <stdio.h>
#include <stdlib.h>

// Additional Libraries
#include <string.h>

#define MAX_ELEMENTS 6
#define PROMPT_MAX 1024
#define MAX_FILENAME 64
#define MAX_LINE 2048

int file_line_count(char input_file[MAX_FILENAME]) {
    /* Inputs and declaration*/
    FILE *file;
    int lines = 1;
    file = fopen(input_file, "r");
    
    /* Processing */
    if (file == NULL) {
        perror("file_line_count Error");
        return -1;
    }

    while (!feof(file) && !ferror(file)) {
        if (fgetc(file) == '\n') {
            lines++;
        }
    }

    fclose(file);

    /* output */
    return lines;
}

int clean_stdin() {
    while (getchar() != '\n');
    return 1;
}

int ranged_input(int range_start, int range_end, char prompt[PROMPT_MAX]) {
    int first_time = 0;
    int input = 0;
    char char2;
    
    do {
        if (first_time == 0) {
            first_time++;
        }
        else {
            printf("\n*** ERROR, please try again. ***\n");
        }
        
        printf("\n%s (%d ~ %d): ", prompt, range_start, range_end);
    } while ((scanf("%d%c", &input, &char2) != 2 || char2 != '\n') && clean_stdin() || input < range_start || input > range_end);

    return input;
}

int task_add() {
    char name_input[MAX_LINE], name_str[MAX_LINE] = "Name:   \t";
    int category_input;
    char category_str[MAX_LINE] = "Category:\t";
    char due_date_input[20], due_date_str[MAX_LINE] = "Due Date:\t";
    char yes_or_no;

    int file_lines = file_line_count("tasks.txt");

    FILE *taskfile;
    taskfile = fopen("tasks.txt", "a");
    if (taskfile == NULL) {
        perror("addtask error");
        return -1;
    }


    printf(
        "-----------------------------\n"
        "\tAdd New Task\n"
        "-----------------------------\n"
    );

    /* Input */
    printf("Task Name: ");
    scanf("%[^\n]", name_input);
    strcat(name_str, name_input);
    
    printf(
        "\nTask Category: \n"
        "1) Homework\n"
        "2) Shopping\n"
        );
    category_input = ranged_input(1, 2, "Please enter your choice");
    if (category_input == 1) {
        strcat(category_str, "Homework");
    }
    else {
        strcat(category_str, "Shopping");
    }

    printf("\nTask Due Date: ");
    scanf("%[^\n]", due_date_input);
    strcat(due_date_str, due_date_input);

    /* Output */
    fprintf(
        taskfile,
        "\n--- Task %d ---\n%s\n%s\n%s\nStatus: \tPending\n",
        file_lines/6 + 1, name_str, category_str, due_date_str
    );

    printf("\nSuccess: Task Added\n");
    fflush(stdin);

    fclose(taskfile);

    return 0;
}

int task_view() {
    char line[MAX_LINE];
    int file_lines = file_line_count("tasks.txt");
    int current_line = 1;

    FILE *taskfile;
    taskfile = fopen("tasks.txt", "r");
    if (taskfile == NULL) {
        perror("Error: ");
        return(-1);
    }

    while (current_line < file_lines) {
        fgets(line, MAX_LINE, taskfile);
        printf("%s", line);
        current_line++;
    }

    printf("\n");

    fclose(taskfile);
    
    return 0;
}

int task_modify() {
    int file_lines = file_line_count("tasks.txt"), task_choice;

    FILE *taskfile, *tempfile;
    taskfile = fopen("tasks.txt", "r");
    tempfile = fopen("temp__tasks.txt", "w");

    if (taskfile == NULL || tempfile == NULL) {
        perror("Error: ");
        return(-1);
    }

    task_choice = ranged_input(1, file_lines/5, "Please enter the number of the task you want to modify");


    int current_line = 1, num = 0, flag = 0;
    char line[MAX_LINE]; 
    char temp_list[MAX_ELEMENTS][MAX_LINE] = {""};

    while (current_line < file_lines) {
        fgets(line, MAX_LINE, taskfile);
        
        if (current_line < (6 * task_choice) && current_line > ((6 * task_choice) - 5)) {
            strcat(temp_list[num], line);
            num++;
            }
        current_line++;
    }
    rewind(taskfile);
    fflush(taskfile);


    int flag_save = 0, line_choice;

    do {
        printf(
            "-----------------------------\n"
            "\tEdit Task\n"
            "-----------------------------\n"
        );

        for (int i = 0; i < MAX_ELEMENTS - 2; i++) {
            printf("%d. %s", i + 1, temp_list[i]);
        }
        printf("5. Save\n");
        printf("6. Cancel\n");

        line_choice = ranged_input(1, 6, "Please enter the number of the line you want to modify");

        char yes_or_no, modified_string[MAX_LINE/2], task_field[MAX_LINE/2];

        switch (line_choice) {
            case 1:
                printf("\nNew Task Name: ");
                scanf("%[^\n]", modified_string);

                strcpy(task_field, "Name:   \t");
                strcat(modified_string, "\n");
                strcat(task_field, modified_string);
                strcpy(temp_list[0], task_field);
                break;
            
            case 2:
                printf("\nChange Category: ");
                scanf("%[^\n]", modified_string);
                
                strcpy(task_field, "Category:\t");
                strcat(modified_string, "\n");
                strcat(task_field, modified_string);
                strcpy(temp_list[1], task_field);
                break;
            
            case 3:
                printf("\nNew Due Date: ");
                scanf("%[^\n]", modified_string);
                
                strcpy(task_field, "Due Date:\t");
                strcat(modified_string, "\n");
                strcat(task_field, modified_string);
                strcpy(temp_list[2], task_field);
                break;

            case 4:
                printf("\nChange Status to \"Complete\"? (Y/N): ");
                scanf("%c", &yes_or_no);
                if (yes_or_no == 'y' || yes_or_no == 'Y') {
                    strcpy(temp_list[3], "Status: \tComplete\n");
                    break;
                }
                else {
                    break;
                }

            case 5:
                flag_save = 1;
                flag = 1;
                break;
            
            case 6:
                flag = 1;
                break;
            
            default:
                printf("\nInvalid Input.");
                break;
        }

        printf("\n");
    } while (flag == 0);    

    if (flag_save == 1) {
        current_line = 1, num = 0;

        while (current_line < file_lines) {
            fgets(line, MAX_LINE, taskfile);

            if (current_line == (6 * task_choice) - 5) {
                fprintf(tempfile, "--- Task %d ---\n", task_choice);
            }
            else if (current_line < ((6 * task_choice) - 5) || current_line > (6 * task_choice) - 1) {
                fprintf(tempfile, "%s", line);
            }
            else {
                fprintf(tempfile, "%s", temp_list[num]);
                num++;
            }
            current_line++;
        }

    fclose(taskfile);
    fclose(tempfile);

    printf("Changes saved in file.\n");

    remove("tasks.txt");
    rename("temp__tasks.txt", "tasks.txt");

    return 0;
    }

    if (flag_save == 0) {
        return 1;
    }
}

int task_remove() {
    FILE *taskfile, *tempfile;
    char line[MAX_LINE];
    int *read, choice;
    int file_lines = file_line_count("tasks.txt");

    taskfile = fopen("tasks.txt", "r");
    tempfile = fopen("temp__tasks.txt", "w");

    if (taskfile == NULL || tempfile == NULL) {
        perror("Error: ");
        return(-1);
    }

    choice = ranged_input(1, file_lines/6, "Please enter the number of the task you want to delete");

    int current_line = 1, current_task = choice;

    while (current_line < file_lines) {
        fgets(line, MAX_LINE, taskfile);
        if (current_line < ((6 * choice) - 5)) {
            fprintf(tempfile, "%s", line);
            }
        if (current_line > (6 * choice)) {
            if (strstr(line, "--- Task ") != NULL) {
                fprintf(tempfile, "--- Task %d ---\n", current_task);
                current_task++;
            }
            else {                
                fprintf(tempfile, "%s", line);
            }
        }
        current_line++;
    }

    printf("\n");

    fclose(taskfile);
    fclose(tempfile);

    remove("tasks.txt");
    rename("temp__tasks.txt", "tasks.txt");

    return 0;
}