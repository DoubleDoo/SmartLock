package com.example.smartlock;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class SecondActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.second_activity);
    }



    public void register(android.view.View view)
    {
        ((TextView)findViewById(R.id.str)).setX(50);
    }
}

