#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>   // For _kbhit() and _getch()
#include <windows.h> // For Sleep()

#define ROAD_WIDTH 40
#define ROAD_HEIGHT 20
#define CAR_POS (ROAD_WIDTH / 2)

char road[ROAD_HEIGHT][ROAD_WIDTH];

void init_road() {
    for (int i = 0; i < ROAD_HEIGHT; i++) {
        for (int j = 0; j < ROAD_WIDTH; j++) {
            if (j == 0 || j == ROAD_WIDTH - 1) {
                road[i][j] = '|'; 
            } else {
                road[i][j] = ' ';
            }
        }
    }
}

void display_road(int car_position, int obstacles[] ) {
    system("cls"); 

    for (int i = 0; i < ROAD_HEIGHT; i++) {
        printf("                "); 

        for (int j = 0; j < ROAD_WIDTH; j++) {
            if (i == ROAD_HEIGHT - 1 && j == car_position) {
                printf("A"); 
            } else if (obstacles[i] == j) {
                printf("X");
            } else {
                printf("%c", road[i][j]);
            }
        }
        printf("\n");
    }

     
}

void move_obstacles(int* obstacles) {
    for (int i = ROAD_HEIGHT - 1; i > 0; i--) {
        obstacles[i] = obstacles[i - 1];
    }
    obstacles[0] = rand() % (ROAD_WIDTH - 2) + 1; 
}

int check_collision(int car_position, int* obstacles) {
    return (obstacles[ROAD_HEIGHT - 1] == car_position);
}




//void printCar() {
//    printf("		          ______		   		     ______\n");
//    printf("		         //  ||\\\\	   		            //  ||\\\\\n");             
//    printf("		   _____//___||_\\\\_____		   	   ________//___||_\\\\_\n");
//    printf("		  /  _           _    \ (    		  ) _           _   \\ |\n");									
//    printf("		  |_/ \\\\________/ \\\\___|	    	 |_/ \\\\________/ \\\\__\|\n");
//    printf("		 ___\\_/_________\\_/______	  +     ___\\_/_________\\_/______\n");
//    
//	printf("                ______			          ______\n");                
//	printf("               //  ||\\\\	                         //  ||\\\\\n");            
//    printf("      ________//___||_\\\\____	        ________//___||_\\\\____\n");					
//    printf("     )  _          _    \\  |           )  _       _      \\   |\n");					
//    printf("     |_/ \\\\________/ \\\\___|	       |_/ \\\\________/ \\\\___|\n");					
//    printf("    ___\\_/________\\_/______	  +   ___\\_/________\\_/______\n");
//	printf("\n");
//	printf("\n");
//	printf(" __        __   _                            _          \n");
//    printf(" \\ \\      / /__| | ___ ___  _ __ ___   ___  | |_ ___    \n");
//    printf("  \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ | __/ _ \\   \n");
//    printf("   \\ V  V /  __/ | (_| (_) | | | | | |  __/ | || (_) |  \n");
//    printf("    \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|  \\__\\___/   \n");
//    printf("\n");
//    printf("\n");	
//    
//    
//}

void pause_game() {
    printf("Game Paused. Press any key to continue...\n");
    _getch(); 
}
void play_mp3(const char *filename) {
    char command[256];
    sprintf(command, "open \"%s\" type mpegvideo alias myMP3", filename);
    mciSendString(command, NULL, 0, NULL);  // Open the MP3 file

    mciSendString("play myMP3 repeat", NULL, 0, NULL);  // Play in a loop (background)
}


void play_mp32(const char *filename) {
    char command[256];
    
    // Open the MP3 file
    sprintf(command, "open \"%s\" type mpegvideo alias myMP3", filename);
    mciSendString(command, NULL, 0, NULL);

    // Play the MP3 file once
    mciSendString("play myMP3", NULL, 0, NULL);
    Sleep(2700);

    // Close the MP3 file after playback
    mciSendString("close myMP3", NULL, 0, NULL);
}

//void play_mp32(const char *filename) {

 // sir monis ke sound ka function
//    char command[256];
//    int result;
//
//    // Open the MP3 file
//    sprintf(command, "open \"%s\" type mpegvideo alias myMP3", filename);
//    result = mciSendString(command, NULL, 0, NULL);
////    if (result != 0) {
////        printf("Error opening file: %d\n", result);
////        return;
////    }
//
//    // Play the MP3 file once
//    result = mciSendString("play myMP3", NULL, 0, NULL);
////    if (result != 0) {
////        printf("Error playing file: %d\n", result);
////        return;
////    }
//
//    // Wait for playback to finish
//    Sleep(3000); // Adjust duration as per the MP3 length or use MCI `status` command
//
//    // Close the MP3 file
//    result = mciSendString("close myMP3", NULL, 0, NULL);
////    if (result != 0) {
////        printf("Error closing file: %d\n", result);
////        return;
////    }
//}




int main() {
	
    int car_position = CAR_POS;
    int obstacles[ROAD_HEIGHT] = {0};
    int game_over = 0;
    int score = 0;
    int delay = 100; 

    srand(time(0)); 
    init_road();


//    printCar(); 
    
    printf("Please Enter 1 to Enter the game: ");
    int num;
    scanf("%d", &num);
    
    if (num == 1) {
    	
    	play_mp3("C:\\Users\\dell\\Desktop\\PF Project\\Car Final\\start.mp3");
    	Sleep(800);
    	


    printf("               _____ \n");
    printf("              |___ / \n");
    printf("                |_ \\ \n");
    printf("               ___) |\n");
    printf("              |____/ \n");
    	Sleep(1100);
	printf("               ____  \n");
    printf("              |___ \\ \n");
    printf("                __) | \n");
    printf("               / __/ \n");
    printf("              |_____| \n");
    	Sleep(1100);
	printf("                ___     \n");
    printf("               / / |    \n");
    printf("              /_/| |     \n");
    printf("                 | |     \n");
    printf("                _|_|_     \n");
    printf("               |_ _ _|     \n");
    	Sleep(900);
    printf("           ____ _____ _    ______ _____  \n");
    printf("         / ___|_   _|/ \\  |  _ \\_   _|  \n");
    printf("         \\___ \\ | | / _ \\ | |_) || |   \n");
    printf("          ___) || |/ ___ \\|  _ < | | \n");
    printf("         |____/ |_/_/   \\_\\_| \\_\\|_| \n");
    	Sleep(100);
		mciSendString("stop myMP3", NULL, 0, NULL);
mciSendString("close myMP3", NULL, 0, NULL);


		play_mp3("C:\\Users\\dell\\Desktop\\PF Project\\Car Final\\mario1.mp3");

		
        while (!game_over) {
            if (_kbhit()) {  
                char key = _getch();
                if (key == 'a' && car_position > 1) {
                    car_position--; 
                } else if (key == 'd' && car_position < ROAD_WIDTH - 2) {
                    car_position++;
                } else if (key == 'p') { 
                    pause_game();
                }
                

            }

            move_obstacles(obstacles);
            game_over = check_collision(car_position, obstacles);

            display_road(car_position, obstacles);
            
           printf("                Score: %d\n", score++); 

            // Gradually decrease delay to increase speed
            if (score % 10 == 0 && delay > 0) {
                delay -= 10; // Reduce delay every 10 points, with a minimum limit
            }

            Sleep(delay); 
    }
    	
//    	                 Stop the background music
mciSendString("stop myMP3", NULL, 0, NULL);
mciSendString("close myMP3", NULL, 0, NULL);

// Play the death sound
play_mp3("C:\\Users\\dell\\Desktop\\PF Project\\Car Final\\death.mp3");




        printf("\n\n                Game Over! Final Score: %d\n", score);
        Sleep(3000);
        mciSendString("stop myMP3", NULL, 0, NULL);
mciSendString("close myMP3", NULL, 0, NULL);
    }

    return 0;
}
