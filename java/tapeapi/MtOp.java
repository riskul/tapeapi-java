package tapeapi;

public class MtOp {
    private MtOp() {}

    public static native int size();

    public static native void setMtOp(long ptr, short value);
    public static native void setMtCount(long ptr, int value);
}

