#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

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

int *mixedOrderOfProblem(int num)
{
	static int *resultArr;
	resultArr = (int*)malloc(sizeof(int) * num);


	for (int i = 0;i < num;i++)
	{
		resultArr[i] = i;
	}

	srand(time(NULL));
	int swapNum;
	int temp;
	for (int i = 0;i < num;i++)
	{
		swapNum = rand() % num;

		temp = resultArr[i];
		resultArr[i] = resultArr[swapNum];
		resultArr[swapNum] = temp;
	}
	return resultArr;
}

int main(void)
{
	char fileName[32];
	printf("ProblemMaker\n���蹮���� �������� �����ݴϴ�.\n������ lbr0452000\n\n");
	printf("������ ������ ���� �̸��� �Է��ϼ���.\n(���� : ���а������ǻ�ȸ��.txt)\n");
	scanf("%s", fileName);
	getchar();
	system("cls");
	FILE *f = fopen(fileName, "r");

	char trash;
	int numberOfProblem = linesOfFile(f) / 3;
	int *orderOfProblem = mixedOrderOfProblem(numberOfProblem);

	for (int i = 0;i < numberOfProblem;i++)
	{
		printLine(f, orderOfProblem[i] * 3);
		while (1)
		{
			scanf("%c", &trash);
			if (trash == '\n')
				break;
		}

		printf("���� : ");
		printNextLine(f);
		printf("\n\n");
	}

	printf("��� ������ ����߽��ϴ�. �ƹ� Ű�� ������ ���α׷��� �����մϴ�.");
	getch();
	
	return 0;
}

