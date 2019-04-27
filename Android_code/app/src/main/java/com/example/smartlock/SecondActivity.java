package com.example.smartlock;


import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;
import android.view.Window;
import android.view.WindowManager;

public class SecondActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
       // requestWindowFeature(Window.FEATURE_NO_TITLE);
       // getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
     //           WindowManager.LayoutParams.FLAG_FULLSCREEN);
        setContentView(R.layout.second_activity);
    }



    public void register(android.view.View view)
    {
        ((TextView)findViewById(R.id.str)).setX(50);
    }
}

