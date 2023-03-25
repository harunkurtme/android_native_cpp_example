#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_harunkurtme_myapplication_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    std::string hello2 = "Hello from C++";
    std::string hello3 = " Hello from C++";
    std::string hello4 = "Hello from C++";
    return env->NewStringUTF(hello.append(hello3).c_str());
}