#include <stdio.h>
#include <stdlib.h>
struct  node {
    int empId;
    char name[15];
    float salary;
    struct node * leftLink,*rightLink;
};
void insertion(struct node **head){
    struct node * newNode=(struct node *)malloc(sizeof(struct node));
    struct node * ptr=*head;
    newNode->leftLink=NULL;
    newNode->rightLink=NULL;
    printf("Enter name : ");
    scanf("%s",newNode->name);
    printf("Enter Employee ID :");
    scanf("%d",&newNode->empId);
    printf("Enter Salary :");
    scanf("%f",&newNode->salary);
    if(*head==NULL){
        *head=newNode;
    }
    else{
        while(ptr->rightLink!=NULL){
            if(newNode->empId<ptr->empId){
                newNode->rightLink=ptr;
                newNode->leftLink=ptr->leftLink;
                newNode->rightLink->leftLink=newNode;
                if(newNode->leftLink==NULL)
                    *head=newNode;
                else
                    newNode->leftLink->rightLink=newNode;   
                return ;
            }
            ptr=ptr->rightLink;
        }
        if(newNode->empId<ptr->empId){
             newNode->rightLink=ptr;
             newNode->leftLink=ptr->leftLink;
             newNode->rightLink->leftLink=newNode;
             if(newNode->leftLink==NULL)
               *head=newNode;
             else
               newNode->leftLink->rightLink=newNode; 
        }
        else{
             newNode->leftLink=ptr;
            ptr->rightLink=newNode;
        }
    }
}
void view(struct node * head){
    if(head==NULL){
        printf("Empty list\n");
    }
    else{
        printf("Details of Employee \n");
        while(head!=NULL){
            printf("Employee ID  :%d\n",head->empId);
            printf("Name         : %s\n",head->name);
            printf("Salary       : %f\n\n",head->salary);
            head=head->rightLink;
        }
    }
}
void main(){
    int dis;
    struct node * emp=NULL;
    printf("1-INSERTION\n2-VIEW\n3-EXIT");
    do{
        printf("\nEnter Your Choice: ");
        scanf("%d",&dis);
        switch(dis){
            case 1:insertion(&emp);
                    break;
            case 2:view(emp);
                    break;
            case 3:break;
        }
    }while(dis!=3);
}