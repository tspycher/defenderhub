# Defender HUB
This arduino project is a box with an arduino, some sensors like temperature and relay's but mainly with an OBD Interface to read realtime Data from the car's engine.
The Data gets shown on a little LCD which is going to be mounted somewhere to show all the data.

Final Solution/Product gets installed in a Land Rover Defender 110 2.4 Puma.

# Project Setup commands
```
pio project init --board uno --ide clion
pio pkg install --library "paulstoffregen/OneWire@^2.3.7"
pio pkg install --library "milesburton/DallasTemperature@^3.11.0"
pio pkg install --library "arduino-libraries/LiquidCrystal@^1.0.7"    
```