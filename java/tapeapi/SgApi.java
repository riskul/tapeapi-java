package tapeapi;

import java.nio.ByteBuffer;

public class SgApi {
    private SgApi() {}

    public static final int SCSI_PT_DO_START_OK  = 0;
    public static final int SCSI_PT_DO_BAD_PARAMS  = 1;
    public static final int SCSI_PT_DO_TIMEOUT  = 2;


    public static native int openDevice(String deviceName, int readonly, int verbose);
    public static native int closeDevice(int deviceFd);

    public static native long constructScsiPtObj();
    public static native void destructScsiPtObj(long ptr);


    public static native int doScsiPt(long scsiPtObjPtr, int deviceFd, int timeoutSecs, int verbose,
    ByteBuffer ra_cdb, ByteBuffer sense_b, ByteBuffer resp);
}