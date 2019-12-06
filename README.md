## Usage

1) Write tape like file
```java
try (final FileInputStream ios = new FileInputStream("/dev/nst0")) {
    try (final FileOutputStream os = new FileOutputStream("test.ova")) {
        long writed = 0;
        final byte[] bytes = new byte[128000];
        int read = ios.read(bytes);
        while (read != -1) {
            os.write(bytes, 0, read);
            writed += read;
            read = ios.read(bytes);
        }
        System.out.print("Writed: ");
        System.out.println(writed);
    }
}
```

2) Rewind tape
```java
System.loadLibrary("tapeapi");
try (final FileInputStream ios = new FileInputStream("/dev/nst0")) {
    final FileDescriptor fd = ios.getFD();
    final int fd = SharedSecrets.getJavaIOFileDescriptorAccess().get(fileDescriptor);
    final long instance = MemOp.create(MtOp.size());
    MtOp.setMtOp(instance, (short) Mtio.MTREW);
    try {
        final int ioctl = Mtio.ioctl(fd, Mtio.MTIOCTOP, instance);
        if (ioctl < 0) {
            throw new IOException();
        }
    } finally {
        MemOp.dispose(instance);
    }
}
```

