package com.harunkurtme.myapplication;

public class SerialPort {
    static {
        System.loadLibrary("serial_port");
    }

    private native boolean serialopen(String portName, int baudRate);
    private native boolean serialclose();

    public boolean openPort(String portName, int baudRate) {
        return serialopen(portName, baudRate);
    }

    public boolean closePort() {
        return serialclose();
    }
}
