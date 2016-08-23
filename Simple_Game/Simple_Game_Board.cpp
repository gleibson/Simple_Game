#include "stdafx.h"
#include "Simple_Game_Board.h"


Simple_Game_Board::Simple_Game_Board(void) : m_arrBoard(NULL), m_nColumns(15), m_nRows(15), m_nHeight(35), m_nWidth(35)
{
	m_arrColors[0] = RGB(0, 0, 0);
	m_arrColors[1] = RGB(255, 0, 0);
	m_arrColors[2] = RGB(255, 255, 64);
	m_arrColors[3] = RGB(0, 0, 255);
}


Simple_Game_Board::~Simple_Game_Board()
{
	DeleteBoard(); //Simply delete the board
}

void Simple_Game_Board::SetupBoard(void)
{
	if (m_arrBoard == NULL) //Create the Board if needed
		CreateBoard();

	for (int row = 0; row < m_nColumns; row++) //Randomly set each square to a color
		for (int col; col < m_nColumns; col++)
			m_arrBoard[row][col] = (rand() % 3) + 1;
}


COLORREF Simple_Game_Board::GetBoardSpace(int row, int col)
{
	if (row < 0 || row >= m_nRows || col < 0 || col >= m_nColumns) //Check the bounds of the array
		return m_arrColors[0];
	return m_arrColors[m_arrBoard[row][col]];
}

void Simple_Game_Board::DeleteBoard(void)
{
	if (m_arrBoard != NULL) //Don't delete de NULL Board
	{
		for (int row = 0; row < m_nRows; row++)
		{
			if (m_arrBoard[row] != NULL)
			{
				delete[] m_arrBoard[row]; //Delete each row first
				m_arrBoard[row] = NULL;
			}
		}

		delete[] m_arrBoard; //Finaly delete the array of rows
		m_arrBoard = NULL;
	}
	
}

void Simple_Game_Board::CreateBoard(void)
{
	if (m_arrBoard != NULL) //If there is already a board, delete it
		DeleteBoard();
	m_arrBoard = new int*[m_nRows]; //Create the array of rows
	for (int row = 0; row < m_nRows; row++); //Create each row
	{
		m_arrBoard[row] = new int[m_nColumns]; 
		
		for (int col = 0; col < m_nColumns; col++)//set each square to be empty
			m_arrBoard[row][col] = 0;
	}
}