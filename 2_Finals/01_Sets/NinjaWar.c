#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int ninjaID;        // Identifier
    char ninjaName[24];
    char village[24];
    int powerLevel;
} ninjaType;

typedef struct node {
    ninjaType ninja;
    struct node* next;
} ninjaNode, *Alliance;

// HELPER FUNCTIONS | Below Main Function 
void initAlliance(Alliance* S);
void displayNinjas(Alliance S); // Bracket Number pertains to ninjaID | Utilize for Sorting Purposes

// Your Task
void markNinjaToWar(Alliance *S, ninjaType a){
    // Implementation Here! 
    // unique check, insert in sorted order by ninjaID

    ninjaNode **trav;

    for(trav = S; *trav!=NULL && (*trav)->ninja.ninjaID < a.ninjaID; trav = &(*trav)->next){}
    if(*trav==NULL || (*trav)->ninja.ninjaID > a.ninjaID) {
        ninjaNode*newNinja = malloc(sizeof(ninjaNode));
        newNinja->ninja = a;
        newNinja->next = *trav;
        *trav = newNinja;
    }else{
        printf("Failed.\n");
    }

}

Alliance assembleNinjas(Alliance A, Alliance B){
    // Implementation Here! 

    Alliance S, *trav;

    initAlliance(&S);

    for(trav = &A; *trav!=NULL; trav = &(*trav)->next){
        markNinjaToWar(&S, (*trav)->ninja);
    }

    for(trav = &B; *trav!=NULL; trav = &(*trav)->next){
        markNinjaToWar(&S, (*trav)->ninja);
    }

    return S;
}

Alliance neededNinjas(Alliance A, Alliance B){
    // Implementation Here! 

    Alliance S, *travA, *travB;
    initAlliance(&S);

    for(travA = &A; *travA!=NULL; travA = &(*travA)->next){
        for(travB = &B; *travB!=NULL && (*travB)->ninja.ninjaID!=(*travA)->ninja.ninjaID; travB = &(*travB)->next){
            if(*travB!=NULL){
                markNinjaToWar(&S, (*travA)->ninja);
            }
        }
    }
    return S;
}

Alliance relocatingNinjas(Alliance A, Alliance B){
    // Implementation Here!

    Alliance S, *travA, *travB;
    initAlliance(&S);

    for(travA = &A; *travA!=NULL; travA = &(*travA)->next){
        for(travB = &B; *travB!=NULL && (*travB)->ninja.ninjaID!=(*travA)->ninja.ninjaID; travB = &(*travB)->next){
            if(*travB==NULL){
                markNinjaToWar(&S, (*travA)->ninja);
            }
        }
    }
    return S;
}

// Main Function & Helper Funtions | DO NOT TOUCH
int main(){

    Alliance HiddenLeaf; initAlliance(&HiddenLeaf);
    Alliance HiddenMist; initAlliance(&HiddenMist);
    Alliance HiddenSand; initAlliance(&HiddenSand);
    Alliance HiddenStone; initAlliance(&HiddenStone);
    Alliance HiddenCloud; initAlliance(&HiddenCloud);
    Alliance U; initAlliance(&U);
    Alliance I; initAlliance(&I);
    Alliance D; initAlliance(&D);
    Alliance V; initAlliance(&V);

    ninjaType ninjas[25] = { {1, "Sasuke", "Hidden Leaf",  900}, {2, "Tsunade","Hidden Leaf",  213},
                             {3, "Sai", "Hidden Leaf", 306}, {4, "Kakashi","Hidden Leaf", 732},
                             {5, "Ino", "Hidden Leaf",  887}, {6, "Mei","Hidden Mist", 814},
                             {7, "Haku","Hidden Mist",  204}, {8, "Mangetsu", "Hidden Mist",  100},
                             {9, "Kisame","Hidden Mist", 643}, {10,"Yagura","Hidden Mist",  632},
                             {11,"Sasori", "Hidden Sand",  999}, {12,"Gaara", "Hidden Sand",  215},
                             {13,"Pakura", "Hidden Sand", 525}, {14,"Maki", "Hidden Sand",  568},
                             {15,"Chiyo", "Hidden Sand", 834}, {16,"Mu", "Hidden Stone",  840},
                             {17,"Roshi", "Hidden Stone",  686}, {18,"Gari","Hidden Stone", 683},
                             {19,"Onoki", "Hidden Stone",  176}, {20,"Deidara","Hidden Stone",  119},
                             {21,"Darui", "Hidden Cloud", 591}, {22,"Killer B","Hidden Cloud",  702},
                             {23,"Yugito", "Hidden Cloud",  442}, {24,"Ayo","Hidden Cloud",  408},
                             {25,"Samui", "Hidden Cloud", 315} };

    int c = 3; // Change this value to test different cases (1-5)

    switch(c){
        case 1:
            printf("Gaara gathering Hidden Leaf Shinobis...\n");
            markNinjaToWar(&HiddenLeaf,ninjas[2]);
            markNinjaToWar(&HiddenLeaf,ninjas[0]);
            markNinjaToWar(&HiddenLeaf,ninjas[3]);
            markNinjaToWar(&HiddenLeaf,ninjas[1]);
            markNinjaToWar(&HiddenLeaf,ninjas[4]);
            displayNinjas(HiddenLeaf);
            printf("Gaara gathering Hidden Cloud Shinobis...\n");
            markNinjaToWar(&HiddenCloud,ninjas[24]);
            markNinjaToWar(&HiddenCloud,ninjas[21]);
            markNinjaToWar(&HiddenCloud,ninjas[23]);
            markNinjaToWar(&HiddenCloud,ninjas[22]);
            markNinjaToWar(&HiddenCloud,ninjas[20]);
            displayNinjas(HiddenCloud);
            printf("Gaara Assembling for Regional Deployment...\n");
            displayNinjas(assembleNinjas(HiddenLeaf,HiddenCloud));
            printf("Gaara fled the Scene as Task is Completed...\n");
            break;
        case 2:
            printf("Gaara gathering Hidden Mist Shinobis...\n");
            markNinjaToWar(&HiddenMist,ninjas[5]);
            markNinjaToWar(&HiddenMist,ninjas[9]);
            markNinjaToWar(&HiddenMist,ninjas[8]);
            markNinjaToWar(&HiddenMist,ninjas[6]);
            markNinjaToWar(&HiddenMist,ninjas[8]); // Duplicate
            markNinjaToWar(&HiddenMist,ninjas[7]);
            displayNinjas(HiddenMist);
            printf("Gaara gathering Hidden Stone Shinobis...\n");
            markNinjaToWar(&HiddenStone,ninjas[19]);
            markNinjaToWar(&HiddenStone,ninjas[18]);
            markNinjaToWar(&HiddenStone,ninjas[19]); // Duplicate
            markNinjaToWar(&HiddenStone,ninjas[17]);
            markNinjaToWar(&HiddenStone,ninjas[16]);
            markNinjaToWar(&HiddenStone,ninjas[15]);
            displayNinjas(HiddenStone);
            printf("Gaara Assembling for Regional Deployment...\n");
            displayNinjas(assembleNinjas(HiddenMist,HiddenStone));
            printf("Gaara fled the Scene as Task is Completed...\n");
            break;
        case 3: 
            printf("Gaara Gathering Shinobis for Sand Area...\n");
            markNinjaToWar(&HiddenStone,ninjas[19]);
            markNinjaToWar(&HiddenStone,ninjas[18]);
            markNinjaToWar(&HiddenStone,ninjas[16]);
            markNinjaToWar(&HiddenCloud,ninjas[23]);
            markNinjaToWar(&HiddenCloud,ninjas[22]);
            markNinjaToWar(&HiddenCloud,ninjas[20]);
            U = assembleNinjas(HiddenStone, HiddenCloud);
            displayNinjas(U);
            printf("Gaara Gathering Shinobis for Grass Area...\n");
            markNinjaToWar(&HiddenCloud,ninjas[23]);
            markNinjaToWar(&HiddenCloud,ninjas[22]);
            markNinjaToWar(&HiddenCloud,ninjas[20]);
            markNinjaToWar(&HiddenSand,ninjas[10]);
            markNinjaToWar(&HiddenSand,ninjas[14]);
            markNinjaToWar(&HiddenSand,ninjas[11]);
            I = assembleNinjas(HiddenCloud, HiddenSand);
            displayNinjas(I);
            printf("Gaara made a Mistake in Assignment! Find Hidden Cloud Shinobis!\n");
            displayNinjas(neededNinjas(U,I));
            printf("Gaara wants to find Shinobi assigned in Sand Area not in Grass Area\n");
            displayNinjas(relocatingNinjas(U,I));
            break;
        case 4: 
            printf("Gaara Gathering Shinobis for Cannon Valley...\n");
            markNinjaToWar(&HiddenLeaf,ninjas[0]);
            markNinjaToWar(&HiddenLeaf,ninjas[3]);
            markNinjaToWar(&HiddenLeaf,ninjas[1]);
            markNinjaToWar(&HiddenMist,ninjas[5]);
            markNinjaToWar(&HiddenMist,ninjas[9]);
            markNinjaToWar(&HiddenMist,ninjas[8]);
            markNinjaToWar(&HiddenMist,ninjas[6]);
            markNinjaToWar(&HiddenMist,ninjas[8]); // Duplicate
            markNinjaToWar(&HiddenMist,ninjas[7]);
            U = assembleNinjas(HiddenMist, HiddenLeaf);
            displayNinjas(U);
            printf("Gaara Gathering Shinobis for Forest of Life...\n");
            markNinjaToWar(&HiddenMist,ninjas[5]);
            markNinjaToWar(&HiddenMist,ninjas[9]);
            markNinjaToWar(&HiddenMist,ninjas[9]); // Duplicate
            markNinjaToWar(&HiddenMist,ninjas[8]);
            markNinjaToWar(&HiddenMist,ninjas[6]);
            markNinjaToWar(&HiddenMist,ninjas[7]);
            markNinjaToWar(&HiddenCloud,ninjas[23]);
            markNinjaToWar(&HiddenCloud,ninjas[22]);
            markNinjaToWar(&HiddenCloud,ninjas[20]);
            I = assembleNinjas(HiddenMist, HiddenCloud);
            displayNinjas(I);
            printf("Oh No! We're Fighting Madara! Gaara assembles people from the Hidden Mist!\n");
            displayNinjas(neededNinjas(U,I));
            break;
        case 5:
            printf("Gaara Gathering Shinobis for Hidden Rain...\n");
            markNinjaToWar(&HiddenSand,ninjas[10]);
            markNinjaToWar(&HiddenSand,ninjas[11]);
            markNinjaToWar(&HiddenSand,ninjas[13]);
            markNinjaToWar(&HiddenSand,ninjas[12]);
            markNinjaToWar(&HiddenMist,ninjas[5]);
            markNinjaToWar(&HiddenMist,ninjas[9]);
            U = assembleNinjas(HiddenSand, HiddenMist);
            displayNinjas(U);
            printf("Gaara Gathering Shinobis for Naka Shrine...\n");
            markNinjaToWar(&HiddenSand,ninjas[10]);
            markNinjaToWar(&HiddenSand,ninjas[11]);
            markNinjaToWar(&HiddenSand,ninjas[13]);
            markNinjaToWar(&HiddenSand,ninjas[12]);
            markNinjaToWar(&HiddenStone,ninjas[18]);
            markNinjaToWar(&HiddenStone,ninjas[16]);
            I = assembleNinjas(HiddenSand, HiddenStone);
            displayNinjas(I);
            printf("Need Wind Jutsu Users against A! Gaara Assembles Hidden Sand Shinobis...\n");
            displayNinjas(neededNinjas(U,I));
            printf("The Remaining Ninjas from both Areas Assemble at Konoha Hospital for Retrieval...\n");
            displayNinjas(assembleNinjas(relocatingNinjas(U,I),relocatingNinjas(I,U)));
            break;
        default:
        break;
    }
    return 0;
}

void initAlliance(Alliance* S){
    *S = NULL;
}

void displayNinjas(Alliance S){
    printf("{\n");
    while (S != NULL){            // Bracket Number pertains to NINJAID | Utilize for Sorting Purposes
        printf("Name: %-10s\tVillage: %-14s\tPower Level: %d [%d]\n",S->ninja.ninjaName,S->ninja.village, S->ninja.powerLevel,S->ninja.ninjaID);
        S = S->next;
    }
    printf("}\n");
}