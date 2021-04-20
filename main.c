#include <stdio.h>
#include <stdlib.h>
struct student {
    char name[24];
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
 b2
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct s_student student;

struct s_student
{
  char name[64];
  int id;
  int  marks;
  int day;
  int month;
  int year;
  // This will point to the next student on the list
  student* nextStudent;
};


typedef struct s_studentList
{
  // This will point to the last available student
  student* lastStudent;
  // This will point to the first available student
  student* firstStudent;
  //this will point to the middle student
  student* middleStudent;
} studentList;

// Allocates the list
void allocStudentsList(studentList** list) {
    if(list == NULL) return;
    *list = (studentList*) malloc(sizeof(studentList));
    (*list)->lastStudent = NULL;
    (*list)->middleStudent=NULL;
    (*list)->firstStudent = NULL;

}

// To add the student to the list
void insert_at_the_beginning(studentList* list, student studentData) {

    if(list == NULL) return;

    // Allocate a place for the next student
    student* st = (student*) malloc(sizeof(student));
        // Fill the student data
    *st = studentData;
    st->nextStudent = NULL;

    // If it's first student in the list
    if(list->middleStudent == NULL) {
        list->middleStudent = st;
        list->firstStudent = st;
        list->lastStudent = st;
    }
    else {
        // The next student after the current last student will be the newly created one
        list->lastStudent->nextStudent = st;
    }



    // Set the middle available student to the one created
    list->middleStudent = st;


}

// To add the student to the list
void insert_at_the_middle(studentList* list, student studentData) {


    if(list == NULL) return;

    // Allocate a place for the next student
    student* st = (student*) malloc(sizeof(student));
        // Fill the student data
    *st = studentData;
    st->nextStudent = NULL;

    // If it's middle student in the list
    if(list->lastStudent == NULL) {
        list->lastStudent = st;
        list->middleStudent = st;
    }
    else {
        // The next student after the current last student will be the newly created one
        list->middleStudent->nextStudent = st;
    }



    // Set the last available student to the one created
    list->lastStudent = st;

}
// To add the student to the list
void insert_at_the_end(studentList* list, student studentData) {


    if(list == NULL) return;

    // Allocate a place for the next student
    student* st = (student*) malloc(sizeof(student));
            // Fill the student data
    *st = studentData;
     st->nextStudent = NULL;

    // If it's first student in the list
    if(list->lastStudent == NULL) {
        list->lastStudent = st;
       // list->firstStudent = st;
    }
    else {
        // The next student after the current last student will be the newly created one
        list->lastStudent->nextStudent = st;
    }


    //st->nextStudent = NULL;

    // Set the last available student to the one created
    list->lastStudent = st;

}
// To recurisvely free the students
void freeStudent(student* stud) {
    if(stud->nextStudent != NULL) {
        // Free next student recursively
        freeStudent(stud->nextStudent);
    }
    free(stud);
}

// To free the students list
void freeStudentsList(studentList* list) {
    if(list != NULL) {
        freeStudent(list->firstStudent);
        free(list);
    }
}

// Function that prints single student and returns next one (after him on the list)
student* printStudent(student* stud) {
    if(stud == NULL) return NULL;
    printf("Student name = %s \n", stud->name);
    printf("Student id = %d \n", stud->id);
    printf("Student  marks= %d \n", stud-> marks);
    printf("Student date of birth = %d/%d/%d \n", stud->day,stud->month,stud->year);
   // return next student
    return stud->nextStudent;
}

// Function that prints students list
void printStudentsList(studentList* list) {
    if(list == NULL) return;

    printf("StudentsList [\n");

    student *current_student=list->firstStudent;
    while(current_student != NULL) {
        current_student = printStudent(current_student);
    }

    printf("]\n");

}

int main(int argc, char** argv) {


  studentList* list = NULL;
  student st1;
  int n,i;
allocStudentsList(&list);

// if we want to put a data for a student at run time delete the comment below

   printf("please enter the information of students\n");
printf("please enter the number of syudents in array\n");
scanf("%d",&n);
student st[n];
int flag;

for(i=0;i<n;i++)
{
     printf("please enter the student's name\n");
     scanf("%s",st[i].name);
     printf("please enter the student id\n");
     scanf("%d",&st[i].id);
     printf("please enter the date of birth\n");
     printf("please enter the day\n");
     scanf("%d",&st[i].day);
     printf("please enter the month\n");
     scanf("%d",&st[i].month);
     printf("please enter the year\n");
     scanf("%d",&st[i].year);
     printf("please enter the  marks of the student\n");
     scanf("%d",&st[i]. marks);
     insert_at_the_beginning(list, st[i] );
}

printf("if u want to add a student at the beginning enter 1 if in middle enter 2 if in end enter 3 else enter \n");
scanf("%d",&flag);
if (flag==1)
    {
 printf("please enter the student's name\n");
     scanf("%s",st1.name);
     printf("please enter the student id\n");
     scanf("%d",&st1.id);
     printf("please enter the date of birth\n");
     printf("please enter the day\n");
     scanf("%d",&st1.day);
     printf("please enter the month\n");
     scanf("%d",&st1.month);
     printf("please enter the year\n");
     scanf("%d",&st1.year);
     printf("please enter the  marks of the student\n");
     scanf("%d",&st1.marks);
 insert_at_the_beginning(list, st1);}
 else if (flag==2)
     {
 printf("please enter the student's name\n");
     scanf("%s",st1.name);
     printf("please enter the student id\n");
     scanf("%d",&st1.id);
     printf("please enter the date of birth\n");
     printf("please enter the day\n");
     scanf("%d",&st1.day);
     printf("please enter the month\n");
     scanf("%d",&st1.month);
     printf("please enter the year\n");
     scanf("%d",&st1.year);
     printf("please enter the  marks of the student\n");
     scanf("%d",&st1. marks);
 insert_at_the_middle(list, st1);}
  else if(flag==3)
    {
 printf("please enter the student's name\n");
     scanf("%s",st1.name);
     printf("please enter the student id\n");
     scanf("%d",&st1.id);
     printf("please enter the date of birth\n");
     printf("please enter the day\n");
     scanf("%d",&st1.day);
     printf("please enter the month\n");
     scanf("%d",&st1.month);
     printf("please enter the year\n");
     scanf("%d",&st1.year);
     printf("please enter the marks of the student\n");
     scanf("%d",&st1.marks);
 insert_at_the_end(list, st1);}
 else {
    //do nothing
 }

  // Create some student data








  // Print the list
  printStudentsList(list);

  // Free the list (recursively free's all students and take care of all the nasty stuff)
  freeStudentsList(list);

  return 0;
=======

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//code using linked list
struct student {
    char name[24];
    int id;
    int day,month,year;
    int marks;};

struct node {
    struct student data;
    struct node *next;
}*head;

void createList(int n);
void insertNodeAtBeginning(struct student data);
void insertNodeAtMiddle(struct student data, int position);
void insertNodeAtEnd(struct student data);
void displayList();


int main()
{
    int n,i,position;
    struct student data;
    // to get informations of n students
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);

    printf("\nData in the list \n\n");
    displayList();

    printf("\n Enter choice \n bress 1 to insert at beginning of the list  \n or 2 to insert at middle of the list \n or 3 to insert at end of the list: ");
    scanf("%d", &i);
    switch (i)
    {case 1:
    // to insert a student in the beginning of the list
       printf("Enter name: ");
    scanf("%s", &data.name);
    printf("Enter id number: ");
    scanf("%d", &data.id);
    printf("Enter the birth day:\n");
    printf("Enter the day: ");
    scanf("%d", &data.day);
    printf("Enter the month: ");
    scanf("%d", &data.month);
    printf("Enter the year: ");
    scanf("%d", &data.year);
    printf("Enter marks: ");
    scanf("%d", &data.marks);
     
    // Calculate the time taken by insertNodeAtBeginning(data);
    clock_t t1;
	t1 = clock();
    insertNodeAtBeginning(data);
    t1 = clock() - t1;
	double time_taken = ((double)t1)/CLOCKS_PER_SEC; // in seconds
	printf("inserting node at the begining took %f seconds to execute  \n", time_taken);


 

    printf("\nData in the list \n\n");
    displayList();
    break;

     case 2:
         // to insert a student in the middle of the list
       printf("Enter name: ");
   scanf("%s", &data.name);
    printf("Enter id number: ");
    scanf("%d", &data.id);

    printf("Enter the birth day:\n");
    printf("Enter the day: ");
    scanf("%d", &data.day);
    printf("Enter the month: ");
    scanf("%d", &data.month);
    printf("Enter the year: ");
    scanf("%d", &data.year);
    printf("Enter marks: ");
    scanf("%d", &data.marks);

    printf("Enter the position to insert new node: " );
    scanf("%d", &position);
     
   // Calculate the time taken by   insertNodeAtMiddle(data, position);
    clock_t t2;
	t2 = clock();
    insertNodeAtMiddle(data, position);
    t2 = clock() - t2;
	double time_taken2 = ((double)t2)/CLOCKS_PER_SEC; // in seconds
printf("inserting node at the middle took %f seconds to execute  \n", time_taken2);

    printf("\nData in the list \n\n");
    displayList();
    break;

     case 3:
        // to insert a student in the end of the list
        printf("Enter name: ");
    scanf("%s", &data.name);
    printf("Enter id number: ");
    scanf("%d", &data.id);

    printf("Enter the birth day:\n");
    printf("Enter the day: ");
    scanf("%d", &data.day);
    printf("Enter the month: ");
    scanf("%d", &data.month);
    printf("Enter the year: ");
    scanf("%d", &data.year);
    printf("Enter marks: ");
    scanf("%d", &data.marks);
     
     // Calculate the time taken by  insertNodeAtEnd(data);
     clock_t t3;
	t3 = clock();
    insertNodeAtEnd(data);
    t3 = clock() - t3;
	double time_taken3 = ((double)t3)/CLOCKS_PER_SEC; // in seconds

    printf("inserting node at the end took %f seconds to execute  \n", time_taken3);

     

    printf("\nData in the list \n\n");
    displayList();
    break;}

     //tocalculare the size taken by one node of the linked list
    printf("the size taken by one node in linked list = %d\n\n",sizeof(struct node));

     //to calculate the size taken by the stucture
    printf("the size taken by strucure in the memory: %d\n",sizeof(data));

    return 0;
}

//function to create a linked list
void createList(int n)
{
    struct node *newNode, *temp;
    struct student data;
    int i;

    head = (struct node *)malloc(sizeof(struct node));

    if(head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {

        printf("Enter the data of node 1: \n ");
           printf("Enter name: ");
    scanf("%s", &data.name);
    printf("Enter id number: ");
    scanf("%d", &data.id);

    printf("Enter the birth day:\n");
    printf("Enter the day: ");
    scanf("%d", &data.day);
    printf("Enter the month: ");
    scanf("%d", &data.month);
    printf("Enter the year: ");
    scanf("%d", &data.year);
    printf("Enter marks: ");
    scanf("%d", &data.marks);


        head->data = data;
        head->next = NULL;

        temp = head;

        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));


            if(newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d: \n", i);
                    printf("Enter name: ");
    scanf("%s", &data.name);
    printf("Enter id number: ");
    scanf("%d", &data.id);

    printf("Enter the birth day:\n");
    printf("Enter the day: ");
    scanf("%d", &data.day);
    printf("Enter the month: ");
    scanf("%d", &data.month);
    printf("Enter the year: ");
    scanf("%d", &data.year);
    printf("Enter marks: ");
    scanf("%d", &data.marks);


                newNode->data = data;
                newNode->next = NULL;

                temp->next = newNode;

                temp = temp->next;
            }
        }

        printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}

   // function to insert a student in the beginning of the list
void insertNodeAtBeginning(struct student data)
{
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data;
        newNode->next = head;

        head = newNode;

        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}

// function to insert a student in the middle of the list
void insertNodeAtMiddle(struct student data, int position)
{
    int i;
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data;
        newNode->next = NULL;

        temp = head;


        for(i=2; i<=position-1; i++)
        {
            temp = temp->next;

            if(temp == NULL)
                break;
        }

        if(temp != NULL)
        {

            newNode->next = temp->next;

                temp->next = newNode;

            printf("DATA INSERTED SUCCESSFULLY\n");
        }
        else
        {
            printf("UNABLE TO INSERT DATA AT THE GIVEN POSITION\n");
        }
    }
}

// function to insert a student in the end of the list
void insertNodeAtEnd( struct student data)
{
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data;
        newNode->next = NULL;

        temp = head;

        while(temp != NULL && temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;

        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}

// display function to print and show the list
void displayList()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("name = %s\n", temp->data.name);
              printf("id = %d\n", temp->data.id);
              printf("date of birth = %d-%d-%d\n", temp->data.day,temp->data.month,temp->data.year);
              printf("marks = %d\n\n", temp->data.marks);
        temp = temp->next;
        }
    }
 main
}
