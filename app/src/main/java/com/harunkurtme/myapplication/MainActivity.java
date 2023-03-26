package com.harunkurtme.myapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import com.harunkurtme.myapplication.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'myapplication' library on application startup.
    static {
        System.loadLibrary("myapplication");
    }

    private ActivityMainBinding binding;
    private Button connect;

    SerialPort serialPort = new SerialPort();


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

//        // Example of a call to a native method
        TextView tv = binding.sampleText;
        TextView tv2 = binding.sampleText3;
        connect = binding.connectButton;
        connect.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                connect.setText("Connect Button");
                System.out.println(serialPort.openPort("/dev/bus/usb/001/006", 9600));
            }
        });

//        TextView tv = (TextView)findViewById(R.id.sample_text3);
        tv.setText("aa");
        tv2.setText(stringFromJNI());
    }


    /**
     * A native method that is implemented by the 'myapplication' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}



