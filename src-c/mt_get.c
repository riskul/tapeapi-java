#include <tapeapi_MtGet.h>
#include <linux/mtio.h>
#include <stdlib.h>

jlong Java_tapeapi_MtGet_getMtType(JNIEnv *env, jclass clazz, jlong ptr) {
    return ((struct mtget *) ptr)->mt_type;
}

jlong Java_tapeapi_MtGet_getMtResid(JNIEnv *env, jclass clazz, jlong ptr) {
    return ((struct mtget *) ptr)->mt_resid;
}

jlong Java_tapeapi_MtGet_getMtDsReg(JNIEnv *env, jclass clazz, jlong ptr) {
    return ((struct mtget *) ptr)->mt_dsreg;
}

jlong Java_tapeapi_MtGet_getMtGStat(JNIEnv *env, jclass clazz, jlong ptr) {
    return ((struct mtget *) ptr)->mt_gstat;
}

jlong Java_tapeapi_MtGet_getMtErReg(JNIEnv *env, jclass clazz, jlong ptr) {
    return ((struct mtget *) ptr)->mt_erreg;
}

jint Java_tapeapi_MtGet_getMtFileNo(JNIEnv *env, jclass clazz, jlong ptr) {
    return ((struct mtget *) ptr)->mt_fileno;
}

jint Java_tapeapi_MtGet_getMtBlkNo(JNIEnv *env, jclass clazz, jlong ptr) {
    return ((struct mtget *) ptr)->mt_blkno;
}

jint Java_tapeapi_MtGet_size(JNIEnv *env, jclass clazz) {
    return sizeof(struct mtget);
}
