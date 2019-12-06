package tapeapi;

public class MemOp {
    private MemOp() {}

    public static long NULLPTR = const_nullptr();

    public static native long create(int size);
    public static native void dispose(long ptr);

    private static native long const_nullptr();
}