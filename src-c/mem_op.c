#include <tapeapi_MemOp.h>

#include <jni.h>
#include <stdlib.h>

jlong Java_tapeapi_MemOp_create(JNIEnv *env, jclass clazz, jint size) {
    return (jlong) calloc(1, size);
}

void Java_tapeapi_MemOp_dispose(JNIEnv *env, jclass clazz, jlong ptr) {
    free((void *) ptr);
}

jlong Java_tapeapi_MemOp_const_1nullptr(JNIEnv *env, jclass clazz) {
    return (jlong) NULL;
}