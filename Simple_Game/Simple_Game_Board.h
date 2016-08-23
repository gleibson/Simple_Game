#pragma once
class Simple_Game_Board
{
public:
	Simple_Game_Board(void); /*Default Constructor*/
	~Simple_Game_Board(void); /*Destructor*/
	
	void SetupBoard(void); /*Function to randomly setup the board*/
	
	COLORREF GetBoardSpace(int row, int col); /*Get color at a particular location */
	
	/* Accessor functions to get board size information*/
	int GetWidth(void) const 
	{ 
		return m_nWidth; 
	} 
	int GetHeight(void) const 
	{ 
		return m_nHeight; 
	}
	int GetColumns(void) const 
	{
		return m_nColumns; 
	}
	int GetRows(void) const 
	{ 
		return m_nRows; 
	}
	/*Function to create the board and allocate memory*/
	void DeleteBoard(void);

private:
	void CreateBoard(void); /* Function to create the board and allocate memory*/
	int** m_arrBoard; /*2D array pointer*/
	COLORREF m_arrColors[4];  /*List of colors, 0 is background and 1-3 are piece colors*/
	/* Board size information */
	int m_nColumns;
	int m_nRows;
	int m_nHeight;
	int m_nWidth;

};

