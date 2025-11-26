#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Hell's Kitchen - Sets
// change "c" to test the cases

typedef char String[30];

typedef struct{
    int id; 
    String name;
    int age;
    String occupation;
} Contestant;

typedef struct node{
    Contestant Cook;
    struct node *next;
} S_Node, *Season;

void newSeason(Season *S); // makes a new season of Hell's Kitchen
void displayContestants(Season S); // shows the roster of the season

void addToSeason(Season *S, Contestant Cook, int s_id); // recruits a contestant to be in a season
void eliminateFromSeason(Season* S, Contestant Cook); // eliminates a contestant from the season
bool findContestant(Season S, Contestant Cook); // finds a contestant

Season mergeSeasons(Season A, Season B); // merges two seasons
Season sameContestants(Season A, Season B); // find partcipants from who competed in 2 seasons

int main(){

    Season S_14; newSeason(&S_14);
    Season S_15; newSeason(&S_15);
    Season All_Stars; newSeason(&All_Stars);
    Season S_Both; newSeason(&S_Both);

   Contestant cooks_14[18] = {
    {1,  "Sarah Baumert",       27, "Chef Instructor"},
    {2,  "Randy Bell",          45, "Line Cook"},
    {3,  "Nick Peters",         25, "Private Chef"},
    {4,  "Monique Booker",      23, "Line Cook"},
    {5,  "Michael Dussault",    38, "Senior Center Chef"},
    {6,  "Meghan Gill",         28, "Executive Chef"},
    {7,  "T Gregoire",          31, "Line Cook"},
    {8,  "Bret Hauser",         30, "Sous Chef"},
    {9,  "Christine Hazel",     30, "Banquet Chef"},
    {10, "Mieka Houser",        25, "Sous Chef"},
    {11, "Adam Livow",          31, "Amusement Park Chef"},
    {12, "Milly Medley",        33, "Executive Chef"},
    {13, "Brendan Pelley",      34, "Executive Chef"},
    {14, "Alison Rivera",       27, "Sous Chef"},
    {15, "Chrissa Schmerler",   34, "Food Truck Chef"},
    {16, "Cameron Spagnolo",    33, "Banquet Chef"},
    {17, "Michelle Tribble",    22, "Line Cook"},
    {18, "Josh Trovato",        24, "Chef de Cuisine"}
};

Contestant cooks_15[18] = {
    {19,  "Ariel Malone",          26, "Country Club Chef"},
    {20,  "Kristin Barone",        27, "Line Cook"},
    {21,  "Ashley Nickell",        27, "Chef de Cuisine"},
    {22,  "Jared Bobkin",          28, "Line Cook / Poker Player"},
    {23,  "Manda Palomino",        30, "Sous Chef"},
    {24,  "Dannie Harrison",       30, "Line Cook"},
    {25,  "Frank Cala",            25, "Marine Chef"},
    {26,  "Jackie Fuchs",          32, "Line Cook"},
    {27,  "Chad Gelso",            25, "Sous Chef"},
    {28, "Joe Ricci",             31, "Chef"},
    {29, "Hassan Musselmani",     24, "Catering Executive Chef"},
    {30, "Eddie Jaskowiak",       27, "Sous Chef"},
    {31, "Alan Parker",           42, "Sous Chef"},
    {32, "Kevin Ridlon",          29, "Culinary Manager"},
    {33, "Melissa Davis",         25, "College Chef"},
    {34, "Vanessa Soltero",       33, "Airport Chef"},
    {35, "Sherkenna Buggs",       30, "Personal Chef"},
    {36, "Mark Paras",            27, "Line Cook"}
};

Contestant randoms[3] = {
    {37,  "Zach Bacolod",          20, "Video Editor"},
    {38,  "Denise Bocado",         20, "Writer"},
};

    int c = 5; // change value to try test cases

    switch(c){
        case 1:
        printf("Selecting contestants to be in Season 14 of Hell's Kitchen...\n");
        printf("------------------------------------------------------------------\n");
        addToSeason(&S_14, cooks_14[0], 14);
        addToSeason(&S_14, cooks_14[1], 14);
        addToSeason(&S_14, cooks_14[2], 14);
        addToSeason(&S_14, cooks_14[3], 14);
        addToSeason(&S_14, cooks_14[4], 14);
        addToSeason(&S_14, cooks_14[5], 14);
        addToSeason(&S_14, cooks_14[6], 14);
        addToSeason(&S_14, cooks_14[7], 14);
        addToSeason(&S_14, cooks_14[8], 14);
        addToSeason(&S_14, cooks_14[9], 14);
        addToSeason(&S_14, cooks_14[10], 14);
        addToSeason(&S_14, cooks_14[11], 14);
        addToSeason(&S_14, cooks_14[12], 14);
        addToSeason(&S_14, cooks_14[13], 14);
        addToSeason(&S_14, cooks_14[14], 14);
        addToSeason(&S_14, cooks_14[15], 14);
        addToSeason(&S_14, cooks_14[16], 14);
        addToSeason(&S_14, cooks_14[17], 14);
        printf("\nDisplaying contestants for Season 14 of Hell's Kitchen:\n\n");
        displayContestants(S_14);
        break;
        case 2: 
        printf("Selecting contestants to be in Season 15 of Hell's Kitchen...\n");
        printf("------------------------------------------------------------------\n");
        addToSeason(&S_15, cooks_14[0], 14);
        printf("\n!! Cook already participated in Season 14 of Hell's Kitchen !!\n\n");
        eliminateFromSeason(&S_15, cooks_14[0]);
        printf("\nReselecting contestants to be in Season 15 of Hell's Kitchen...\n");
        printf("------------------------------------------------------------------\n");
        addToSeason(&S_15, cooks_15[0], 15);
        addToSeason(&S_15, cooks_15[1], 15);
        addToSeason(&S_15, cooks_15[2], 15);
        addToSeason(&S_15, cooks_15[3], 15);
        addToSeason(&S_15, cooks_15[4], 15);
        addToSeason(&S_15, cooks_15[5], 15);
        addToSeason(&S_15, cooks_15[6], 15);
        addToSeason(&S_15, cooks_15[7], 15);
        addToSeason(&S_15, cooks_15[8], 15);
        addToSeason(&S_15, cooks_15[9], 15);
        addToSeason(&S_15, cooks_15[10], 15);
        addToSeason(&S_15, cooks_15[11], 15);
        addToSeason(&S_15, cooks_15[12], 15);
        addToSeason(&S_15, cooks_15[13], 15);
        addToSeason(&S_15, cooks_15[14], 15);
        addToSeason(&S_15, cooks_15[15], 15);
        addToSeason(&S_15, cooks_15[16], 15);
        addToSeason(&S_15, cooks_15[17], 15);
        printf("\nDisplaying contestants for Season 15 of Hell's Kitchen:\n\n");
        displayContestants(S_15);
        break;
        case 3:
        printf("Selecting contestants to be in Season 15 of Hell's Kitchen...\n");
        printf("------------------------------------------------------------------\n");
        addToSeason(&S_15, cooks_15[0], 15);
        addToSeason(&S_15, cooks_15[1], 15);
        addToSeason(&S_15, cooks_15[2], 15);
        addToSeason(&S_15, cooks_15[3], 15);
        addToSeason(&S_15, cooks_15[4], 15);
        addToSeason(&S_15, cooks_15[5], 15);
        addToSeason(&S_15, cooks_15[6], 15);
        addToSeason(&S_15, cooks_15[7], 15);
        addToSeason(&S_15, cooks_15[8], 15);
        addToSeason(&S_15, cooks_15[9], 15);
        addToSeason(&S_15, cooks_15[10], 15);
        addToSeason(&S_15, cooks_15[11], 15);
        addToSeason(&S_15, cooks_15[12], 15);
        addToSeason(&S_15, cooks_15[13], 15);
        addToSeason(&S_15, cooks_15[14], 15);
        addToSeason(&S_15, cooks_15[15], 15);
        addToSeason(&S_15, cooks_15[16], 15);
        addToSeason(&S_15, cooks_15[17], 15);
        printf("\nDisplaying contestants for Season 15 of Hell's Kitchen:\n\n");
        displayContestants(S_15);
        printf("\nDuring a service...\n");
        printf("------------------------------------------------------------------\n");
        printf("Gordon's looking for %s because he served him raw meat!!\n", cooks_15[3].name);
        printf("Contestant %s was %s \n", cooks_15[3].name, (findContestant(S_15, cooks_15[3]) == 1) ? "found on the Meat Station throwing away the best quality meat." : "not found by Sous Chef Christina.");
        printf("Gordon was so mad, he threw him out of Hell's Kitchen.\n");
        eliminateFromSeason(&S_15, cooks_15[3]);
        printf("\n");
        break;
        case 4: 
        printf("Gordon wants to have an All-Stars season of Hell's Kitchen!\n\n");
        printf("Selecting contestants from Season 14 of Hell's Kitchen...\n");
        printf("------------------------------------------------------------------\n");
        addToSeason(&S_14, cooks_14[0], 14);
        addToSeason(&S_14, cooks_14[3], 14);
        addToSeason(&S_14, cooks_14[10], 14);
        addToSeason(&S_14, cooks_14[8], 14);
        printf("\nSelecting contestants from Season 15 of Hell's Kitchen...\n");
        printf("------------------------------------------------------------------\n");
        addToSeason(&S_15, cooks_15[1], 15);
        addToSeason(&S_15, cooks_15[9], 15);
        addToSeason(&S_15, randoms[1], 15);
        addToSeason(&S_15, randoms[0], 15);
        printf("\nSelecting contestants to be in the All-Stars of Hell's Kitchen...\n");
        All_Stars = mergeSeasons(S_14, S_15);
        printf("------------------------------------------------------------------\n");
        printf("\nAll-Stars have been selected! Displaying contestants:\n\n");
        displayContestants(All_Stars);
        printf("\n");
        break;
        case 5:
        printf("Selecting contestants from Season 14 of Hell's Kitchen...\n");
        printf("------------------------------------------------------------------\n");
        addToSeason(&S_14, cooks_14[0], 14);
        addToSeason(&S_14, cooks_14[1], 14);
        addToSeason(&S_14, cooks_14[2], 14);
        addToSeason(&S_14, cooks_14[15], 14);
        addToSeason(&S_14, randoms[1], 14);
        addToSeason(&S_14, randoms[0], 14);
        printf("\nSelecting contestants from Season 15 of Hell's Kitchen...\n");
        printf("------------------------------------------------------------------\n");
        addToSeason(&S_15, cooks_15[0], 15);
        addToSeason(&S_15, cooks_15[1], 15);
        addToSeason(&S_15, cooks_15[2], 15);
        addToSeason(&S_15, cooks_15[3], 15);
        addToSeason(&S_15, randoms[1], 15);
        addToSeason(&S_15, randoms[0], 15);
        printf("\nAre there any contestants who joined Season 14 and Season 15 of Hell's Kitchen?\n");
        printf("\nFinding contestants from both seasons...\n");
        S_Both = sameContestants(S_14, S_15);
        printf("Displaying now:\n\n");
        displayContestants(S_Both);
        printf("\n");
    }

}

void newSeason(Season *S){
    *S = NULL;
}

void displayContestants(Season S){
    if(S!=NULL){
        printf("%-4s %-20s %-5s %-25s\n", "ID", "Name", "Age", "Occupation");
        printf("------------------------------------------------------------------\n");
        for(; S!=NULL; S = S->next){
        printf("%-4d %-20s %-5d %-25s\n",
               S->Cook.id,
               S->Cook.name,
               S->Cook.age,
               S->Cook.occupation);
    }
    }else{
        printf("!! The season's contestants have not been recruited yet. !!\n");
    }
    
}

void addToSeason(Season *S, Contestant Cook, int s_id){
    S_Node **trav;
    for(trav = S; *trav!=NULL && (*trav)->Cook.id != Cook.id; trav = &(*trav)->next){}
    if(*trav == NULL){ // cook is not yet in season
        S_Node *newCook = malloc(sizeof(S_Node));
        if(newCook!=NULL){
            newCook->Cook = Cook;
            newCook->next = *trav;
            *trav = newCook;
            printf("[Recruited participant %s to participate in Season %d.]\n", Cook.name, s_id);
        }else{ // cook is already in season
            printf("[Unable to recruit participant %s.]\n", Cook.name);
        }

    }else{
        printf("[Participant %s is not applicable to be in Season %d.]\n", Cook.name, s_id);
    }

}

void eliminateFromSeason(Season* S, Contestant Cook){
    S_Node *temp, **trav;
    for(trav = S; *trav!=NULL && (*trav)->Cook.id != Cook.id; trav = &(*trav)->next){}
    if(*trav!=NULL){ // cook has been found
        temp = *trav;
        *trav = temp->next;
        free(temp);
        printf("[Removed participant %s from the season.]\n", Cook.name);
    }else{
        printf("[Participant %s cannot be found and removed.]\n", Cook.name);
    }
}

bool findContestant(Season S, Contestant Cook){
    for(; S != NULL && S->Cook.id !=Cook.id; S = S->next){}
    return(S != NULL) ? 1 : 0; 
}

Season mergeSeasons(Season A, Season B){
    Season S;
    newSeason(&S);

    for (Season travA = A; travA != NULL; travA = travA->next){
        addToSeason(&S, travA->Cook, 16);
    }

    for (Season travB = B; travB != NULL; travB = travB->next){
        addToSeason(&S, travB->Cook, 16);
    }

    return S;
}

Season sameContestants(Season A, Season B){
    Season S;
    newSeason(&S);

    for (Season travA = A; travA != NULL; travA = travA->next){
        Season travB;
        for (travB = B; travB != NULL && strcmp(travA->Cook.name, travB->Cook.name) != 0; travB = travB->next){}
        
        if(travB != NULL){
            addToSeason(&S, travA->Cook, 17);
        }
    }
    
    return S;
}