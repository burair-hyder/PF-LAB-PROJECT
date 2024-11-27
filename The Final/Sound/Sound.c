void play_mp3(const char *filename) {
    char command[256];
    sprintf(command, "open \"%s\" type mpegvideo alias myMP3", filename);
    mciSendString(command, NULL, 0, NULL);  // Open the MP3 file

    mciSendString("play myMP3 repeat", NULL, 0, NULL);  // Play in a loop (background)
}
