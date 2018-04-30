#include <jni.h>
#include <android/log.h>

extern "C"
JNIEXPORT void JNICALL
Java_com_example_demo0502_MainActivity_iterateArray(JNIEnv *env, jobject instance,
                                                    jobjectArray stringArray) {
    // 获取数组长度
    jint len = env->GetArrayLength(stringArray);

    for (int i = 0; i < len; i++) {
        // 获取数组的第i个元素
        jstring str = (jstring) env->GetObjectArrayElement(stringArray, i);

        // 打印
        __android_log_print(ANDROID_LOG_DEBUG, "debug", "%s", env->GetStringUTFChars(str, NULL));

        // 删除本地引用
        env->DeleteLocalRef(str);

    }

}