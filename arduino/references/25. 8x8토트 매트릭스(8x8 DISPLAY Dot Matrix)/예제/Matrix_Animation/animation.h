int animationFrames = (6+8+3+4+4+4+8+2+2+3+7+3+11+5+4+2+2+4+2);

int animationDelays[] = { 
200, 200, 200, 200, 200, 200 
,200, 200, 200, 200, 200, 200, 200, 200
,200, 200, 200
,200, 200, 200, 200
,200, 200, 200, 200
,200, 200, 200, 200
,400, 100, 100, 200, 100, 100, 100, 200 
,200, 200
,400, 400 
,200, 200, 200
, 200, 200, 200, 200, 200, 200, 200 
,200, 200, 200
,200, 200, 50, 50, 50, 50, 50, 50, 50, 50, 500
,200, 100, 100, 100, 200
, 200, 200, 200, 200
,300, 300 
,200, 300 
,200, 200, 200, 200 
,300, 300
};

// Animation is designed for 8x8 pixels
uint8_t animation[][16] = {
  //16
  { 0x0, 0x0, 0xc0, 0x0, 0x0, 0x3, 0x30, 0x33, 0xc, 0xcf, 0xfc, 0x3f, 0xfc, 0x3f, 0xf0, 0xf },
  { 0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0x0, 0xf, 0xc, 0xcc, 0xcf, 0x3f, 0xff, 0xf, 0xfc, 0xf },
  { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x30, 0xc, 0xc, 0x3c, 0x3f, 0x3f, 0xff, 0x3f, 0xfc, 0xf },
  { 0x0, 0x0, 0x0, 0x0, 0xc0, 0xc, 0xf0, 0x0, 0x30, 0xc, 0x3f, 0x3f, 0xff, 0x3f, 0xfc, 0xf },
  { 0x0, 0x0, 0x0, 0x0, 0xc0, 0xc, 0xc0, 0x0, 0xf3, 0xc, 0x3c, 0x3f, 0xfc, 0x3f, 0xf0, 0xf },
  { 0x0, 0x0, 0x0, 0x0, 0xc0, 0x0, 0xcc, 0x30, 0xc3, 0xf3, 0xcf, 0x3f, 0xfc, 0xf, 0xf0, 0xf },
  //17
  { 0x0, 0x0, 0x30, 0xc, 0xfc, 0x3f, 0x30, 0xc, 0x30, 0xc, 0xfc, 0x3f, 0x30, 0xc, 0x0, 0x0 },
  { 0x0, 0x0, 0x0, 0x0, 0xc0, 0x30, 0xf0, 0xff, 0xc0, 0x30, 0xc0, 0x30, 0xf0, 0xff, 0xc0, 0x30 },
  { 0x0, 0x0, 0x3c, 0x30, 0x3c, 0xc, 0x0, 0x3, 0xc0, 0x0, 0x30, 0x3c, 0xc, 0x3c, 0x0, 0x0 },
  { 0xf0, 0xc0, 0xf0, 0x30, 0x0, 0xc, 0x0, 0x3, 0xc0, 0xf0, 0x30, 0xf0, 0x0, 0x0, 0x0, 0x0 },
  { 0x0, 0x0, 0x0, 0x3, 0x0, 0xf, 0x0, 0x33, 0x0, 0x33, 0xc0, 0x3, 0xf0, 0x3, 0xf0, 0x0 },
  { 0xc0, 0x0, 0xc0, 0x3, 0xc0, 0xc, 0xc0, 0xc, 0xf0, 0x0, 0xfc, 0x0, 0x3c, 0x0, 0x0, 0x0 },
  { 0xfc, 0x0, 0x3c, 0x0, 0xcc, 0x0, 0x0, 0x3f, 0x0, 0x33, 0x0, 0x3f, 0x0, 0x0, 0x0, 0x0 },
  { 0x0, 0x0, 0xfc, 0x0, 0x3c, 0x0, 0xcc, 0x0, 0x0, 0x3f, 0x0, 0x33, 0x0, 0x3f, 0x0, 0x0 },
//18
 { 0x0, 0x0, 0xf0, 0x3, 0xc, 0xc, 0x0, 0xc, 0x0, 0x3, 0xc0, 0x0, 0x0, 0x0, 0xc0, 0x0 },
  { 0xc0, 0xf, 0x30, 0x30, 0x0, 0x30, 0x0, 0xc, 0x0, 0x3, 0x0, 0x0, 0x0, 0x3, 0x0, 0x0 },
  { 0x0, 0x0, 0xc0, 0xf, 0x30, 0x30, 0x0, 0x30, 0x0, 0xc, 0x0, 0x3, 0x0, 0x0, 0x0, 0x3 },
//19
{ 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3c, 0xf, 0xfc, 0xf, 0xf0, 0x3, 0xc0, 0x0, 0x0, 0x0 },
  { 0x0, 0x0, 0xf0, 0x3c, 0xfc, 0xff, 0xfc, 0xff, 0xf0, 0x3f, 0xc0, 0xf, 0x0, 0x3, 0x0, 0x0 },
  { 0x0, 0x0, 0x0, 0x0, 0xf0, 0x3c, 0xf0, 0x3f, 0xc0, 0xf, 0x0, 0x3, 0x0, 0x0, 0x0, 0x0 },
  { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x30, 0x3, 0xf0, 0x3, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x0 },

//22
 { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc0, 0xf, 0x0, 0x3, 0xc0, 0xf },
  { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc0, 0x3f, 0x0, 0xc, 0x0, 0x3, 0xc0, 0x3f, 0x0, 0x0 },
  { 0x0, 0x0, 0xfc, 0xf, 0x0, 0x3, 0xc0, 0x0, 0x30, 0x0, 0xfc, 0xf, 0x0, 0x0, 0x0, 0x30 },
  { 0xfc, 0x3, 0xc0, 0x0, 0x30, 0x0, 0xfc, 0x3, 0x0, 0x0, 0x0, 0x3f, 0x0, 0xc, 0x0, 0x3f },
  //01
   { 0xf0, 0xf, 0xc, 0x30, 0xc3, 0xc3, 0x33, 0xcc, 0xc3, 0xc, 0xc, 0xc, 0xf0, 0x3, 0x0, 0x0 },
  { 0xf0, 0x0, 0xc, 0x0, 0xc3, 0xf, 0x33, 0x30, 0x33, 0x33, 0xc3, 0x30, 0xc, 0xc, 0xf0, 0x3 },
  { 0x0, 0x0, 0xc0, 0xf, 0x30, 0x30, 0x30, 0xc3, 0x33, 0xcc, 0xc3, 0xc3, 0xc, 0x30, 0xf0, 0xf },
  { 0xc0, 0xf, 0x30, 0x30, 0xc, 0xc3, 0xcc, 0xcc, 0xc, 0xcc, 0xf0, 0xc3, 0x0, 0x30, 0x0, 0xf },
//02
 { 0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xc0, 0x3, 0xf, 0xf0, 0xf0, 0xf, 0x0, 0x0, 0x0, 0x0 },
  { 0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xc0, 0x3, 0xf, 0xf0, 0xf0, 0xf, 0x0, 0x0, 0x0, 0x0 },
  { 0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xc0, 0x3, 0xf, 0xf0, 0xf0, 0xf, 0x0, 0x0, 0x0, 0x0 },
  { 0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xcf, 0xf3, 0xf0, 0xf, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 },
  { 0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xfc, 0x3f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 },
  { 0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xcf, 0xf3, 0xf0, 0xf, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 },
  { 0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xc0, 0x3, 0xf, 0xf0, 0xf0, 0xf, 0x0, 0x0, 0x0, 0x0 },
  { 0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xc0, 0x3, 0xf, 0xf0, 0xf0, 0xf, 0x0, 0x0, 0x0, 0x0 },

//04
 { 0xf0, 0xf, 0xc, 0x30, 0x3, 0xc0, 0xc3, 0xc3, 0xc3, 0xc3, 0x3, 0xc0, 0xc, 0x30, 0xf0, 0xf },
  { 0x0, 0x0, 0xf0, 0xf, 0xc, 0x30, 0xcc, 0x33, 0xcc, 0x33, 0xc, 0x30, 0xf0, 0xf, 0x0, 0x0 },
//05
 { 0x0, 0x0, 0x0, 0x0, 0xc0, 0x3, 0xf0, 0xf, 0x3c, 0x3c, 0xc, 0x30, 0x0, 0x0, 0x0, 0x0 },
  { 0x0, 0x0, 0xc0, 0x3, 0xf0, 0xf, 0x3c, 0x3c, 0xc, 0x30, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 },
//06
{ 0xc0, 0x0, 0xf0, 0xf, 0xcc, 0x0, 0xf0, 0x3, 0xc0, 0xc, 0xfc, 0x3, 0xc0, 0x0, 0x0, 0x0 },
  { 0x0, 0x0, 0x0, 0x3, 0xc0, 0x3f, 0x30, 0x3, 0xc0, 0xf, 0x0, 0x33, 0xf0, 0xf, 0x0, 0x3 },
  { 0x0, 0x3, 0xc0, 0x3f, 0x30, 0x3, 0xc0, 0xf, 0x0, 0x33, 0xf0, 0xf, 0x0, 0x3, 0x0, 0x0 },
//07
 { 0xc0, 0x3, 0xc0, 0x3, 0xc0, 0x3, 0xc0, 0x3, 0x0, 0x0, 0xc0, 0x3, 0xc0, 0x3, 0x0, 0x0 },
  { 0x0, 0x0, 0xc0, 0x3, 0xc0, 0x3, 0xc0, 0x3, 0xc0, 0x3, 0x0, 0x0, 0xc0, 0x3, 0xc0, 0x3 },
  { 0x0, 0x0, 0x3c, 0x0, 0xfc, 0x0, 0xf0, 0x3, 0xc0, 0x3, 0x0, 0x3c, 0x0, 0x3c, 0x0, 0x0 },
  { 0x0, 0x0, 0xc0, 0x3, 0xc0, 0x3, 0xc0, 0x3, 0xc0, 0x3, 0x0, 0x0, 0xc0, 0x3, 0xc0, 0x3 },
  { 0xc0, 0x3, 0xc0, 0x3, 0xc0, 0x3, 0xc0, 0x3, 0x0, 0x0, 0xc0, 0x3, 0xc0, 0x3, 0x0, 0x0 },
  { 0x0, 0x0, 0x0, 0x3c, 0x0, 0x3f, 0xc0, 0xf, 0xc0, 0x3, 0x3c, 0x0, 0x3c, 0x0, 0x0, 0x0 },
  { 0x0, 0x0, 0xc0, 0x3, 0xc0, 0x3, 0xc0, 0x3, 0xc0, 0x3, 0x0, 0x0, 0xc0, 0x3, 0xc0, 0x3 },
//08
 { 0x0, 0x0, 0xc0, 0x0, 0xcc, 0xc, 0xf0, 0x3, 0xcc, 0xc, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x0 },
  { 0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0x30, 0x33, 0xc0, 0xf, 0x30, 0x33, 0x0, 0x3, 0x0, 0x0 },
  { 0x0, 0x0, 0x0, 0x3, 0x30, 0x33, 0xc0, 0xf, 0x30, 0x33, 0x0, 0x3, 0x0, 0x0, 0x0, 0x0 },
//09
 { 0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 },
  { 0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 },
  { 0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xf0, 0xf, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 },
  { 0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xc0, 0x3, 0xc0, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 },
  { 0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xc0, 0x3, 0xc0, 0x3, 0xc0, 0x3, 0x0, 0x0, 0x0, 0x0 },
  { 0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xc0, 0x3, 0xc0, 0x3, 0xc0, 0x3, 0xc0, 0x3, 0x0, 0x0 },
  { 0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xc0, 0x3, 0xc0, 0x3, 0xc0, 0x3, 0xc0, 0x3, 0xc0, 0x3 },
  { 0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xf0, 0xf, 0xc0, 0x3, 0xc0, 0x3, 0xc0, 0x3, 0xc0, 0x3 },
  { 0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xf0, 0xf, 0xf0, 0xf, 0xf0, 0xf, 0xc0, 0x3, 0xc0, 0x3 },
  { 0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xf0, 0xf, 0xf0, 0xf, 0xf0, 0xf, 0xf0, 0xf, 0xf0, 0xf },
  { 0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xf0, 0xf, 0xf0, 0xf, 0xf0, 0xf, 0xf0, 0xf, 0xf0, 0xf },
//10
 { 0x0, 0x0, 0xc0, 0x0, 0xc0, 0x3, 0x0, 0xf, 0x0, 0x3c, 0x0, 0xf, 0xc0, 0x3, 0xc0, 0x0 },
  { 0x0, 0x0, 0x30, 0x0, 0xf0, 0x0, 0xc0, 0x3, 0x0, 0xf, 0xc0, 0x3, 0xf0, 0x0, 0x30, 0x0 },
  { 0x0, 0x0, 0xc, 0x0, 0x3c, 0x0, 0xf0, 0x0, 0xc0, 0x3, 0xf0, 0x0, 0x3c, 0x0, 0xc, 0x0 },
  { 0x0, 0x0, 0x30, 0x0, 0xf0, 0x0, 0xc0, 0x3, 0x0, 0xf, 0xc0, 0x3, 0xf0, 0x0, 0x30, 0x0 },
  { 0x0, 0x0, 0xc0, 0x0, 0xc0, 0x3, 0x0, 0xf, 0x0, 0x3c, 0x0, 0xf, 0xc0, 0x3, 0xc0, 0x0 },
//11
 { 0x0, 0x0, 0x0, 0x0, 0x30, 0xc, 0xc0, 0x3, 0xc0, 0x3, 0x30, 0xc, 0x0, 0x0, 0x0, 0x0 },
  { 0x0, 0x0, 0xc, 0x30, 0x30, 0xc, 0xc0, 0x3, 0xc0, 0x3, 0x30, 0xc, 0xc, 0x30, 0x0, 0x0 },
  { 0x3, 0xc0, 0xc, 0x30, 0x30, 0xc, 0xc0, 0x3, 0xc0, 0x3, 0x30, 0xc, 0xc, 0x30, 0x3, 0xc0 },
  { 0x0, 0x0, 0xc, 0x30, 0x30, 0xc, 0xc0, 0x3, 0xc0, 0x3, 0x30, 0xc, 0xc, 0x30, 0x0, 0x0 },
//12
{ 0x0, 0x0, 0x0, 0x3c, 0x0, 0xf, 0xc0, 0x3, 0xf0, 0x0, 0x3c, 0x3c, 0x0, 0x3c, 0x0, 0x0 },
  { 0x0, 0xc, 0x0, 0xf, 0xc0, 0x3, 0xf0, 0x0, 0x3c, 0x0, 0x0, 0x3c, 0x0, 0x3c, 0x0, 0x0 },
//13
  { 0x0, 0x0, 0x0, 0x0, 0xc0, 0x3, 0xf0, 0xf, 0x30, 0xc, 0xf0, 0xf, 0x0, 0x0, 0x0, 0x0 },
  { 0x0, 0x0, 0xf0, 0xf, 0x30, 0xc, 0x3f, 0xfc, 0x3, 0xc0, 0x3, 0xc0, 0xff, 0xff, 0x0, 0x0 },
//14
{ 0x0, 0x0, 0xf0, 0xf, 0xfc, 0x3c, 0xfc, 0x33, 0xc, 0x3f, 0xc, 0x3f, 0xf0, 0xf, 0x0, 0x0 },
  { 0x0, 0x0, 0xf0, 0xf, 0x3c, 0x3f, 0xfc, 0x3f, 0x3c, 0x3c, 0x3c, 0x3c, 0xf0, 0xf, 0x0, 0x0 },
  { 0x0, 0x0, 0xf0, 0xf, 0xfc, 0x3f, 0xc, 0x33, 0xc, 0x3f, 0xfc, 0x3f, 0xf0, 0xf, 0x0, 0x0 },
  { 0x0, 0x0, 0xf0, 0xf, 0x3c, 0x3f, 0xfc, 0x3f, 0xc, 0x3f, 0xc, 0x3f, 0xf0, 0xf, 0x0, 0x0 },
//15
{ 0xf0, 0xf, 0xc, 0x30, 0x0, 0x0, 0x0, 0x0, 0xfc, 0x3f, 0xcc, 0x33, 0xcc, 0x33, 0xf0, 0xf },
  { 0x0, 0x0, 0xf0, 0xf, 0xc, 0x30, 0x0, 0x0, 0xfc, 0x3f, 0xcc, 0x33, 0xcc, 0x33, 0xf0, 0xf },

};

