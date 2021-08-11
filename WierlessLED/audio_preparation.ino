void get_max_vol()
{
  max_vol = 0;
  int x;
  for(uint8_t i = 0; i < 100; ++i)
  {
     x = analogRead(MIC_PIN);
     if(x > max_vol)
     {
      max_vol=x;
     }
  }
}

void get_fft_from_audio()
{
  for (int i = 0; i < SAMPLES; i++) 
  {
    vReal[i] = analogRead(A0);
    vImag[i] = 0;
  }
  FFT.Windowing(vReal, SAMPLES, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
  FFT.Compute(vReal, vImag, SAMPLES, FFT_FORWARD);
  FFT.ComplexToMagnitude(vReal, vImag, SAMPLES);
}
