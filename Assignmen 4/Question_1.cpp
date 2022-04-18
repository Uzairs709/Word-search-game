#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<ctime>

class puzzle {
private:
	std::string wordsFromFile[8];
	char** grid;
	int largestWordSize;//which creates row and column for grid
	char CharacterFromFile;
	int counter;

public:
	puzzle();//initialize all variable and takes the input of 8 words from file
	//~puzzle();//will destroy all the memory and creat txt file and writes data in it
	//void arrangeLeftToRight(std::string a);
	//void arrangrRightToLeft(std::string a);
	//void arrangeUpToDown(std::string a);
	//void arrangeDownToUp(std::string a);
	//void arrangeDiagonalUpDown(std::string a);
	//void arrangeDiagonalDownUp(std::string a);
	//void arrangeNonDiagonalUpDown(std::string a);
	//void arrangeNonDiagonalDownUP(std::string a);
};
void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int n=8)
{
	int i, j, min_idx;

	
	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j; 
		swap(&arr[min_idx], &arr[i]);
	}
}
puzzle::puzzle() {
	int wordNumberForFile[8];

	srand(time(0));
	counter = 0;
	std::ifstream fin;
	std::string extra;
	fin.open("Input.txt");
	if (fin.is_open()) {
		while (!fin.eof()) {
			fin >> extra;
			counter++;
		}


		fin.close();
		for (int i = 0; i < 8; i++) {
			wordNumberForFile[i] = (rand() % counter)+1;
			for (int j = 0; j < i; j++) {
				if (wordNumberForFile[i] == wordNumberForFile[j]) {
					while (wordNumberForFile[i] == wordNumberForFile[j]) {
						wordNumberForFile[i] = (rand() % counter)+1;
					}
				}
			}
		}
		selectionSort(wordNumberForFile);
	}
	else
		std::cout << "File not open";

	fin.open("Input.txt");
	if (fin.is_open()) {
		int i = 1, j = 0;
		while (fin.get(CharacterFromFile)) {
			int k = 0;
			if (i == wordNumberForFile[j]) {
				if (CharacterFromFile != ' ') {
					wordsFromFile[j][k] = CharacterFromFile;
					k++;
				}
				if (CharacterFromFile == '\n') {
					i++;
					j++;
				}

			}
			else {
				fin >> extra;
				i++;
			}
		}
	}
	fin.close();
	for (int i = 0; i < 8; i++) {
		std::cout << wordsFromFile[i] << std::endl;
	}
	largestWordSize = 0;
}


//main body
int main() {
	puzzle a;
}