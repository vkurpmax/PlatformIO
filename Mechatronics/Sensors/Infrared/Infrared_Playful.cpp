/*
    Source: Youtube - Playful Technology
    BOARD: Arduino Nano
*/

/**
 * "Touch-free" touch sensor using IR obstacle detector
 * https: www.banggood.com/custlink/3KGdtHNjdu
 * 
 * Advantages:
 * - Simple, fast, digital
 * - Detects, hands, skin, or any reflective object
 * - Adjustable sensitivity through hardware
 * 
 * Disadvantages:
 * - Transmitter and sensor need to be exposed (can't be placed behind surface)
 * - Detection can be affected by environmental conditions - lighting etc.
 * - Different objects have different reflectivity - black objects absorb light (including IR light) insted of reflecting it
 *   so may not be detected
 */

// CONSTANTS
// Pin to which the output signal from the IR sensor is connected
const byte sensorPin = 2;
// LED pin will be driven HIGH to indicate when input is detected
const byte ledPin = 13;

// GLOBALS
// Flag to detect whether object is detected
bool detected = false;

void setup()
{
    // Start a USB serial connection
    Serial.begin(9600);
    // Print out the file and the date at which it was last compiled
    Serial.println(_FILE_ __DATE__);
    // Configure the output pin
    pinMode(ledPin, OUTPUT);
}

// This function is called once when a new object is detected
void inputDetected()
{
    digitalWrite(ledPin, HIGH);
    Serial.print(F("New input detected! "));
    detected = true;
}

// This function is called repeatedly while an object remains present
void inputHeld()
{
    Serial.print(".");
}

// This function is called once when an object is removed
void inputRemoved()
{
    digitalWrite(ledPin, LOW);
    Serial.println(F("removed"));
    detected = false;
}

void loop()
{
    // Sensor reads LOW when detected or HIGH otherwise
    int reading = !digitalRead(sensorPin);
    // If an object is detected now
    if(reading)
    {
        // ... and there wasn't an object detected last frame
        if(detected == false)
        {
            // New object
            inputDetected();
        }
        // ... or if there already was an object last frame
        else
        {
            inputHeld();
        }
    }
    // If no object is detected now
    else
    {
        // If object was detected in the previous frame, it means it's just been removed
        if(detected)
        {
            inputRemoved();
        }
    }
    delay(20);
}