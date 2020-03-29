/*
Snake Game

TASK 1: Check tokens eaten
TASK 2: Input from the joystick and move accordingly
TASK 3: Map game matrix to the LCD
TASK 4: Check push button status (play, pause, stop)
TASK 5: Check for collisions

*****Initialize Peripherals*****
1. Push Button
2. LCD
3. LED's
4. Joystick

%%% Game Limits %%%
X: 0-20
Y: 0-15
*/

/* GIMP RGBA C-Source image dump (snake.c) */
#define GIMP_IMAGE_WIDTH (15)
#define GIMP_IMAGE_HEIGHT (15)
#define GIMP_IMAGE_BYTES_PER_PIXEL (4) /* 2:RGB16, 3:RGB, 4:RGBA */
#define GIMP_IMAGE_PIXEL_DATA ((unsigned char*) GIMP_IMAGE_pixel_data)
static const unsigned char GIMP_IMAGE_pixel_data [15 * 15 * 4 + 1] =
("MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM"
 "\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377"
 "MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM"
 "\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377"
 "MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM"
 "\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377"
 "MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM"
 "\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377"
 "MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM"
 "\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377"
 "MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM"
 "\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377"
 "MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM"
 "\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377"
 "MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM"
 "\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377"
 "MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM"
 "\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377"
 "MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM"
 "\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377"
 "MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM\377MMM"
 "\377MMM\377MMM\377MMM\377MMM\377");
 
 
 /* GIMP RGB C-Source image dump (Snack.c) */

#define SNACK_WIDTH (15)
#define SNACK_HEIGHT (15)
#define SNACK_BYTES_PER_PIXEL (2) /* 2:RGB16, 3:RGB, 4:RGBA */
#define SNACK_PIXEL_DATA ((unsigned char*) SNACK_pixel_data)
static const unsigned char SNACK_pixel_data[15 * 15 * 2 + 1] =
("\000\000\000\000\000\000\000\000@w@w@w@w@w@w@w\000\000\000\000\000\000\000\000\000\000\000\000@w@w@w@w@w@w@w@w@w@"
 "w@w\000\000\000\000\000\000@w@w@w@w@w@w@w@w@w@w@w@w@w\000\000\000\000@w@w@w@w@w@w@w@w@w@w@w@w"
 "@w\000\000@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@"
 "w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w"
 "@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w@w\000\000"
 "@w@w@w@w@w@w@w@w@w@w@w@w@w\000\000\000\000@w@w@w@w@w@w@w@w@w@w@w@w@w\000\000\000\000\000\000@"
 "w@w@w@w@w@w@w@w@w@w@w\000\000\000\000\000\000\000\000\000\000\000\000@w@w@w@w@w@w@w\000\000\000\000\000\000\000"
 "\000");

/* GIMP RGB C-Source image dump (empty_square.c) */

#define EMPTY_BLOCK_WIDTH (15)
#define EMPTY_BLOCK_HEIGHT (15)
#define EMPTY_BLOCK_BYTES_PER_PIXEL (2) /* 2:RGB16, 3:RGB, 4:RGBA */
#define EMPTY_BLOCK_PIXEL_DATA ((unsigned char*) EMPTY_BLOCK_pixel_data)
static const unsigned char EMPTY_BLOCK_pixel_data[15 * 15 * 2 + 1] =
("\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
 "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
 "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
 "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
 "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
 "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
 "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
 "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
 "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
 "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
 "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
 "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
 "\000\000\000\000\000\000");


#include <lpc17xx.h>
#include <stdio.h>
#include <cmsis_os2.h>
#include <stdlib.h>
#include "GLCD.h"
//#include "GLCD_SPI_LPC1700.c"

// Define Coord
typedef struct {
	int x;
	int y;
} coord;

// Setup Game Variables
const char  UP = 'u';
const char  DOWN = 'd';
const char  LEFT = 'l';
const char  RIGHT = 'r';
int LIVES = 3;
char CUR_DIR = RIGHT;
const int BLOCK_SIZE = 15;

coord SNACK_COORD;
coord TAIL_COORD;
osMutexId_t snakeMutex;

// Global Flags
int SNACK_COUNT = 0;
int SET_NEW_TAIL = 0;
int DEATH_FLAG = 0;
int GAME_OVER = 0;
int PAUSED = 0;

// Use LEDs to set lives (0 - 3)
void setLED(int num) {
	if(num == 3){
		LPC_GPIO1->FIOSET |= 0x01 << 31;
		LPC_GPIO1->FIOSET |= 0x01 << 29;
		LPC_GPIO1->FIOSET |= 0x01 << 28;
	}else if (num == 2) {
		LPC_GPIO1->FIOCLR |= 0x01 << 31;
	}else if (num == 1) {
		LPC_GPIO1->FIOCLR |= 0x01 << 31;
		LPC_GPIO1->FIOCLR |= 0x01 << 29;
	}else {
		LPC_GPIO2->FIOCLR |= 0x0000007C;
		LPC_GPIO1->FIOCLR |= 0xB0000000;
	}
}

// Define Snake elements
typedef struct body_node {
	struct body_node * next;
	coord cur_pos;
} body_node_t;

typedef struct {
		body_node_t * head;
		body_node_t * tail;
		int length;
		char cur_direction;
} snake_t;

// Initialize game snake
coord start = {8, 12};
snake_t initialize_game_snake = {NULL, NULL, 1, RIGHT};
snake_t * game_snake = &initialize_game_snake;


// Linked List Setup
body_node_t * createBodyNode(coord pos, body_node_t * next) {
	body_node_t * new_node = (body_node_t *)malloc(sizeof(body_node_t));
	if (new_node == NULL) {
		printf("Error creating a new node.\n");
	}
	new_node->cur_pos = pos;
	new_node->next = next;
	
	return new_node;
}

void enqueue(body_node_t * newNode) {
	game_snake->head->next  = newNode;
	game_snake->head = newNode;
	game_snake->length++;
}

body_node_t * dequeue() {
	body_node_t * ret_tail = game_snake->tail;
	game_snake->tail = game_snake->tail->next;
	game_snake->length--;
	return ret_tail;
}

void deleteSnake() {
	body_node_t * cursor, *temp;
	body_node_t *tail = game_snake->tail;
	if (tail != NULL) {
		cursor = tail->next;
		tail->next = NULL;
		
		while(cursor != NULL) {
			temp = cursor->next;
			free(cursor);
			cursor = temp;
		}
	}
	game_snake->head = NULL;
	game_snake->tail = NULL;
}

// Snake Methods
void resetSnake() {
	osMutexAcquire(snakeMutex, osWaitForever);
	deleteSnake();
	body_node_t * new_snake_head = createBodyNode(start, NULL);
	game_snake->head = new_snake_head;
	game_snake->tail = new_snake_head;
	osDelay(osKernelGetTickFreq()* 2);
	DEATH_FLAG = 0;
	LIVES -= 1;
	setLED(LIVES);
	GLCD_Clear(Black);
	SNACK_COUNT = 0;
	osMutexRelease(snakeMutex);
}

int coordInSnake(coord test_coord) {
	body_node_t * cur_node  = game_snake->tail;
	int found = 0;
	while(cur_node && !found) {
		if (cur_node->cur_pos.x == test_coord.x && cur_node->cur_pos.y == test_coord.y)
			found = 1;
		cur_node = cur_node->next;
	}
	return found;
}


// Peripheral Methods
void pushButtonPause() {
		if ((LPC_GPIO2->FIOPIN & (0x01 << 10)) == 0) {
			while ((LPC_GPIO2->FIOPIN & (0x01 << 10)) == 0){}
			PAUSED = !PAUSED;
		}			
}

void runPushButton(void *args) {	
	LPC_GPIO2->FIODIR |= 0x0000007C;
	while(1) {
		osThreadYield();
		pushButtonPause();
	}
}

void dirSwitch(char newDir){
	if (CUR_DIR == DOWN || CUR_DIR == UP) {
		if (newDir == LEFT || newDir == RIGHT) 
			CUR_DIR = newDir;	
	} else if (CUR_DIR == RIGHT || CUR_DIR == LEFT) {
		if (newDir == DOWN || newDir == UP) 
			CUR_DIR = newDir;
	}
}

coord getNextCoord(int cur_x, int cur_y) {
	coord return_coord = {cur_x, cur_y};
	switch(CUR_DIR) {
		case LEFT:
				return_coord.x += 1;
				if ((return_coord.x) > 20 || coordInSnake(return_coord))
					DEATH_FLAG = 1;
				break;
		case RIGHT:
				return_coord.x -= 1;
				if ((return_coord.x) < 0 || coordInSnake(return_coord))
					DEATH_FLAG = 1;
				break;
		case UP:
				return_coord.y += 1;
				if ((return_coord.y) > 15 || coordInSnake(return_coord))
					DEATH_FLAG = 1;
				break;
		case DOWN:
				return_coord.y -= 1;
				if ((return_coord.y) < 0 || coordInSnake(return_coord))
					DEATH_FLAG = 1;
				break;
	}
	return return_coord;
}

void mapSnake() {
	if (!GAME_OVER) {
		if(DEATH_FLAG) {
			resetSnake();
		} else {
			osMutexAcquire(snakeMutex, osWaitForever);
			body_node_t * cur_node = game_snake->tail;
			while(cur_node) {
				GLCD_Bitmap(cur_node->cur_pos.x*15, cur_node->cur_pos.y*15, 15, 15, GIMP_IMAGE_PIXEL_DATA);
				cur_node = cur_node->next;
			}
			if (!(TAIL_COORD.x == game_snake->head->cur_pos.x && TAIL_COORD.y == game_snake->head->cur_pos.y))
				GLCD_Bitmap(TAIL_COORD.x*15, TAIL_COORD.y*15, 15, 15, EMPTY_BLOCK_PIXEL_DATA);
			osMutexRelease(snakeMutex);
		}
	} else {
		GLCD_Clear(Black);
	}
	
}



void updateLocation(){
	// Update Position of snake head and children
	osMutexAcquire(snakeMutex, osWaitForever);
	body_node_t * new_node = createBodyNode(getNextCoord(game_snake->head->cur_pos.x, game_snake->head->cur_pos.y), NULL);
	
	// MAP THE SNEK
	if (new_node->cur_pos.x == SNACK_COORD.x && new_node->cur_pos.y == SNACK_COORD.y) {
		enqueue(new_node);
		SNACK_COUNT--;
	} else {
		enqueue(new_node);
		body_node_t * prev_tail = dequeue();
		TAIL_COORD.x = prev_tail->cur_pos.x;
		TAIL_COORD.y = prev_tail->cur_pos.y;
		free(prev_tail);
	}
		
	osDelay(osKernelGetTickFreq()/10);
	osMutexRelease(snakeMutex);
	mapSnake();
}



coord getRandCoord() {
	coord rand_coord = {(rand() % 20) + 1,  (rand() % 15) + 1};
	while (coordInSnake(rand_coord)) {
		rand_coord.x = (rand() % 20) + 1;
		rand_coord.y = (rand() % 15) + 1;
	}
	return rand_coord;
}


void placeNewSnack(void * args) {
	while(!GAME_OVER) {
		while(PAUSED){}
		if (SNACK_COUNT == 0) {
			SNACK_COORD = getRandCoord();
			GLCD_Bitmap(SNACK_COORD.x*15, SNACK_COORD.y*15, 15, 15, SNACK_PIXEL_DATA);
			SNACK_COUNT++;
		}
	}
}



void moveSnake(void *args){
	while(!GAME_OVER){
		while(PAUSED){}
		updateLocation();
		osThreadYield();
	}
}



void getJoyData(){
	// Update the current direction global var
	if ((LPC_GPIO1->FIOPIN & (0x01 << 25)) == 0) {
		dirSwitch(UP);
		while((LPC_GPIO1->FIOPIN & (0x01 << 25)) == 0);

	} else if ((LPC_GPIO1->FIOPIN & (0x01 << 23)) == 0) {
		dirSwitch(DOWN);
		while((LPC_GPIO1->FIOPIN & (0x01 << 23)) == 0);

	} else if ((LPC_GPIO1->FIOPIN & (0x01 << 26)) == 0) {
		dirSwitch(RIGHT);
		while((LPC_GPIO1->FIOPIN & (0x01 << 26)) == 0);

	} else if ((LPC_GPIO1->FIOPIN & (0x01 << 24)) == 0) {
		dirSwitch(LEFT);
		while((LPC_GPIO1->FIOPIN & (0x01 << 24)) == 0);
	}
}



void readJoystick(void * args){
	while(!GAME_OVER){
		osThreadYield();
		while(PAUSED){}
		getJoyData();
	}
}


void checkGameOver(void * args) {
	while(!GAME_OVER) {
		if (LIVES == 0) {
			GAME_OVER = 1;
			osMutexAcquire(snakeMutex, osWaitForever);
			GLCD_Clear(Black);
			GLCD_SetBackColor(Black);
			GLCD_SetTextColor(Red);
			unsigned char gameOverStr[] = "GAME OVER";
			char scoreBuffer[50];
			int score = sprintf(scoreBuffer, "Score: %i", game_snake->length);
			
			GLCD_DisplayString(3, 5, 1, gameOverStr);
			GLCD_DisplayString(6, 5, 1, (unsigned char * )scoreBuffer);
			osMutexRelease(snakeMutex);
		}
		osThreadYield();
	}
}

int main(void) {
	// Initialize LEDs
	LPC_GPIO2->FIOCLR |= 0x0000007C;
	uint32_t reset = 0x01 << 23;
	reset |= 0x01 << 24;
	reset |= 0x01 << 25;
	reset |= 0x01 << 26;
	LPC_GPIO1->FIOCLR |= (reset);	
	
	// Initialize LCD
	GLCD_Init();
	 
	//Initialize Kernel
	osKernelInitialize();
	snakeMutex = osMutexNew(NULL);
	body_node_t * head = createBodyNode(start, NULL);
	game_snake->head = head;
	game_snake->tail = head;
	
	// Initialize Random
	srand(osKernelGetSysTimerCount());
	LPC_GPIO2->FIODIR |= 0x0000007C;
	LPC_GPIO1->FIODIR |= 0xB0000000;
	
	// Set Lives and clera screen
	setLED(3);
	GLCD_Clear(Black);
	
	// Start Threads
	osThreadNew(readJoystick, NULL, NULL);
	osThreadNew(moveSnake, NULL, NULL);
	osThreadNew(runPushButton, NULL, NULL);
	osThreadNew(placeNewSnack, NULL, NULL);
	osThreadNew(checkGameOver, NULL, NULL);
	osKernelStart();
	for(;;){}
}



