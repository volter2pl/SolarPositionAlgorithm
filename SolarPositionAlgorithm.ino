#include "spa.h"

SPACalc spa;
spa_data data;

void setup() {
  Serial.begin(74880);

  data.year = 2023;
  data.month = 6;
  data.day = 24;
  data.hour = 12;
  data.minute = 0;
  data.second = 0;
  data.timezone = 0.0;
  data.pressure = 1013;
  data.temperature = 25;
  data.delta_t = 64.797;
  data.longitude = 16.9340707;
  data.latitude = 52.4084872;
  data.atmos_refract = 0.5667;
  data.elevation = 65.55;
  data.slope = 0;
  data.azm_rotation = 0;
  data.function = SPA_ZA;

  spa.spa_calculate(&data);

  printf(
    "DateTime: %04d-%02d-%02d %02d:%02d:%02d %+03d | error: %d | azimuth: %.2f | zenith: %.2f | altitude: %.2f\n",
    data.year,
    data.month,
    data.day,
    data.hour,
    data.minute,
    data.second,
    int(data.timezone),
    data.error,
    data.azimuth,
    data.zenith,
    (data.zenith-90)*-1
  );
}

void loop() {}

