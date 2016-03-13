
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

void CSimple_GameView::OnDraw(CDC* /*pDC*/)
{
	CSimple_GameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

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


// CSimple_GameView message handlers
