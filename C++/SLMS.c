#include <stdio.h>
#include <string.h>
#include <time.h>

char student_name[50],student_id[20],book_name[50],book_id[10],branch[5];

char* time_now(){
    static char timestamp[50];
    time_t now = time(NULL);
    struct tm *local = localtime(&now);
    strftime(timestamp, sizeof(timestamp), "%d-%m-%Y %H:%M:%S", local);
    return timestamp;
}
char* time_then() {
    static char return_date[30];
    time_t now = time(NULL);
    now += 17 * 24 * 60 * 60; 
    struct tm *local = localtime(&now);
    strftime(return_date, sizeof(return_date), "%d-%m-%Y", local);
    return return_date;
}

void issue(){
    printf("ENTER THE STUDENT NAME : \n");
    getchar();
    fgets(student_name, sizeof(student_name), stdin);
    student_name[strcspn(student_name, "\n")] = '\0';
    printf("ENTER THE STUDENT ID : \n");
    scanf("%s",student_id);
    printf("ENTER THE BOOK NAME : \n");
    getchar();
    fgets(book_name, sizeof(book_name), stdin);
    book_name[strcspn(book_name, "\n")] = '\0';
    printf("ENTER THE BOOK ID : \n");
    scanf("%s",book_id);
    char *timestamp=time_now();
    char *return_date=time_then();
    FILE *fp = fopen("issue.csv", "a");
    if (fp == NULL) {
        printf("ERROR: Could not open file!\n");
        return;
    }
    fprintf(fp, "%s,%s,%s,%s,%s,%s\n", student_name, student_id, book_name, book_id,timestamp,return_date);
    fclose(fp);
    printf("====== ISSUE INFO :: =====\n");
    printf("STUDENT NAME   :: %s\n",student_name);
    printf("STUDENT ID     :: %s\n",student_id);
    printf("BOOK NAME      :: %s\n",book_name);
    printf("BOOK ID        :: %s\n",book_id);
    printf("DATE OF ISSUE  :: %s\n",timestamp);
    printf("DATE OF RETURN :: %s\n",return_date);
    printf("\n");
    printf("\n");
    printf("================ BOOK ISSUED SUCCESSFULLY! ===============\n");
    printf("\n");
    }
void record(){

#define MAX_ROWS 100
#define MAX_COLS 10
#define MAX_LEN 300

    char line[MAX_LEN];
    char *data[MAX_ROWS][MAX_COLS];
    int col_width[MAX_COLS] = {0};
    int row_count = 0, col_count = 0;

    FILE *fp = fopen("issue.csv", "r");
    if (!fp) {
        printf("Error: Cannot open file.\n");
    }
    while (fgets(line, sizeof(line), fp)) {
        line[strcspn(line, "\n")] = '\0';
    int col = 0;
        char *token = strtok(line, ",");
        while (token && col < MAX_COLS) {
            data[row_count][col] = strdup(token);
            int len = strlen(token);
            if (len > col_width[col]) col_width[col] = len;
            col++;
            token = strtok(NULL, ",");
        }
        col_count = col;
        row_count++;
    }
    fclose(fp);
    for (int r = 0; r < row_count; r++) {
        for (int c = 0; c < col_count; c++) {
            printf("%-*s", col_width[c], data[r][c]);
            if (c < col_count - 1)
                printf(" || ");
        }
        printf("\n");
        printf("\n");
    }

}

int main() {
    int ch_main;

    printf("=============================================\n");
    printf("   LIBRARY MANAGEMENT SYSTEM (STUDENT DATA)  \n");
    printf("=============================================\n");
    printf("\n");
    printf("====== MAIN MENU =====::\n1. ISSUE\n2. STUDENT RECORDS\nYOUR INPUT (1-2): ");
    scanf("%d", &ch_main);

    switch (ch_main) {
        case 1:
            printf("\n================= BOOK ISSUE PLATFORM =================\n");
            issue();
            break;
        case 2:
            printf("\n================================================= BOOK RECORD PLATFORM =================================================\n");
            printf("\n");
            record();
            break;
        default:
            printf("==== INVALID INPUT! ===\n");
    }
    printf("==== THANKYOU FOR USING THE LIBRARY MANAGEMNT SYSTEM =====");
    return 0;
}
