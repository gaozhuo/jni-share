#include <iostream>
#include <jni.h>
#include <unistd.h>



int main() {

    JavaVM *jvm; // java 虚拟机
    JNIEnv *env; // jni环境
    JavaVMInitArgs vm_args; // 创建虚拟机所需参数

    JavaVMOption *options = new JavaVMOption[1];
    options[0].optionString = "-Djava.class.path=."; // Java 类路径

    vm_args.version = JNI_VERSION_1_8; // jni版本
    vm_args.nOptions = 1;
    vm_args.options = options;
    vm_args.ignoreUnrecognized = JNI_FALSE; //参数错误时是否忽略


    // 创建Java虚拟机
    JNI_CreateJavaVM(&jvm, (void **) &env, &vm_args);

    //--------- 下面的流程和原来一样 -------------------------

    // 加载类
    jclass cls = env->FindClass("com/example/HelloWorld");

    // 获取方法ID
    jmethodID mid = env->GetStaticMethodID(cls, "say", "()V");

    // 调用Java 方法
    env->CallStaticVoidMethod(cls, mid);

    // 销毁虚拟机
    jvm->DestroyJavaVM();

    return 0;
}