#include <KmeStepper.h>
////Begin pins
KmeStepper KmeStepper(14,4,15,5);
long loadold;
void setup() {
  Serial.begin(115200);
//KmeStepper.KmeDc(8,9); this for dc motor begin
//KmeStepper.left(60,2);  dc motor left
//KmeStepper.right(60,2); dc motor right
///Load cell pins begin
KmeStepper.Loadcellbegin(13,12);
////read loadcell value
loadold=KmeStepper.Loadcell(20);
}
void loop() {
//KmeStepper.Dcright();
//delay(2000);
//KmeStepper.Dcleft();
long x=KmeStepper.Loadcell(2);
long wight=x-loadold;
Serial.println(wight/29000);
}
