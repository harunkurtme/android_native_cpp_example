LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := serial_port
LOCAL_SRC_FILES := ser.cpp
LOCAL_C_INCLUDES := $(LOCAL_PATH)/include
LOCAL_LDLIBS := -llog

include $(BUILD_SHARED_LIBRARY)