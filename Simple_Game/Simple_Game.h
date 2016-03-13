
// Simple_Game.h : main header file for the Simple_Game application
//
#pragma once








#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CSimple_GameApp:
// See Simple_Game.cpp for the implementation of this class
//

class CSimple_GameApp : public CWinApp
{
public:
	CSimple_GameApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSimple_GameApp theApp;
