
// SimuroSot5Dlg.h : header file
//

#pragma once

enum TeamColor { BLUE_TEAM = 1, YELLOW_TEAM };

enum PlayMode {
	PM_PlayOn = 0,           // ��������
	PM_FreeBall_LeftTop,     // ������������  1
	PM_FreeBall_LeftBot,     // ������������  2 
	PM_FreeBall_RightTop,    // ������������  3
	PM_FreeBall_RightBot,    // ������������  4
	PM_PlaceKick_Yellow,     // �ƶӿ���      5
	PM_PlaceKick_Blue,       // ���ӿ���      6
	PM_PenaltyKick_Yellow,   // �ƶӻ�õ���  7
	PM_PenaltyKick_Blue,     // ���ӻ�õ���  8
	PM_FreeKick_Yellow,      // �ƶ�������    9
	PM_FreeKick_Blue,        // ����������    10
	PM_GoalKick_Yellow,      // �ƶӻ������  11
	PM_GoalKick_Blue         // ���ӻ������  12
};

typedef struct
{
	double x, y, z;
} Vector3D;

typedef struct
{
	Vector3D pos;
	double rotation;
	double velocityLeft, velocityRight;
} Robot;

struct RefRobot
{
	Vector3D pos;
	double rotation;
	Vector3D vertex[4];
};


struct ReferData
{
	int xianbai;
	Robot Posxianbai[5];
	Robot Poshoubai[5];
	Vector3D Posball;
	PlayMode gameState;
	char blueTeamName[50];
	char yellowTeamName[50];
	int nBlueVPushTime;  // 2021
	int nYellowVPushTime;  // 2021
};


// CSimuroSot5Dlg dialog
class CSimuroSot5Dlg : public CDialogEx
{
// Construction
public:
	CSimuroSot5Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_SIMUROSOT5_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support	

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	LRESULT OnReceiveData(WPARAM wParam, LPARAM lParam);
	BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedBnStart();
	afx_msg void OnBnClickedBnPause();
	afx_msg void OnBnClickedBnClose();	

	ReferData m_data;
	bool work;
	int nPause;

	int nPastSecond;
	int nBlueGoals;
	int nYellowGoals;
	afx_msg void OnClose();
};
