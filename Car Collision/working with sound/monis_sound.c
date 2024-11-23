void play_mp32(const char *filename) {

 // sir monis ke sound ka function
  char command[256];
   int result;

   // Open the MP3 file
   sprintf(command, "open \"%s\" type mpegvideo alias myMP3", filename);
   result = mciSendString(command, NULL, 0, NULL);
//    if (result != 0) {
//        printf("Error opening file: %d\n", result);
//        return;
//    }

   // Play the MP3 file once
   result = mciSendString("play myMP3", NULL, 0, NULL);
//    if (result != 0) {
//        printf("Error playing file: %d\n", result);
//        return;
//    }

   // Wait for playback to finish
   Sleep(3000); // Adjust duration as per the MP3 length or use MCI `status` command

   // Close the MP3 file
   result = mciSendString("close myMP3", NULL, 0, NULL);
//    if (result != 0) {
//        printf("Error closing file: %d\n", result);
//        return;
//    }
}
