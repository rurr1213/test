#pragma once
#include "perfTest.h"
#include "fileMgr.h"
#include "stats.h"

class CfileTest :
	public CperfTestBase
{
	CfileMgr m_fileMgr;
	int m_fileSize;
public:
	CfileTest() {
		setStatName((char*)"fileTests");
	};
	~CfileTest() {
		m_fileMgr.deleteFile();
	}
	bool createTestFile(int fileSizeMB);
	int testLoading(int fileSizeMB);
	bool testRamp(void);

	bool run(void);
	int getValue(void);
};

