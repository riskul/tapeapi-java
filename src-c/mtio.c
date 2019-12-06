#include <tapeapi_Mtio.h>

#include <sys/ioctl.h>
#include <linux/mtio.h>
#include <errno.h>


#include <jni.h>

jint Java_tapeapi_Mtio_ioctl(JNIEnv *env, jclass clazz, jint fd, jlong request, jlong ptr) {
    return ioctl(fd, request, ptr);
}

jint Java_tapeapi_Mtio_errno(JNIEnv *env, jclass clazz) {
    return errno;
}

jlong Java_tapeapi_Mtio_const_1mtioctop_1get(JNIEnv *env, jclass clazz) {
    return (jlong) MTIOCTOP;
}

jlong Java_tapeapi_Mtio_const_1mtioc_1get(JNIEnv *env, jclass clazz) {
    return (jlong) MTIOCGET;
}