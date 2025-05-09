// ESP32 Button to control LED

const int buttonPin = 4;      // GPIO pin connected to the button
const int ledPin = 5;         // GPIO pin connected to the LED control
const int ledPowerPin = 25;   // GPIO pin used as power source for LED
int buttonState = 0;          // Variable to store button state

void setup() {
  // Set LED control pin as output
  pinMode(ledPin, OUTPUT);
  
  // Set LED power pin as output and keep it HIGH
  pinMode(ledPowerPin, OUTPUT);
  digitalWrite(ledPowerPin, HIGH);  // Supply 3.3V to the LED through this pin
  
  // Set button pin as input with internal pull-up resistor enabled
  pinMode(buttonPin, INPUT_PULLUP);
  
  Serial.begin(115200);
  Serial.println("ESP32 Button-LED Test");
}

void loop() {
  // Read the state of the button
  buttonState = digitalRead(buttonPin);
  
  // Check if the button is pressed (LOW when using pull-up resistor)
  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);  // Turn on the LED when button is pressed
    Serial.println("Button pressed - LED ON");
  } else {
    digitalWrite(ledPin, LOW);   // Turn off the LED when button is released
    Serial.println("Button released - LED OFF");
  }
  
  delay(100);  // Small delay for debouncing
}