#include "Adafruit_SSD1306.h"
#include <ESP8266WiFi.h>
#include <helpers.hpp>

// 64 x 48
#define OLED_RESET 0 // GPIO0
Adafruit_SSD1306 display(OLED_RESET);

void setup()
{
    Serial.begin(115200);

    display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Initialize with the I2C addr 0x3C (for the 64x48)
    display.display();
}

void loop()
{
    byte available_networks = WiFi.scanNetworks();
    if (available_networks > 0)
    {
        for (int network = 0; network < available_networks; network++)
        {
            display.clearDisplay();
            display.setTextSize(1);
            display.setTextColor(WHITE);

            String ssid = WiFi.SSID(network);
            long rssi = WiFi.RSSI(network);
            int bars = getBarsSignal(rssi);
            Serial.print("RSSI:");
            Serial.println(rssi);

            // Display network name, signal Strength and battery level
            display.setCursor(0, 0);
            display.print("SSID: ");
            display.setCursor(0, 8);
            display.println(ssid);
            display.setCursor(0, 32);
            display.print("CH: ");
            display.setCursor(18, 32);
            display.println(WiFi.channel(network));
            display.setCursor(0, 40);
            display.print("RSSI: ");
            display.setCursor(29, 40);
            display.print(rssi);

            const int16_t bar_width = 2;
            const int16_t scaling_factor = 3;
            const int16_t top_left_x_coord = 46;
            const int16_t top_left_y_coord = 48;

            // Display signal quality bars
            for (int b = 0; b <= bars; b++)
            {
                display.fillRect(top_left_x_coord + (b*scaling_factor), top_left_y_coord - (b*scaling_factor), bar_width , b*scaling_factor , WHITE);
            }

            display.display();

            delay(1500);

            // Update available networks again to show latest RSSI
            available_networks = WiFi.scanNetworks();
        }

        
    }
}