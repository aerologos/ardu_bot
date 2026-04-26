**Introduction**\
This is a firmware for Arduino robot that is made for robots of Bobic series:\
https://aerologos.by/ru/robots/#robots

The main (though extremely simple) logic is located within ardu_bot.ino file.

**Movement:**\
The logic is started from the movement_algorithm abstraction.
There are a few implementations of it that you can use to test the robot at different stages of assembly. 

**Chasis:**\
Though, only one implementation present front wheel chasis, the abstractions allow to adapt it to any type of chasis.\
You just need to provide your own implementation of chasis.h looking at the existing example: chasis_two_front_wheels.h

**Orientation:**\
The orientation is implemented with rotated ultro-sound distance meter HC-SR04 (Vally eyes).\
But you can exchange it with anything else providing the alternative implementation of distance_meter.h
