# SolarPositionAlgorithm
NREL Solar Position Algorithm implemented in C++ for ESP8266

This algorithm calculates the solar zenith and azimuth angles in the period from the year -2000 to 6000, with uncertainties of 0.0003 degrees based on the date, time, and location on Earth. (Reference: Reda, I.; Andreas, A., Solar Position Algorithm for Solar Radiation Applications, Solar Energy. Vol. 76(5), 2004; pp. 577-589). The software has not been tested on a variety of platforms and is not guaranteed to work on yours. It is provided here as a convenience.
Further information on this algorithm is available in the following NREL technical report:

[Reda, I.; Andreas, A. (2003). Solar Position Algorithm for Solar Radiation Applications. 55 pp.; NREL Report No. TP-560-34302, Revised January 2008.](http://www.nrel.gov/docs/fy08osti/34302.pdf)

Original code in C/C++ and licence can be found [here](http://www.nrel.gov/midc/spa/).

Example of use:
```cpp
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
```

This code should output the following result:
```
DateTime: 2023-06-24 12:00:00 +00 | error: 0 | azimuth: 209.53 | zenith: 31.56 | altitude: 58.44
```
