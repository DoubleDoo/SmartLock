#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SoftwareSerial.h>

 
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define NUMFLAKES     10 // Number of snowflakes in the animation example
SoftwareSerial SIM800(8, 9); 
#define XPOS   0 // Indexes into the 'icons' array in function below
#define YPOS   1
#define DELTAY 2

  

const int left = A0;
const int right = A1;
int count=1;
int state=0;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
 #define LOGO_HEIGHT   32
#define LOGO_WIDTH    32

class page
{
  protected:
  int* object_x;
  int* object_y;
  int* object_length;
  int* object_height;
  const uint8_t** objects;
  int pointer;
  int objects_count;

 
  public:
  page(int _objects_count)
  {

    objects_count=_objects_count;
    objects=new unsigned char*[objects_count];
    object_x=new int[objects_count];
    object_y=new int[objects_count];
    object_height=new int[objects_count];
    object_length=new int[objects_count];
    pointer=0;
  }

  
  add_object(const uint8_t *bitmap,int x,int y,int hght,int lnght)
  {
    if(pointer<objects_count)
    {
      object_x[pointer]=x;
      object_y[pointer]=y;
      object_height[pointer]=hght;
      object_length[pointer]=lnght;    
      objects[pointer]=bitmap;
      pointer++;

    }
    else
    {
      Serial.println("!");
    }
  }

  show_page(Adafruit_SSD1306 display)
  {
    for (int i=0; i < objects_count ; i++)
    {
       display.drawBitmap(object_x[i], object_y[i], objects[i],object_length[i], object_height[i], WHITE);
    }
  }
};

class Node
{
  page* parent;
  page* this_page;
  page* childes;
  int pointer;

  
  public:
  Node(page* _page, page* _childes)
  {
    this_page=_page;
    parent=nullptr;
    childes=_childes;
    pointer=0;
  }
  
  Node(page* _page,page* _parent,page* _childes)
  {
    this_page=_page;
    parent=_parent;
    childes=childes;
    pointer=0;
  }

  page swith_on_child()
  {
    return childes[pointer];
  }

  page swith_on_parent()
  {
    return parent;
  }

  page* next_child()
  {
    //if (pointer<childes)
    //pointer++;
    //return 
  }

  page* previous_child()
  {
    
  }
  
};



static const unsigned char PROGMEM gear[] =
{ B00000000, B00000001,B10000000, B00000000,
  B00000000, B00000011,B11000000, B00000000,
  B00000000, B00000111,B11100000, B00000000,
  B00011110, B00001111,B11110000, B01111000,
  B00011111, B10011110,B01111001, B11111000,
  B00011111, B11111100,B00111111, B11111000,
  B00011111, B11100000,B00000111, B11111000,
  B00001111, B00000000,B00000000, B11111000,
  B00001110, B00000111,B11100000, B01110000,
  B00000110, B00001110,B01110000, B01100000,
  B00000110, B00011000,B00011000, B01100000,
  B00001100, B00110000,B00001100, B00110000,
  B00011100, B01100001,B10000110, B00111000,
  B00111100, B11000011,B11000011, B00111100,
  B01111001, B10000111,B11100001, B10011110,
  B11110001, B10001110,B01110001, B10011111,
  B11110001, B10001110,B01110001, B10011111,
  B01111001, B10000111,B11100001, B10011110,
  B00111100, B11000011,B11000011, B00111100,
  B00011100, B01100001,B10000110, B00111000,
  B00001100, B00110000,B00001100, B00110000,
  B00000110, B00011000,B00011000, B01100000,
  B00000110, B00001110,B01110000, B01100000,
  B00001110, B00000111,B11100000, B01110000,
  B00001111, B00000000,B00000000, B11111000,
  B00011111, B11100000,B00000111, B11111000,
  B00011111, B11111100,B00111111, B11111000,
  B00011111, B10011110,B01111001, B11111000,
  B00011110, B00001111,B11110000, B01111000,
  B00000000, B00000111,B11100000, B00000000,
  B00000000, B00000011,B11000000, B00000000,
  B00000000, B00000000,B00000000, B00000000,
  B00000000, B00000000,B00000000, B00000000,
  B00000000, B00000000,B00000000, B00000000,
  B00000000, B00000000,B00000000, B00000000,
  B00000000, B00000001,B10000000, B00000000
  };

  static const unsigned char PROGMEM lock[] =
{
  B00000000, B00000000,B00000000, B00000000,
  B00000000, B00000000,B00000000, B00000000,
  B00000000, B00000000,B00000000, B00000000,
  B00000000, B00000000,B00000000, B00000000,
  B00000000, B00000001,B10000000, B00000000,
  B00000000, B00000111,B11100000, B00000000,
  B00000000, B00011100,B00111000, B00000000,
  B00000000, B01110000,B00001110, B00000000,
  B00000000, B11100000,B00000111, B00000000,
  B00000001, B11000000,B00000011, B10000000,
  B00000001, B11000000,B00000011, B10000000,
  B00000001, B11000000,B00000011, B10000000,
  B00000001, B11000000,B00000011, B10000000,
  B00000001, B11000000,B00000011, B10000000,
  B00000001, B11000000,B00000011, B10000000,
  B00000011, B11111111,B11111111, B11000000,
  B00000011, B11111111,B11111111, B11000000,
  B00000011, B11111111,B11111111, B11000000,
  B00000011, B11111110,B01111111, B11000000,
  B00000011, B11111100,B00111111, B11000000,
  B00000011, B11111100,B00111111, B11000000,
  B00000011, B11111110,B01111111, B11000000,
  B00000011, B11111110,B01111111, B11000000,
  B00000011, B11111100,B01111111, B11000000,
  B00000011, B11111110,B01111111, B11000000,
  B00000011, B11111111,B11111111, B11000000,
  B00000011, B11111111,B11111111, B11000000,
  B00000000, B00000000,B00000000, B00000000,
  B00000000, B00000000,B00000000, B00000000,
  B00000000, B00000000,B00000000, B00000000,
  B00000000, B00000000,B00000000, B00000000,
  B00000000, B00000000,B00000000, B00000000
  };

 

      static const unsigned char PROGMEM rt[] =
{

  B10000000,
  B11000000,
  B11100000,
  B11110000,
  B11111000,
  B11111100,
  B11111110,
  B11111111,
  B11111111,
  B11111110,
  B11111100,
  B11111000,
  B11110000,
  B11100000,
  B11000000,
  B10000000
  };

     static const unsigned char PROGMEM unlock[] =
{
  B00000000, B00000000,B00000000, B00000000,
  B00000000, B00000001,B10000000, B00000000,
  B00000000, B00000111,B11100000, B00000000,
  B00000000, B00011100,B00111000, B00000000,
  B00000000, B01110000,B00001110, B00000000,
  B00000000, B11100000,B00000111, B00000000,
  B00000001, B11000000,B00000011, B10000000,
  B00000001, B11000000,B00000011, B10000000,
  B00000001, B11000000,B00000011, B10000000,
  B00000001, B11000000,B00000011, B10000000,
  B00000001, B11000000,B00000011, B10000000,
  B00000001, B11000000,B00000011, B10000000,
  B00000000, B10000000,B00000011, B10000000,
  B00000000, B00000000,B00000011, B10000000,
  B00000000, B00000000,B00000011, B10000000,
  B00000011, B11111111,B11111111, B11000000,
  B00000011, B11111111,B11111111, B11000000,
  B00000011, B11111111,B11111111, B11000000,
  B00000011, B11111110,B01111111, B11000000,
  B00000011, B11111100,B00111111, B11000000,
  B00000011, B11111100,B00111111, B11000000,
  B00000011, B11111110,B01111111, B11000000,
  B00000011, B11111110,B01111111, B11000000,
  B00000011, B11111100,B01111111, B11000000,
  B00000011, B11111110,B01111111, B11000000,
  B00000011, B11111111,B11111111, B11000000,
  B00000011, B11111111,B11111111, B11000000,
  B00000000, B00000000,B00000000, B00000000,
  B00000000, B00000000,B00000000, B00000000,
  B00000000, B00000000,B00000000, B00000000,
  B00000000, B00000000,B00000000, B00000000,
  B00000000, B00000000,B00000000, B00000000
  };
        static const unsigned char PROGMEM lt[] =
{

  B00000001,
  B00000011,
  B00000111,
  B00001111,
  B00011111,
  B00111111,
  B01111111,
  B11111111,
  B11111111,
  B01111111,
  B00111111,
  B00011111,
  B00001111,
  B00000111,
  B00000011,
  B00000001
  };

          static const unsigned char PROGMEM batary5[] =
{
  B00111111, B11111111,B11111111, B11111100,
  B00100000, B00000000,B00000000, B00000100,
  B00101111, B01111011,B11011110, B11110100,
  B00101111, B01111011,B11011110, B11110100,
  B00101111, B01111011,B11011110, B11110100,
  B00101111, B01111011,B11011110, B11110100,
  B00100000, B00000000,B00000000, B00000100,
  B00111111, B11111111,B11111111, B11111100
  };

            static const unsigned char PROGMEM batary4[] =
{
  B00111111, B11111111,B11111111, B11111100,
  B00100000, B00000000,B00000000, B00000100,
  B00101111, B01111011,B11011110, B00000100,
  B00101111, B01111011,B11011110, B00000100,
  B00101111, B01111011,B11011110, B00000100,
  B00101111, B01111011,B11011110, B00000100,
  B00100000, B00000000,B00000000, B00000100,
  B00111111, B11111111,B11111111, B11111100
  };

            static const unsigned char PROGMEM batary3[] =
{
  B00111111, B11111111,B11111111, B11111100,
  B00100000, B00000000,B00000000, B00000100,
  B00101111, B01111011,B11000000, B00000100,
  B00101111, B01111011,B11000000, B00000100,
  B00101111, B01111011,B11000000, B00000100,
  B00101111, B01111011,B11000000, B00000100,
  B00100000, B00000000,B00000000, B00000100,
  B00111111, B11111111,B11111111, B11111100
  };

            static const unsigned char PROGMEM batary2[] =
{
  B00111111, B11111111,B11111111, B11111100,
  B00100000, B00000000,B00000000, B00000100,
  B00101111, B01111000,B00000000, B00000100,
  B00101111, B01111000,B00000000, B00000100,
  B00101111, B01111000,B00000000, B00000100,
  B00101111, B01111000,B00000000, B00000100,
  B00100000, B00000000,B00000000, B00000100,
  B00111111, B11111111,B11111111, B11111100
  };

              static const unsigned char PROGMEM batary1[] =
{
  B00111111, B11111111,B11111111, B11111100,
  B00100000, B00000000,B00000000, B00000100,
  B00101111, B00000000,B00000000, B00000100,
  B00101111, B00000000,B00000000, B00000100,
  B00101111, B00000000,B00000000, B00000100,
  B00101111, B00000000,B00000000, B00000100,
  B00100000, B00000000,B00000000, B00000100,
  B00111111, B11111111,B11111111, B11111100
  };

                static const unsigned char PROGMEM batary0[] =
{
  B00111111, B11111111,B11111111, B11111100,
  B00100000, B00000000,B00000000, B00000100,
  B00100000, B00000000,B00000000, B00000100,
  B00100000, B00000000,B00000000, B00000100,
  B00100000, B00000000,B00000000, B00000100,
  B00100000, B00000000,B00000000, B00000100,
  B00100000, B00000000,B00000000, B00000100,
  B00111111, B11111111,B11111111, B11111100
  };


   static const unsigned char PROGMEM Net4[] =
{
  B11100000, B00000000,
  B11100000, B00000000,
  B11101110, B00000000,
  B11101110, B00000000,
  B11101110, B11100000,
  B11101110, B11100000,
  B11101110, B11101110,
  B11101110, B11101110,

  };


   static const unsigned char PROGMEM Net3[] =
{
  B11100000, B00000000,
  B10100000, B00000000,
  B10101110, B00000000,
  B10101110, B00000000,
  B10101110, B11100000,
  B10101110, B11100000,
  B10101110, B11101110,
  B11101110, B11101110,

  };

  
   static const unsigned char PROGMEM Net2[] =
{
  B11100000, B00000000,
  B10100000, B00000000,
  B10101110, B00000000,
  B10101010, B00000000,
  B10101010, B11100000,
  B10101010, B11100000,
  B10101010, B11101110,
  B11101110, B11101110,
  };

  
   static const unsigned char PROGMEM Net1[] =
{
  B11100000, B00000000,
  B10100000, B00000000,
  B10101110, B00000000,
  B10101010, B00000000,
  B10101010, B11100000,
  B10101010, B10100000,
  B10101010, B10101110,
  B11101110, B11101110,

  };
  
   static const unsigned char PROGMEM Net0[] =
{
  B11100000, B00000000,
  B10100000, B00001010,
  B10101110, B00000100,
  B10101010, B00001010,
  B10101010, B11100000,
  B10101010, B10100000,
  B10101010, B10101110,
  B11101110, B10101110,
  };

   




  
void setup() {
  pinMode(left, INPUT);
  pinMode(right,INPUT);
  Serial.begin(9600);               // Скорость обмена данными с компьютером
  Serial.println("Start!");
  SIM800.begin(115200);               // Скорость обмена данными с модемом
  SIM800.println("AT");
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
    display.display();
    delay(2000); 
    display.clearDisplay();
    /*
    testanimate(gear,32,32,48,16); 
    testanimate(lt,16,8,24,24); 
    testanimate(rt,16,8,96,24); 
    testanimate(batary5,8,32,96,0); 
    testanimate(Net4,8,16,80,0); 
    display.display();
    delay(2000);
    display.clearDisplay();
    testanimate(lock,32,32,48,16); 
    testanimate(lt,16,8,24,24);
    testanimate(rt,16,8,96,24); 
    testanimate(batary4,8,32,96,0); 
    testanimate(Net3,8,16,80,0); 
    display.display();
    delay(2000); 
    display.clearDisplay();
    testanimate(unlock,32,32,48,16); 
    testanimate(lt,16,8,24,24); 
    testanimate(rt,16,8,96,24);
    testanimate(batary3,8,32,96,0); 
    testanimate(Net2,8,16,80,0); 
    display.display();
    delay(2000); 
    display.clearDisplay();
    testanimate(gear,32,32,48,16); 
    testanimate(lt,16,8,24,24); 
    testanimate(rt,16,8,96,24);
    testanimate(batary0,8,32,96,0); 
    testanimate(Net0,8,16,80,0); 
    */
    page pg(3);
    pg.add_object(Net2,8,0,8,16);
    pg.add_object(batary3,20,20,8,32);
    pg.add_object(lt,80,40,16,8);
  //  pg.add_object(Net0,50,50,8,16);
  //  pg.add_object(Net0,50,50,8,16);
   pg.show_page(display);
   //display.drawBitmap(80,80,Net0,16,8, WHITE);

      delay(2000);
    display.display();

}
 
void loop() {

  /*
if (state==0)
{
buttonscheck();
 OledWrite();  
  delay(50);
  Atspeak();
}
else if (state==1)
{
  Atspeak();
}
//checkNet();delay (1000);
}
//display.println(F("Hello, world!"));


void testanimate(const uint8_t *bitmap,int w,int h,int x,int y) {
display.drawBitmap(x, y, bitmap, h, w, WHITE);
*/
}



/*

void buttonscheck()
{
if(digitalRead(left)==1||digitalRead(right)==1)
  {
    if(digitalRead(left)==1)
    {
      delay(50);
      if(digitalRead(right)==1) {Serial.println(count);delay(500);}
      else {Serial.println(--count);delay(100);}
    }
    else if(digitalRead(right)==1)
    {
      delay(50);
      if(digitalRead(left)==1) {Serial.println(count);delay(500);}
      else {Serial.println(++count);delay(100);}
    }
  }
   if (count>3) {count=3;}
    if (count<1) {count=1;}
}


void OledWrite()
{
  display.clearDisplay();
if(count==1)
    {
    testanimate(gear,32,32,48,16); 
    testanimate(rt,16,8,96,24); 
    testanimate(batary5,8,32,96,0); 
    testanimate(Net4,8,16,80,0);
    }
    if(count==2)
    {
    testanimate(unlock,32,32,48,16); 
    testanimate(lt,16,8,24,24);
    testanimate(rt,16,8,96,24); 
    testanimate(batary4,8,32,96,0); 
    testanimate(Net3,8,16,80,0);  
    }
    if(count==3)
    {
    testanimate(lock,32,32,48,16); 
    testanimate(lt,16,8,24,24); 
    testanimate(batary3,8,32,96,0); 
    testanimate(Net2,8,16,80,0); 
    }
    
    delay(50);
    display.display();
  

}

void Atspeak()
{
  if (SIM800.available())          
    {Serial.write(SIM800.read());  
state=0;  
    }
    if (Serial.available())    
    {       
    state=1;
    SIM800.write(Serial.read());   
    }
}


void checkNet()
{

    
  while(true)
  {    if (Serial.available())    
    {       
     SIM800.write("AT+CSQ");    
    }
    if (SIM800.available())          
    {Serial.write(SIM800.read());  
    break;
    }
  }
}*/
