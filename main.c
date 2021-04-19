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

#include <stdio.h>
#include <stdlib.h>
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

    insertNodeAtBeginning(data);

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
    insertNodeAtMiddle(data, position);

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
       insertNodeAtEnd(data);

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
}
