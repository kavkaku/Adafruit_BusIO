#ifndef ADAFRUIT_GENERICDEVICE_H
#define ADAFRUIT_GENERICDEVICE_H

#include <Arduino.h>

typedef bool (*busio_genericdevice_read_t)(uint8_t *buffer, size_t len);
typedef bool (*busio_genericdevice_write_t)(const uint8_t *buffer, size_t len);
typedef bool (*busio_genericdevice_readreg_t)(uint8_t *addr_buf, uint8_t addrsiz, uint8_t *buf, uint16_t bufsiz);
typedef bool (*busio_genericdevice_writereg_t)(uint8_t *addr_buf, uint8_t addrsiz, const uint8_t *buf, uint16_t bufsiz);

/*!
 * @brief Class for communicating with a device via generic read/write functions
 */
class Adafruit_GenericDevice {
public:
  Adafruit_GenericDevice(busio_genericdevice_read_t read_func, 
                        busio_genericdevice_write_t write_func,
                        busio_genericdevice_readreg_t readreg_func = nullptr,
                        busio_genericdevice_writereg_t writereg_func = nullptr);
  
  bool begin(void);
  
  bool read(uint8_t *buffer, size_t len);
  bool write(const uint8_t *buffer, size_t len);
  bool readRegister(uint8_t *addr_buf, uint8_t addrsiz, uint8_t *buf, uint16_t bufsiz);
  bool writeRegister(uint8_t *addr_buf, uint8_t addrsiz, const uint8_t *buf, uint16_t bufsiz);

protected:
  busio_genericdevice_read_t _read_func;
  busio_genericdevice_write_t _write_func;
  busio_genericdevice_readreg_t _readreg_func;
  busio_genericdevice_writereg_t _writereg_func;
  
  bool _begun;
};

#endif // ADAFRUIT_GENERICDEVICE_H
