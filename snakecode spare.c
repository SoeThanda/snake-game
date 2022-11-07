
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<conio.h>
#include<time.h>


#define N 20
#define M 40

int i,j,Field[N][M],x,y,Head,Tail,Gy,Game,frog,a,b,var,dir,score,HighScore,speed;
FILE *f;


void print(){
for(i=0;i<=M+1;i++)
    {
        if(i==0){
            printf("%c",201);
        }
        else if(i==M+1){
            printf("%c",187);
        }
        else{
            printf("%c",205);
        }
    }
   printf("Current score :%d,HighScore:%d",score,HighScore);
    for(i=0;i<N;i++){
        printf("\n%c",186);
        for(j=0;j<M;j++)
        {   if(Field[i][j]==0)printf(" ");
            if(j==M-1)printf("%c",186);
            if(Field[i][j]>0&&Field[i][j]!=Head)printf("%c",176);
            if(Field[i][j]==Head)printf("%c",178);
            if(Field[i][j]==-1)printf("%c",15);   }
    }
    printf("\n");
    for(i=0;i<=M+1;i++)
    {
        if(i==0){
            printf("%c",200);
        }
        else if(i==M+1){
            printf("%c",188);
        }
        else{
            printf("%c",205);
        }
}
}
void snakeInitialization(){
    f=fopen("highscore.txt","r");
    fscanf(f,"%d",&HighScore);
    fclose(f);
for(i=0;i<N;i++){
    for(j=0;j<M;j++){
        Field[i][j]=0;
    }
}
x=N/2;y=M/2;Head=5;Tail=1;Gy=y;Game=0;frog=0;dir='d';score=0;speed=99;
for(i=0;i<Head;i++){
    Gy++;
    Field[x][Gy-Head]=i+1;
}
}
void ResetScreenPosition(){
HANDLE hOut;
COORD Position;
hOut=GetStdHandle(STD_OUTPUT_HANDLE);
Position.X=0;
Position.Y=0;
SetConsoleCursorPosition(hOut,Position);
}
Random(){
srand(time(0));
a=1+rand()%18;
b=1+rand()%38;
if(frog==0&&Field[a][b]==0){
    Field[a][b]=-1;
    frog=1;
    if(speed>10&&score!=0)
    {
        speed=speed-15;
    }
}

}
int getch_noblock(){
if(_kbhit())
    return _getch();
else
    return -1;
}
void movement(){
var=getch_noblock();
var=tolower(var);
if(((var=='d'||var=='a')||(var=='w'||var=='s'))&&(abs(dir-var)>5))
    dir=var;
if(dir=='d'){
    y++;
    if(Field[x][y]!=0&&Field[x][y]!=-1)Gameover();
    if(y==M-1)y=0;
    if(Field[x][y]==-1){
        frog=0;
        score+=5;
        Tail-=2;
    }
    Head++;
    Field[x][y]=Head;
}
if(dir=='a'){
    y--;
    if(Field[x][y]!=0&&Field[x][y]!=-1)Gameover();
    if(y==0)y=M-1;
     if(Field[x][y]==-1){
        frog=0;
        score+=5;
        Tail-=2;
    }
    Head++;
    Field[x][y]=Head;
}
if(dir=='w'){
    x--;
    if(Field[x][y]!=0&&Field[x][y]!=-1)Gameover();
    if(x==0)x=N-1;
     if(Field[x][y]==-1){
        frog=0;
        score+=5;
        Tail-=2;
    }
    Head++;
    Field[x][y]=Head;
}
if(dir=='s'){
    x++;
    if(Field[x][y]!=0&&Field[x][y]!=-1)Gameover();
    if(x==N-1)x=0;
     if(Field[x][y]==-1){
        frog=0;
        score+=5;
        Tail-=2;
    }
    Head++;
    Field[x][y]=Head;
}
}

void TailRemove(){
for(i=0;i<N;i++){
    for(j=0;j<M;j++){
        if(Field[i][j]==Tail)
        {
            Field[i][j]=0;
        }
    }
}
Tail++;

}
void Gameover(){
printf("\a");
Sleep(1500);
system("Cls");
if(score>HighScore){
    printf("New Highscore %d",score);
    system("pause");
    f=fopen("highscore.txt","w");
    fprintf(f,"%d",score);
    fclose(f);
    system("Cls");
}

printf("                            \n\n  GameOver      ");
printf("                             \n\n  score:%d\n\n",score);
printf("                              Enter for play again and esc for exit");
while(1){
var=getch_noblock();
if(var==13){
    system("Cls");
    Game=0;
    snakeInitialization();
    break;
}
else if(var==27){
    Game=1;
    break;

}}
}


void main(){
snakeInitialization();
while(Game==0){
    print();
    ResetScreenPosition();
    Random();
    movement();
    TailRemove();
    Sleep(speed);
}

}
