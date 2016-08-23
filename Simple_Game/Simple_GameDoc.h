
// Simple_GameDoc.h : interface of the CSimple_GameDoc class
// Instance of the object game board encapsulated

#pragma once
#include "Simple_Game_Board.h"

class CSimple_GameDoc : public CDocument
{
protected: // create from serialization only
	CSimple_GameDoc();
	virtual ~CSimple_GameDoc();
	DECLARE_DYNCREATE(CSimple_GameDoc)

// Attributes
public:

// Operations
public:
	//function for accesing the game board
	COLORREF GetBoardSpace(int row, int col)
	{
		return m_board.GetBoardSpace(row, col);
		
	}
	void SetupBoard(void)
	{
		m_board.SetupBoard();
	}
	int GetWidth(void)
	{
		return m_board.GetWidth();
	}
	int GetHeight(void)
	{
		return m_board.GetHeight();
    }
	int GetColumns(void)
	{
		return m_board.GetColumns();
	}
	int GetRows(void)
	{
		return m_board.GetRows();
	}
	void DeleteBoard(void)
	{
		m_board.DeleteBoard();
	}
// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CSimple_GameDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	//Instance of the game Board
	Simple_Game_Board m_board;
// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
