
// PRCView.h : interface of the CPRCView class
//

#pragma once


class CPRCView : public CView
{
protected: // create from serialization only
	CPRCView();
	DECLARE_DYNCREATE(CPRCView)

// Attributes
public:
	CPRCDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CPRCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PRCView.cpp
inline CPRCDoc* CPRCView::GetDocument() const
   { return reinterpret_cast<CPRCDoc*>(m_pDocument); }
#endif

