/* header files */
#include<snake.h>
#include<global.h>
#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
#include<string.h>

/* This function outputs the snake, fruit and the bounding box to the screen
 according to their coordinates. */

int Plot()                                                    
{                                                              
    int i, j, k, flag;
    system("clear");                                           
    for(i = 0; i < Nr ; i++)
    {
        for(j = 0; j < Nc; j++)
        {
            if(i == 0 || j == 0 || i == (Nr-1) || j == (Nc-1))
            {
                printf("*");
            }

            else
            {
                if((i == SnakeX) && (j == SnakeY))
                {
                    printf("Q");
                }

                else if((i == fruitX) && (j == fruitY))
                {
                    printf("0");
                }
                else
                {
                    flag = 1;
                    for(k = 0; k < tailCount ; k++)
                    {
                        if(i == tailX[k] && j == tailY[k])
                        {
                            printf("o");
                            flag = 0;
                        }


                    }

                    if(flag == 1)
                    {
                        printf(" ");

                    }
                }


            }

        }

        printf("\n");
    }

    printf("SCORE : %d\n", score);
    return(i+j);

}

/* This function tracks the user's inputs */
int UserInput()
{
   // if(kbhit())
   // {
        switch(getchar())
        {
            case 'a': userpress = 1;
                      break;
            case 's': userpress = 2;
                      break;
            case 'd': userpress = 3;
                      break;
            case 'w': userpress = 4;
                      break;
            case 'x': endGame = 1;
                      break;
        }
  //  }

    return(1);
}

/* This function changes the coordinates of the objects, according to the user's inputs */
int KeyResponse()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int i, prev2X, prev2Y, testKey = 0;
    tailX[0] = SnakeX;
    tailY[0] = SnakeY;

    for(i = 1; i < tailCount ; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch(userpress)
    {
        case 1: SnakeY--;
                break;

        case 2: SnakeX++;
                break;

        case 3: SnakeY++;
                break;

        case 4: SnakeX--;
                break;

        default: break;
    }

    if(SnakeX < 0 || SnakeX > Nc || SnakeY < 0 || SnakeY > Nr)
    {
        endGame = 1;

    }

    for(i = 0; i < tailCount; i++)
    {
        if(SnakeX == tailX[i] && SnakeY == tailY[i])
        {
            endGame = 1;
        }
    }


    if((SnakeX == fruitX) && (SnakeY == fruitY))
    {
        point3:
        fruitX = rand() % 19;
        if(fruitX == 0)
            goto point3;

        point4:
        fruitY = rand() % 19;
        if(fruitY == 0)
            goto point4;

        score += 10;
        tailCount++;
    }

    testKey = 100;
    return(testKey);

}
