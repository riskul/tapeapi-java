#include <tapeapi_MtOp.h>
#include <linux/mtio.h>
#include <stdlib.h>

jint Java_tapeapi_MtOp_size(JNIEnv *env, jclass clazz) {
    return sizeof(struct mtop);
}

void Java_tapeapi_MtOp_setMtOp(JNIEnv *env, jclass clazz, jlong ptr, jshort value) {
    ((struct mtop *) ptr)->mt_op = value;
}

void Java_tapeapi_MtOp_setMtCount(JNIEnv *env, jclass clazz, jlong ptr, jint value) {
    ((struct mtop *) ptr)->mt_count = value;
}
