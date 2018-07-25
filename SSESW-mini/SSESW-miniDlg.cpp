
// SSESW-miniDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SSESW-mini.h"
#include "SSESW-miniDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CSSESWminiDlg 对话框



CSSESWminiDlg::CSSESWminiDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_SSESWMINI_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CSSESWminiDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_sw);
	DDX_Control(pDX, IDC_COMBO2, m_wp);
}

BEGIN_MESSAGE_MAP(CSSESWminiDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, &CSSESWminiDlg::OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CSSESWminiDlg::OnCbnSelchangeCombo2)
	ON_BN_CLICKED(IDOK, &CSSESWminiDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CSSESWminiDlg 消息处理程序

BOOL CSSESWminiDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	ModifyStyle(WS_THICKFRAME, 0, 0);   //禁止窗口被拖动大小
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	ComListInit();
	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CSSESWminiDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CSSESWminiDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CSSESWminiDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CSSESWminiDlg::ComListInit()
{
	/*********软件***********/
	int index = 0;
	m_sw.InsertString(index, L"Endnote");		index++;
	m_sw.InsertString(index, L"cmd");		index++;
	m_sw.InsertString(index, L"powershell");		index++;
	m_sw.InsertString(index, L"记事本");		index++;
	m_sw.InsertString(index, L"画图板");		index++;
	m_sw.InsertString(index, L"写字板");		index++;
	m_sw.InsertString(index, L"360极速");		index++;
	m_sw.InsertString(index, L"PythonIDE");		index++;
	m_sw.InsertString(index, L"计算器");		index++;
	//m_sw.InsertString(index, L"");		index++;

	/***********网页***********/
	index = 0;
	m_wp.InsertString(index, L"CSDN");		index++;
	m_wp.InsertString(index, L"百度传课");		index++;
	m_wp.InsertString(index, L"大佬的工作笔记");		index++;
	m_wp.InsertString(index, L"图书馆");		index++;
	m_wp.InsertString(index, L"邮箱");		index++;
	m_wp.InsertString(index, L"readfree");		index++;
	m_wp.InsertString(index, L"GitHub");		index++;
	m_wp.InsertString(index, L"YouTube");		index++;
	m_wp.InsertString(index, L"Halcon");		index++;
	m_wp.InsertString(index, L"朝闻道");		index++;
	m_wp.InsertString(index, L"Concurrency Runtime");		index++;
}

void CSSESWminiDlg::OnCbnSelchangeCombo1()
{
	int nIndex = m_sw.GetCurSel();
	switch (nIndex)
	{
	case 0: program = L"F:\\Program Files (x86)\\EndnoteX8\\EndNote.exe ";		break;
	case 1: program = L"cmd";		break;
	case 2: program = L"powershell";		break;
	case 3: program = L"notepad";		break;
	case 4: program = L"mspaint";		break;
	case 5: program = L"write";		break;
	case 6: program = L"C:\\Users\\Catlin Cao\\AppData\\Local\\360Chrome\\Chrome\\Application\\360chrome.exe";		break;
	case 7: program = L"C:\\Users\\Catlin Cao\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Python 3.6\\IDLE (Python 3.6 64-bit)";		break;
	case 8: program = L"calc";		break;
	default: program = NULL;		break;
	}
	SetDlgItemText(IDC_COMBO2, L" ");
}


void CSSESWminiDlg::OnCbnSelchangeCombo2()
{
	int nIndex = m_wp.GetCurSel();
	switch (nIndex)
	{
	case 0: program = L"https://blog.csdn.net\/ruibin_cao";		break;
	case 1: program = L"https://chuanke.baidu.com\/v1760453-135963-593956.html";		break;
	case 2: program = L"https://blog.csdn.net/app_12062011";		break;
	case 3: program = L"http://www.lib.hust.edu.cn/";		break;
	case 4: program = L"https://mail.hust.edu.cn/";		break;
	case 5: program = L"http://readfree.me/";		break;
	case 6: program = L"https://github.com/";		break;
	case 7: program = L"https://www.youtube.com/";		break;
	case 8: program = L"https://51halcon.com/forum.php";		break;
	case 9: program = L"http://www.cnblogs.com/findumars/";		break;
	case 10: program = L"https://docs.microsoft.com/en-us/previous-versions/visualstudio/visual-studio-2013/dd504870(v=vs.120)";		break;
	default: program = NULL;		break;
	}
	SetDlgItemText(IDC_COMBO1, L" ");
}


void CSSESWminiDlg::OnBnClickedOk()
{
	ShellExecute(NULL, L"open", program, NULL, L"E:\\", SW_SHOWNORMAL);
	program = L"E:\\";
	SetDlgItemText(IDC_COMBO1, L" ");
	SetDlgItemText(IDC_COMBO2, program);
}
