#ifndef __SAKURA_IO_DEBUG_H__
#define __SAKURA_IO_DEBUG_H__


#if defined(SAKURA_DEBUG)
#define dbg(...) printf(__VA_ARGS__)
#define dbgln(...) DEBUG_PRINTF_LN(__VA_ARGS__, "\r\n")
#define DEBUG_PRINTF_LN(type, fmt, ...) printf(fmt "%s", __VA_ARGS__)
#else
#define dbg(...)
#define dbgln(...)
#endif

#endif //__SAKURA_IO_DEBUG_H__
