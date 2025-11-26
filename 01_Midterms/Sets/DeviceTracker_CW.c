#include <stdio.h>

typedef unsigned char HomeDevices;

HomeDevices mask;

void turnOn(HomeDevices* devices, int index);
void turnOff(HomeDevices* devices, int index);
int isOn(HomeDevices devices, int index);
int countOnDevices(HomeDevices devices);
void displayDevices(HomeDevices devices);
HomeDevices unionDevices(HomeDevices a, HomeDevices b);
HomeDevices intersectDevices(HomeDevices a, HomeDevices b);
HomeDevices differenceDevices(HomeDevices a, HomeDevices b);

int main(){

    HomeDevices home1 = 0;
    HomeDevices home2 = 0;

    turnOn(&home1, 0);
    turnOn(&home1, 2);
    turnOn(&home1, 6);

    turnOn(&home2, 1);
    turnOn(&home2, 2);
    turnOn(&home2, 6);
    
}

void turnOn(HomeDevices* devices, int index){
    mask = 1 << index;
    *devices = *devices | mask;
}


void turnOff(HomeDevices* devices, int index){
    mask = 1 << index;
    *devices = *devices & ~mask;
}

int isOn(HomeDevices devices, int index){
    return (devices & (1 << index)) ? 1 : 0;
}

int countOnDevices(HomeDevices devices){
    int count = 0;
    for(int i = 0; i < 8; i++){
        if(devices & (1 << i)){
            count++;
        }
    }

    return count;
}

void displayDevices(HomeDevices devices){
    for(int i = 0; i < 8; i++){
            printf("%s ", (devices & (1 << i)) ? "ON" : "OFF");
    }
    printf("\n");
}

HomeDevices unionDevices(HomeDevices a, HomeDevices b){ return a | b; }
HomeDevices intersectDevices(HomeDevices a, HomeDevices b){ return a & b; }
HomeDevices differenceDevices(HomeDevices a, HomeDevices b){ return a & (~b);}
