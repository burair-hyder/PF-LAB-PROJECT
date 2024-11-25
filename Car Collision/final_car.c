#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>   // For _kbhit() and _getch()
#include <windows.h> // For Sleep()
#include<string.h>
#define ROAD_WIDTH 40
#define ROAD_HEIGHT 20
#define CAR_POS (ROAD_WIDTH / 2)
struct signin{
	char name[100];
	char password[100];
	int scores[2];
	int max;
	int react;
}obj;
char road[ROAD_HEIGHT][ROAD_WIDTH];
void init_road();
void display_road(int car_position, int obstacles[] );
void move_obstacles(int* obstacles);
int check_collision(int car_position, int* obstacles);
void pause_game();
void printCar();
int play();
//FILE HANDLING FUNCTIONS
void sign_up();
void sign_in();
void update_score(char name[100],FILE *p1);
void leaderbord();
void play_mp3(const char *filename) {
    char command[256];
    sprintf(command, "open \"%s\" type mpegvideo alias myMP3", filename);
    mciSendString(command, NULL, 0, NULL);  // Open the MP3 file

    mciSendString("play myMP3 repeat", NULL, 0, NULL);  // Play in a loop (background)
}s


int main(){
    int choice;
    printCar();
    while (1) {
        printf("\nMenu:\n");
        printf("1. Sign Up\n");
        printf("2. Log In and Play Game\n");
        printf("3. View Leaderboard\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

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
        }
        
        
    }
    return 0;
}

void init_road() {
	int i,j;
    for (i = 0; i < ROAD_HEIGHT; i++) {
        for (j = 0; j < ROAD_WIDTH; j++) {
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
int i,j;
    for (i = 0; i < ROAD_HEIGHT; i++) {
        printf("                "); 

        for (j = 0; j < ROAD_WIDTH; j++) {
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
	int i;
    for (i = ROAD_HEIGHT - 1; i > 0; i--) {
        obstacles[i] = obstacles[i - 1];
    }
    obstacles[0] = rand() % (ROAD_WIDTH - 2) + 1; 
}

int check_collision(int car_position, int* obstacles) {
    return (obstacles[ROAD_HEIGHT - 1] == car_position);
}

void pause_game() {
    printf("Game Paused. Press any key to continue...\n");
    _getch(); 
}

int play(){
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
        Sleep(2500);
         mciSendString("stop myMP3", NULL, 0, NULL);
mciSendString("close myMP3", NULL, 0, NULL);
    }
    return score;
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
	printf("The Name Already Exists");
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
sign_in();
}
fclose(p1);
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
//  fclose(p1);
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
    printf("Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·Â·\n");
//    return 0;                                                                                                                             :\n");

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

