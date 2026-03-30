package com.example.jnidemo;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    public native String helloFromJNI();
    public native int factorial(int n);
    public native String reverseString(String s);
    public native int sumArray(int[] values);

    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TextView tvHello = findViewById(R.id.tvHello);
        TextView tvFact = findViewById(R.id.tvFact);
        TextView tvReverse = findViewById(R.id.tvReverse);
        TextView tvArray = findViewById(R.id.tvArray);

        tvHello.setText(helloFromJNI());

        tvFact.setText("Factoriel(20) = " + factorial(20));

        tvReverse.setText("Reverse empty: " + reverseString(""));
        int[] nums = {};
        tvArray.setText("Somme = " + sumArray(nums));
    }
}