// bubbleHtml.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "DiskInfo.h"
#include "bubbleHtml.h"
#include "afxdialogex.h"


// bubbleHtml-Dialog

IMPLEMENT_DYNAMIC(bubbleHtml, CDialogEx)

bubbleHtml::bubbleHtml(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

bubbleHtml::~bubbleHtml()
{
}

void bubbleHtml::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(bubbleHtml, CDialogEx)
END_MESSAGE_MAP()


// bubbleHtml-Meldungshandler
