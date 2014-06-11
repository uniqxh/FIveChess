#if !defined(AFX_SET_DLG_H__9AE9D03F_BA12_47EF_A8E6_C0E42324F443__INCLUDED_)
#define AFX_SET_DLG_H__9AE9D03F_BA12_47EF_A8E6_C0E42324F443__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// set_dlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// set_dlg dialog

class set_dlg : public CDialog
{
// Construction
public:
	CString m_host_ip;
	BOOL m_is_host;
	set_dlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(set_dlg)
	enum { IDD = IDD_set_dlg };
	CIPAddressCtrl	m_ip;
	CString	m_port;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(set_dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(set_dlg)
	virtual BOOL OnInitDialog();
	afx_msg void Onhost();
	afx_msg void Onclient();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SET_DLG_H__9AE9D03F_BA12_47EF_A8E6_C0E42324F443__INCLUDED_)
