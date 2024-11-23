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
