/*
In Phase 1:
Motor Under Cards: motorA
Motor to Send Cards to Phase 2: motorB

In Phase 2:
Motor to Regulate Scanning of Cards: motorC
*/
void cardScanningP2()
{

}
void sendCardP1(int timedelay_1, int timedelay_2)
{
      motor[motorA] = 10;
      wait1Msec(timedelay_1);
      motor[motorA] = 0;
      motor[motorB] = -90;
      motor[motorA] = -60;
      wait1Msec(timedelay_1);
      motor[motorA] = 0;
      motor[motorA] = 50;
      wait1Msec(timedelay_2);
      motor[motorB] = 0;
      motor[motorA] = 0;
}
//void configureAllSensors(){}
task main()
{
      for(int i=1; i<=3;i++)
      {
            for(int j=1; j<=3; j++)
            {
                  motor[motorC] = -5
                  sendCardP1(370,650);
                  wait1Msec(200);
            }
                  motor[motorA]=30;
                  motor[motorB] = 30;
                  int timedelay_3 = 600;
                  wait1Msec(timedelay_3);
      }
}
big ass ;

