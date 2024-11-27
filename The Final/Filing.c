//FILE HANDLING FUNCTIONS
void sign_up();
void sign_in();
void update_score(char name[100],FILE *p1);
void leaderbord();

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

}
	fclose(p1);
	sign_in();
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
 fclose(p1);
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
