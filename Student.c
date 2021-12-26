#include <stdio.h>
#include <string.h>

typedef struct Student {
    char id[9];
    char name[10];
    int score1;
    int score2;
    int score3;
    float average;
} student;

student newStudent(char id, char name, int score1, int score2, int score3) {
    student s;
    strcpy(s.id, id);
    strcpy(s.name, name);
    s.score1 = score1;
    s.score2 = score2;
    s.score3 = score3;
    s.average = (score1 + score2 + score3) / 3.0;

    return s;
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
                char id;
                scanf("%s", &id);
                for(int i = 0; i < 6; i++) {
                    if(strcmp(id, list[i].id) == 0) {
                        printf("%s\t%s\t%d\t%d\t%d\n", list[i].id, list[i].name, list[i].score1, list[i].score2, list[i].score3);
                        break;
                    }
                    else {
                        printf("%s\n", "No such student");
                        continue;
                    }
                }
            case 's':
                for(int i = 0; i < 6; i++) {
                    printf("%s\t%s\t%d\t%d\t%d\n", list[i].id, list[i].name, list[i].score1, list[i].score2, list[i].score3);
                }
                printf("%s\n", "----------");
            // case 'd':
            // student temp;
            // student listHighToLow[6] = list;
            //     for(int i = 0; i < 5; ++i) {
            //         for(int j = 0; j < 5 - i; ++j) {
            //             if(listHighToLow[j].average > listHighToLow[j].average) {
            //                 temp = listHighToLow[j];
            //                 listHighToLow[j] = listHighToLow[j + 1];
            //                 listHighToLow[j + 1] = temp;
            //             }
            //         }
            //     }
            //     for(int i = 0; i < 6; i++) {
            //         printf("%s\t%s\t%d\t%d\t%d\n", listHighToLow[i].id, listHighToLow[i].name, listHighToLow[i].score1, listHighToLow[i].score2, listHighToLow[i].score3);
            //     }
            // case 'a':
            // student temp;
            // student listLowToHigh[6] = list;
            //     for(int i = 0; i < 5; ++i) {
            //         for(int j = 0; j < 5 - i; ++j) {
            //             if(listHighToLow[j].average < listHighToLow[j].average) {
            //                 temp = listLowToHigh[j];
            //                 listLowToHigh[j] = listLowToHigh[j + 1];
            //                 listLowToHigh[j + 1] = temp;
            //             }
            //         }
            //     }
            //     for(int i = 0; i < 6; i++) {
            //         printf("%s\t%s\t%d\t%d\t%d\n", listLowToHigh[i].id, listLowToHigh[i].name, listHighToLow[i].score1, listHighToLow[i].score2, listHighToLow[i].score3);
            //     }
            case 'b':
                for(int i = 0; i < 6; i++) {
                    printf("%s\t%s\t%2f\n", list[i].id, list[i].name, list[i].average);
                    printf("%s\n", "--**--**--**--**--");
                }
            case 'q':
                break;
        }
    }

    return 0;
}