#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

const char VERSIONSNR[] = "0.1";

const int DB_SIZE = 20;

typedef struct person_t{
	int personalnummer;
	char nachname[20];
	char vorname[20];
	int geburtsjahr;
} person_t;

int main(int argc, char* argv[]){
	person_t database[DB_SIZE];
	int option;
	char filename[80];
	FILE *filepointer = NULL;
	while((option = getopt(argc, argv, "hvf:"))!=-1)
	switch(option)
	{
		case 'h':
			printf("Bitte -f nutzen um einen File-Path anzugeben\n");
			exit(0);
		case 'v':
			printf("Version %s\n", VERSIONSNR);
			exit(0);
		case 'f':
			if(NULL == (filepointer = fopen(optarg, "r"))){
				printf("Couldnt open file");
				exit(2);
			}
			break;
		default:
			printf("Wrong Usage. Please try -h");
			exit(0);
	}
	


	fscanf(filepointer, "%d,%[^,],%[^,],%d", &database[0].personalnummer, database[0].nachname, 
	database[0].vorname, &database[0].geburtsjahr);
	
	
	printf("%d, %s, %s, %d", database[0].personalnummer, database[0].nachname, database[0].vorname,
	database[0].geburtsjahr);

	return 0;
}

