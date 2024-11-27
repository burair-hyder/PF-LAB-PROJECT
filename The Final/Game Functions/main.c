int main(){
	int check;
    
    printCar();
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Sign Up\n");
        printf("2. Log In and Play Game\n");
        printf("3. View Leaderboard\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        check = scanf("%d", &choice);
        if (check!=1){
        	printf("Invalid data type");
        	while (getchar() != '\n'); // discard the left over invalid data in input buffer
			// clearing the input buffer for valid data
			
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
