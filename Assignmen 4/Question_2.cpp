//#include<iostream>
//#include<fstream>
//#include<string>
//#include<conio.h>
//
//class search {
//private:
//	char** InputFromFIle;//taking grid input from file
//	int row;//no of rows for grid
//	int col;//no of columns for grid
//	int no_test;//no of test cases
//	int startingIndex[2];//starting index of string searched in grid entered by usr
//	int EndingIndex[2];//endeding index
//	std::string* Userinput;//string variable array for user input
//	//these functions will be called inside another search function and return true if found the element
//	//if the element is found the public function which would be calling these print the indexes of strating and ending of word
//	bool DiagonalSearchUpDown(std::string a);
//	bool DiagonalSearchDownUP(std::string a);
//	bool LeftRightSearch(std::string a);
//	bool RightLeftSearch(std::string a);
//	bool UpDownSearch(std::string a);
//	bool DownUpSearch(std::string a);
//	bool non_diagonalSearchUpDown(std::string a);
//	bool non_diagonalSearchDownUp(std::string a);
//	int stringlength(std::string a);
//public:
//	search();//constructor
//	~search();//destructor
//	void InputFromUser();
//	void searchWords();
//	
//};
////initializing every variable inside constructor
////also taking input from file in InPutFromFIle
//search::search() {
//	std::ifstream fin;
//	fin.open("output.txt");//opens the file
//	fin >> row >> col >> no_test;//gets no of rows and colums and no of test cases 
//	
//	Userinput = new std::string[no_test];//creating string array of no test cases these will be entered by user
//	
//	InputFromFIle = new char* [row];
//	for (int i = 0; i < row; i++) {
//		InputFromFIle[i] = new char[col+1];
//	}
//	
//	int i = 0, j = 0;
//	char c;
//	
//	if (fin.is_open()) {
//
//		//getting input from file
//		while (fin.get(c)) {//getting input character by chharacter
//			
//			if (c != ' ' && c != '\n') {
//				InputFromFIle[i][j] = c;
//				j++;
//			}
//			if (j == col) {
//				InputFromFIle[i][j] = '\0';
//				j = 0;
//				i++;
//			}			
//		}
//	}
//	fin.close();//closing a file
//
//	startingIndex[0] = -1;
//	startingIndex[1] = -1;
//
//	EndingIndex[0] = -1;
//	EndingIndex[1] = -1;
//
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j <= col; j++)
//		{
//			std::cout << InputFromFIle[i][j] << " ";
//
//		}
//		std::cout << std::endl;
//		
//	}
//
//}
////destroying dynamic memeory allocated in constructor
//search::~search() {
//
//	delete[]Userinput;
//	for (int i = 0; i < row; i++) {
//		delete[]InputFromFIle[i];
//	}
//	delete[]InputFromFIle;
//
//}
////taking input in UserInput from the user
//void search::InputFromUser() {
//	std::cout << "Input:" << std::endl;
//	for (int i = 0; i < no_test; i++) {
//		std::getline(std::cin, Userinput[i]);
//	}
//}
////finding length of string
//int search::stringlength(std::string a) {
//	int i = 0;
//	for (i; a[i] != '\0'; i++) {
//		a[i];
//	}
//
//	return i;
//}
////searching element left to right
//bool search::LeftRightSearch(std::string a) {
//	int userInputIndex = 0;
//	startingIndex[0] = EndingIndex[0] = startingIndex[1] = EndingIndex[1] = -1;
//	for (int i = 0; i < row; i++) {
//		userInputIndex = 0;
//		for (int j = 0; j  <=col; j++) {
//			if (a[userInputIndex] == InputFromFIle[i][j]) {
//				if (userInputIndex == 0) {
//					startingIndex[0] = i;
//					startingIndex[1] = j;
//				}
//				
//			}
//			if(a[userInputIndex]!=InputFromFIle[i][j]) {
//				startingIndex[0] = -1;
//				startingIndex[1] = -1;
//				userInputIndex = -1;
//			}
//			if (userInputIndex == 0 && j + stringlength(a) >= col && a[userInputIndex] != InputFromFIle[i][j]) {
//				startingIndex[0] = -1;
//				startingIndex[1] = -1;
//				userInputIndex = 0;
//				break;
//			}
//			if (userInputIndex == stringlength(a) - 1 && a[userInputIndex] == InputFromFIle[i][j]) {
//				EndingIndex[0] = i;
//				EndingIndex[1] = j;
//				break;
//			}
//			userInputIndex++;
//		}
//		if (EndingIndex[0] != -1) {
//			break;
//		}
//	}
//	if (EndingIndex[0] != -1 && EndingIndex[1] != -1 && startingIndex[0] != -1 && startingIndex[1] != -1) {
//		return true;
//	}
//	else
//		return false;
//
//}
////searching for word right to left
//bool  search::RightLeftSearch(std::string a) {
//
//	int userInputIndex = 0;
//	startingIndex[0] = EndingIndex[0] = startingIndex[1] = EndingIndex[1] = -1;
//	for (int i = 0; i < row; i++) {
//		userInputIndex = 0;
//		for (int j = col; j>-1; j--) {
//			if (a[userInputIndex] == InputFromFIle[i][j] ) {
//				if (userInputIndex == 0) {
//					startingIndex[0] = i;
//					startingIndex[1] = j;
//				}
//				
//			}
//
//			if (a[userInputIndex] != InputFromFIle[i][j]) {
//				startingIndex[0] = -1;
//				startingIndex[1] = -1;
//				userInputIndex = -1;
//			}
//			if (userInputIndex == 0 && j + stringlength(a) >= col && a[userInputIndex] != InputFromFIle[i][j]) {
//				startingIndex[0] = -1;
//				startingIndex[1] = -1;
//				userInputIndex = 0;
//				break;
//			}
//			if (userInputIndex == stringlength(a) - 1 && a[userInputIndex] == InputFromFIle[i][j]) {
//				EndingIndex[0] = i;
//				EndingIndex[1] = j;
//				break;
//			}
//			userInputIndex++;
//		}
//		if (EndingIndex[0] != -1) {
//			break;
//		}
//	}
//	if (EndingIndex[0] != -1 && EndingIndex[1] != -1 && startingIndex[0] != -1 && startingIndex[1] != -1) {
//		return true;
//	}
//	else
//		return false;
//
//}
////search for word top to bottom
//bool search::UpDownSearch(std::string a) {
//	int UserInputIndex = 0;
//	startingIndex[0] = EndingIndex[0] = startingIndex[1] = EndingIndex[1] = -1;
//	for (int i = 0; i <= col; i++) {
//		UserInputIndex = 0;
//		for (int j = 0; j < row; j++) {
//			if (a[UserInputIndex] == InputFromFIle[j][i]) {
//				if (UserInputIndex == 0) {
//					startingIndex[0] = i;
//					startingIndex[1] = j;
//				}
//			 
//			}
//			if (a[UserInputIndex] != InputFromFIle[j][i]) {
//				startingIndex[0] = -1;
//				startingIndex[1] = -1;
//				UserInputIndex = -1;
//			}
//			if (UserInputIndex == 0 && j + stringlength(a) >= row && a[UserInputIndex] != InputFromFIle[j][i]) {
//				startingIndex[0] = -1;
//				startingIndex[1] = -1;
//				UserInputIndex = 0;
//				break;
//			}
//			if (UserInputIndex == stringlength(a) - 1 && a[UserInputIndex] == InputFromFIle[j][i]) {
//				EndingIndex[0] = i;
//				EndingIndex[1] = j;
//				break;
//			}
//			UserInputIndex++;
//		}
//		if (EndingIndex[0] != -1) {
//			break;
//		}
//	}
//	if (EndingIndex[0] != -1 && EndingIndex[1] != -1 && startingIndex[0] != -1 && startingIndex[1] != -1) {
//		return true;
//	}
//	else
//		return false;
//}
////search for word bottom to top
//bool search::DownUpSearch(std::string a) {
//	int UserInputIndex = 0;
//	startingIndex[0] = EndingIndex[0] = startingIndex[1] = EndingIndex[1] = -1;
//	for (int i = 0; i <= col; i++) {
//		UserInputIndex = 0;
//		for (int j = row-1; j>0; j--) {
//			if (a[UserInputIndex] == InputFromFIle[j][i]) {
//				if (UserInputIndex == 0) {
//					startingIndex[0] = i;
//					startingIndex[1] = j;
//				}
//				
//			}
//			if (a[UserInputIndex] != InputFromFIle[j][i]) {
//				startingIndex[0] = -1;
//				startingIndex[1] = -1;
//				UserInputIndex = -1;
//			}
//			if (UserInputIndex == 0 && j + stringlength(a) >= row && a[UserInputIndex] != InputFromFIle[j][i]) {
//				startingIndex[0] = -1;
//				startingIndex[1] = -1;
//				UserInputIndex = 0;
//				break;
//			}
//			if (UserInputIndex == stringlength(a) - 1 && a[UserInputIndex] == InputFromFIle[j][i]) {
//				EndingIndex[0] = i;
//				EndingIndex[1] = j;
//				break;
//			}
//			UserInputIndex++;
//		}
//		if (EndingIndex[0] != -1) {
//			break;
//		}
//	}
//	if (EndingIndex[0] != -1 && EndingIndex[1] != -1 && startingIndex[0] != -1 && startingIndex[1] != -1) {
//		return true;
//	}
//	else
//		return false;
//
//}
////cell counter for diagonal search up to down
//int cellCounterDiagonnalUpDown(int row, int col,int cellPositionX,int cellPositionY) {
//	int counter = 0;
//	for ( counter = 0; cellPositionX < row && cellPositionY <= col;counter++) {
//		cellPositionX++;
//		cellPositionY++;
//	}
//	return counter;
//}
////cell counter for diagonal down to up
//int cellCounterDiagonalDownup(int row, int col, int cellPositionX, int cellPositionY) {
//	int counter = 0;
//	while (cellPositionX >= 0 && cellPositionY >= 0) {
//		cellPositionX--;
//		cellPositionY--;
//		counter++;
//	}
//	return counter;
//}
////cell counter for non diagonal up to down
//int cellCounterNonDiagonalUpDown( int row, int col, int cellPositionX, int cellPositionY) {
//	int counter = 0;
//	while (cellPositionX < row && cellPositionY >= 0) {
//		cellPositionX++;
//		cellPositionY--;
//		counter++;
//	}
//	return counter;
//}
////cell counter for non diagonal down to up
//int cellCounterNonDiagonalDownUp(int row, int col, int cellPositionX, int cellPositionY) {
//	int counter = 0;
//	while (cellPositionX >= 0 && cellPositionY <= col) {
//		cellPositionX--;
//		cellPositionY++;
//		counter++;
//	}
//	return counter;
//}
////diagonal search from top left to bottom right (diagonalSearchUpDown)
//bool search::DiagonalSearchUpDown(std::string a) {
//	int UserInputIndex = 0;
//	startingIndex[0] = EndingIndex[0] = startingIndex[1] = EndingIndex[1] = -1;
//	
//	//matric lower part
//	for (int i = 0; i <row; i++) {
//		UserInputIndex = 0;
//		int k = i;
//		for (int j = 0; j <=col&&k<row; j++,k++) {
//			if (a[UserInputIndex] == InputFromFIle[k][j] ) {
//				if (UserInputIndex == 0) {
//					startingIndex[0] = k;
//					startingIndex[1] = j;
//				}
//				
//			}
//			if (a[UserInputIndex] != InputFromFIle[k][j]) {
//				startingIndex[0] = -1;
//				startingIndex[1] = -1;
//				UserInputIndex = -1;
//			}
//			if ( stringlength(a)<=cellCounterDiagonnalUpDown(row,col,k,j) && UserInputIndex == 0 && InputFromFIle[k][j] != a[UserInputIndex]) {
//				startingIndex[0] = -1;
//				startingIndex[1] = -1;
//				UserInputIndex = 0;
//				break;
//			}
//			if (UserInputIndex == stringlength(a) - 1 && a[UserInputIndex] == InputFromFIle[k][j]) {
//				EndingIndex[0] = k;
//				EndingIndex[1] = j;
//				break;
//			}
//			UserInputIndex++;
//		}
//		if (EndingIndex[0] != -1) {
//			break;
//		}
//	}
//	//matrix upper part
//	if (EndingIndex[0] == -1) {
//		for (int i = 0; i < row; i++) {
//			UserInputIndex = 0;
//			int k = i;
//			for (int j = 0; j <= col&&k<row; j++, k++) {
//				if (a[UserInputIndex] == InputFromFIle[j][k]) {
//					if (UserInputIndex == 0) {
//						startingIndex[0] = j;
//						startingIndex[1] = k;
//					}
//					
//				}
//				if (a[UserInputIndex] != InputFromFIle[j][k]) {
//					startingIndex[0] = -1;
//					startingIndex[1] = -1;
//					UserInputIndex = -1;
//				}
//				if (stringlength(a)<= cellCounterDiagonnalUpDown(row, col, j, k) && UserInputIndex == 0 && InputFromFIle[j][k] != a[UserInputIndex]) {
//					startingIndex[0] = -1;
//					startingIndex[1] = -1;
//					UserInputIndex = 0;
//					break;
//				}
//				if (UserInputIndex == stringlength(a) - 1 && a[UserInputIndex] == InputFromFIle[k][j]) {
//					EndingIndex[0] = j;
//					EndingIndex[1] = k;
//					break;
//				}
//				UserInputIndex++;
//			}
//			if (EndingIndex[0] != -1) {
//				break;
//			}
//		}
//	}
//	if (EndingIndex[0] != -1 && EndingIndex[1] != -1 && startingIndex[0] != -1 && startingIndex[1] != -1) {
//		return true;
//	}
//	else
//		return false;
//}
////diagonal search from bottom right to upper left (diagonalSearchDownUp)
//bool search::DiagonalSearchDownUP(std::string a) {
//	int UserInputIndex = 0;
//	startingIndex[0] = EndingIndex[0] = startingIndex[1] = EndingIndex[1] = -1;
//	//matrix upper part
//	for (int i = row-1; i >-1; i--) {
//		UserInputIndex = 0;
//		int k = i;
//		for (int j = col; j > -1 && k >-1; j--, k--) {
//			if (a[UserInputIndex] == InputFromFIle[k][j]) {
//				if (UserInputIndex == 0) {
//					startingIndex[0] = k;
//					startingIndex[1] = j;
//				}
//				
//			}
//			if (a[UserInputIndex] != InputFromFIle[k][j]) {
//				startingIndex[0] = -1;
//				startingIndex[1] = -1;
//				UserInputIndex = -1;
//			}
//			if (stringlength(a) <=cellCounterDiagonalDownup(row,col,k,j) && UserInputIndex == 0 && InputFromFIle[k][j] != a[UserInputIndex]) {
//				startingIndex[0] = -1;
//				startingIndex[1] = -1;
//				UserInputIndex = 0;
//				break;
//			}
//			if (UserInputIndex == stringlength(a) - 1 && a[UserInputIndex] == InputFromFIle[k][j]) {
//				EndingIndex[0] = k;
//				EndingIndex[1] = j;
//				break;
//			}
//			UserInputIndex++;
//		}
//		if (EndingIndex[0] != -1) {
//			break;
//		}
//	}
//	//matrix lower part
//	if (EndingIndex[0] == -1) {
//		for (int i = col; i > -1; i--) {
//			UserInputIndex = 0;
//			int k = i;
//			for (int j = row-1;k>-1&&j>-1; j--, k--) {
//				if (a[UserInputIndex] == InputFromFIle[j][k]) {
//					if (UserInputIndex == 0) {
//						startingIndex[0] = j;
//						startingIndex[1] = k;
//					}
//					
//				}
//				if (a[UserInputIndex] != InputFromFIle[j][k]) {
//					startingIndex[0] = -1;
//					startingIndex[1] = -1;
//					UserInputIndex = -1;
//				}
//				if (stringlength(a)<= cellCounterDiagonalDownup(row, col, j, k) && UserInputIndex == 0 && InputFromFIle[j][k] != a[UserInputIndex]) {
//					startingIndex[0] = -1;
//					startingIndex[1] = -1;
//					UserInputIndex = 0;
//					break;
//				}
//				if (UserInputIndex == stringlength(a) - 1 && a[UserInputIndex] == InputFromFIle[j][k]) {
//					EndingIndex[0] = j;
//					EndingIndex[1] = k;
//					break;
//				}
//				UserInputIndex++;
//			}
//			if (EndingIndex[0] != -1) {
//				break;
//			}
//		}
//	}
//	if (EndingIndex[0] != -1 && EndingIndex[1] != -1 && startingIndex[0] != -1 && startingIndex[1] != -1) {
//		return true;
//	}
//	else
//		return false;
//
//}
////non-diagonal searching top right to bottom left
//bool search::non_diagonalSearchUpDown(std::string a) {
//		int UserInputIndex = 0;
//		startingIndex[0] = EndingIndex[0] = startingIndex[1] = EndingIndex[1] = -1;
//		//matrix lower part
//		for (int i = 0; i<row ; i++) {
//			UserInputIndex = 0;
//			int k = i;
//			for (int j = col; j > -1 && k < row; j--, k++) {
//				if (a[UserInputIndex] == InputFromFIle[k][j]) {
//					if (UserInputIndex == 0) {
//						startingIndex[0] = k;
//						startingIndex[1] = j;
//					}
//					
//				}
//				if (a[UserInputIndex] != InputFromFIle[k][j]) {
//					startingIndex[0] = -1;
//					startingIndex[1] = -1;
//					UserInputIndex = -1;
//				}
//				if ( stringlength(a)<=cellCounterNonDiagonalUpDown(row,col,k,j) && UserInputIndex == 0 && InputFromFIle[k][j] != a[UserInputIndex]) {
//					startingIndex[0] = -1;
//					startingIndex[1] = -1;
//					UserInputIndex = 0;
//					break;
//				}
//				if (UserInputIndex == stringlength(a) - 1 && a[UserInputIndex] == InputFromFIle[k][j]) {
//					EndingIndex[0] = k;
//					EndingIndex[1] = j;
//					break;
//				}
//				UserInputIndex++;
//			}
//			if (EndingIndex[0] != -1) {
//				break;
//			}
//		}
//		//matrix upper part
//		if (EndingIndex[0] == -1) {
//			for (int i = col; i >=0; i--) {
//				UserInputIndex = 0;
//				int k = i;
//				for (int j = 0;j<row&& k>-1; j++, k--) {
//					if (a[UserInputIndex] == InputFromFIle[j][k]) {
//						if (UserInputIndex == 0) {
//							startingIndex[0] = j;
//							startingIndex[1] = k;
//						}
//						
//					}
//					if (a[UserInputIndex] != InputFromFIle[j][k]) {
//						startingIndex[0] = -1;
//						startingIndex[1] = -1;
//						UserInputIndex = -1;
//					}
//					if (stringlength(a)<= cellCounterNonDiagonalUpDown(row, col, j, k) && UserInputIndex == 0 && InputFromFIle[j][k] != a[UserInputIndex]) {
//						startingIndex[0] = -1;
//						startingIndex[1] = -1;
//						UserInputIndex = 0;
//						break;
//					}
//					if (UserInputIndex == stringlength(a) - 1 && a[UserInputIndex] == InputFromFIle[j][k]) {
//						EndingIndex[0] = j;
//						EndingIndex[1] = k;
//						break;
//					}
//					UserInputIndex++;
//				}
//				if (EndingIndex[0] != -1) {
//					break;
//				}
//			}
//		}
//		if (EndingIndex[0] != -1 && EndingIndex[1] != -1 && startingIndex[0] != -1 && startingIndex[1] != -1) {
//			return true;
//		}
//		else
//			return false;
//	
//}
////non-diagonal search botthom left to upper right
//bool search::non_diagonalSearchDownUp(std::string a) {
//	int UserInputIndex = 0;
//	startingIndex[0] = EndingIndex[0] = startingIndex[1] = EndingIndex[1] = -1;
//	//matrix upper part
//	for (int i = row-1; i>=0; i--) {
//		UserInputIndex = 0;
//		int k = i;
//		for (int j = 0;j<=col&&k>=0; j++, k--) {
//			if (a[UserInputIndex] == InputFromFIle[k][j]) {
//				if (UserInputIndex == 0) {
//					startingIndex[0] = k;
//					startingIndex[1] = j;
//				}
//				
//			}
//			if (a[UserInputIndex] != InputFromFIle[k][j]) {
//				startingIndex[0] = -1;
//				startingIndex[1] = -1;
//				UserInputIndex = -1;
//			}
//			if (stringlength(a) <= cellCounterNonDiagonalDownUp(row, col, k, j) && UserInputIndex == 0 && InputFromFIle[k][j] != a[UserInputIndex]) {
//				startingIndex[0] = -1;
//				startingIndex[1] = -1;
//				UserInputIndex = 0;
//				break;
//			}
//			if (UserInputIndex == stringlength(a) - 1 && a[UserInputIndex] == InputFromFIle[k][j]) {
//				EndingIndex[0] = k;
//				EndingIndex[1] = j;
//				break;
//			}
//			UserInputIndex++;
//		}
//		if (EndingIndex[0] != -1) {
//			break;
//		}
//	}
//	//matrix lower part
//	if (EndingIndex[0] == -1) {
//		for (int i = 0; i <=col; i++) {
//			UserInputIndex = 0;
//			int k = i;
//			for (int j = row-1; j >=0&&k<=col; j--, k++) {
//				if (a[UserInputIndex] == InputFromFIle[j][k]) {
//					if (UserInputIndex == 0) {
//						startingIndex[0] = j;
//						startingIndex[1] = k;
//					}
//					
//				}
//				if (a[UserInputIndex] != InputFromFIle[j][k]) {
//					startingIndex[0] = -1;
//					startingIndex[1] = -1;
//					UserInputIndex = -1;
//				}
//				if (stringlength(a) <= cellCounterNonDiagonalDownUp(row, col, j, k) && UserInputIndex == 0 && InputFromFIle[j][k] != a[UserInputIndex]) {
//					startingIndex[0] = -1;
//					startingIndex[1] = -1;
//					UserInputIndex = 0;
//					break;
//				}
//				if (UserInputIndex == stringlength(a) - 1 && a[UserInputIndex] == InputFromFIle[j][k]) {
//					EndingIndex[0] = j;
//					EndingIndex[1] = k;
//					break;
//				}
//				UserInputIndex++;
//			}
//			if (EndingIndex[0] != -1) {
//				break;
//			}
//		}
//	}
//	if (EndingIndex[0] != -1 && EndingIndex[1] != -1 && startingIndex[0] != -1 && startingIndex[1] != -1) {
//		return true;
//	}
//	else
//		return false;
//
//}
////main searching which would be actually called in main
//void search::searchWords() {
//	for (int i = 0; i < no_test; i++) {
//		if (LeftRightSearch(Userinput[i])) {
//			std::cout << "{" << startingIndex[0] << "," << startingIndex[1] << "}";
//			std::cout << "{" << EndingIndex[0] << "," << EndingIndex[1] << "}";
//			std::cout << std::endl;
//		}
//		else if (RightLeftSearch(Userinput[i])) {
//			std::cout << "{" << startingIndex[0] << "," << startingIndex[1] << "}";
//			std::cout << "{" << EndingIndex[0] << "," << EndingIndex[1] << "}";
//			std::cout << std::endl;
//		}
//		else if (UpDownSearch(Userinput[i])) {
//			std::cout << "{" << startingIndex[0] << "," << startingIndex[1] << "}";
//			std::cout << "{" << EndingIndex[0] << "," << EndingIndex[1] << "}";
//			std::cout << std::endl;
//		}
//		else if (DownUpSearch(Userinput[i])) {
//			std::cout << "{" << startingIndex[0] << "," << startingIndex[1] << "}";
//			std::cout << "{" << EndingIndex[0] << "," << EndingIndex[1] << "}";
//			std::cout << std::endl;
//		}
//		else if (DiagonalSearchUpDown(Userinput[i])) {
//			std::cout << "{" << startingIndex[0] << "," << startingIndex[1] << "}";
//			std::cout << "{" << EndingIndex[0] << "," << EndingIndex[1] << "}";
//			std::cout << std::endl;
//		}
//		else if (DiagonalSearchDownUP(Userinput[i])) {
//			std::cout << "{" << startingIndex[0] << "," << startingIndex[1] << "}";
//			std::cout << "{" << EndingIndex[0] << "," << EndingIndex[1] << "}";
//			std::cout << std::endl;
//		}
//		else if (non_diagonalSearchUpDown(Userinput[i])) {
//			std::cout << "{" << startingIndex[0] << "," << startingIndex[1] << "}";
//			std::cout << "{" << EndingIndex[0] << "," << EndingIndex[1] << "}";
//			std::cout << std::endl;
//		}
//		else if (non_diagonalSearchDownUp(Userinput[i])) {
//			//std::cout << "{" << startingIndex[0] << "," << startingIndex[1] << "}";
//			std::cout << "{" << EndingIndex[0] << "," << EndingIndex[1] << "}";
//			std::cout << std::endl;
//		}
//		else {
//			std::cout << "NOT FOUND" << std::endl;
//		}
//	}
//
//}
//
//int main() {
//
//	search a;
//	a.InputFromUser();
//	a.searchWords();
//}