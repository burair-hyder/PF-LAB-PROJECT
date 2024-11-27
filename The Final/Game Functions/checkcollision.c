int check_collision(int car_position, int* obstacles) {
    return (obstacles[ROAD_HEIGHT - 1] == car_position);
}
