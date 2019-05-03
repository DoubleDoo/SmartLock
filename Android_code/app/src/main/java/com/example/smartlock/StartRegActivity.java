package com.example.smartlock;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

public class StartRegActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_start_reg);
    }

    public void startregistration(android.view.View view)
    {
        Intent intent = new Intent(StartRegActivity.this, RegistrationActivity.class);
        startActivity(intent);
        finish();
    }
}
