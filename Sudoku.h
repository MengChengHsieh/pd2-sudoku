#include <iostream>
#include <vector>
using namespace std;

class Map {

	public:
		Map();
		int getElement(int index);
		void setElement(int index, int value);
		vector<int> check_only(int zero);
		int getFirstZeroIndex();
		bool isCorrect();
		static const int sudokuSize = 144;

	private:
		bool checkUnity(int arr[]);
		int map[sudokuSize];
};

class Sudoku {

	public:
		Sudoku();
		int getAnswer(Map question, Map & answer);
		int GQ0(int arr[]);
		void Solve();
		void ReadIn();	
		int GiveQuestion();
		Map question;
		Map answer;
		static const int sudokuSize = 144;

	private:
		int count, init_map[sudokuSize];

};

