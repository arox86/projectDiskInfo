// BubbleChart.cpp: Implementierungsdatei
//
#include "stdafx.h"  

#include "DiskInfo.h"
#include "BubbleChart.h"
#include "afxdialogex.h"


// BubbleChart-Dialog

IMPLEMENT_DYNAMIC(BubbleChart, CDialogEx)

BubbleChart::BubbleChart(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BUBBLE, pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

BubbleChart::~BubbleChart()
{
}

void BubbleChart::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(BubbleChart, CDialogEx)
END_MESSAGE_MAP()


// BubbleChart-Meldungshandler
