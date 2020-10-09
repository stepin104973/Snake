#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
#include<string.h>
#include<global.h>
#include<snake.h>

//function declaration
void Initial(void);

int scoreUpdate(void);

//main program begins
int main()
{
    int i, j, fileScoreRecieve;

    char play;

    do
    {
        Initial();
        while(!endGame)
        {
            Plot();
            UserInput();
            KeyResponse();
            for(i = 0 ; i < 1000; i++)                           //delays the programming execution to make the snake move slower
            {
                for(j = 0; j < 20000; j++)
                {

                }
            }

        }


        //Updating the high score
        fileScoreRecieve = scoreUpdate();

        system("clear");
        

        if(score > fileScoreRecieve)
        {
           printf("Score : %d", score);
           printf("\n\nThat's a new highscore!");
        }

        else
        {
            printf("Your Score : %d", score);
            printf("\n\nCurrent highscore : %d", fileScoreRecieve);
        }

        printf("\n\nControls");
        printf("\nw - move up\ns - move down\na - move left\nd - move right \nx - Quit");
        printf("\n\n\nDo you want to play again? (Press y followed by Enter key) ");
        scanf(" %c", &play);                                    //scanf ignores whitespace



    } while(play == 'y');
    system("clear");
    
    return(0);
}


/*Initializing all the variables*/
void Initial()                                                 
{
    endGame = 0;
    SnakeX = Nc/2;
    SnakeY = Nr/2;
    userpress = 0;
    tailCount = 0;
    point1:
    fruitX = rand() % 19;
    if(fruitX == 0)
        goto point1;

    point2:
    fruitY = rand() % 19;
    if(fruitY == 0)
        goto point2;

    score = 0;
}


int scoreUpdate()
{
    int fileScore;
	FILE *scoreFileRead;
    //score file handling
    scoreFileRead = fopen("scoreFile", "r");

    if(scoreFileRead == NULL)
    {
    	FILE *initialPointer;
        initialPointer = fopen("scoreFile", "w");
        putw(score, initialPointer);
        fclose(initialPointer);
        fileScore = score;
    }

    else
    {
        fileScore = getw(scoreFileRead);
        fclose(scoreFileRead);
        if(score > fileScore)
        {
        	FILE *scoreFileWrite;
            scoreFileWrite = fopen("scoreFile", "w");
            putw(score, scoreFileWrite);
            fclose(scoreFileWrite);
        }

    }

    return (fileScore);

}
