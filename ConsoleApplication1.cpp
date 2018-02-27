#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;


void Sort(int** mas, int a)
{
	bool exit = false;
	while (!exit) {
		exit = true;
		for (int i = 0; i < a-1; i++) {
			
				if (mas[i][1] > mas[i+1][1])
				{
					int tmp1 = 0;
					int tmp2 = 0;
					tmp1 = mas[i][0];
					tmp2 = mas[i][1];
					mas[i][0] = mas[i + 1][0];
					mas[i][1] = mas[i + 1][1];
					mas[i + 1][0] = tmp1;
					mas[i + 1][1] = tmp2;
					exit = false;
				}
			}
		}
	}



int main(int argc, char* argv[]) {


	ifstream b(argv[1]);
	
	char bufp[13];
	int count_p = 0;
	while (b.getline(bufp, 13)) { count_p++; }
	b.clear();
	b.seekg(0, ios::beg);

	int *arr_players = new int[count_p];
	for (int i = 0; i < count_p; i++) {
		b >> arr_players[i];
		b >> arr_players[i];
	}
	b.close();
	
	

	ifstream a(argv[2]);
	
	char buft[126];
	int count_t = 0;
	while (a.getline(buft, 126)) { count_t++; }
	a.clear();
	a.seekg(0, ios::beg);

	int **arr_team_rating = new int*[count_t];
	for (int i = 0; i < count_t; i++) {
		arr_team_rating[i] = new int[2];
		int team_rating = 0;
		int player_index = 0;
		a >> team_rating;
		team_rating = 0;
		for (int j = 0; j < 15; j++) {
			a >> player_index;
			team_rating += arr_players[player_index];
		}	
		arr_team_rating[i][0] = i;
		arr_team_rating[i][1] = team_rating;
	}
	a.close();

	

	Sort(arr_team_rating, count_t);


	
	ofstream c;
	c.open("pairs.txt", ios::trunc);
	for (int i = 0; i < count_t; i = i + 2) {
		c << arr_team_rating[i][0] << ' ';
		if (i + 1 >= count_t) { break; } 
		 c << arr_team_rating[i + 1][0] << ' ' << endl;
	}
	c.close();

	cout << "Completed" << endl;
	system("pause");
}




