#pragma once

#include <afxdialogex.h>


// BubbleChart-Dialog

class BubbleChart : public CDialogEx
{
	DECLARE_DYNAMIC(BubbleChart)

public:
	BubbleChart(CWnd* pParent = nullptr);   // Standardkonstruktor
	virtual ~BubbleChart();

// Dialogfelddaten
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BUBBLE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung

	DECLARE_MESSAGE_MAP()
};
