#include <Arduino.h>
#include "Pico2WBoard.h"

#include <Wire.h>

static void connect_callback(uint16_t conn_handle){
    (void)conn_handle;
    MESH_DEBUG_PRINTLN("BLE client connected");
}

static void disconnect_callback(uint16_t conn_handle, uint8_t reason) {
  (void)conn_handle;
  (void)reason;

  MESH_DEBUG_PRINTLN("BLE client disconnected");
}

void Pico2WBoard::begin()
{
    startup_reason = BD_STARTUP_NORMAL;

    #ifdef P_LORA_TX_LED
    pinMode(P_LORA_TX_LED, OUTPUT);
    #endif

    #ifdef PIN_VBAT_READ
    pinMode(PIN_VBAT_READ, INPUT);
    #endif

    #if defined(PIN_BOARD_SDA) && defined(PIN_BOARD_SCL)
    Wire.setPins(PIN_BOARD_SDA, PIN_BOARD_SCL);
    #endif

    Wire.begin();

    delay(10);

};

// For now, OTA Updates will not be supported on the RP2350
bool Pico2WBoard::startOTAUpdate(const char *id, char reply[])
{
    return false;
};