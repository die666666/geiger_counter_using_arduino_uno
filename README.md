# Geiger_counter_using_arduino_uno


Geiger counter using Arduino Uno is a project that utilizes an Arduino Uno board to create a radiation detector. It involves wiring a Geiger-Muller tube to the board and programming it to read the number of counts per minute and display the data on an LCD screen or serial monitor. The project can be customized with additional features such as a buzzer alarm to alert the user of high radiation levels. The Geiger counter using Arduino Uno project is a great way to learn about electronics, programming, and radiation detection. It can be used for educational purposes or for practical applications such as monitoring radiation levels in a specific environment.


Components:-
1. Arduino Uno 
2. SBM20 Geiger muller tube
3. lcd 16x2

Steps:-

Step 1. Setting up the liquid crystal display 1602 module
The 1602 lcd display is connected to arduino and the connections are as follows :-
1.The GND pin of 1602 module lcd to the GND pin of arduino.
2.The Vcc pin of lcd to the 5v of power pin of arduino.
3.The SDA pin of lcd to the A4 of analog input of arduino.
4.The SCL pin of lcd to the A5 of analog input of arduino.
The main function of lcd is to display our radiation value. 

Step 2.  Setting up the Geiger tube and arduino  
The Geiger tube is connected to high voltage generator and the connections are as follows :-
1.The output high voltage generator is connected to the negative part of the Geiger muller tube 
2.The positive part of Geiger muller tube connect to 2 pin of arduino.
Geiger tube will be our main component which can detect the beta and gamma radiation through a radioactive material.

Step 3.  Setting up the buzzer for indication
The buzzer is connected to arduino and the connections are as follows:-
1.The buzzer contains two terminals positive and negative. Basically, positive terminal is bigger than negative terminal.
2.The negative terminal of buzzer should be connected to thr GND of arduino.
3.And the positive terminal should be connected on pin 10 on arduino.
4.If it doesn’t work we just have to switch the terminals i.e negative terminal on pin 10 and the positive terminal on 5v of Vcc.
Buzzer will used for indication of beta and gamma radiation substance.  
