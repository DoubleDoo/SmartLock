package com.example.smartlock;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }



public void register(android.view.View view)
{
    ((TextView)findViewById(R.id.str)).setX(1);
    Intent intent = new Intent(MainActivity.this, SecondActivity.class);
    startActivity(intent);
}
}

