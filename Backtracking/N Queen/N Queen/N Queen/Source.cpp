#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int get_row(vector<string>& matrix, int col, int N)
{
	for (int i = 0; i < N; i++)
	{
		if (matrix[i][col] == 'Q')
			return i;
	}

	return -1;
}

bool is_safe(vector<string>& matrix, int N)
{
	vector<int> positions;

	for (int i = 0; i < N; i++)
	{
		int row = get_row(matrix, i, N);

		if (row >= 0)
			positions.push_back(row);
	}

	if (positions.size() <= 1)
		return true;

	for (int i = 1; i < positions.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (positions[i] == positions[j])
				return false;

			if (positions[i] + (j - i) == positions[j] || positions[i] + (i - j) == positions[j])
				return false;
		}
	}

	return true;
}


void NQueen(vector<string>& matrix, int column, int N, vector<vector<string>>& solutions)
{
	if (N < 4)
		return;

	if (column > N)
		return;

	else if (column == N)
	{
		solutions.push_back(matrix);
		return;
	}

	for (int i = 0; i < N; i++)
	{
		matrix[i][column] = 'Q';

		if(is_safe(matrix, N))
			NQueen(matrix, column + 1, N, solutions);

		matrix[i][column] = '.';
	}
}


int main()
{
	int N;
	printf("Insert N:");

	scanf("%d", &N);

	vector<string> matrix;

	vector<vector<string>> solutions;

	for (int i = 0; i < N; i++)
	{
		string s;

		for (int j = 0; j < N; j++)
			s.push_back('.');

		matrix.push_back(s);
	}

	NQueen(matrix, 0, N, solutions);

	printf("Here are all the solutions:\n\n");


	for (int i = 0; i < solutions.size(); i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%s\n", solutions[i][j].c_str());
		}

		printf("\n\n");
	}

	getchar();
	getchar();

	return 0;
}