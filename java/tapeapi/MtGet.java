package tapeapi;

public class MtGet {
    private MtGet() {}
    public static native long getMtType(long ptr);
    public static native long getMtResid(long ptr);
    public static native long getMtDsReg(long ptr);
    public static native long getMtGStat(long ptr);
    public static native long getMtErReg(long ptr);
    public static native int getMtFileNo(long ptr);
    public static native int getMtBlkNo(long ptr);
    public static native int size();
}