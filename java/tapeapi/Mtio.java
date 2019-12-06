package tapeapi;

import java.nio.ByteBuffer;

public class Mtio {
    private Mtio() {}
    // #define MTRESET 0	/* +reset drive in case of problems */
    public static final long MTRESET = 0;
    // #define MTFSF	1	/* forward space over FileMark, position at first record of next file */
    public static final long MTFSF = 1;

    // #define MTWEOF	5	/* write an end-of-file record (mark) */
    public static final long MTWEOF = 5;
    // #define MTREW	6	/* rewind */
    public static final long MTREW = 6;
    // #define MTOFFL	7	/* rewind and put the drive offline (eject?) */
    public static final long MTOFFL = 7;
    // #define MTEOM	12	/* goto end of recorded media (for appending files).
    //			 * MTEOM positions after the last FM, ready for
    //			 * appending another file.
    //			 */
    public static final long MTEOM = 12;
    //#define MTERASE 13	/* erase tape -- be careful! */
    public static final long MTERASE = 13;


    //     #define MT_ISSCSI1		0x71	/* Generic ANSI SCSI-1 tape unit */
    public static final long MT_ISSCSI1 = 0x71;
    //     #define MT_ISSCSI2		0x72	/* Generic ANSI SCSI-2 tape unit */
    public static final long MT_ISSCSI2 = 0x72;

    public static final long MTIOCTOP = const_mtioctop_get();
    public static final long MTIOCGET = const_mtioc_get();

    public static native int errno();
    public static native int ioctl(int fd, long request, long ptr);

    private static native long const_mtioctop_get();
    private static native long const_mtioc_get();
}

