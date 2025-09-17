#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef enum {FALSE, TRUE} Bool;

typedef struct{
    char name[32];
    int experience;
}actor;

typedef struct{
    char charName[32];
    actor act;
    int auraPoints;
}disneyChar;

typedef struct{
    actor actorList[MAX];
    int front;
    int rear;
}applicantQueue;

typedef struct{
    disneyChar DC[10];
    int count;
}disneyList;


Bool isEmpty(applicantQueue Q){
    return ((Q.rear+1)%MAX == Q.front)? TRUE:FALSE;
}
void deQueue(applicantQueue* Q){
    if(isEmpty(*Q)!=TRUE){
        Q->front = (Q->front+1)%MAX;
    }
}

/* Write the code for the function applyAsDisneyChar().
   The function will receive as parameter an applicantQueue and a disneyList.
   The function will go through each applicant on the Queue, and find for the best match in terms of gender and auraPoints.   
   If there is an applicable match of applicant based on the gender and aurapoints, update the disneyChar actor to be the actor.
   Return an array of actors with NO JOBS. Let the experience of the last index of actors be -1 as sentinel.
*/

actor* applyAsDisneyChar(applicantQueue* AQ, disneyList* DL)
{
    actor* JOBLESS = (actor*)malloc(sizeof(actor)*MAX);
    if(JOBLESS!=NULL){
        int count=0;
        while(isEmpty(*AQ)!=TRUE){
            int i;
            for(i=0; i<DL->count && AQ->actorList[AQ->front].experience != DL->DC[i].auraPoints; i++){}
            if(i<DL->count){
                DL->DC[i].act = AQ->actorList[AQ->front];
            }
            else{
                JOBLESS[count++]=AQ->actorList[AQ->front];
            }
            deQueue(AQ);
        } 
        JOBLESS[count].experience = -1;
        return JOBLESS;
    }
    
}

void display(disneyList DL, actor* JOBLESS){
    for(int i = 0; i<DL.count;i++){
        printf("\n %s\t%s", DL.DC[i].charName, DL.DC[i].act.name);
    }
    printf("\nJOBLESS\n");
    for(int j = 0; JOBLESS[j].experience!=-1;j++){
        printf("\n %s", JOBLESS[j].name);
    }
}

int main(void)
{
    disneyList dList = {{
            {"Mickey",   {"XXX", 0}, 1000},
            {"Goofy",   {"XXX", 0}, 500},
            {"Minnie",     {"XXX", 0}, 600},
            {"Snow White",     {"XXX", 0}, 1100},
            {"Gingerbread Man",   {"XXX", 0}, 1500}
            }, 5
            };

    // Initialize applicantQueue with 5 actors
    applicantQueue aQueue = {{
            {"Fern", 1100},
            {"Torcy", 200},
            {"Razel", 500},
            {"Althea", 1200},
            {"Denise", 1500}
            }, 0, 4};
    actor* catcher = applyAsDisneyChar(&aQueue, &dList);
    display(dList, catcher);
    return 0;
}
