
// SSESW-miniDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SSESW-mini.h"
#include "SSESW-miniDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CSSESWminiDlg �Ի���



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


// CSSESWminiDlg ��Ϣ�������

BOOL CSSESWminiDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	ModifyStyle(WS_THICKFRAME, 0, 0);   //��ֹ���ڱ��϶���С
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
	ComListInit();
	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CSSESWminiDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CSSESWminiDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CSSESWminiDlg::ComListInit()
{
	/*********���***********/
	int index = 0;
	m_sw.InsertString(index, L"Endnote");		index++;
	m_sw.InsertString(index, L"cmd");		index++;
	m_sw.InsertString(index, L"powershell");		index++;
	m_sw.InsertString(index, L"���±�");		index++;
	m_sw.InsertString(index, L"��ͼ��");		index++;
	m_sw.InsertString(index, L"д�ְ�");		index++;
	m_sw.InsertString(index, L"360����");		index++;
	m_sw.InsertString(index, L"PythonIDE");		index++;
	m_sw.InsertString(index, L"������");		index++;
	//m_sw.InsertString(index, L"");		index++;

	/***********��ҳ***********/
	index = 0;
	m_wp.InsertString(index, L"CSDN");		index++;
	m_wp.InsertString(index, L"�ٶȴ���");		index++;
	m_wp.InsertString(index, L"���еĹ����ʼ�");		index++;
	m_wp.InsertString(index, L"ͼ���");		index++;
	m_wp.InsertString(index, L"����");		index++;
	m_wp.InsertString(index, L"readfree");		index++;
	m_wp.InsertString(index, L"GitHub");		index++;
	m_wp.InsertString(index, L"YouTube");		index++;
	m_wp.InsertString(index, L"Halcon");		index++;
	m_wp.InsertString(index, L"���ŵ�");		index++;
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
