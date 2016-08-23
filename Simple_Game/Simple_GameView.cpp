
// Simple_GameView.cpp : implementation of the CSimple_GameView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Simple_Game.h"
#endif

#include "Simple_GameDoc.h"
#include "Simple_GameView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSimple_GameView

IMPLEMENT_DYNCREATE(CSimple_GameView, CView)

BEGIN_MESSAGE_MAP(CSimple_GameView, CView)
END_MESSAGE_MAP()

// CSimple_GameView construction/destruction

CSimple_GameView::CSimple_GameView()
{
	// TODO: add construction code here

}

CSimple_GameView::~CSimple_GameView()
{
}

BOOL CSimple_GameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CSimple_GameView drawing

void CSimple_GameView::OnDraw(CDC* pDC)
{
	CSimple_GameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	//Save the current satate of the device context
	int nDCSave = pDC->SaveDC();
	//Get the client rectangule
	CRect rcClient;
	GetClientRect(&rcClient);
	// Get the background color of the board
	COLORREF clr = pDoc->GetBoardSpace(-1, -1);
	// Draw the background first
	pDC->FillSolidRect(&rcClient, clr);
	//Create the brush for drawing
	CBrush br;
	br.CreateStockObject(HOLLOW_BRUSH);
	CBrush* pbrOld = pDC->SelectObject(&br);
	//Draw the squares
	for (int row = 0; row < pDoc->GetRows(); row++)
	{
		for (int col = 0; col < pDoc->GetColumns(); col++)
		{	//Get the color for this board space
			CRect rcBlock;
			rcBlock.top = row * pDoc->GetHeight();
			rcBlock.left = col* pDoc->GetWidth();
			rcBlock.right = rcBlock.left + pDoc->GetWidth();
			rcBlock.bottom = rcBlock.top + pDoc->GetHeight();
			// Fill in the block with the correct color;
			pDC->FillSolidRect(&rcBlock, clr);
			//Draw the block outline
			pDC->Rectangle(&rcBlock);
		}
	}
	// Restore the device context settings
	pDC->RestoreDC(nDCSave);
	br.DeleteObject();
	// TODO: add draw code for native data here
}


// CSimple_GameView diagnostics

#ifdef _DEBUG
void CSimple_GameView::AssertValid() const
{
	CView::AssertValid();
}

void CSimple_GameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSimple_GameDoc* CSimple_GameView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSimple_GameDoc)));
	return (CSimple_GameDoc*)m_pDocument;
}
#endif //_DEBUG
void CSimple_GameView::OnInitialUpdate()
{
	CView::OnInitialUpdate;
	//resize window
	ResizeWindow();
}
// CSimple_GameView message handlers
void CSimple_GameView::ResizeWindow()
{
	//First get a pointer to the document
	CSimple_GameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	//Get the size of the client area and the window 
	CRect rcClient, rcWindow;
	GetClientRect(&rcClient);
	GetParentFrame()->GetWindowRect(&rcWindow);
	// Calculate the difference
	int nWidthDiff = rcWindow.Width() - rcClient.Width();
	int nHeightDiff = rcWindow.Height() - rcClient.Height();
	// Change the Window size based on the size of the game board
	rcWindow.right = rcWindow.left + pDoc->GetWidth() * pDoc->GetColumns() + nWidthDiff;
	rcWindow.bottom = rcWindow.top + pDoc->GetHeight() * pDoc->GetRows() + nHeightDiff;
	// The MoveWindow function resizes the frame window
	GetParentFrame()->MoveWindow(&rcWindow);
}