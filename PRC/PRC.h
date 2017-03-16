
// PRC.h : main header file for the PRC application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CPRCApp:
// See PRC.cpp for the implementation of this class
//

class CPRCApp : public CWinApp
{
public:
	CPRCApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPRCApp theApp;
