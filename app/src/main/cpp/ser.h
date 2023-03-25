//
// Created by X on 3/25/2023.
//

#ifndef SERIAL_PORT_H
#define SERIAL_PORT_H

#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

class SerialPort {
public:
    SerialPort(const char *portName, speed_t baudRate);
    virtual ~SerialPort();

    bool isOpen();
    bool openPort();
    bool closePort();
    bool readPort(void *buf, size_t bufSize);
    bool writePort(const void *buf, size_t bufSize);
private:
    int m_fd;
    const char *m_portName;
    speed_t m_baudRate;
    struct termios m_options;
};

#endif /* SERIAL_PORT_H */
