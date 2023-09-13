/*'* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
'* Program name    : L1-3                                              *
'*                                                                     *
'* Written by      : Clarence Defiesta, Kenjustin Yabut, Allen Dadia   *
'*                                                                     *
'* Purpose         : Create an array of 10,000 integers and sort       *
'*                   the array with varying algorithms and time it     *
'* 					 then reload the arrays and list it in increasing  *
'* 					 and decreasing sequential order				   *
'*                                                                     *
'* Inputs          : None                                              *
'*                                                                     *
'* Outputs         : Display of sorting algorithms and the array       *
'* 					 before it was sorted and after. Show the time in  *
'* 					 microseconds									   *
'*                                                                     *
'* Calls           : No internal or external calls                     *
'*                                                                     *
'* Structure       : BEGIN                                             *
'*                        Straight line code no sub-processes          *
'*                   STOP                                              *
'*                        End of Program                               *
'*                                                                     *
'*---------------------------------------------------------------------*
'*                                                                     *
'* Collaboration: Youtube "Portfolio Courses" for help on sorting      *
'*							algorithms								   *
'*                                                                     *
'*---------------------------------------------------------------------*
'* Change Log:                                                         *
'*                         Revision                                    *
'*       Date    Changed  Rel Ver Mod Purpose                          *
'* 09/04/2023   cdefiesta 000.000.000 Initial release of program       *
*  09/04/2023   kyabut 000.000.000 start ch3SortTest.cpp               *
'* 09/05/2023   adadia 000.000.000 created initial arrays to sort      *
'* 09/05/2023   cdefiesta 000.000.000 created bubble sorting function  *
'* 09/06/2023   kyabut  000.000.000 created insertion sorting function *
'* 09/06/2023 cdefiesta 000.000.000 created selection sorting function *
'* 09/06/2023   adadia    000.000.000 fixed sorting array errors       *
'* 09/07/2023   cdefiesta 000.000.000 implemented timing functions     *
'* 09/07/2023   kyabut 000.000.000 coded ascending functions           *
'* 09/07/2023   adadia 000.000.000 coded descending functions          *
'* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;
const int LENGTH = 10000;


//create array of 10,000 random integers
int bubSortArr[LENGTH];
void makeArrayInt() {
	for (int i = 0; i < LENGTH; i++) {
		bubSortArr[i] = rand();
	}

}

//copy the array of random integers into 2 more arrays
int insSortArr[LENGTH];
int selSortArr[LENGTH];
void copyArr() {
	for (int i = 0; i < LENGTH; i++) {
		insSortArr[i] = bubSortArr[i];
		selSortArr[i] = bubSortArr[i];
	}
}



void bubbleSort() {
	//in the bubble sorting method, we move each value
	//to the right if it is bigger than the one consecutive
	//to it

	//performs bubble sorting
	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < LENGTH - 1; j++) {
			if (bubSortArr[j] > bubSortArr[j + 1]) {
				int temp = bubSortArr[j];
				bubSortArr[j] = bubSortArr[j + 1];
				bubSortArr[j + 1] = temp;
			}
		}
	}
}

void insertionSort() {
	//in the insertion sorting method
	//the current value of index is compared to
	//the value of the previous index, if it is smaller than
	//the previous index, the previous index takes its place
	//and the current value takes the previous index's place
	for (int x = 1; x < LENGTH; x++) {
		int j = x - 1;
		int temp = insSortArr[x];
		while (j >= 0 && temp < insSortArr[j])
		{
			insSortArr[j + 1] = insSortArr[j];
			j = j - 1;
		}
		insSortArr[j + 1] = temp;
	}
}

void selectionSort() {
	//in selection sorting method we compare the 
	//current value to the rest of the index values
	//and find the smallest value. It then takes the postion
	//of the current value and moves to the next index position and
	//repeats
	for (int i = 0; i < LENGTH - 1; i++) {
		int minVal = i;
		for (int j = i + 1; j < LENGTH; j++)
		{
			if (selSortArr[j] < selSortArr[minVal]) {
				minVal = j;
			}
		}
		if (minVal != i) {
			int temp = selSortArr[i];
			selSortArr[i] = selSortArr[minVal];
			selSortArr[minVal] = temp;
		}
	}

}

//creates a sequential array
void makeArrayIntSeq() {

	for (int i = 0; i < LENGTH; i++) {
		bubSortArr[i] = i;
	}
}


int main() {
	cout << "Clarence Defiesta Kenjustin Yabut Allen Dadia\t" << "L1_3 \t" << "L1-3.exe" << endl << endl;

	//regular sequential order
	makeArrayInt();
	copyArr();

	//bubble sort
	cout << "\nBubble Sort: ";
	cout << "\nBefore Sort: ";
	clock_t time_req;
	for (int i = 0; i < 12; i++) {
		cout << bubSortArr[i] << " ";
	}
	time_req = clock();//gets starting time

	bubbleSort();//call bubbleSort function

	time_req = clock() - time_req; //subtract to get the time interval

	cout << "\nAfter Sort: ";
	for (int i = 0; i < 12; i++) {
		cout << bubSortArr[i] << " ";
	}

	cout << "\nProcessing " << LENGTH << " elements with" <<
		"\nBubble Sort took ";
	cout << (float)time_req / CLOCKS_PER_SEC << " microseconds" << endl << endl;

	//insertion sort
	cout << "\nInsertion Sort: ";
	cout << "\nBefore Sort: ";
	for (int i = 0; i < 12; i++) {
		cout << insSortArr[i] << " ";
	}
	time_req = clock();
	insertionSort();//call insertionSort function

	time_req = clock() - time_req;

	cout << "\nAfter Sort: ";
	for (int i = 0; i < 12; i++) {
		cout << insSortArr[i] << " ";
	}

	cout << "\nProcessing " << LENGTH << " elements with" <<
		"\nInsertion Sort took ";
	cout << (float)time_req / CLOCKS_PER_SEC << " microseconds" << endl << endl;

	//selectionSort
	cout << "\nSelection Sort: ";
	cout << "\nBefore Sort: ";
	for (int i = 0; i < 12; i++) {
		cout << selSortArr[i] << " ";
	}
	time_req = clock();
	selectionSort();//call selection sort
	time_req = clock() - time_req;

	cout << "\nAfter Sort: ";
	for (int i = 0; i < 12; i++) {
		cout << selSortArr[i] << " ";
	}

	cout << "\nProcessing " << LENGTH << " elements with" <<
		"\nSelection Sort took ";
	cout << (float)time_req / CLOCKS_PER_SEC << " microseconds" << endl << endl;

	//ascending sequential order
	cout << "Now sorting in ASCENDING sequential order: " << endl;
	makeArrayIntSeq();
	copyArr();

	//bubble sort
	cout << "\nBubble Sort: ";
	cout << "\nBefore Sort: ";

	for (int i = 0; i < 12; i++) {
		cout << bubSortArr[i] << " ";
	}
	time_req = clock();//gets starting time

	bubbleSort();//call bubbleSort function

	time_req = clock() - time_req; //subtract to get the time interval

	cout << "\nAfter Sort: ";
	for (int i = 0; i < 12; i++) {
		cout << bubSortArr[i] << " ";
	}

	cout << "\nProcessing " << LENGTH << " elements with" <<
		"\nBubble Sort took ";
	cout << (float)time_req / CLOCKS_PER_SEC << " microseconds" << endl << endl;

	//Insertion Sort
	cout << "\nInsertion Sort: ";
	cout << "\nBefore Sort: ";
	for (int i = 0; i < 12; i++) {
		cout << insSortArr[i] << " ";
	}
	time_req = clock();
	insertionSort();//call insertionSort function

	time_req = clock() - time_req;

	cout << "\nAfter Sort: ";
	for (int i = 0; i < 12; i++) {
		cout << insSortArr[i] << " ";
	}

	cout << "\nProcessing " << LENGTH << " elements with" <<
		"\nInsertion Sort took ";
	cout << (float)time_req / CLOCKS_PER_SEC << " microseconds" << endl << endl;

	//selectionSort
	cout << "\nSelection Sort: ";
	cout << "\nBefore Sort: ";
	for (int i = 0; i < 12; i++) {
		cout << selSortArr[i] << " ";
	}
	time_req = clock();
	selectionSort();//call selection sort
	time_req = clock() - time_req;

	cout << "\nAfter Sort: ";
	for (int i = 0; i < 12; i++) {
		cout << selSortArr[i] << " ";
	}

	cout << "\nProcessing " << LENGTH << " elements with" <<
		"\nSelection Sort took ";
	cout << (float)time_req / CLOCKS_PER_SEC << " microseconds" << endl << endl;

	//descending sequential order
	cout << "Now sorting in DESCENDING sequential order: " << endl;

	cout << "\nBubble Sort: ";
	cout << "\nBefore Sort: ";
	for (int i = LENGTH - 1; i > 9988; i--) {
		cout << bubSortArr[i] << " ";
	}

	time_req = clock();//gets starting time
	//performs bubble sorting
	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < LENGTH - 1; j++) {
			if (bubSortArr[j] > bubSortArr[j + 1]) {
				int temp = bubSortArr[j];
				bubSortArr[j] = bubSortArr[j + 1];
				bubSortArr[j + 1] = temp;
			}
		}
	}
	time_req = clock() - time_req; //subtract to get the time interval

	cout << "\nAfter Sort: ";
	for (int i = 0; i < 12; i++) {
		cout << bubSortArr[i] << " ";
	}

	cout << "\nProcessing " << LENGTH << " elements with" <<
		"\nBubble Sort took ";
	cout << (float)time_req / CLOCKS_PER_SEC << " microseconds" << endl << endl;

	//insertion sort
	cout << "\nInsertion Sort: ";
	cout << "\nBefore Sort: ";
	for (int i = LENGTH - 1; i > 9988; i--) {
		cout << insSortArr[i] << " ";
	}
	time_req = clock();
	insertionSort();//call insertionSort function

	time_req = clock() - time_req;

	cout << "\nAfter Sort: ";
	for (int i = 0; i < 12; i++) {
		cout << insSortArr[i] << " ";
	}

	cout << "\nProcessing " << LENGTH << " elements with" <<
		"\nBubble Sort took ";
	cout << (float)time_req / CLOCKS_PER_SEC << " microseconds" << endl << endl;

	//selectionSort
	cout << "\nSelection Sort: ";
	cout << "\nBefore Sort: ";
	for (int i = 0; i < 12; i++) {
		cout << selSortArr[i] << " ";
	}
	time_req = clock();
	selectionSort();//call selection sort
	time_req = clock() - time_req;

	cout << "\nAfter Sort: ";
	for (int i = LENGTH - 1; i > 9988; i--) {
		cout << selSortArr[i] << " ";
	}

	cout << "\nProcessing " << LENGTH << " elements with" <<
		"\nSelection Sort took ";
	cout << (float)time_req / CLOCKS_PER_SEC << " microseconds" << endl << endl;
	return 0;

}