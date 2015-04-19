#include "Sudoku.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;

Sudoku::Sudoku()
{
	count = 0;
}
int Sudoku::getAnswer(Map question, Map & answer)
{
	int firstZero = 0; 
	vector<int>num_psb;
	firstZero = question.getFirstZeroIndex();

	if(firstZero == -1)
	{ // end condition
		if(question.isCorrect())
		{
			answer = question;
			count += 1;
			if(count == 2)
				return 2;
			return 0;		
		}

		else
			return 0;
	}


	else
	{  num_psb = question.check_only(firstZero);

		for(int num=0; num<num_psb.size(); ++num)
		{ 
			//cout << num_psb.at(num) << endl;
			question.setElement(firstZero, num_psb.at(num)+1);

			if(getAnswer(question, answer) >= 1)
			{
				if(count ==2)
					return 2;
				else if(count == 1)
					return 0;
			}

		}
		return 0;
	}
}
int Sudoku::GQ0(int arr[])
{	
	int r[9]={0,0,0,0,0,0,0,0,0};
	for(int y=0;y<9;++y){
		r[y]=arr[y];
	}

	int init_map[144]={'i','g','h','c','a','b','f','d','e','z','z','z','c','a','b','f','d','e','i','g','h','z','z','z','f','d','e','i','g','h','c','a','b','z','z','z','g','h','i','a','b','c','z','z','z','d','e','f','a','b','c','d','e','f','z','z','z','g','h','i','d','e','f','g','h','i','z','z','z','a','b','c','h','i','g','z','z','z','d','e','f','c','a','b','b','c','a','z','z','z','h','g','i','f','d','e','e','f','d','z','z','z','a','b','c','i','g','h','z','z','z','b','c','a','e','f','d','h','i','g','z','z','z','e','f','d','h','i','g','b','c','a','z','z','z','h','i','g','b','c','a','e','f','d'};

	for(int y=0;y<144;++y){
		switch(init_map[y]){
			case 'a':
				init_map[y]=r[0];
				break;
			case 'b':
				init_map[y]=r[1];
				break;
			case 'c':
				init_map[y]=r[2];
				break;
			case 'd':
				init_map[y]=r[3];
				break;
			case 'e':
				init_map[y]=r[4];
				break;
			case 'f':
				init_map[y]=r[5];
				break;
			case 'g':
				init_map[y]=r[6];
				break;
			case 'h':
				init_map[y]=r[7];
				break;
			case 'i':
				init_map[y]=r[8];
				break;
			case 'z':
				init_map[y]= -1;
				break;
			default:
				cout<<"fault"<<endl;
				break;
		}
	}
	init_map[3]=init_map[4]=init_map[143]=init_map[141]=init_map[135]=init_map[18]=init_map[13]=init_map[46]=init_map[63]=0;

	for(int i=0;i<144;++i){
		if(i%12==11){
			cout<< init_map[i]<<endl;
		}else{
			cout<< init_map[i]<<" ";
		}
	}

}

int Sudoku::GiveQuestion() 
{ 
	int mode;
	srand(time(NULL));
	mode = rand()%3;

	int n = 9;
	int cnt, num, r[9];
	int find;
	srand(time(NULL));
	cnt = 0;
	while(cnt < n){
		num = rand()%9+1;
		find = 0;
		for(int i = 0;i<cnt;++i){
			if(r[i]==num){ find=1; break;}
		}
		if(find==0){ 
			r[cnt]=num; ++cnt;
		}
	}
	/*for(int i = 0;i<n;++i){
	 * 		cout<<r[i]<<" ";
	 * 			}*/

	/*switch(mode){
	 * 		case 0:
	 * 					GQ0(r);
	 * 								break;
	 * 										case 1:
	 * 													GQ1(r);
	 * 																break;
	 * 																		case 2:
	 * 																					GQ2(r);
	 * 																								break;
	 * 																										default:
	 * 																													cout << "fault"<<endl;
	 * 																																break;
	 * 																																	}*/
	GQ0(r);

}


void Sudoku::ReadIn()
{ 
	int num;
	int j = 0;
	//ifstream infile("out.txt",ios::in);
	for(int i=0;i<144;++i) // read in question
	{
		cin >> num;

		//infile >> num;
/*cout << num << " ";
if(i%12 == 11)
	cout << endl;*/
		question.setElement(i, num);
	}

}

void Sudoku::Solve()
{
	int solution;
	solution = getAnswer(question, answer);

	if(solution == 0 && !answer.isCorrect()) {
		cout << "0\n";



	}
	else if(solution == 2)
		cout << "2\n";

	else
	{
		cout << "1\n";
		for(int i=0; i<144; i++)
		{
			cout << answer.getElement(i) << " ";
			if(i%12==11)
				cout << endl;
		}
	}

}


Map::Map()
{
	for(int i=0 ; i<sudokuSize ; ++i)
		map[i] = 0;
}

int Map::getElement(int index)
{
	return map[index];
}

bool Map::checkUnity(int arr[])
{
	int arr_unity[12]; // counters
	//printf("%d\n",sizeof(arr_unity));
	//if(sizeof(arr)<10)
	int minus = 0;
	for(int i=0; i<12; ++i)
		arr_unity[i] = 0; // initialize
	for(int i=0; i<12; ++i){
		if(arr[i] == -1 && minus < 3){
			++minus;
			++arr_unity[8+minus];
		}
		else if(arr[i] == -1 && minus >= 3)
			++minus;
		else if(arr[i] == -2)
			++arr_unity[i];
		else	
			++arr_unity[arr[i]-1];
		//
	}
	/*	
		for(int i=0; i<144; i++)
		{
		cout << map[i] << " ";
		if(i%12==11)
		cout << endl;
		}*/
	for(int i=0; i<12; ++i){
		//printf("%d\n",arr[i]);
		if(arr_unity[i] != 1 && minus != 9){
			//printf("%d\n",i);
			//printf("fuck\n");
			return false;
			//
		}
	}
	return true;
}


bool Map::isCorrect()
{
	bool check_result;
	int check_arr[12];
	//int ch_arr_cell[9];
	int location;
	for(int j =0; j< 12; ++j)
		check_arr[j] = -2;
	for(int i=0; i<144; i+=12) // check rows
	{
		for(int j=0; j<12; ++j)

			check_arr[j] = map[i+j];

		check_result = checkUnity(check_arr);
		if(check_result == false)
			return false;
	}
	for(int i=0; i<12; ++i) // check columns
	{
		for(int j=0; j<12; ++j)

			check_arr[j] = map[i+12*j];

		check_result = checkUnity(check_arr);
		if(check_result == false)
			return false;
	}

	for(int i=0; i<16; ++i) // check cells
	{
		for(int j =9; j< 12; ++j)
			check_arr[j] = -2;
		for(int j=0; j<9; ++j)
		{

			location = 36*(i/4) + 3*(i%4) + 12*(j/3) + (j%3);

			check_arr[j] = map[location];
		}

		check_result = checkUnity(check_arr);
		if(check_result == false)
			return false;
	}
	return true;
}

vector<int>Map::check_only(int zero)
{int arr_exist[12];
	vector<int>arr_return;
	int row, col, cell, area_i, num = 0, num1 = 0, num2 = 0;
	for(int i=0; i<12 ; ++i)
		arr_exist[i] = 0;

	row = zero/12;
	col = zero%12;
	area_i = (col/3) + 4*(row/3);
	for(int j=0; j<12; ++j)
	{	
		if(map[row*12+j] != 0 && map[row*12+j] != -1)
			arr_exist[map[row*12+j]-1] = 1; 
		else if(map[row*12+j] == -1){
			++num1	;
			arr_exist[8+num1] = 1;
		}
		if(map[col+j*12] != 0 && map[col+j*12] != -1)
			arr_exist[map[col+j*12]-1] = 1;
		else if(map[col+j*12] == -1){
			++num2;
			arr_exist[8+num2] = 1;
		}


		if(j<9){	
			cell = 36*(area_i/4) + 3*(area_i%4) + 12*(j/3) + (j%3);	

			if(map[cell] != 0 && map[cell] != -1)  
				arr_exist[map[cell]-1] = 1;
			else if(map[cell] == -1 && num<3){
				num+=1;
				arr_exist[8+num] = 1;
			}
			else if(num>=3)
				++num;

		}
	}
	for(int i=0; i<12 ;++i){
		if(arr_exist[i] == 0){
			arr_return.push_back(i) ;
		}
	}

	return arr_return;
}



void Map::setElement(int index, int value)
{
	map[index] = value;
	//cout << map[index] << endl;

}

int Map::getFirstZeroIndex()
{
	for(int i=0;i<sudokuSize;++i){
		if(map[i] == 0)
			return i;

	}
	return -1;
}

