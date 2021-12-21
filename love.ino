
const byte SENSOR_PIN = A0; 
const byte LED_1 = 2;       
const byte LED_2 = 3;       
const byte LED_3 = 4;       

const float BASE_TEMP = 20.0;
unsigned int sensor_val;

void setup() {
    Serial.begin(9600);

    for (byte pin = LED_1; pin <= LED_3; pin++) {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }
}

void loop() {

    sensor_val = analogRead(SENSOR_PIN);
    Serial.print("Sensor value: ");
    Serial.println(sensor_val);

    float voltage = (sensor_val / 1024.0) * 5.0;
    Serial.print("Volts: ");
    Serial.println(voltage);


    float temperature = (voltage - 0.5) * 100;
    Serial.print("Degrees C: ");
    Serial.println(temperature);
    Serial.println();


    if ((temperature >= BASE_TEMP)
        && (temperature < BASE_TEMP + 2)) {
        digitalWrite(LED_1, HIGH);
        digitalWrite(LED_2, HIGH);
        digitalWrite(LED_3, HIGH);
    }
    else if (temperature < BASE_TEMP) {
        digitalWrite(LED_1, LOW);
        digitalWrite(LED_2, LOW);
        digitalWrite(LED_3, LOW);
    }
    else if ((temperature >= BASE_TEMP + 2)
             && (temperature < BASE_TEMP + 4)) {
        digitalWrite(LED_1, HIGH);
        digitalWrite(LED_2, LOW);
        digitalWrite(LED_3, LOW);
    }

    else if ((temperature >= BASE_TEMP + 4)
             && (temperature < BASE_TEMP + 6)) {
        digitalWrite(LED_1, LOW);
        digitalWrite(LED_2, HIGH);
        digitalWrite(LED_3, LOW);
    }

    else {
        digitalWrite(LED_1, LOW);
        digitalWrite(LED_2, LOW);
        digitalWrite(LED_3, HIGH);
    }
}
