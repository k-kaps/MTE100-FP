/*
In Phase 1:
Motor Under Cards: motorA
Motor to Send Cards to Phase 2: motorB

In Phase 2:
Motor to Regulate Scanning of Cards: motorC

In Phase 3: 
Motor to flip the cards: motorD
*/

bool touchWait(inty waittimeMS)
{
	/*
	Description: To make the touch sensor wait for specific times for an input
	Parameters:
	int waittimeMS: stores the milliseconds to wait for an input
	Return:
	true/false depending on the pressing of the touch sensor
	*/
	time1[T1] = 0;
	while (T1 <= waittimeMS)
	{
		if(SensorValue[S1] == 1)
		{
			return true;
		}
	}
	return false;
}
int cardScanning()
{
	/*
	Description: To calculate the value of the card
	Parameters:
	None
	Return:
	int cardvalue: stores the value of the card
	*/
	int cardvalue = 0;
	if (SensorValue[S1] == int(colorBlack))
	{
		cardvalue = 1;
	}
	else if (SensorValue[S1] == int(colorBlue))
	{
		cardvalue = 2;
	}
	else if (SensorValue[S1] == int(colorGreen))
	{
		cardvalue = 3;
	}
	else if (SensorValue[S1] == int(colorYellow))
	{
		cardvalue = 4;
	}
	else if (SensorValue[S1] == int(colorRed))
	{
		cardvalue = 5;
	}
	else if (SensorValue[S1] == int(colorBrown))
	{
		cardvalue = 6;
	}
	else
	{
		cardvalue = -1;
	}
	return cardvalue;
}
void cardDistribution_P2()
{

}
void cardDistribution_P1(int timedelay)
{
	//Set MotorB on HIGH SPEED
	motor[motorB] = -70;
	//Set MotorA on LOW SPEED
	motor[motorA] = -50;
	wait1Msec(timedelay);
	motor[motorA] = 0;
	motor[motorA] = 30;
	wait1Msec(timedelay);
	motor[motorB] = 0;
	motor[motorA] = 0;
}
//void configureAllSensors(){ // MEVAN}
task main()
{
}
