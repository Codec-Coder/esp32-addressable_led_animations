#include <FastLED.h>

#define NUM_LEDS 41 //Number of Leds in your Led strip. Change as per your numbers of Led

#define DATA_PIN 23 //Data pin for addressable led.
#define CLOCK_PIN 13 //for clocked led strips.



CRGB leds[NUM_LEDS];//Array to hold led colors.

//Predifined array  of colors in RGB format , you can add or remove colors.
int c[][3]={   
                  {237, 189, 187}, 
                  {184, 20, 13},
                  {247, 134, 35},
                  {255, 205, 89},
                  {255, 238, 0},
                  {208, 255, 0},
                  {128, 255, 0},
                  {0, 255, 106}, 
                  {0, 255, 208},
                  {0, 217, 255},
                  {0, 145, 255},
                  {0, 13, 255},
                  {179, 0, 255},
                  {238, 0, 255},
                  {255, 0, 174},
                  {255, 0, 68},
                  {255, 0, 0}
              };
int Number_of_colors = sizeof(c) / (3*sizeof(int));

void setup() {
     Serial.begin(115200);
     delay(500);
     //Initializing the esp32 output data streams.
    // Uncomment/edit one of the following lines for your leds arrangement.
    // ## Clockless types ##
    //FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed
    FastLED.addLeds<SM16703, DATA_PIN, BRG>(leds, NUM_LEDS);
    // FastLED.addLeds<TM1829, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<TM1812, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<TM1809, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<TM1804, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<TM1803, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<UCS1903, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<UCS1903B, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<UCS1904, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<UCS2903, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
    // FastLED.addLeds<WS2852, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
    // FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
    // FastLED.addLeds<GS1903, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<SK6812, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
    // FastLED.addLeds<SK6822, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<APA106, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<PL9823, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<SK6822, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<WS2813, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<APA104, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<WS2811_400, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<GE8822, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<GW6205, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<GW6205_400, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<LPD1886, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<LPD1886_8BIT, DATA_PIN, RGB>(leds, NUM_LEDS);
    // ## Clocked (SPI) types ##
    // FastLED.addLeds<LPD6803, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
    // FastLED.addLeds<LPD8806, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
    // FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<WS2803, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<SM16716, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<P9813, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);  // BGR ordering is typical
    // FastLED.addLeds<DOTSTAR, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);  // BGR ordering is typical
    // FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);  // BGR ordering is typical
    // FastLED.addLeds<SK9822, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);  // BGR ordering is typical
     
     
     Serial.println(Number_of_colors);
}

void loop() {
      int p = (int)random(Number_of_colors) ;
      int q = (int)random(Number_of_colors) ;
      
      int i = 0 ;       //First address for led strip 
      int j = NUM_LEDS ;//Last  address for led strip
      
      int k = -3 ;
      int l = +3 ;
      
      int timer1 = (int)random(35,80);//speed for led group1 selected at random
      int timer2 = (int)random(35,80);//speed for led group2 selected at random
      
      int counter1=0; //holds current postion of animation for group1 leds
      int counter2=0; //holds current postion of animation for group2 leds
      
      int moveloop1 =  1;//direction for leds in group1
      int moveloop2 = -1;//direction for leds in group2
      
      while(true){
        if(timer1==counter1 ){//animation controls for first group of leds
          leds[i] = CRGB(c[p][0],c[p][1],c[p][2]);
          leds[i+k] = CRGB(0,0,0);
          FastLED.show();
          if(i==0){
            moveloop1=1;
            timer1 = (int)random(20,100);
            p = (int)random(Number_of_colors); Serial.println(Number_of_colors);
            k=-3;
          }
          if(i==NUM_LEDS){
            moveloop1=-1;
            timer1 = (int)random(20,100);
            p = (int)random(Number_of_colors); Serial.println(Number_of_colors);
            k=+3;
          }
          i+=moveloop1;
          counter1=0 ;
        }
        if(timer2==counter2){//animation controls for second group of leds
          leds[j] = CRGB(c[q][0],c[q][1],c[q][2]);
          leds[j+l] = CRGB(0,0,0);
          FastLED.show();
          if(j==0){
            moveloop2=1;
            timer2 = (int)random(20,100);
            q = (int)random(Number_of_colors) ;Serial.println(Number_of_colors);
            k=-3;
          }
          if(j==NUM_LEDS){
            moveloop2=-1;
            timer2 = (int)random(20,100);
            q = (int)random(Number_of_colors); Serial.println(Number_of_colors);
            k=+3;
          }
          j+=moveloop2;
          counter2=0;
        }
        
        delay(1);//speed for overall animation.
        counter1++;
        counter2++;
      }
}
