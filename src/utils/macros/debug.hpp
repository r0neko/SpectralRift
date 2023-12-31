#include <cassert>
#include <cstdio>

#ifdef ENGINE_TARGET_ANDROID
#include <android/log.h>
#endif

#define ASSERT_MSG(condition, message) assert(condition && message);

#ifndef DEBUG_MSG
#ifndef BUILD_RELEASE
#ifndef ENGINE_TARGET_ANDROID
#define DEBUG_MSG(...) \
    printf("[%s:%i] ", __FILE__, __LINE__); \
    printf(__VA_ARGS__);
#else
#define STRINGIZE_HELPER(x) #x
#define STRINGIZE(x) STRINGIZE_HELPER(x)
#define DEBUG_MSG(...) __android_log_print(ANDROID_LOG_DEBUG, "SpectralRift", "[" __FILE__ ":" STRINGIZE(__LINE__) "] " __VA_ARGS__);
#endif
#else
#define DEBUG_MSG
#endif
#endif