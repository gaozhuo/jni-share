package com.example.demo0502;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;

public class MainActivity extends AppCompatActivity {

    public String[] stringArray = new String[520];

    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // 初始化数组
        for (int i = 0; i < stringArray.length; i++) {
            stringArray[i] = String.format("%04d", i + 1);
        }

    }


    public void onButtonClick01(View view) {

        iterateArray(stringArray);

    }


    public native void iterateArray(String[] stringArray);
}
