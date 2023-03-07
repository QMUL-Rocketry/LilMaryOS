/*

iteration 1:

Rocket coast

Repeated checks of altitude must be completed when approaching apogee

Ensure motor is no longer burning 

Ensure acceleration is 0

Increase sampling rate / resolution of the altimeter 
--> Why would we need to ramp this up, are we starting with a low sample rate for the
sake of power consumption ? I wouldve assumed the sampling resoltuion and frequency would 
remain constant 



*/


int obtain_Acceleration ()
{
    /*
    Obtain sensor readings and do an necceasry calcualtions to return a value for 
    acceleration
    */
}

bool Obtain_engine_State ()
{
    /*
    True for on 
    False otherwise
    */
}

void enhance_Altitude_Readings ()
{
    /*
    Increase the samplying rate and resolution of the alitmeter 
    */
}

void state_Coast ()
{
    /*
    Function to combine the above into functional code
    Roughly done as:

    1. Turn off motor
    2. Periodically measure acceleration following motor shutdown   
        2.1. Ensure acceleration is not increasing at this stage lest the motor is still on
    3. BEFORE the instanece of acceleration hitting 0 (apogee), enhance the altimeter readings
    Perpahs this will trigger when the acceleration is no longer increasing
    */
}


/*

Planning the Hows of this section of flight, code implemntation should be around second iteration

*/