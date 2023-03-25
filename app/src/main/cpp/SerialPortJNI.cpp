//
// Created by X on 3/25/2023.
//

#include <jni.h>
#include "ser.h"

static SerialPort* s_port;

extern "C" JNIEXPORT jboolean JNICALL
Java_com_harunkurtme_myapplication_SerialPort_serialopen(JNIEnv *env, jobject obj, jstring portName, jint baudRate) {
    if (s_port)
        return JNI_FALSE;

    const char* c_portName = env->GetStringUTFChars(portName, NULL);
    s_port = new SerialPort(c_portName, baudRate);
    bool result = s_port->openPort();
    env->ReleaseStringUTFChars(portName, c_portName);

    return result ? JNI_TRUE : JNI_FALSE;
}

extern "C" JNIEXPORT jboolean JNICALL Java_com_harunkurtme_myapplication_SerialPort_serialclose(JNIEnv *env, jobject obj) {
    if (!s_port)
        return JNI_FALSE;

    bool result = s_port->closePort();
    delete s_port;
    s_port = NULL;

    return result ? JNI_TRUE : JNI_FALSE;
}