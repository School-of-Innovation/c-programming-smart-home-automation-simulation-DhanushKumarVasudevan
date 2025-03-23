/*
 * 🚨 WARNING: CHALLENGE MODE ACTIVATED 🚨
 * 
 * 1️⃣ Sit back, take a deep breath, and **THINK**.
 * 2️⃣ For the next **10 minutes**, avoid using **Gen AI, ChatGPT, or any shortcuts**.
 * 3️⃣ Trust your **brain**—you’re smarter than you think!
 * 4️⃣ Consider yourself a **LOSER** if you cheat. Seriously, promise yourself you won't. 😤
 * 5️⃣ If you solve it on your own, **you WIN** and level up as a true programmer and come and meet me ! 
 * 
 * 
 * 💡 Remember: The best coders aren’t the ones who copy-paste. They are the ones who **struggle, think, fail, and then succeed.** 
 *    
 * Now, write your code! You got this! 💪🔥
 */

#include <stdio.h>
#include <stdlib.h>     //I used rand function to assign values for the temperatures, Beacause nothing is mentioned in the instruction about, how the values are assigned for temp
#define MAX_ROOMS 5  //  max number of rooms

// Function prototypes
void initializeSystem();
void displayMenu();
void controlLights();
void readTemperature();
void detectMotion();
void securitySystem();
void analyzeHouseStatus();

int main() {

    int allon=1;//for checking all lights are ON
    int cycle[1]={0};// For counting iterations
    int rooms;
    printf("Enter the number of rooms in the house: ");
    scanf("%d",&rooms);
    if(rooms<=0 || rooms>MAX_ROOMS){
        printf("Enter a valid number of rooms\n");
        return 1;
    }
    int light[rooms],door[rooms],motion[rooms],temp[rooms];
    initializeSystem(light,door,motion,temp,rooms);
    
    int choice = 0;
    do
    {
        displayMenu();
        printf("Enter your choice :");
        scanf("%d",&choice);
        if(choice<=0 || choice >6){
            printf("Enter valid choice \n");
            return 1;
        }
        switch (choice){
            case 1: 
            controlLights(rooms,light,cycle,allon);
            break;
            case 2: 
            readTemperature(rooms,temp);
            break;
            case 3: 
            detectMotion(rooms,motion);
            break;
            case 4: 
            securitySystem(rooms,door,motion,cycle);
            break;
            case 5: 
            analyzeHouseStatus(rooms,light,temp,motion,door);
            break;
            case 6: 
            printf("Exiting...");
            break;
            printf("\nEnter a valid choice\n");
            break;
        }

       ++cycle[0];
    } while (choice != 6);


    return 0;
}

 
void initializeSystem(int light[], int door[], int motion[], int temp[], int rooms) {
    printf("System initialized...\n");
    int L=20,M=35; // for generating random values for temperature
    for(int i=0; i<rooms; i++){
        light[i] = 0;
        door[i] = 0;
        motion[i] = 0;
        temp[i]= rand()%(M-L +1)+L;

    }
}

void displayMenu() {
    printf("\n ***** SMART HOME APPLICATION MENU ***** \n\n1.Toggle Light\n2.Read Temperature\n3.Check Motion Sensor\n4.Lock/Unlock Security System\n5.House Status Summary\n6.Exit\n");
}
void controlLights(int rooms, int light[],int cycle[], int allon) {
     
    // Additional Challenge
    for(int i=0;i<rooms;i++){
        allon = allon && light[i];
    }

    if(allon == 1 && cycle[0]>=5){
        printf("\n\nAll lights are ON for long time, consider turning the OFF\n\n");
        cycle[0]=0;
    }

    int room_no;
    printf("Enter room number to toggle light(%d-%d);",1,rooms);
    scanf("%d", &room_no);
    if(room_no<=0 || room_no>rooms){
        printf("Enter valid room number");
        return;
    }
    if(light[room_no -1] ==0){
        light[room_no-1] =1;
    }else{
        light[room_no-1]=0;
    }


    if(light[room_no-1]==1){
        printf("Light in Room %d is ON\n\n",room_no);
    }else{
        printf("Light in Room %d is OFF\n\n", room_no);
    }


}
void readTemperature(int rooms, int temp[]) {
    printf("Temperture Status :\n\n");
    for(int i=0; i<rooms;i++){
        printf("Temperature in Room %d is %d°C\n", i+1,temp[i]);
        // Additional Challenge
        if(temp[i]>30){
            printf("(Warning temperature in room %d is above 30°C)\n\n",i+1);
        }
    }
}
void detectMotion(int rooms ,int motion[]) { 
    printf("Motion Sensors Status:\n");
    for(int i=0; i<rooms; i++){
        if(motion[i]==0){
            printf("No Motion Detected in Room %d\n", i+1);
        }
        else{
            printf("Motion Detected in Room \n%de",i+1);
        }
    }

}
void securitySystem( int rooms,int door[], int motion[], int cycle[]) {
    int doorno;
    int status;
    printf("\nEnter the Room number to lock or unlock the door(1-%d):",rooms);
    scanf("%d",&doorno);
    if(door<=0 || doorno>rooms){
        printf("\nEnter valid number ");
        return;
    }
    printf("\nLock or Unlock the door(1/0) :");
    scanf ("%d",&status);
    if(status!=1 && status !=0){
        printf("\nEnter valid number");
        return;
    }
    if(status == 1){
        door[doorno-1] =1;
        printf ("\n The door of  room %d is  unlocked.\n", doorno);
    }
    else{
        printf ("\n The door of room %d is locked.\n",doorno);
    }
    //Additional challenge

    if (cycle[0]>=5){
        for (int i=0;i<rooms;i++){
            int nomotion =1 ;
        nomotion = nomotion && (motion[i]^1);
        if(nomotion ==1){
            if(door[i]==1){
                printf( "\n Since, no motion is detected in room %d for 5 inputs the door is now locked automatically.\n",i+1);
                door[i] = 0;
                cycle[0] = 0;
            }

        }
        }
    }

}
void analyzeHouseStatus(int rooms, int light[], int temp[], int motion[], int door[]) {
     printf("\n House Status:\n");
     for (int i=0;i<rooms;i++){
        printf("Room %d :", i+1);
        if(light[i]==0){
            printf("Light OFF,");
        }
        else if(light[i]==1){
            printf("Light ON");
        }
        printf("Temp %d°C:", temp[i]);
        if(motion[i]==0){
            printf("No motion,");
        }
        else if(motion[i]==1){
            printf("Motion Detected,");
        }
        if(door[i]==0){
            printf("Locked\n");
        }
        else if(door[i]==1){
            printf("Unlocked\n");
        }
     }
}
