/*
In Phase 1:
Motor Under Cards: motorA
Motor to Send Cards to Phase 2: motorB

In Phase 2:
Motor to Regulate Scanning of Cards: motorC

In Phase 3:
Motor to flip the cards: motorD
*/
void flipperAllignment(int deg1)
{
	nMotorEncoder[motorD] = 0;
	motor[motorD] = -1;
	while(nMotorEncoder[motorD] > deg1)
	{
	}
	motor[motorD] = 0;
}
int scoreCalculator(int &cardvalues, int arraylength)
{
	/*
	Description: Function to Calculate the Score for the player and dealer
	Parameters:
	int cardvalues[]: Array which stores the values of the cards
	Return:
	totalscore: the total score for the player/dealer
	*/
	int acesarray[5] = {0, 0, 0, 0, 0};
	int totalscore = 0;
	for (int loopvar = 0; loopvar < arraylength; loopvar++)
	{
		if (cardvalues == 12)
		{
			acesarray[loopvar] = 12;
		}
		else
		{
			totalscore = totalscore + cardvalues;
		}
	}
	for (int loopvar = 0; loopvar < 5; loopvar++)
	{
		if (acesarray[loopvar] == 12)
		{
			if ((totalscore+11) > 21)
			{
				totalscore = totalscore + 1;
			}
			else
			{
				totalscore = totalscore + 11;
			}
		}
	}
	return totalscore;
}
void cardDistribution_P3(int flip, int deg1)
{
	/*
	Description: Final phase of card distribution (card flipping)
	Parameters:
	int flip:
	Return: None
	*/
	if (flip == 0)
	{
		motor[motorC] = -5;
		wait1Msec(510);
		motor[motorC] = -2;
		wait1Msec(8000);
		motor[motorC] = 5;
		wait1Msec(800);
		motor[motorC] = -2;
		wait1Msec(800);
		motor[motorC] = 5;
		wait1Msec(800);
		motor[motorC] = -2;
		wait1Msec(4000);
		motor[motorC] = 0;
		wait1Msec(1500);
		nMotorEncoder[motorD] = 0;
		motor[motorD] = 1;
		while(nMotorEncoder[motorD] < deg1)
		{}
		motor[motorD] = 0;
	}
	else if (flip == 1)
	{
		motor[motorC] = -8;
		wait1Msec(1200);
		motor[motorC] = 0;
		nMotorEncoder[motorD] = 0;
		motor[motorD] = 60;
		while(nMotorEncoder[motorD] < 90)
		{
		}
		motor[motorD] = 0;
		nMotorEncoder[motorD] = 0;
		motor[motorD] = -1;
		while(nMotorEncoder[motorD] > -(90+deg1))
		{}
		motor[motorD] = 0;
	}
}
bool touchWait(int waittimeMS)
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
		if(SensorValue[S2] == 1)
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
	if (SensorValue[S1] == (int)colorBlack)
	{
		displayString(5, "COLOR DETECTED IS BLACK")
		wait1Msec(10000);
		cardvalue = 1;
	}
	else if (SensorValue[S1] == (int)colorBlue)
	{
		displayString(5, "COLOR DETECTED IS BLUE")
		wait1Msec(10000);
		cardvalue = 2;
	}
	else if (SensorValue[S1] == (int)colorRed)
	{
		displayString(5, "COLOR DETECTED IS RED")
		wait1Msec(10000);
		cardvalue = 3;
	}
	else if (SensorValue[S1] == (int)colorYellow)
	{
		displayString(5, "COLOR DETECTED IS YELLOW")
		wait1Msec(10000);
		cardvalue = 4;
	}
	else if (SensorValue[S1] == (int)colorGreen)
	{
		displayString(5, "COLOR DETECTED IS GREEN")
		wait1Msec(10000);
		cardvalue = 5;
	}
	else if (SensorValue[S1] == (int)colorBrown)
	{
		displayString(5, "COLOR DETECTED IS BROWN")
		wait1Msec(10000);
		cardvalue = 6;
	}
	else
	{
		displayString(5, "ERROR: NO COLOR DETECTED")
		wait1Msec(10000);
		cardvalue = -1;
	}
	return cardvalue;
}
void cardDistribution_P2()
{
	motor[motorC] = -4;
	wait1Msec(2000);
	motor[motorC] = 4;
	wait1Msec(2000);
}
/*
void cardDistribution_P1(int timedelay)
{
//Set MotorB on HIGH SPEED
motor[motorB] = -90;
//Set MotorA on LOW SPEED
motor[motorA] = -40;
wait1Msec(timedelay);
motor[motorA] = 0;
motor[motorA] = 30;
wait1Msec(timedelay);
motor[motorB] = 0;
motor[motorA] = 0;
}
*/
void cardDistribution_P2(int timedelay1, int timedelay2, int timedelay3)
{
	motor[motorC] = -2;
	wait1Msec(timedelay1);
	motor[motorC] = 4;
	wait1Msec(timedelay2);
	motor[motorC] = -2;
	wait1Msec(timedelay3);
}
void cardDistribution_P1(int timedelay1, int timedelay2)
{
	motor[motorC] = -2;
	//Set MotorB on HIGH SPEED
	motor[motorB] = -100;
	//Set MotorA on LOW SPEED
	motor[motorA] = -20;
	wait1Msec(timedelay1);
	motor[motorA] = 0;
	motor[motorA] = 20;
	wait1Msec(timedelay2);
	motor[motorB] = 0;
	motor[motorA] = 0;
	motor[motorC] = 0;
}
void card_return(int timedelay3)
{
	motor[motorA] = 10;
	motor[motorA] = 10;
	wait1Msec(timedelay3);
	motor[motorB] = 0;
	motor[motorA] = 0;
}

void configureAllSensors()
{
	  SensorType[S2] = sensorEV3_Touch;
    wait1Msec(50);
    /*
    SensorType[S2] = sensorEV3_Ultrasonic;
    wait1Msec(50);
    SensorType[S4] = sensorEV3_Gyro;
    wait1Msec(50);
    SensorMode[S4] = modeEV3Gyro_Calibration;
    wait1Msec(100);
    SensorMode[S4] = modeEV3Gyro_RateAndAngle;
    wait1Msec(50);
    */
    SensorType[S1] = sensorEV3_Color;
    wait1Msec(50);
    SensorMode[S1] = modeEV3Color_Color;
    wait1Msec(100);
}

task main()
{
	configureAllSensors();
	int deg1 = -75, deg2 = -25;

	for (int i = 0; i < 3; i++)
	{
		flipperAllignment(deg1);
		cardDistribution_P1(800, 800);
		cardDistribution_P2(2000, 2000, 5000);
		cardDistribution_P3(1, deg1);
		card_return(600);
	}
	flipperAllignment(deg2);
	cardDistribution_P1(800, 800);
	cardDistribution_P2(2000, 2000, 5000);
	cardDistribution_P3(0, deg2);
	card_return(600);

	int n = 0;
	bool usercard = true;
	/*
	while (n < 5 && usercard != false)
	{
		displayString(5, "Do you want more cards");
		usercard = touchWait(10000);
		if(usercard == true)
		{
			displayString(5, "OK, here you go :)    ");
			flipperAllignment(deg1);
			cardDistribution_P1(750, 800);
			cardDistribution_P2(2000, 2000, 5000);
			cardDistribution_P3(1, deg1);
			card_return(600);
		}
		else
		{
			displayString(5, "OK, Ending Process... Calculating Results...");
			usercard == false;
		}
		n+=1;
	}
	*/

}
