
// PRCView.cpp : implementation of the CPRCView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "PRC.h"
#endif

#include "PRCDoc.h"
#include "PRCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPRCView

IMPLEMENT_DYNCREATE(CPRCView, CView)

BEGIN_MESSAGE_MAP(CPRCView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CPRCView construction/destruction

CPRCView::CPRCView()
{
	// TODO: add construction code here

}

CPRCView::~CPRCView()
{
}

BOOL CPRCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CPRCView drawing

void CPRCView::OnDraw(CDC* /*pDC*/)
{
	CPRCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CPRCView printing

BOOL CPRCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPRCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPRCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CPRCView diagnostics

#ifdef _DEBUG
void CPRCView::AssertValid() const
{
	CView::AssertValid();
}

void CPRCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPRCDoc* CPRCView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPRCDoc)));
	return (CPRCDoc*)m_pDocument;
}
#endif //_DEBUG


// CPRCView message handlers
