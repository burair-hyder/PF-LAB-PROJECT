#include <stdio.h> // for input and output
#include <stdlib.h> // for rand function and srand function
#include <time.h> // for time(0) // 1970 abhe tak jitnay seconds 
#include <string.h>  // for strcpy,strcmp,strlen
#include <conio.h>   // For _kbhit() and _getch()
#include <windows.h> // For Sleep()
#include <limits.h> // for INT_MAX AND INT_MIN  (not used)
// global
#define ROAD_WIDTH 40 // columns
#define ROAD_HEIGHT 20 // rows
#define CAR_POS (ROAD_WIDTH / 2) // middle of road

struct signin{
	char name[100];
	char password[100];
	int scores[2];
	int max;
	int react;
}obj;

char road[ROAD_HEIGHT][ROAD_WIDTH]; // 2D array of Rows = height and columns = width 
// Prototypes
void init_road(); 
void display_road(int car_position, int obstacles[] );
void move_obstacles(int *obstacles);
int check_collision(int car_position, int* obstacles);
void pause_game();
int play();
void play_mp3(const char *filename);
void printCar();
//FILE HANDLING FUNCTIONS

void sign_up();
void sign_in();
void update_score(char name[100],FILE *p1);
void leaderbord();


void display_road(int car_position, int obstacles[] ) {
	system("cls"); //clears screen
int i,j;
    for (i = 0; i < ROAD_HEIGHT; i++) {
        printf("                ");  //centering the game

        for (j = 0; j < ROAD_WIDTH; j++) {
            if (i == ROAD_HEIGHT - 1 && j == car_position) {
                printf("A"); 
            } else if (obstacles[i] == j && j!=0) {
                printf("X");
            } else {
                printf("%c", road[i][j]);
            }
        }
        printf("\n");
    }     
}

int main(){
	int check;
	int choice;
	printCar();
 
	while (1) {
	        printf("\nMenu:\n");
	        printf("1. Sign Up\n");
	        printf("2. Log In and Play Game\n");
	        printf("3. View Leaderboard\n");
	        printf("4. Exit\n");
	        printf("Enter your choice: ");
	        check = scanf("%d", &choice); //scanf returns 1 after successfulll input of data.
	        if (check!=1){
	        	printf("Invalid data type");
	        	while (getchar() != '\n'); // discard the left over invalid data in input buffer
				// clearing the input buffer for valid data
				// if not done. indefinte loop or unexpected behaviour
				
			}
			else if( choice< 1 || choice >4){
				printf("Out Of Valid Range!");
				
			
			}
			
			else{
			
	        switch (choice) {
	            case 1:
	                sign_up();
	                break;
	            case 2:
	                sign_in();
	                break;
	            case 3:
	                leaderbord();
	                break;
	            case 4:
	                printf("Exiting program.\n");
	                return 0;
	            default:
	                printf("Invalid choice! Please try again.\n");
	                break;
	        }
    }
    
        
        
    }
    return 0;
}

void init_road() {
	int i,j;
    for (i = 0; i < ROAD_HEIGHT; i++) {
        for (j = 0; j < ROAD_WIDTH; j++) {
            if (j == 0 || j == ROAD_WIDTH - 1) {
                road[i][j] = '|';  // setting border on left and right side of road
            } else {
                road[i][j] = ' ';
            }
        }
    }
}

 

void move_obstacles(int* obstacles) {
	int i;
    for (i = ROAD_HEIGHT - 1; i > 0; i--) { // loop from width(max column) to 1
        obstacles[i] = obstacles[i - 1]; // update the obstacles to move down on road
    }
    obstacles[0] = rand() % (ROAD_WIDTH - 2) + 1;  // @ 0 border , @ width -1 border exsists
    // rand() % (100) ==> generates  a random number between 0 and 100 
    
}

int check_collision(int car_position, int* obstacles) {
    return (obstacles[ROAD_HEIGHT - 1] == car_position); // value @ last index of array becomes equal to the column where car exits
}

void pause_game() {
    printf("Game Paused. Press any key to continue...\n");    
    _getch();  // this function inputs a character .. waits for input
}

int play(){
	int car_position = CAR_POS; // width /2
    int obstacles[ROAD_HEIGHT] = {0}; // sets values of obstacles to zero
    int game_over = 0;
    int score = 0;
    int delay = 100;  // intial delay 

    srand(time(0)); // seconds from 1970;  neceesary for rand();
    init_road(); // sets border and intializes the road


    
    printf("Press 1 To Enter The Game or  0 to exit: ");
    int num; // to store input
    int res; // to store return from scanf
	while(1){
		res = scanf("%d",&num); // inputs untill num is 0 or 1.
		while(getchar()!='\n'); // clear input buffer for new input
		
		if( res!=1){ // means not successfull input. user entered wrong data type . for e.g string
			printf("Ivalid DataType\n Please Enter 1 to enter game or 0 to exit");
		}
		else if (num!=1 && num!=0){ // num is not 1 and num is also not zero then 
			printf("Out of Range\n");
			printf("Enter 1 to Enter game or 0 to exit");
	}
		else{
			if (num==0){ 
				return 0;  // exit play module
			}
			break; // breaks the loop if num ==1.
		}
		
	}

	// continuationn of code only possible is num ==1 else it would have returned already.
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
	
			
	        while (!game_over) { // game over becomes 1 on collision from check_collision module.
	            if (_kbhit()) {   // _kbhit return non zero if key pressed and 0 if not .
	                char key = _getch(); // getch takes input character without need to press enter
	                if (key == 'a' && car_position > 1) { // >1 ensures car doesnot go beyond left border
	                    car_position--; 
	                } else if (key == 'd' && car_position < ROAD_WIDTH - 2) { // , width ensures that car does not go beyong right border of road
	                    car_position++;
	                } else if (key == 'p') { 
	                    pause_game(); // pause game call _getch . which means program waits untill a character is pressed.
	                }
	                
	
	            }
			
	            move_obstacles(obstacles); // calling to update position of obstacles
	            game_over = check_collision(car_position, obstacles); // checking for collisiion
	
	            display_road(car_position, obstacles); // ouput current state of road
	            
	           printf("                Score: %d\n", score++);  // outputs real time score
	
	            // Gradually decrease delay to increase speed
	            if (score % 10 == 0 && delay > 0) {
	                delay -= 10; // Reduce delay every 10 points, with a minimum limit
	            }
	
	            Sleep(delay);   // controls speed of game.
	    }
	     //    	                 Stop the background music
	mciSendString("stop myMP3", NULL, 0, NULL);
	mciSendString("close myMP3", NULL, 0, NULL);
	
	// Play the death sound
	play_mp3("C:\\Users\\dell\\Desktop\\PF Project\\Car Final\\death.mp3");
	    	
	        printf("\n\n                Game Over! Final Score: %d\n", score);
	        Sleep(2500);
	         mciSendString("stop myMP3", NULL, 0, NULL);
	mciSendString("close myMP3", NULL, 0, NULL);
	    
	    
	

return score; // returns score to update score in files
}



void sign_up(){
	FILE *p1=fopen("data1.txt","a+");
	char name[100];
	char pass[100];
	int present=0,i;
printf("Enter your name:");
scanf("%s",name);
while(fscanf(p1,"%s %s %d %d %d %d",obj.name,obj.password,&obj.scores[0],&obj.scores[1],&obj.max,&obj.react)==6){
	if(strcmp(obj.name,name)==0){
		present=1;
		break;
	}
}
if (present==1){
	printf("The Name Already Exists\n");
	fclose(p1);
}
else if(present==0){
//	printf("%d",present);
printf("Enter your password:");
scanf("%s",pass);
for(i=0;i<3;i++){
	obj.scores[i]=0;
}
obj.max=0;
obj.react=0;
fprintf(p1,"\n");
fprintf(p1,"%s %s %d %d %d %d",name,pass,obj.scores[0],obj.scores[1],obj.max,obj.react);
printf("Email Successfully Added\n");
fclose(p1);
sign_in();
}

}

void sign_in(){
	printf("Sign-In Portal\n");
	int check=0;
	FILE *p1=fopen("data1.txt","r");
	char name[100];
	char pass[100];
	printf("Enter your name:");
	scanf("%s",name);
	printf("Enter your pass:");
	scanf("%s",pass);
	while(fscanf(p1,"%s %s %d %d %d %d",obj.name,obj.password,&obj.scores[0],&obj.scores[1],&obj.max,&obj.react)==6){
     if(strcmp(obj.name,name)==0&&strcmp(obj.password,pass)==0){
     	check=1;
     	 update_score(name,p1);
     	 break;
	 }
	 else{
	 	
	 }
  }
  if(check==0){
  	printf("Invalid Email Or Password");
  }
// fclose(p1);
}


void update_score(char name[100],FILE *p1){
  int i;
//  FILE *p1=fopen("data1.txt","r");
fseek(p1,0,SEEK_SET);
  FILE *p2=fopen("temp.txt","w");
int score=0;
 i=1;
int temp=0;

while(fscanf(p1,"%s %s %d %d %d %d",obj.name,obj.password,&obj.scores[0],&obj.scores[1],&obj.max,&obj.react)==6){
	if(strcmp(name,obj.name)==0){
      do{
      	score=play();
      	temp=obj.scores[0];
        obj.scores[0]=score;
        obj.scores[1]=temp;
        if(score>obj.max)obj.max=score;
      	printf("Enter 4 to quit:");
      	scanf("%d",&i);
	  }	while(i!=4);
	
	}
	fprintf(p2,"%s %s %d %d %d %d\n",obj.name,obj.password,obj.scores[0],obj.scores[1],obj.max,obj.react);
}
fclose(p1);
fclose(p2);
remove("data1.txt");
rename("temp.txt","data1.txt");
}	

void leaderbord(){
	int i=0,count=0,j,temp=0;
	FILE *p1=fopen("data1.txt","r");
	 while(fscanf(p1,"%s %s %d %d %d %d",obj.name,obj.password,&obj.scores[0],&obj.scores[1],&obj.max,&obj.react)==6){
       count++;       
  }
  fseek(p1,0,SEEK_SET);
  
 int a[count];
  while(fscanf(p1,"%s %s %d %d %d %d",obj.name,obj.password,&obj.scores[0],&obj.scores[1],&obj.max,&obj.react)==6){
     a[i]=obj.max;
    i++;
  }


  for(i=0;i<count;i++){
  	for(j=i+1;j<count;j++){
  		if(a[j]>a[i]){
  			temp=a[i];
  			a[i]=a[j];
  			a[j]=temp;
		  }
	  }
  }
  i=0;
  fseek(p1,0,SEEK_SET);
  while(fscanf(p1,"%s %s %d %d %d %d",obj.name,obj.password,&obj.scores[0],&obj.scores[1],&obj.max,&obj.react)==6){
     if(obj.max==a[i]&&i<2){
     	printf("Rank %d: %s %d\n",i+1,obj.name,obj.max);
     	i++;
     	fseek(p1,0,SEEK_SET);
	 }
  }

}


void printCar() {
	
    printf("................................................................................................................................\n");
    printf(":                                                                                                                              :\n");
    printf(":                                                                                                                              :\n");
    printf(":                                                                                                                              :\n");
    printf(":        ____    __    ____  _______  __        ______   ______   .___  ___.  _______    .___________.  ______                 :\n");
    printf(":        \\   \\  /  \\  /   / |   ____||  |      /      | /  __  \\  |   \\/   | |   ____|   |           | /  __  \\                :\n");
    printf(":         \\   \\/    \\/   /  |  |__   |  |     |  ,----'|  |  |  | |  \\  /  | |  |__      `---|  |----`|  |  |  |               :\n");
    printf(":          \\            /   |   __|  |  |     |  |     |  |  |  | |  |\\/|  | |   __|         |  |     |  |  |  |               :\n");
    printf(":           \\    /\\    /    |  |____ |  `----.|  `----.|  `--'  | |  |  |  | |  |____        |  |     |  `--'  |               :\n");
    printf(":            \\__/  \\__/     |_______||_______| \\______| \\______/  |__|  |__| |_______|       |__|      \\______/                :\n");
    printf(":                                                                                                                              :\n");
    printf(":        ______      ___      .______           ______   ______    __       __       __       _______. __    ______   .__   __.:\n");
    printf(":       /      |    /   \\     |   _  \\         /      | /  __  \\  |  |     |  |     |  |     /       ||  |  /  __  \\  |  \\ |  |:\n");
    printf(":      |  ,----'   /  ^  \\    |  |_)  |       |  ,----'|  |  |  | |  |     |  |     |  |    |   (----`|  | |  |  |  | |   \\|  |:\n");
    printf(":      |  |       /  /_\\  \\   |      /        |  |     |  |  |  | |  |     |  |     |  |     \\   \\    |  | |  |  |  | |  . `  |:\n");
    printf("       |  `----. /  _____  \\  |  |\\  \\----.   |  `----.|  `--'  | |  `----.|  `----.|  | .----)   |   |  | |  `--'  | |  |\\   |:\n");
    printf(":       \\______|/__/     \\__\\ | _| `._____|    \\______| \\______/  |_______||_______||__| |_______/    |__|  \\______/  |__| \\__|:\n");
    printf(":                                                                                                                              :\n");
    printf(":     _______      ___      .___  ___.  _______                                                                                :\n");
    printf(":    /  _____|    /   \\     |   \\/   | |   ____|                                                                               :\n");
    printf(":   |  |  __     /  ^  \\    |  \\  /  | |  |__                                                                                  :\n");
    printf(":   |  | |_ |   /  /_\\  \\   |  |\\/|  | |   __|                                                                                 :\n");
    printf(":   |  |__| |  /  _____  \\  |  |  |  | |  |____                                                                                :\n");
    printf(":    \\______| /__/     \\__\\ |__|  |__| |_______|                                                                               :\n");
    printf(":                                                                                                                              :\n");
    printf(":                                                                                                                              :\n");
    printf(":                                                                                                                              :\n");
    printf("................................................................................................................................\n");

    printf("\n");
    printf("\n");
    

    printf("		          ______		   		     ______\n");
    printf("		         //  ||\\\\	   		            //  ||\\\\\n");             
    printf("		   _____//___||_\\\\_____		   	   ________//___||_\\\\_\n");
    printf("		  /  _           _    \\ (    		  ) _           _   \\ |\n");									
    printf("		  |_/ \\\\________/ \\\\___|	    	 |_/ \\\\________/ \\\\__|\n");
    printf("		 ___\\_/_________\\_/______	  +     ___\\_/_________\\_/______\n");
    
    printf("                ______			          ______\n");                
    printf("               //  ||\\\\	                         //  ||\\\\\n");            
    printf("      ________//___||_\\\\____	        ________//___||_\\\\____\n");					
    printf("     )  _          _    \\  |           )  _       _      \\   |\n");					
    printf("     |_/ \\\\________/ \\\\___|	       |_/ \\\\________/ \\\\___|\n");					
    printf("    ___\\_/________\\_/______	  +   ___\\_/________\\_/______\n");
    printf("\n");
    printf("\n");
    	

}


void play_mp3(const char *filename) {
    char command[256];
    sprintf(command, "open \"%s\" type mpegvideo alias myMP3", filename); //sprintf formats the given string .
	// stores open (filename) type mpegvideo alias myMP3 in command
    mciSendString(command, NULL, 0, NULL);  // Open the MP3 file 

    mciSendString("play myMP3 repeat", NULL, 0, NULL);  // Play in a loop (background) (repeat)
	// myMP3 alias for filename
}
