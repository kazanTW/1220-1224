#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Student {
    char id[10];
    char name[10];
    int score1;
    int score2;
    int score3;
    float average;
} student;

student newStudent(char* id, char* name , int score1, int score2, int score3) {
    student s;
    strcpy(s.id, id);
    strcpy(s.name, name);
    s.score1 = score1;
    s.score2 = score2;
    s.score3 = score3;
    s.average = (score1 + score2 + score3) / 3.0;

    return s;
}

void sortingDecline(student arr[]) {
    student temp;
    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < 5 - i; ++j) {
            if(arr[j].average < arr[j + 1].average) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void sortingIncrease(student arr[]) {
    student temp;
    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < 5 - i; ++j) {
            if(arr[j].average > arr[j + 1].average) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char** argv) {
    char func;

    student David = newStudent("D11009923", "David", 80, 90, 90);
    student Jack = newStudent("D11009933", "Jack", 90, 90, 90);
    student Kevin = newStudent("D11009943", "Kevin", 80, 70, 90);
    student Jannie = newStudent("D11009823", "Jannie", 80, 90, 50);
    student Justin = newStudent("D11007923", "Justin", 80, 70, 90);
    student Allen = newStudent("D11069923", "Allen", 40, 90, 90);

    student list[6] = {David, Jack, Kevin, Jannie, Justin, Allen}; 
    student listHighToLow[6];
    student listLowToHigh[6];
    memcpy(listHighToLow, list, sizeof(list));
    memcpy(listLowToHigh, list, sizeof(list));

    printf("%s\n", "===== menu =====");
    printf("%s\n", "f: find specific student data");
    printf("%s\n", "s: show all students' data");
    printf("%s\n", "d: show the sorted students' data (high to low) ");
    printf("%s\n", "a: show the sorted students' data (low to high) ");
    printf("%s\n", "b: show the average score value");
    printf("%s\n", "q: quit");
    
    printf("%s", "function choice: ");
    
    while(func = getchar(), func != EOF) {
        switch(func) {
            case 'f':
                printf("%s", "Student's ID: ");
                const char id_target[10] = {};
                scanf("%s", id_target);
                for(int i = 0; i < 6; i++) {
                    if(strcmp(list[i].id, id_target) == 0) {
                        printf("%s\t%s\t%d\t%d\t%d\n", list[i].id, list[i].name, list[i].score1, list[i].score2, list[i].score3);
                        break;
                    }
                    else {
                        printf("%s\n", "No such student");
                        break;
                    }
                }
                printf("%s\n", "----------");
                continue;
            case 's':
                for(int i = 0; i < 6; i++) {
                    printf("%s\t%s\t%d\t%d\t%d\n", list[i].id, list[i].name, list[i].score1, list[i].score2, list[i].score3);
                }
                printf("%s\n", "----------");
                continue;
            case 'd':
                sortingDecline(listHighToLow);                
                for(int i = 0; i < 6; i++) {
                    printf("%s\t%s\t%d\t%d\t%d\n", listHighToLow[i].id, listHighToLow[i].name, listHighToLow[i].score1, listHighToLow[i].score2, listHighToLow[i].score3);
                }
                printf("%s\n", "----------");
                continue;
            case 'a':
                sortingIncrease(listLowToHigh);
                for(int i = 0; i < 6; i++) {
                    printf("%s\t%s\t%d\t%d\t%d\n", listLowToHigh[i].id, listLowToHigh[i].name, listLowToHigh[i].score1, listLowToHigh[i].score2, listLowToHigh[i].score3);
                }
                printf("%s\n", "----------");
                continue;
            case 'b':
                for(int i = 0; i < 6; i++) {
                    printf("%s\t%s\t%2f\n", list[i].id, list[i].name, list[i].average);
                }
                printf("%s\n", "--**--**--**--**--");
                continue;
            case 'q':
                printf("%s\n", "Thanks for using. Bye!");
                exit(EXIT_SUCCESS);
        }
    }

    return 0;
}