
// Simple_GameView.h : interface of the CSimple_GameView class
//

#pragma once


class CSimple_GameView : public CView
{
protected: // create from serialization only
	CSimple_GameView();
	DECLARE_DYNCREATE(CSimple_GameView)

// Attributes
public:
	CSimple_GameDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CSimple_GameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Simple_GameView.cpp
inline CSimple_GameDoc* CSimple_GameView::GetDocument() const
   { return reinterpret_cast<CSimple_GameDoc*>(m_pDocument); }
#endif

