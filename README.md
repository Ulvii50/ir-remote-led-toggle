# IR Remote LED Toggle

Bu layihədə IR pult vasitəsilə LED-i idarə etmək mümkündür. Hər dəfə müəyyən bir düyməyə basdıqda LED-in vəziyyəti dəyişir: əgər sönülü idisə yanır, yanılı idisə sönür.

## İstifadə olunan komponentlər
- Arduino UNO
- IR Receiver
- IR Remote
- LED
- 220 ohm rezistor
- Breadboard və kabel

## Əsas funksiyalar
- Pultdakı istənilən düyməyə basdıqda LED açılır və ya söndürülür.
- IR siqnal `Serial Monitor` vasitəsilə oxunur.
- `irrecv.resume();` funksiyası növbəti siqnalı qəbul etməyə imkan verir.

## Kodun işləmə prinsipi
IR siqnal alındıqda `results.value` dəyişəni vasitəsilə kod oxunur. Hər basışda `state` dəyişəni dəyişərək LED vəziyyəti dəyişir.

## Tinkercad Simulyasiya Linki:
https://www.tinkercad.com/things/evWE8dV2zfs-fantastic-hillar


## Kod 
#include<IRremote.h>
int recv_pin = 2;
int ledPin = 5;
int state = 0;

IRrecv recv(recv_pin);
decode_results results;

void setup(){
 Serial.begin(9600);
 pinMode(ledPin,OUTPUT);
 recv.enableIRIn();
  	
}

void loop(){
if(recv.decode(&results))
{
  Serial.println(results.value);
  if(results.value)
  {
    state= !state;
    digitalWrite(5,state);
  }
  
  recv.resume();
}
}

