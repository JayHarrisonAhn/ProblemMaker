#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

void printLine(FILE *f, int line)
{
	char currentText;
	fseek(f, 0, SEEK_SET);

	for (int i = 0; i < line; i++)
	{
		while (fscanf(f, "%c", &currentText) != EOF)
		{
			if (currentText == '\n')
				break;
		}
	}

	while (fscanf(f, "%c", &currentText) != EOF)
	{
		printf("%c", currentText);
		if (currentText == '\n')
			break;
	}
}

void printNextLine(FILE *f)
{
	char currentText;
	
	while (fscanf(f, "%c", &currentText) != EOF)
	{
		printf("%c", currentText);
		if (currentText == '\n')
			break;
	}
}

int linesOfFile(FILE *f)
{
	fseek(f, 0, SEEK_SET);
	char currentText;
	int lines = 1;
	while (fscanf(f, "%c", &currentText) != EOF)
	{
		if (currentText == '\n')
		{
			lines++;
		}
			
	}
	return lines;
}

int numberOfProblem(FILE *f)
{
	return (linesOfFile(f) / 3) - 1;
}

int randomProblemNumber(FILE *f)
{
	srand(time(NULL));
	return (rand() % numberOfProblem(f)) + 1;
}

int main(void)
{
	FILE *f = fopen("문예사.txt", "r");
	char trash;
	while (1)
	{
		printLine(f, randomProblemNumber(f) * 3);
		while (1)
		{
			scanf("%c", &trash);
			if (trash == '\n')
				break;
		}
		
		printf("정답 : ");
		printNextLine(f);
		printf("\n\n");
	}
	
	return 0;
}

