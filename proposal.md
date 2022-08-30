## Title of your project


## Team members
Eleanor Sigrest
Peter Benitez

## Project description
The goal of this project is to create an automated waterbottle filler that
stops pouring water based on the water level height in the bottle. This is
a replacement for the current water bottle fliining stations that are time based.

The raspberry pi will know to close the water valve by comparing the water level to the
height of the water bottle. The raspberry pi will detect water level by using a VL53L0X
time-of-flight distance sensor. The height of the water bottle will be detected using a
line of photoresistors and lasers. Since the photoresistors and lasers will be spread at
regular intervals, the height of the water bottle will be calculated by adding the number
of photoresisters that have their laser blocked. A servo/stepper motor will be used and
controlled by the raspberry pi to open and close the water valve.

Additional functionality ideas include:
- Add an LED to light up when a water bottle is placed in the filling station
- Add button(s) for user to choose straw or no straw which changes the set fill height
- Add LCD display to show progress of how much water has been filled
- Add LCD to show number of water bottles saved
- Possibly add a filter and LCD to show filter status (clean or not clean)

## Hardware, budget
- VL53L0X Sensor (have)
- Raspberry Pi (have)
- Lasers and Photosensors (about $13)
- Servo
- Valve
- 5 Gallon Water Bottle (find from campus)
- Table (something cheap from amazon)
- Aluminum barstock to create stand (find from campus/PRL/Lab 64)
- The wood material stuff thats not corkboard but not plywood (find from campus/PRL/Lab 64)
- LCD or monitor (optional... if using monitor have)
- LED (have)

## Tasks, member responsibilities
Each team member should be responsible for a clearly identifiable part of the project.

## Schedule, midpoint milestones
What are the one-week goals you plan to meet for next week?

## Resources needed, issues
Are there books/code/tools/materials that you need access to? 
What are the possible risks to overcome? What are you concerned about? 
How can we help you succeed?
