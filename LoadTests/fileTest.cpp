#include "fileMgr.h"
#include "timing.h"
#include "stats.h"
#include "fileTest.h"

bool CfileTest::createTestFile(int fileSizeMB) {
	m_fileSize = 1024 * 1024;
	m_fileSize *= fileSizeMB;
	m_fileMgr.setName((char*) "fileTest.dat");
	m_fileMgr.deleteFile();
	if (!m_fileMgr.create(m_fileSize)) {
		LOG(L_ERROR, "Failed to create File");
		return false;
	}
	return true;
};

int CfileTest::testLoading(int fileSizeMB) {
	if (!createTestFile(fileSizeMB)) return 0;
	CTiming t;
	CstatSet statSet;
	void* pbuffer = malloc(m_fileSize);
	for (int i = 0; i < 50; i++) {
		t.start();
		bool loaded = m_fileMgr.load(pbuffer, m_fileSize);
		t.end();
		statSet.add(i, t.getElapsedTimeMilliSecs());
		if (!loaded) {
			LOG(L_ERROR, "Failed to load file");
		}
	}
	if (pbuffer) free(pbuffer);
	int avg = statSet.getAvg();
	m_stats.add(getTime(), avg);
	LOG(L_PRINT, "Testing %d MB - %d mSecs | ", fileSizeMB, (int)(avg));
	statSet.printStats();
	return statSet.getAvg();
};

bool CfileTest::testRamp(void) {
	for (int i = 10; i <= 30; i += 10) {
		testLoading(i);
	}
	m_stats.printAll();
	return true;
};

bool CfileTest::run(void) {
	LOGNAME("CfileMgr.run");
	CTiming t, t2;
	testRamp();
	return true;
};