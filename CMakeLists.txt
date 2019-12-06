cmake_minimum_required(VERSION 3.7)
project(tapeapi C)
set(CMAKE_C_STANDARD 90)
set(_JAVA_HOME /usr/lib/jvm/java-1.8.0-openjdk-amd64)

find_package(Java 1.8 REQUIRED)
find_package(JNI 1.8 REQUIRED)

include(UseJava)

include_directories(${JNI_INCLUDE_DIRS})

set(CMAKE_JNI_TARGET TRUE)
add_jar(tapeapi-java java/tapeapi/MemOp.java java/tapeapi/Mtio.java java/tapeapi/MtGet.java java/tapeapi/MtOp.java java/tapeapi/SgApi.java MANIFEST java/MANIFEST.MF GENERATE_NATIVE_HEADERS tapeapi-native-headers VERSION 0.1)

include_directories(tapeapi-native-headers)

add_library(tapeapi SHARED src-c/mem_op.c src-c/mtio.c src-c/mt_get.c src-c/mt_op.c src-c/sg_api.c)
target_link_libraries(tapeapi ${JNI_LIBRARIES} tapeapi-native-headers sgutils2)
