#define resett 15
#define dice 14
char digit[6]={0x02, 0x79, 0x24, 0x30, 0x19, 0x12};
int pin[7]={6,5,4,3,2,1,0};
void setup()
{
  for(int i=0;i<7;i++)
  pinMode(pin[i], OUTPUT);
  pinMode(dice, INPUT);
  pinMode(resett, INPUT);
  digitalWrite(dice, HIGH);
  digitalWrite(resett, HIGH);
   int temp=0x40;
    for(int i=0;i<7;i++)
    {
      int temp1=temp&0x01;
      digitalWrite(pin[i], temp1);
      temp=temp>>1;
    }
    delay(1000);
}
void loop()
{
  int temp=rand();
  if(digitalRead(dice)==0)
  {
    int k=temp%6;
    temp=digit[k];
    wait();
    for(int i=0;i<7;i++)
    {
      int temp1=temp&0x01;
      digitalWrite(pin[i], temp1);
      temp=temp>>1;
    }
    delay(200);
  }
  
  if(digitalRead(resett)==0)
  {
    temp=0x40;
    for(int i=0;i<7;i++)
    {
      int temp1=temp&0x01;
      digitalWrite(pin[i], temp1);
      temp=temp>>1;
    }
  }
}
void wait()
{
  for(int m=0;m<10;m++)
  {
   for(int k=0;k<6;k++)
   {
    int ch=digit[k];
    for(int l=0;l<7;l++)
    {
      char tem2=ch&0x01;
      digitalWrite(pin[l], tem2);
      ch=ch>>1;
    }
    delay(50);
   }
  } 
}
