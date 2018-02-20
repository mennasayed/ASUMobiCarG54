// variables
int GREEN = 2;
int YELLOW = 3;
int RED = 4;
int DELAY_GREEN = 5000;
int DELAY_YELLOW = 2000;
int DELAY_RED = 5000;

// basic functions
void setup()
{
  // setup LED modesv   // we're specifying that we're that 
  // we're going to send information to this LED
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
}

  void loop()
{
  green_light();
  delay(DELAY_GREEN);
  
  // code to make a yellow light
  delay(DELAY_YELLOW);
  
  // code to make a red light
  delay(DELAY_RED);
}

void green_light()
{
  digitalWrite(GREEN, HIGH);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, LOW);
}

void yellow_light()
{
  // your code here
}

void red_light()
{
  // your code here
}

// 
