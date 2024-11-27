void move_obstacles(int* obstacles) {
	int i;
    for (i = ROAD_HEIGHT - 1; i > 0; i--) {
        obstacles[i] = obstacles[i - 1];
    }
    obstacles[0] = rand() % (ROAD_WIDTH - 2) + 1; 
}
