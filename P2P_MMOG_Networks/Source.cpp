//// February 2006 using excellent code::blocks IDE with mingw
//// C++ Code for changing colors of text in the console window
//#include <iostream>
//#include <windows.h>
//
//using namespace std;
//
//int main()
//{
//
//	HANDLE hConsole;
//	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//
//	// Use the three primary colors for mixing any other color.
//	// Use FOREGROUND_INTENSITY for brighter colors.
//	SetConsoleTextAttribute
//	(hConsole, FOREGROUND_GREEN );
//	cout << "Bright red text\n";
//
//	SetConsoleTextAttribute
//	(hConsole, FOREGROUND_BLUE );
//	cout << "Bright blue text\n";
//
//	SetConsoleTextAttribute
//	(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
//	cout << "Back to normal white text\n";
//
//	// Wait for user pressing key before exiting
//	// Gives them a chance to see the output
//	cout << "\n\nPress any key to exit program.....";
//	cin.get();
//
//	return 0;
//}
// color your text in Windows console mode
// colors are 0=black 1=blue 2=green and so on to 15=white  
// colorattribute = foreground + background * 16
// to get red text on yellow use 4 + 14*16 = 228
// light red on yellow would be 12 + 14*16 = 236
// a Dev-C++ tested console application by  vegaseat  07nov2004

#include <iostream>
#include <windows.h>   // WinApi header

using namespace std;    // std::cout, std::cin

int main()
{
	HANDLE  hConsole;
	int k;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << 0 << " I want to be nice today!" << endl;

	// you can loop k higher to see more color choices
	for (k = 1; k < 16; k++)
	{
		// pick the colorattribute k you want
		SetConsoleTextAttribute(hConsole, k);
		cout << k << " I want to be nice today!" << endl;
	}

	system("pause");
	return 0;
}