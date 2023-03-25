//
// Created by X on 3/25/2023.
//

#include "ser.h"
#include <iostream>
SerialPort::SerialPort(const char *portName, speed_t baudRate) {
    std::cout<<portName<<"\n";
    m_portName = portName;
    m_baudRate = baudRate;
    m_fd = -1;
}

SerialPort::~SerialPort() {
    closePort();
}

bool SerialPort::isOpen() {
    return m_fd >= 0;
}

bool SerialPort::openPort() {
    if (isOpen())
        return true;

    m_fd = open(m_portName, O_RDWR | O_NOCTTY | O_NDELAY);
    if (m_fd < 0)
        return false;

    fcntl(m_fd, F_SETFL, 0);

    tcgetattr(m_fd, &m_options);
    cfmakeraw(&m_options);
    cfsetispeed(&m_options, m_baudRate);
    cfsetospeed(&m_options, m_baudRate);

    m_options.c_cflag |= (CLOCAL | CREAD);
    m_options.c_cflag &= ~PARENB;
    m_options.c_cflag &= ~CSTOPB;
    m_options.c_cflag &= ~CSIZE;
    m_options.c_cflag |= CS8;

    m_options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    m_options.c_iflag &= ~(IXON | IXOFF | IXANY);

    tcsetattr(m_fd, TCSANOW, &m_options);
    return true;
}

bool SerialPort::closePort() {
    if (!isOpen())
        return true;

    close(m_fd);
    m_fd = -1;
    return true;
}

bool SerialPort::readPort(void *buf, size_t bufSize) {
    if (!isOpen())
        return false;

    ssize_t bytesRead = read(m_fd, buf, bufSize);
    return bytesRead >= 0;
}

bool SerialPort::writePort(const void *buf, size_t bufSize) {
    if (!isOpen()){
        return false;}

    }
