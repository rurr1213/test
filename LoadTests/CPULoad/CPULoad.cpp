// CPULoad.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <assert.h>
#include <list>

static const long MEG = 1024 * 1024;
static const long GIG = MEG * 1024L;

class MemTest {
    class Buffer {
    public:
        void* pstart = 0;
        uint64_t size = 0;
        Buffer(uint64_t size) {
            pstart = malloc((size_t)size);
            assert(pstart != 0);
        }
        ~Buffer(void) {
            if (pstart) {
                free(pstart);
            }
        }
        void stride(long numSteps) {
            if (!pstart) return;
            char* pmemEnd = (char*)((char*)pstart + size);
            uint64_t stepSize = size / numSteps;
            for (char* ploc = (char*)pstart; ploc < pmemEnd; ploc += stepSize) {
                *ploc = *ploc + 1;
            }
        }
    };
    class LargeMem {
        std::list<Buffer*> bufferList;
    public:
        LargeMem(uint64_t _size) {
            int64_t size = _size;
            while (size > 0) {
                int64_t allocSize = size;
                if (allocSize > GIG) allocSize = GIG;
                Buffer* pbuf = new Buffer(allocSize);
                assert(pbuf);
                bufferList.push_back(pbuf);
                size -= allocSize;
            }
        }
        void stride(long numSteps) {
            for (auto item : bufferList) {
                if (item) item->stride(numSteps);
            }
        }
        ~LargeMem() {
            for (auto item : bufferList) {
                if (item) delete item;
            }
        }
    };
public:

    LargeMem largeMem;
    MemTest(uint64_t _size) : largeMem(_size) {
    }
    ~MemTest(void) {
    }
    void stride(long numSteps) {
        largeMem.stride(numSteps);
    }
};

int main()
{
    std::cout << "Hello World!\n";

    for (int i = 0; i < 1000000; i++) {
        std::cout << "s";
        uint64_t size = MEG * 1000LL * 2LL;
        MemTest* pmemTest = new MemTest(size);
      //  pmemTest->walk();
        pmemTest->stride(10);
        delete pmemTest;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
