// Define the pin numbers for the trig pin and echo pins 
//of four ultrasonic sensors
#define trig 4

#define echo_x1 3
#define echo_x2 9
#define echo_y1 5
#define echo_y2 11

// Constants for the length of the x-axis and y-axis
int const x_lenght = 5;
int const y_lenght = 6;

void setup()
{
  Serial.begin(9600);
  
  // Set the pin mode of the trig pin to OUTPUT
  pinMode(trig,OUTPUT);
  
  // Set the pin modes of the echo pins to INPUT
  pinMode(echo_x1,INPUT);
  pinMode(echo_x2,INPUT);
  pinMode(echo_y1,INPUT);
  pinMode(echo_y2,INPUT);
  
}

void loop()
{
  // Variables to store the calculated distances
  int distance_x=0, distance_y=0;

  // Trigger the ultrasonic sensors
  digitalWrite(trig,LOW);
  delayMicroseconds(5);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  
  // Measure the duration of the echo signals for each sensor
  int t_x1 = pulseIn(echo_x1,HIGH);
  int t_x2 = pulseIn(echo_x2,HIGH);
  int t_y1 = pulseIn(echo_y1,HIGH);
  int t_y2 = pulseIn(echo_y2,HIGH);
  
  // Calculate the distances based on the measured durations
  int distance_x1 = t_x1 / 58;
  int distance_x2 = t_x2 / 58;
  
  int distance_y1 = t_y1 / 58;
  int distance_y2 = t_y2 / 58;
  
  // Calculate the average distances for the x-axis and y-axis
  distance_x = ((x_lenght - distance_x1) + distance_x2) / 2;
  distance_y = ((y_lenght - distance_y1) + distance_y2) / 2;
  
  // Print the calculated coordinates to the serial monitor
  Serial.print("(");
  Serial.print(distance_x);
  Serial.print(", ");
  Serial.print(distance_y);
  Serial.print(")");

  delay(10);
}