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
