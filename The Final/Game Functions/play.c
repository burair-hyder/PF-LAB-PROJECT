int play(){
	    int car_position = CAR_POS;
    int obstacles[ROAD_HEIGHT] = {0};
    int game_over = 0;
    int score = 0;
    int delay = 100; 

    srand(time(0)); 
    init_road();


    
    printf("Press 1 TO Enter The Game: ");
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
