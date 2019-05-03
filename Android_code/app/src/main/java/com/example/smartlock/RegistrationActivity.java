package com.example.smartlock;


import android.content.Intent;
import android.content.SharedPreferences;
import android.preference.PreferenceManager;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class RegistrationActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_registration);
        SharedPreferences myPreferences = PreferenceManager.getDefaultSharedPreferences(RegistrationActivity.this);
        TextView nm = (TextView)findViewById(R.id.editText5);
        TextView sn = (TextView)findViewById(R.id.editText6);
        TextView ad = (TextView)findViewById(R.id.editText3);
        TextView nu = (TextView)findViewById(R.id.editText4);
        TextView dn = (TextView)findViewById(R.id.editText2);
        TextView cd = (TextView)findViewById(R.id.editText7);
        nm.setText(myPreferences.getString("NAME", ""));
        sn.setText(myPreferences.getString("SYENAME", ""));
        ad.setText(myPreferences.getString("ADDRESS", ""));
        nu.setText(myPreferences.getString("NUMBER", ""));
        dn.setText(myPreferences.getString("DNUMBER", ""));
        cd.setText(myPreferences.getString("CODE", ""));

    }



    public void endregistration(android.view.View view)
    {
        TextView nm = (TextView)findViewById(R.id.editText5);
        TextView sn = (TextView)findViewById(R.id.editText6);
        TextView ad = (TextView)findViewById(R.id.editText3);
        TextView nu = (TextView)findViewById(R.id.editText4);
        TextView dn = (TextView)findViewById(R.id.editText2);
        TextView cd = (TextView)findViewById(R.id.editText7);
        SharedPreferences myPreferences = PreferenceManager.getDefaultSharedPreferences(RegistrationActivity.this);
        SharedPreferences.Editor myEditor = myPreferences.edit();
        myEditor.putString("NAME",nm.getText().toString());
        myEditor.putString("SYENAME",sn.getText().toString() );
        myEditor.putString("ADDRESS",ad.getText().toString() );
        myEditor.putString("NUMBER",nu.getText().toString() );
        myEditor.putString("DNUMBER",dn.getText().toString() );
        myEditor.putString("CODE",cd.getText().toString() );
        myEditor.putBoolean("NEW",false );
        myEditor.commit();
        Intent intent = new Intent(RegistrationActivity.this, MenuActivity.class);
        startActivity(intent);
        finish();
    }
}

