#pragma once


class MainRaytracingProceduralGeometry
{
	HANDLE hThread = 0;
	HINSTANCE hInstance = 0;
public:
	bool run(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow);
	bool create(HINSTANCE hInstance);
	bool destroy(void);
	bool Do(void);

	static DWORD WINAPI staticDo(LPVOID lpParameter)
	{
		// The new thread will start here
		((MainRaytracingProceduralGeometry*)lpParameter)->Do();
		return 0;
	}
};