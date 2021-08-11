void fastLed_init()
{
   // основные настройки для адресной ленты
   FastLED.addLeds <LED_MODEL, PWM_PIN, GRB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
}

void mode_off()
{
   for(int i = 0; i < NUM_LEDS; i++)
   {
    leds[i].setRGB(0, 0, 0); // задаем для первого пикселя синий цвет
    leds[i].fadeLightBy( 255 );
   }
   FastLED.show();
}

void mode_backlight()
{
   for(int i = 0; i < NUM_LEDS; i++)
   {
    leds[i].setRGB(red, green, blue); // задаем для первого пикселя синий цвет
    leds[i].fadeLightBy( 255 - brightness);
   }
   FastLED.show();
}

byte for_loop;

inline void rainbow()
{
  t_dif = millis() - start_t;
  if(t_dif>=RAINBOW_DELAY && t_dif)
  {
   for (int i = 0; i < NUM_LEDS; i++) {
    hsv2rgb_rainbow( CHSV(i - (for_loop * 2), SATURATION, brightness), leds[i]);
   }
   ++for_loop;
   FastLED.show();
   start_t=millis();
  }
}

void display_max_vol_br()
{
   get_max_vol();
   
   for(int i = 0; i < NUM_LEDS; i++)
   {
    leds[i].setRGB(red, green, blue); // задаем для первого пикселя синий цвет
    leds[i].fadeLightBy( 255 - max_vol);
   }
   FastLED.show();
}

void display_max_vol_num()
{
  get_max_vol();
  
  int num = (max_vol * NUM_LEDS)/1024;
   for(int i = 0; i < NUM_LEDS; i++)
   {
    if((NUM_LEDS/2 - num/2) <= i && i <=((NUM_LEDS/2 - 1) + num/2))
    {
      leds[i].setRGB(red, green, blue); // задаем для первого пикселя синий цвет
      leds[i].fadeLightBy( 255 - brightness);
    }
    else
    {
      leds[i].setRGB(0, 0, 0); // задаем для первого пикселя синий цвет
      leds[i].fadeLightBy( 255 - brightness);
    }
   }
   FastLED.show();
}

const int v = (SAMPLES/2 - 3)/NUM_LEDS;

void friqency_mode()
{
  get_fft_from_audio();

  int max_val = 250;
  
  for (int i = 0; i < NUM_LEDS; ++i)
  {
    int value = int(vReal[i * v + 3]);
    
    if(value>max_val)
    {
      max_val = value;
    }
    else if(value < 250)
    {
      vReal[i * v + 3] = 0;
    }
  }

  for (int i = 0; i < NUM_LEDS; ++i)
  {
    leds[i].setRGB(red * int(vReal[i * v + 3]) / max_val, green * int(vReal[i * v + 3]) / max_val, blue * int(vReal[i * v + 3]) / max_val);
  }
  LEDS.show();
}
