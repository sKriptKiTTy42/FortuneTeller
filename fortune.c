#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define BSIZE 256




int main()
{
	const char filename[] = "pithy.txt";
	FILE *fp;
	char buffer[BSIZE];
	char lines[10][BSIZE]; // Assuming a maximum of 10 lines
	
	int lineCount = 0;


		

	// Open the file
	fp = fopen(filename, "r"); 
	if( fp == NULL )
	{
		fprintf(stderr,"Unable to open file %s\n", filename);
		exit(1);
	}



	while (fgets(buffer,BSIZE,fp) != NULL && lineCount < 10) {
		strcpy(lines[lineCount], buffer);
		lineCount++;
	}

	// Close the file
	fclose(fp);

	// Set seed for random number generation
	srand((unsigned int)time(NULL));

	// Generate a random index within the range of lines read
	int randomIndex = rand() % lineCount;

	// Output a random line from the array
	printf("%s", lines[randomIndex]);


	return(0);
}

		





