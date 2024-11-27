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
