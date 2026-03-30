#include <jni.h>
#include <string>
#include <algorithm>
#include <climits>
#include <android/log.h>

#define LOG_TAG "JNI_DEMO"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

// 1) Hello
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_jnidemo_MainActivity_helloFromJNI(
        JNIEnv* env,
        jobject) {

    return env->NewStringUTF("Hello from C++ via JNI !");
}

// 2) Factorial
extern "C"
JNIEXPORT jint JNICALL
Java_com_example_jnidemo_MainActivity_factorial(
        JNIEnv* env,
        jobject,
        jint n) {

    if (n < 0) return -1;

    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
        if (fact > INT_MAX) return -2;
    }

    return (jint) fact;
}

// 3) Reverse string
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_jnidemo_MainActivity_reverseString(
        JNIEnv* env,
        jobject,
        jstring input) {

    const char* str = env->GetStringUTFChars(input, 0);
    std::string s(str);
    env->ReleaseStringUTFChars(input, str);

    std::reverse(s.begin(), s.end());

    return env->NewStringUTF(s.c_str());
}

// 4) Sum array
extern "C"
JNIEXPORT jint JNICALL
Java_com_example_jnidemo_MainActivity_sumArray(
        JNIEnv* env,
        jobject,
        jintArray array) {

    jsize len = env->GetArrayLength(array);
    jint* elems = env->GetIntArrayElements(array, 0);

    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += elems[i];
    }

    env->ReleaseIntArrayElements(array, elems, 0);

    return sum;
}