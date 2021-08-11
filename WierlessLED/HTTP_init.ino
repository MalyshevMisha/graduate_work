void HTTP_init(void) 
{
  HTTP.on("/", handleRoot); // Главная страница при  подключении к маршрутизатору http://192.168.0.101/
  HTTP.on("/led", led_settings);
  // Запускаем HTTP сервер
  HTTP.begin();
  Serial.println("WebServer started");
}

void handleRoot() 
{
  HTTP.send(200, "text/plain", "correct IP");
  Serial.println("correct IP");
}

void led_settings()
{
  current_mode = atoi(HTTP.arg("mode").c_str());
  brightness = atoi(HTTP.arg("brightness").c_str());
  red = atoi(HTTP.arg("red").c_str());
  green = atoi(HTTP.arg("green").c_str());
  blue = atoi(HTTP.arg("blue").c_str());
  HTTP.send(200, "text/plain", "OK");
  Serial.print("mode = ");
  Serial.println(current_mode);
  Serial.print("brightnessght = ");
  Serial.println(brightness);
  Serial.print("red = ");
  Serial.println(red);
  Serial.print("green = ");
  Serial.println(green);
  Serial.print("blue = ");
  Serial.println(blue);
}
