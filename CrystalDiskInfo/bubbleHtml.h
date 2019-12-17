#pragma once
#include <afxdialogex.h>


// bubbleHtml-Dialog

class bubbleHtml : public CDialogEx
{
	DECLARE_DYNAMIC(bubbleHtml)

public:
	bubbleHtml(CWnd* pParent = nullptr);   // Standardkonstruktor
	virtual ~bubbleHtml();

// Dialogfelddaten
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung

	DECLARE_MESSAGE_MAP()
};
