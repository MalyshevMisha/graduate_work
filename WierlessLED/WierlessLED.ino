#include <ESP8266WiFi.h>        
#include <ESP8266WebServer.h>   
#include <FastLED.h>
#include <arduinoFFT.h>

IPAddress apIP(192, 168, 4, 1);

ESP8266WebServer HTTP(80);

#define MIC_PIN A0

#define NUM_LEDS 60 // указываем количество светодиодов на ленте
#define PWM_PIN 1   // указываем пин для подключения ленты
#define LED_MODEL WS2812B

arduinoFFT FFT = arduinoFFT();

#define SAMPLES 128              //Must be a power of 2
double vReal[SAMPLES];
double vImag[SAMPLES];

CRGB leds[NUM_LEDS];

#define RAINBOW_DELAY 50
#define AUDIO_DELAY 50

// Определяем переменные wifi
const String _ssid = "home", // Для хранения SSID
  _password = "i12345678", // Для хранения пароля сети
  _ssidAP = "WiFi",   // SSID AP точки доступа
  _passwordAP = ""; // пароль точки доступа

unsigned int current_mode = 2,
  previous_mode;
uint8_t brightness = 50,
  red, green, blue;
  
#define SATURATION 255   // Control the saturation of your leds (only for rainbow mode)

int max_vol;

void setup() 
{
  Serial.begin(115200);
  Serial.println("");
  Serial.println("Start WIFI");
  WIFIinit();
  Serial.println("Start WebServer");
  HTTP_init();
  fastLed_init();
}

int start_t,
  t_dif;

void loop() 
{
  HTTP.handleClient();

  switch(current_mode)
  {
    case 0:
    mode_off();
    previous_mode = current_mode;
    break;
    
    case 1:
    mode_backlight();
    previous_mode = current_mode;
    break;
    
    case 2:
    rainbow();
    previous_mode = current_mode;
    break;

    case 3:
    t_dif = millis() - start_t;
    if(t_dif>=AUDIO_DELAY && t_dif)
    {
      display_max_vol_br();
      previous_mode = current_mode;
    }
    break;

    case 4:
    t_dif = millis() - start_t;
    if(t_dif>=AUDIO_DELAY && t_dif)
    {
      display_max_vol_num();
      previous_mode = current_mode;
    }
    break;

    case 5:
    t_dif = millis() - start_t;
    if(t_dif>=AUDIO_DELAY && t_dif)
    {
      friqency_mode();
      previous_mode = current_mode;
    }
    break;
    
    default:
    current_mode = previous_mode;
    break;
  }
}
