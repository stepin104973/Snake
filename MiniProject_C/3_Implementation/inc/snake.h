/** 
* @file snake.h
* Snake game's functions
*
*/
#ifndef __SNAKE_H__
#define __SNAKE_H__

/**
* Print all the objects to the screen according to their positions
* @return Sum of final values of "i" and "j"
*/
int Plot(void);

/**
*Tracks the user's keyboard inputs
* @return Result of successful function execution
*/
int UserInput(void);

/**
*Changes the object coordinates according to the inputs recieved from the user
* @return Result of successful function execution
*/
int KeyResponse(void);

#endif  /* #define __SNAKE_H__ */
 

