#include <stdio.h>
#include <stdlib.h>
struct student {
    char name[50];
    int id;
    int day,month,year;
    int last_mark;
} s;

int main() {
    printf("Enter information:\n");
    printf("Enter name: ");
    fgets(s.name, sizeof(s.name), stdin);

    printf("Enter id number: ");
    scanf("%d", &s.id);

    printf("Enter the birth day:\n");
    printf("Enter the day: ");
    scanf("%d", &s.day);
    printf("Enter the month: ");
    scanf("%d", &s.month);
    printf("Enter the year: ");
    scanf("%d", &s.year);

    printf("Enter last_Mark: ");
    scanf("%d", &s.last_mark);

    printf("Displaying Information:\n");
    printf("Name: %s", s.name);
    printf("id number: %d\n", s.id);
    printf("day.month.year: %d-%d-%d\n",s.day,s.month,s.year);
    printf("last_Mark: %.1d\n", s.last_mark);

    return 0;
}
