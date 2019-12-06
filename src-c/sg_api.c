#include <tapeapi_SgApi.h>

#include <scsi/sg_pt.h>
#include <scsi/sg_cmds_basic.h>
#include <jni.h>

jint Java_tapeapi_SgApi_openDevice(JNIEnv *env, jclass clazz, jstring deviceName, jint readonly, jint verbose) {
    const jchar *deviceNameString;
    jint result;
    deviceNameString = (*env)->GetStringChars(env, deviceName, JNI_FALSE);
    result = sg_cmds_open_device((const char *) deviceNameString, readonly, verbose);
    (*env)->ReleaseStringChars(env, deviceName, deviceNameString);
    return result;
}

jint Java_tapeapi_SgApi_closeDevice(JNIEnv *env, jclass clazz, jint deviceFd) {
    return sg_cmds_close_device(deviceFd);
}

jlong Java_tapeapi_SgApi_constructScsiPtObj(JNIEnv *env, jclass clazz) {
    return (jlong) construct_scsi_pt_obj();
}

void Java_tapeapi_SgApi_destructScsiPtObj(JNIEnv *env, jclass clazz, jlong ptr) {
    destruct_scsi_pt_obj((struct sg_pt_base *) ptr);
}

jint Java_tapeapi_SgApi_doScsiPt(JNIEnv *env, jclass clazz, long scsiPtObjPtr, jint deviceFd, jint timeoutSecs, jint verbose,
        jobject ra_cdb, jobject sense_b, jobject response) {
    void *ra_cdb_ptr;
    jlong ra_cdb_size;

    void *sense_b_ptr;
    jlong sense_b_size;

    void *response_ptr;
    jlong response_size;

    ra_cdb_ptr = (*env)->GetDirectBufferAddress(env, ra_cdb);
    ra_cdb_size = (*env)->GetDirectBufferCapacity(env, ra_cdb);
    set_scsi_pt_cdb((struct sg_pt_base *) scsiPtObjPtr, ra_cdb_ptr, ra_cdb_size);

    sense_b_ptr = (*env)->GetDirectBufferAddress(env, sense_b);
    sense_b_size = (*env)->GetDirectBufferCapacity(env, sense_b);
    set_scsi_pt_sense((struct sg_pt_base *) scsiPtObjPtr, sense_b_ptr, sense_b_size);

    response_ptr = (*env)->GetDirectBufferAddress(env, response);
    response_size = (*env)->GetDirectBufferCapacity(env, response);

    set_scsi_pt_data_in((struct sg_pt_base *) scsiPtObjPtr, response_ptr, response_size);
    return do_scsi_pt((struct sg_pt_base *) scsiPtObjPtr, deviceFd, timeoutSecs, verbose);
}
