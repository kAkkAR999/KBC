#include<stdio.h>
#include<stdlib.h>
#include<curses.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include<ctype.h>
#define MAX 200
typedef struct questions{
    int line;
    char question[256];
    char optionA[256];
    char optionB[256];
    char optionC[256];
    char optionD[256];
    char ans[256];
}QUESTION;
void kbcHeader();
void screen1(); //function to display main screen
void generateLineNum(int line[], int len); //function to generate line numbers for accessing file
void shuffle(int line[], int len);//function to randomly shuffle line numbers
void readdata(int linenumber, char question[], char a[], char b[], char c[], char d[], char ans[]); //function to read qyestion,options and correct answer from file
int main()
{
    kbcHeader();
    screen1();
    char m;
    scanf("%c",&m);
    system("clear");
    int linenum[120] = {0};
    QUESTION qarray[16];//16 questions - 1 extra for FLIP THE QUESTION LIFELINE
    generateLineNum(linenum, sizeof(linenum)/sizeof(linenum[0]));
    shuffle(linenum, sizeof(linenum)/sizeof(linenum[0]));
    //loop to store line number of questions 
    for(int i = 0; i<16; i++)
    {
        qarray[i].line = linenum[i];
    }
    //loop to read data into the array of questions
    for(int i = 0; i<16; i++)
    {
        readdata(qarray[i].line, qarray[i].question, qarray[i].optionA, qarray[i].optionB, qarray[i].optionC, qarray[i].optionD, qarray[i].ans);
    }
    char answer;    
    for(int i = 0; i<16; i++)
    {
        kbcHeader();
        printf("QUESTION%d: ",i+1);
        printf("%s", qarray[i].question);
        sleep(1);
        printf("%s", qarray[i].optionA);
        sleep(1);
        printf("%s", qarray[i].optionB);
        sleep(1);
        printf("%s", qarray[i].optionC);
        sleep(1);
        printf("%s", qarray[i].optionD);
        sleep(1);
        printf("ENTER YOUR CHOICE:\n");
        scanf("\n%c",&answer);
        if(toupper(answer)==qarray[i].ans[0])
        {
	correct(i);
            printf("CORRECT ANSWER! CONGRATULATIONS YOU HAVE WON RS. %d \n ", correct(i));
            sleep(2);
        }
        else
        {
	incorrect(i);
            printf("WRONG ANSWER! The correct answer is %s\n", qarray[i].ans);
	printf("You have earned %d\n", incorrect(i));
            break;
        }
        
        system("clear");       
    }
        
    return 0;
    
}
void kbcHeader()
{
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    system("setterm -bold on");
    printf("\t\t\t\t\t\t\t\t\t\t\tKAUN BANEGA CROREPATI\n");
    system("setterm -bold off");
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}
void screen1()
{
    system("setterm -bold on");
    printf("\t\t\t\t\t\t\t\t\t\t\t  RULES OF THE GAME\n");
    system("setterm -bold off");
    printf("\t1.There are total 15 questions in this game and the prize money corresponding to each question is :\n");
    system("setterm -bold on");
    printf("\t\tQ1 - Rs 1000 \n");
    system("setterm -bold off");
    printf("\t\tQ2 - Rs 2000 \n");
    printf("\t\tQ3 - Rs 3000 \n");
    printf("\t\tQ4 - Rs 5000 \n");
    system("setterm -bold on");
    printf("\t\tQ5 - Rs 10,000 \n");
    system("setterm -bold off");
    printf("\t\tQ6 - Rs 20,000 \n");
    printf("\t\tQ7 - Rs 40,000 \n");
    printf("\t\tQ8 - Rs 80,000 \n");
    printf("\t\tQ9 - Rs 1,60,000 \n");
    system("setterm -bold on");
    printf("\t\tQ10 - Rs 3,20,000 \n");
    system("setterm -bold off");
    printf("\t\tQ11 - Rs 6,40,000 \n");
    printf("\t\tQ12 - Rs 12,50,000 \n");
    printf("\t\tQ13 - Rs 25,00,000 \n");
    printf("\t\tQ14 - Rs 50,00,000 \n");
    printf("\t\tQ15 - Rs 1,00,00,000 \n");
    printf("\t2.The player has 2 lifelines in each game : 50-50 and FLIP THE QUESTION. They can be used in same question or different questions or not at all!\n");
    printf("\t\t50-50: Two incorrect options will be removed from the screen. \n");
    printf("\t\tFLIP THE QUESTION: Current question will be replaced by a new question \n");
    printf("\t3. There are three intermediate levels in the game: Q1, Q5 and Q10.\n");
    printf("\t4. For every correct answer the prize money corresponding the question will be added to your final total.\n");
    printf("\t5. If the option selected by the user is incorrect the game will exit and the final amount won by the player will be corresponding to the last intermediate level crossed by him/her.\n");
    printf("\n\n");
    system("setterm -bold on");
    printf("\t\t\t\t\t\t\t\t\t\t\t Press ANY key to conitnue!\n");
    system("setterm -bold off");
}

void generateLineNum(int line[], int len)
{
    line[0] = 0;
    for(int i = 1; i<len; i++)
    {
        line[i] = line[i-1]+6;
    }
}

void shuffle(int line[], int len)
{
    srand(time(NULL));
    for(int i = 0; i<len; i++)
    {
        int j = i + rand() % (120-i);
        int temp = line[i];
        line[i] = line[j];
        line[j] = temp;
    }
}

void readdata(int linenumber, char question[256], char a[256], char b[256], char c[256], char d[256], char ans[256])
{
    FILE *fp;
    fp = fopen("KBC QUESTION BANK.txt","r");
    if(fp == NULL)
    {
        printf("Oops! Unable to open file. Make sure the source code and file are saved in the same folder and try again!");
        return;
    }
    else
    {
        int count = 1;
        char text[256];
        while(count<=(linenumber+6))
        {
            fgets(text,256,fp);
            if(count == linenumber+1)
            strcpy(question, text);
            else if(count == linenumber+2)
            strcpy(a,text);
            else if(count == linenumber+3)
            strcpy(b,text);
            else if(count == linenumber+4)
            strcpy(c,text);
            else if(count == linenumber+5)
            strcpy(d,text);
            else if(count == linenumber+6)
            strcpy(ans,text);
            count++;
        }
        fclose(fp);
        return;
    }
}

correct(int x)
{
int score;
	int money[15]={1000,2000,3000,5000,10000,20000,40000,80000,160000,320000,640000,1250000,2500000,5000000,100000000};
	if(x<16){
	score= money[x];
		}  
return(score);
	}


incorrect(int x)
{
int score;
int money[15]={1000,2000,3000,5000,10000,20000,40000,80000,160000,320000,640000,1250000,2500000,5000000,100000000};
	if(x<5){
	score=money[0];
	           }
	if(x<10){
	score= money[4];
	}
	else if(x>10) {
	score= money[9];
		}
return(score);
}
