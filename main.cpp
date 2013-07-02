#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

float w1[5], w2[5],alfa,theta,b=1.0,newb[5] ={0,1,1,1,1},y[5];
int i,isTrue[5]={0,0,0,0,0};
float x1[5],x2[5], T[5],net[5], fnet[5],dw1[5] ={0,0,0,0},dw2[5]={0,0,0,0},db[5]={0,0,0,0};
bool isFinish = false;

COORD koordinat={0,0};
void gotoxy(int x,int y){
    koordinat.X=x;
    koordinat.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),koordinat);
}
bool training(int countEpoch){
    int counterCheck,checkSum;
    isFinish = true;
    for(i=1;i<5;i++){
            //count the output y net
        net[i] = (x1[i]*w1[i-1])+(x2[i]*w2[i-1])+newb[i-1];
        //give value for output with threshold
        if(net[i]>=theta) fnet[i] = 1;
        else if(net[i]>= (-1*theta) && net[i] <= theta) fnet[i] = 0;
        else if(net[i] < (-1*theta)) fnet[i] = -1;
        //count the change
        y[i]=fnet[i];
        if(y[i]!=T[i]){
            //get new value
            dw1[i] = alfa*x1[i]*T[i];
            dw2[i] = alfa*x2[i]*T[i];
            db[i] = alfa*T[i];
            //update Weight
            w1[i] = w1[i-1] + dw1[i];
            w2[i] = w2[i-1] + dw2[i];
            newb[i] = newb[i-1] + db[i];
            isFinish = false;
        }
        else {
            w1[i]=w1[i-1];
            w2[i]=w2[i-1];
            newb[i]=newb[i-1];
        }
    }
     return isFinish;
}
void display(int countEpoch){
    printf("\t\n\nEPOCH  : %d\n",countEpoch);
    printf("\t\tLearning rate : %.2f, theta : %.2f\n",alfa, theta);
    printf("\t__________________________________________________________________________________\n");
    printf("\t|   Input    |    |     |  Y_in  |  Y=    |  Perubahan Bobot    |    Bobot Baru   |\n");
    printf("\t|------------|----|-----|--------|--------|---------------------|-----------------|\n");
    printf("\t| x1  |   x2 | b  |  T  |  = net | f(net) | dw1  |  dw2  |  db  |  w1 |  w2 |  b  |\n");
    printf("\t|____________|____|_____|________|________|______|_______|______|_____|_____|_____|\n\n");
    printf("\t|------------|----|-----|--------|--------|Inisialisasi awal    |%.2f% | %.2f | %.2f|\n", w1[0],w2[0],newb[0]);
    printf("\t| %2.0f  |  %2.0f  |%3.0f | %2.0f  | %5.2f  |  %.0f |  %.2f |  %.2f | %.2f | %.2f| %.2f | %.2f |\n",x1[1],x2[1],b,T[1],net[1],fnet[1],dw1[1],dw2[1],db[1],w1[1],w2[1],newb[1]);
    printf("\t| %2.0f  |  %2.0f  |%3.0f | %2.0f  | %5.2f  |  %.0f  | %.2f |  %.2f | %.2f | %.2f| %.2f | %.2f |\n",x1[2],x2[2],b,T[2],net[2],fnet[2],dw1[2],dw2[2],db[2],w1[2],w2[2],newb[2]);
    printf("\t| %2.0f  |  %2.0f  |%3.0f | %2.0f  | %5.2f  |  %.0f  | %.2f |  %.2f | %.2f | %.2f| %.2f | %.2f |\n",x1[3],x2[3],b,T[3],net[3],fnet[3],dw1[3],dw2[3],db[3],w1[3],w2[3],newb[3]);
    printf("\t| %2.0f  |  %2.0f  |%3.0f | %2.0f  | %5.2f  |  %.0f  | %.2f |  %.2f | %.2f | %.2f| %.2f | %.2f |\n",x1[4],x2[4],b,T[4],net[4],fnet[4],dw1[4],dw2[4],db[4],w1[4],w2[4],newb[4]);
    printf("\t|_____|______|____|_____|________|________|______|_______|______|_____|_____|_____|\n");
    w1[0]= w1[4]; w2[0] = w2[4]; newb[0] = newb[4];
}
void input(int countEpoch){
    printf("\t\t alfa : ");scanf("%f",&alfa);
    printf("\t\tTheta : ");scanf("%f",&theta);
    system("cls");
    printf("\t\n\nEPOCH  : %d\n",countEpoch);
    printf("\t\tLearning rate : %.2f, theta : %.2f\n",alfa, theta);
    printf("\t___________________________________________________________________________________\n");
    printf("\t|   Input     |    |     |  Y_in  |  Y=    |  Perubahan Bobot    |    Bobot Baru   |\n");
    printf("\t|-------------|----|-----|--------|--------|---------------------|-----------------|\n");
    printf("\t| x1  |   x2  | b  |  T  |  = net | f(net) | dw1  |  dw2  |  db  |  w1 |  w2 |  b  |\n");
    printf("\t|_____|_______|____|_____|________|________|______|_______|______|_____|_____|_____|\n\n");
    printf("\t|-------------|----|-----|--------|--------|Inisialisasi awal    |     |     |     |\n");
    printf("\t|     |       |%3.0f |     |        |        |      |       |      |     |     |     |\n",b);
    printf("\t|     |       |%3.0f |     |        |        |      |       |      |     |     |     |\n",b);
    printf("\t|     |       |%3.0f |     |        |        |      |       |      |     |     |     |\n",b);
    printf("\t|     |       |%3.0f |     |        |        |      |       |      |     |     |     |\n",b);
    printf("\t|_____|_______|____|_____|________|________|______|_______|______|_____|_____|_____|\n");
    gotoxy(75,10);
    scanf("%f",&w1[1]);
    gotoxy(82,10);
    scanf("%f",&w2[1]);
    gotoxy(87,10);
    scanf("%f",&newb[1]);
    for(i=1;i<5;i++){
        gotoxy(10,10+i);
        scanf("%f",&x1[i]);
    }
    for(i=1;i<5;i++){
        gotoxy(16,10+i);
        scanf("%f",&x2[i]);
    }
     for(i=1;i<5;i++){
        gotoxy(28,10+i);
        scanf("%f",&T[i]);
    }
}

int main()
{
    int countEpoch = 0;
    countEpoch = countEpoch+1;
    input(countEpoch);
    system("cls");
    while(!isFinish){
        training(countEpoch);
        display(countEpoch);
        getch();
        countEpoch = countEpoch+1;
    }

    if(isFinish){
        printf("Pelatihan selesai berhenti pada EPOCH ke %d\n",countEpoch-1);
//        printf("tekan s untuk save\n");
//        getchar()
    }
    return 0;
}

