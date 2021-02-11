# TMS570_free_RTOS_GIO_OUTPUT# TMS570_free_RTOS_blinky
This is an example code helps to use TMS570 to do blink or 0 output and 1 output

please follow these steps:

/*In HALCOGEN*/ 
Step 1:

go -> creat project -> select your microcontroller

Step 2:

Configure driver code generation:
•Enable GIO driver
•Disable others

Navigate: -> TMS570LSxx /RM4 -> Driver Enable

Step 3:

Enable GIOA2 :
Navigate: -> GIO -> GIOA2 -> mark dir and interrupt there

Step 4:

Generate code

Navigate: -> File -> Generate Code

/*In CODE COMPOSER STUDIO*/ 

Step 5:

Navigate: -> File -> NEW -> CCS project 
then in the window Navigate: -> target -> TMS570LS04x 
Navigate: -> Connection -> texas instruments XDS100v2 USB Debug probe 

Step 6:

in project properties
Navigate: -> include option -> add include file from the code we generate in HALCOGEN
Navigate: -> advanced option -> language -> change it to c99
Navigate: -> Debug -> Flash option -> erase option -> neccessry only

Step 11:

then write the code i have been added here

