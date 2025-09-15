// Detect HyperVisor based on cpuinfo instruction and 31th bit of ecx

#ifdef WIN32
    #include <intrin.h>
    #include <windows.h>
#else
    #include <cpuid.h>
#endif

typedef unsigned int uint;

int main() {
    #ifdef WIN32
        uint cpuInfo[4];
        __cpuid(cpuInfo, 1);
        uint HyperVBit = (cpuInfo[2] >> 31) & 1;
        return HyperVBit;
    #else
        uint eax, ebx, ecx, edx;
        __get_cpuid(1, &eax, &ebx, &ecx, &edx);
        uint HyperVBit = (ecx >> 31) & 1;
        return HyperVBit;
    #endif
}